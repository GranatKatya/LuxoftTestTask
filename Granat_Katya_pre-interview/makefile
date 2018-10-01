output: main.o Application.o Factory.o File.o IProcessor.o stdafx.o

main.o: workwithfile.cpp.txt
	g++ -c workwithfile.cpp.txt

Application.o: Application.cpp.txt Application.h.txt
	g++ -c Application.cpp.txt

Factory.o: Factory.cpp.txt Factory.h.txt
	g++ -c Factory.cpp.txt

File.o: File.cpp.txt File.h.txt
	g++ -c File.cpp.txt

IProcessor.o: IProcessor.cpp IProcessor.h
	g++ -c IProcessor.cpp.txt

stdafx.o: stdafx.cpp.txt stdafx.h.txt
	gcc -c stdafx.cpp.txt
	gcc -o  stdafx.cpp.txt stdafx.h.txt

clean:
	rm *.o output
