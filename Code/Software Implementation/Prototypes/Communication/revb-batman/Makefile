all : read_port.o rs232.0
	g++ rs232.o read_port.o   -o read_port
rs232.0 : rs232.c
	g++ -c rs232.c
read_port.o : read_port.cpp
	g++ -c read_port.cpp 



