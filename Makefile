# Makefile for Baz

all: LoginDriver

LoginDriver:	Login.o LoginDriver.o
	g++ -g -Wall -o LoginDriver Login.o LoginDriver.o

Login.o:	Login.cpp Login.h
	g++ -g -Wall -c Login.cpp

LoginDriver.o:	LoginDriver.cpp Login.h
	g++ -g -Wall -c LoginDriver.cpp