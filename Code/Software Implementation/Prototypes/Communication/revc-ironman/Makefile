all : SerialComms.o rs232.o main.o
	g++ main.o rs232.o SerialComms.o -o main 
rs232.0 : rs232.c
	g++ -c rs232.c -g
read_port.o : SerialComms.cpp
	g++ -c SerialComms.cpp -g

main.o : main.cpp
	g++ -c main.cpp -g

