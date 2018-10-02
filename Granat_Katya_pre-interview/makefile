install: workwithfile.o Application.o Factory.o File.o IProcessor.o stdafx.o
	g++ workwithfile.o Application.o Factory.o File.o IProcessor.o stdafx.o -o workwithfile

test: workwithfileTest.o Application.o Factory.o File.o IProcessor.o stdafx.o
	g++ workwithfileTest.o Application.o Factory.o File.o IProcessor.o stdafx.o -o tests
	./tests

workwithfileTest.o: workwithfileTest.cpp
	g++ -c workwithfileTest.cpp

workwithfile.o: workwithfile.cpp
	g++ -c workwithfile.cpp

Application.o: Application.cpp Application.h
	g++ -c Application.cpp

Factory.o: Factory.cpp Factory.h
	g++ -c Factory.cpp

File.o: File.cpp File.h
	g++ -c File.cpp

IProcessor.o: IProcessor.cpp IProcessor.h
	g++ -c IProcessor.cpp

stdafx.o: stdafx.cpp stdafx.h
	g++ -c stdafx.cpp

clean:
	rm *.o tests workwithfile | true

