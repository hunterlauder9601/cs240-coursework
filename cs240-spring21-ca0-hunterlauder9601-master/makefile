
all: LauderHello Hello_Class
	g++ LauderHello.o Hello_Class.o -o LauderHello.exe

LauderHello: LauderHello.cpp
	g++ -c LauderHello.cpp

Hello_Class: Hello_Class.cpp
	g++ -c Hello_Class.cpp

clean:
	rm -f *.o LauderHello.exe
