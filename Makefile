# Makefile for Baz

all: LoginDriver DateDriver DayDriver ItineraryDriver a.out

LoginDriver:	Login.o LoginDriver.o Itinerary.o Date.o Day.o ../react.o
	g++ -g -Wall -o LoginDriver Login.o LoginDriver.o Itinerary.o Date.o Day.o ../react.o -lcurl

Login.o:	Login.cpp Login.h Itinerary.h Date.h Day.h ../react.h
	g++ -g -Wall -c Login.cpp

LoginDriver.o:	LoginDriver.cpp Login.h Itinerary.h Date.h Day.h ../react.h
	g++ -g -Wall -c LoginDriver.cpp

DateDriver:  Date.o DateDriver.o 
	g++ -g -Wall -o DateDriver Date.o DateDriver.o

Date.o:  Date.cpp Date.h 
	g++ -g -Wall -c Date.cpp

DateDriver.o:  DateDriver.cpp Date.h
	g++ -g -Wall -c DateDriver.cpp

DayDriver:  Day.o DayDriver.o 
	g++ -g -Wall -o DayDriver Day.o DayDriver.o

Day.o:  Day.cpp Day.h
	g++ -g -Wall -c Day.cpp

DayDriver.o:  DayDriver.cpp Day.h 
	g++ -g -Wall -c DayDriver.cpp

ItineraryDriver:  Itinerary.o ItineraryDriver.o Date.o Day.o Login.o ../react.o
	g++ -g -Wall -o ItineraryDriver Itinerary.o ItineraryDriver.o Date.o Day.o Login.o ../react.o -o ItineraryDriver -lcurl

Itinerary.o:  Itinerary.cpp Itinerary.h Date.h Day.h
	g++ -g -Wall -c Itinerary.cpp

ItineraryDriver.o:  ItineraryDriver.cpp Itinerary.h Date.h Day.h ../react.o
	g++ -g -Wall -c ItineraryDriver.cpp

a.out:  Itinerary.o ItineraryDriver.o Day.o DayDriver.o Date.o DateDriver.o LoginDriver.o Login.o
	g++ -Wall Login.o Itinerary.o ItineraryDriver.o Day.o Date.o ../react.o -lcurl

clean:  
	rm *.o Login.o LoginDriver a.out cached_input out.yaml

