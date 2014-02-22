F_CPU = 16000000

default:
	avr-gcc -mmcu=atmega2560 -DF_CPU=$(F_CPU) -O2 -o test.elf main.c 
	avr-objcopy -O ihex test.elf test.hex
	avr-size test.elf

clean:
	rm -rf *.elf *.o *.hex

download:
	#may need to change /dev/tty to correct port on your computer
	avrdude -p atmega2560 -P /dev/ttyACM0 -c avrispmkII -F -u -U flash:w:test.hex


