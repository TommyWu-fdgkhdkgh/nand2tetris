all: assembler parser_unittest code_unittest symbolTable_unittest

parser_unittest: ./test/src/parser_unittest.cpp 
	g++ ./test/src/parser_unittest.cpp -Iinc -o parser_unittest -lgtest -lpthread

code_unittest: ./test/src/code_unittest.cpp
	g++ ./test/src/code_unittest.cpp -Iinc -o code_unittest -lgtest -lpthread

symbolTable_unittest: ./test/src/symbolTable_unittest.cpp
	g++ ./test/src/symbolTable_unittest.cpp -Iinc -o symbolTable_unittest -lgtest -lpthread

assembler: ./src/main.cpp
	g++ ./src/main.cpp -Iinc -o assembler

clean:
	rm -f assembler parser_unittest code_unittest
	
