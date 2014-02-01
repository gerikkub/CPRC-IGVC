F_CPU = 16000000

default:
	avr-gcc -mmcu=atmega328p -DF_CPU=$(F_CPU) -O2 -o test.elf main.c 
	avr-objcopy -O ihex test.elf test.hex
	avr-size test.elf

clean:
	rm -rf *.elf *.o *.hex

download_mac:
	#may need to change /dev/tty to correct port on your computer
	avrdude -p m328p -P /dev/tty.usbmodem1411 -c arduino -F -u -U flash:w:test.hex

download_linux:
	#may need to change /dev/tty to correct port on your computer
	avrdude -p m328p -P /dev/ttyACM0 -c arduino -F -u -U flash:w:test.hex

download_windows:
	avrdude -p m328p -P com3 -c arduino -F -u -U flash:w:test.hex 
