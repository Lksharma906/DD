#!/bin/bash
CC=gcc
CF=-c -Wall -Wextra
LT=-lpthread

app: app.o open_driver.o write_driver.o read_driver.o close_driver.o nested_driver_access.o
	$(CC) -o app app.o open_driver.o write_driver.o read_driver.o close_driver.o nested_driver_access.o $(LT)

app.o: ./header.h
	$(CC) $(CF) app.c $(LT)

open_driver.o: ./header.h
	$(CC) $(CF) open_driver.c $(LT)

write_driver.o: ./header.h
	$(CC) $(CF) write_driver.c $(LT)

read_driver.o: ./header.h
	$(CC) $(CF) read_driver.c $(LT)

close_driver.o: ./header.h
	$(CC) $(CF) close_driver.c $(LT)

nested_driver_access.o: ./header.h
	$(CC) $(CF) nested_driver_access.c $(LT)


clean:
	-rm *.o
	-rm app

