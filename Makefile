CC=gcc -Wall 
CLIB=-lgps

clean:
	rm -f *.o *.gch core.* dcgps
dcgps: gps-utils.o dcgps.o gpsprint.o
	$(CC) -o dcgps gps-utils.o dcgps.o gpsprint.o $(CLIB)
dcgps.o:
	$(CC) -c ERRNO.h dcgps.c 
gps-utils.o: 
	$(CC) -c gps-utils.c
gpsprint.o:
	$(CC) -c gpsprint.c