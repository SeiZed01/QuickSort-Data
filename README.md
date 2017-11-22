# QuickSort-Data
## Instructions on how to compile and use program 1

A makefile is included with the files being turned in. It currently only compiles quickSort.C , if you want it to compile fullProgramTest.C and inputFileGenerator.C then uncomment it.

When compiling is done, to use quickSort file you will need two arguments. 
First Argument should be the input file and second is output.

I have also included the inputFileGenerator.C here and commented it out in the makefile. If you want to use the inputFileGenerator, it will create 100 random files and put it in a folder called "inputfiles".

I have also included another source code file called fullProgramTest which will generate all the random files with the input into the folder called "inputfiles" and also run quickSort and output into the "outputfiles" folder. 

When running quickSort, two txt files will be created executionTime and avgExecution Time. These contain the execution times for all the input sizes of the randomly generated files. 
