encoder.out : decoder.o encoder.o encoderRunner.o Huffman.o tries.o
	g++ -pg -ansi -Wall -g -o encoder.out decoder.o encoder.o encoderRunner.o Huffman.o tries.o 

Huffman.o : Huffman.cpp Huffman.h
	g++ -pg -ansi -Wall -g -c Huffman.cpp

tries.o : tries.cpp tries.h
	g++ -pg -ansi -Wall -g -c tries.cpp
 
decoder.o : decoder.cpp decoder.h tries.h
	g++ -pg -ansi -Wall -g -c decoder.cpp

encoder.o : encoder.cpp encoder.h Huffman.h
	g++ -pg -ansi -Wall -g -c encoder.cpp

encoderRunner.o : encoderRunner.cpp CPUTimer.h encoder.h decoder.h 
	g++ -pg -ansi -Wall -g -c encoderRunner.cpp

clean : 
	rm -f encoder.out decoder.o  encoder.o  encoderRunner.o Huffman.o tries.o 
