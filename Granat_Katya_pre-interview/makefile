install: workwithfile.o Application.o Factory.o File.o IProcessor.o stdafx.o
	g++ workwithfile.o Application.o Factory.o File.o IProcessor.o stdafx.o

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
	rm *.o output
