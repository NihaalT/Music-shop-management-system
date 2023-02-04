output: coursework.o product.o
	g++ coursework.o product.o -o output

coursework.o: coursework.cpp
	g++ -c coursework.cpp

product.o: product.cpp product.h
	g++ -c product.cpp

clean:
	rm *.o output
