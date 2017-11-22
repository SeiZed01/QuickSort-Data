## fullProgram and inputFileGenerator is commented out. Uncomment if want to run fullProgram. Read instructions.txt
all: quickSort ##fullProgram inputFileGenerator

##inputFileGenerator:
##	g++  -std=c++11 -o generateFile inputFileGenerator.C

quickSort:
	g++ -std=c++11 -o quickSort quickSort.C

##fullProgram:
##	g++ -std=c++11 -o fullProgram fullProgramTest.C

clean:
##	rm fullProgram
	rm quickSort
##	rm generateFile
