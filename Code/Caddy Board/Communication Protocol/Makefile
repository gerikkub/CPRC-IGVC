default : debug

debug : main.o protocol.o
	gcc -g main.o protocol.o -o CommunicationProtocol 

main.o : main.c
	gcc -g -c -std=c11 main.c -o main.o

protocol.o : protocol.c
	gcc -g -c -std=c11 protocol.c -o protocol.o
