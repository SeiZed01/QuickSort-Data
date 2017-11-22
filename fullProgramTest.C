#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;
const char* sortName = "quickSort";
const int MIN = 10;
const int MAX = 100000;
const int FILE_SIZE = 100;
const char* executionTime = "Nguyen_Hung_timeOfExecution.txt";

void generateFile(){
	cout << "Randomly generating input files:" << endl;
	system("./generateFile");
}
void runQuickSort(const string& inputFile, const string& outputFile){
	string cmd = "./" + string(sortName) + " " + inputFile + " " + outputFile;
	system(cmd.data());
}
int main(){
	generateFile();
	cout << "Sorting input files:" << endl;
	ofstream out;
	out.open(executionTime);
	out << setw(10) << "Input Size " << setw(15) << "Execution Time" << endl;
	out.close();
	for(int i = MIN; i <= MAX; i*=10){
		for(int j = 1; j<= FILE_SIZE; ++j){
			string inputFile = "inputfiles/" + to_string(i) + "_" + to_string(j);
			string outputFile = "outputfiles/" + to_string(i) + "_" + to_string(j);
			runQuickSort(inputFile, outputFile);
		}
	}
	cout << "All Done!" << endl;
}
