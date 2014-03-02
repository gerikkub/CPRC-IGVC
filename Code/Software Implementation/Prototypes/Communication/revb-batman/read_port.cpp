#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#define NUMRETRYS 200
#define HEADER_RESPONSE_SIZE 3
int cport_nr=16,        /* /dev/ttyS0 (COM1 on windows) */
bdrate=115200;       /* 9600 baud */
unsigned char buf[4096];
typedef  unsigned char  uchar;
using namespace std;


int sendCommand();

void SendHeader(uchar groupid , uchar cmd, uchar size  )
{
    uchar checksum  = groupid+ cmd +size;


     RS232_SendByte(cport_nr, groupid) ;
      RS232_SendByte(cport_nr, cmd) ;
     RS232_SendByte(cport_nr, size ) ;
      RS232_SendByte(cport_nr, checksum ) ;
}



int main()
{
    int i, n;


        if(RS232_OpenComport(cport_nr, bdrate))
        {
          printf("Can not open comport\n");

          return(0);
        }

    int runs = 0;
    int errors = 0;

    for(;;){
      if(sendCommand() == EXIT_FAILURE){
        errors++;
      }
      runs++;

      std::cout << ((float)(runs-errors)/runs)*100 << "%\n";

      usleep(100000);

    }


}

int sendCommand(){


    std::cerr << "Starting serial transmission" << std::endl;
        usleep(100) ;
        int size = 0;
        SendHeader(1,1,size);
        char next_byte;
          int  y= 0;
        while( RS232_PollComport(cport_nr, buf, 1)== 0)
        {
            usleep(1000) ;

         y++;
         if(y == NUMRETRYS)
         {
         break;
         }
        }
        if((uchar)buf[0] == 128) {
            std::cerr << "good shit\n";
        } else {

            std::cerr << "bad shit\n";
            return EXIT_FAILURE;
        }

        /*unsigned char array[10] = {0xff,2,3,6, 4,4,4};
        uchar checksum = 0;
        for(int i = 0;  i < size; i++)
        {
            serial_port.write( &(((const char *)array)[i]), 1 ) ;
            checksum  += array[i];


        cout << "sent "<< "\n";

        }
         serial_port.write((char *)&checksum,1);

         serial_port.get(next_byte);
         if((uchar)next_byte == 255)
             std::cout << "good shit\n";
         else
             std::cout << "bad shit\n";
         */


        //std::cout << "recieved bytes:" <<next_byte << "\n";

 //       std::cerr << std::hex << static_cast<int>(next_byte) << " ";
        usleep(100) ;

        //prepare to recieve header validation (3 bytes)
        char headerResponse[HEADER_RESPONSE_SIZE];
        for(int i = 0; i < HEADER_RESPONSE_SIZE; i++) {
            int y = 0;

           while(     RS232_PollComport(cport_nr,(unsigned char*) &headerResponse[i], 1)== 0);
           {
               usleep(1000) ;

            y++;
            if(y == NUMRETRYS)
            {
            break;
            }
           //serial_port >> headerResponse[i];
        }
        }
        //check for header checksum
        uchar checksum = headerResponse[0] + headerResponse[1];
        if(checksum != headerResponse[2]) {
           std::cerr << "ERROR: Expected " << checksum << " in header response but recieved"
              << headerResponse[2] << std::endl;

           RS232_SendByte(cport_nr,0);
           //std:cout << "e";
           return EXIT_FAILURE;
        } else {
           std::cerr << "Correct checksum in header response" << std::endl;
           std::cerr << "Size was 0x" << std::hex << std::setw(2) << std::setfill('0')
              << (int)headerResponse[1] << std::endl;
           RS232_SendByte(cport_nr, 128 ) ;
        }
        usleep(10000) ;
        //recieve payload
        char *payload = (char*) malloc(sizeof(char) * headerResponse[1]);
        char payloadSum = 0;
        //read extra byte to see if ther is extra hiding data for testing
        //REMOVE LATER
        memset(payload,0,headerResponse[1]);

        std::cerr << "Starting to Revcieve\n";

        for(char i = 0; i < headerResponse[1]; i++) {
                int y = 0;
                while(  RS232_PollComport(cport_nr,(unsigned char*) &payload[i], 1)==0)
                   {

                    usleep(1000) ;

                    y++;
                    if(y == NUMRETRYS)
                    {
                    break;
                    }
                    }


          std::cerr << "Recieved byte 0x" << std::hex  << std::setw(2) << std::setfill('0')
            << (unsigned int)payload[i] << " " << (0x30 | i) << std::endl;
          payloadSum += payload[i];
        }
        //checksum payload
        unsigned char payloadSentSum;
         y = 0;
        while(RS232_PollComport(cport_nr,(unsigned char*) &payloadSentSum, 1)==0)
        {

            usleep(1000) ;

         y++;
         if(y == NUMRETRYS)
         {
         break;
         }
        }

        if(payloadSentSum != payloadSum) {
           std::cerr << "ERROR: Expected checksum of " << std::hex << (int)payloadSentSum  <<
              " and recieved " << std::hex << (int) payloadSum << std::endl;
           return EXIT_FAILURE;
        } else {
           std::cerr << "Correct checksum in the payload" << std::endl;
        }


   std::cerr << std::endl ;
   return EXIT_SUCCESS ;
}

