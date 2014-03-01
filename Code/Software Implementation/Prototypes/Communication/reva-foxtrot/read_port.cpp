#include <SerialStream.h>
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

#define HEADER_RESPONSE_SIZE 3

typedef  unsigned char  uchar;
using namespace std;
using namespace LibSerial ;
SerialStream serial_port ;

int sendCommand();

void SendHeader(uchar groupid , uchar cmd, uchar size  )
{
    uchar checksum  = groupid+ cmd +size;

    serial_port.write( ( char *)&groupid, 1 ) ;
    serial_port.write( ( char *)&cmd, 1 ) ;
    serial_port.write( ( char *)&size, 1 ) ;
    serial_port.write( ( char *)&checksum, 1 ) ;
}


int main()
{
    //
    // Open the serial port.
    //
    serial_port.Open( "/dev/ttyUSB0" ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] "
                  << "Error: Could not open serial port." 
                  << std::endl ;
        exit(1) ;
    }
    //
    // Set the baud rate of the serial port.
    //
    serial_port.SetBaudRate( SerialStreamBuf::BAUD_115200 ) ;
    if ( ! serial_port.good() )
    {
        std::cerr << "Error: Could not set the baud rate." << std::endl ;
        exit(1) ;
    }
    //
    // Set the number of data bits.
    //
    serial_port.SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not set the character size." << std::endl ;
    }
    //
    // Disable parity.
    //
    serial_port.SetParity( SerialStreamBuf::PARITY_NONE ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not disable the parity." << std::endl ;
        exit(1) ;
    }
    //
    // Set the number of stop bits.
    //
    serial_port.SetNumOfStopBits( 1 ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not set the number of stop bits."
                  << std::endl ;
        exit(1) ;
    }
    //
    // Turn off hardware flow control.
    //
    serial_port.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not use hardware flow control."
                  << std::endl ;
        exit(1) ;
    }
    //
    // Do not skip whitespace characters while reading from the
    // serial port.
    //
    // serial_port.unsetf( std::ios_base::skipws ) ;
    //
    // Wait for some data to be available at the serial port.
    //

    int runs = 0;
    int errors = 0;

    for(;;){
      if(sendCommand() == EXIT_FAILURE){
        errors++;
      }
      runs++;

      std::cout << ((float)(runs-errors)/runs)*100 << "%\n";

      usleep(300000);

    }


}
int sendCommand(){

    serialCommandsStart:

    std::cerr << "Starting serial transmission" << std::endl;
        usleep(100) ;
        int size = 0;
        SendHeader(1,1,size);
        char next_byte;
        serial_port.get(next_byte);
        if((uchar)next_byte == 128) {
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
           serial_port.get(headerResponse[i]);
           //serial_port >> headerResponse[i];
        }
        //check for header checksum
        uchar checksum = headerResponse[0] + headerResponse[1];
        if(checksum != headerResponse[2]) {
           std::cerr << "ERROR: Expected " << checksum << " in header response but recieved"
              << headerResponse[2] << std::endl;
           serial_port << 0x00;
           //std:cout << "e";
           return EXIT_FAILURE;
        } else {
           std::cerr << "Correct checksum in header response" << std::endl;
           std::cerr << "Size was 0x" << std::hex << std::setw(2) << std::setfill('0')
              << (int)headerResponse[1] << std::endl;
           serial_port << 128;
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
          do {
            serial_port.get(payload[i]);
       
   } while(payload[i] == -1);
          std::cerr << "Recieved byte 0x" << std::hex  << std::setw(2) << std::setfill('0')
            << (unsigned int)payload[i] << " " << (0x30 | i) << std::endl;
          payloadSum += payload[i];
        }
        //checksum payload
        char payloadSentSum;
        serial_port.get(payloadSentSum);
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

