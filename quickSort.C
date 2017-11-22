// Hung Nguyen CSCE350 Project 1

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include <sstream>
#include <string.h>
#include <string>

using namespace std;
const int MIN = 10;
const int MAX = 100000;
const int FILE_SIZE = 100;
const char* executionTime = "Nguyen_Hung_timeOfExecution.txt";
const char* averageExecutionTime = "Nguyen_Hung_averageExecutionTime.txt";
void quickSort(int start, int end, vector<double>& numbs){
	if(start >= end)
		return;
	
	int x = start;
	double y;
	int i = start + 1, j = end - 1;

	while(i <=j){
		while(i < end && numbs[i] <= numbs[x])
			++i;
		while(j > start && numbs[j] >= numbs[x])
			--j;
		if(i < j){
			y = numbs[i];
			numbs[i] = numbs[j];
			numbs[j] = y;
		}		
	}	
	if(i == end){
		y = numbs[x];
		numbs[x] = numbs[end - 1];
		quickSort(start, end-1, numbs);
	}
	else if ( j == start){
		quickSort(start + 1, end, numbs);
	}
	else {
		if(i == j)
			j--;
		
		y = numbs[x];
		numbs[x] = numbs[j];
		numbs[j] = y;
		quickSort(start, j, numbs);
		quickSort(j + 1, end, numbs);
	}
}

void outputExecutionTime(int size, double time){
	ofstream out(executionTime, std::ios::app);
	out << setw(10) << size << " " << fixed << setw(15) << showpoint << time << endl;
	out.close();
}

void outputAverageExecutionTime(){
	ifstream in;
	ofstream out;
	in.open(executionTime);
	out.open(averageExecutionTime);
	out << setw(10) << "Input Size " << setw(22) << "Average Execution Time" << endl;
	string item;
	int size;
	double sum = 0;
	double time;

	in >> item;
	in >> item;
	in >> item;
	in >> item;

	for(int i = MIN; i <= MAX; i *= 10){
		sum = 0;
		for(int j = 0; j < FILE_SIZE; j++){
			in >> size >> time;
			sum += time;
		}
		out << setw(10) << size << " " << setw(22) << sum / 100.0 << endl;
		sum = 0;
	}
	out.close();
}

void sortIt(const char* inputFile, const char* outputFile){
	ifstream in;
	ofstream out;
	in.open(inputFile, std::ios::in);
	if(!in.is_open()){
		cerr << "Input file cannot be found!" << endl;
		exit(-1);
	}
	vector<double> numbs;
	double theNumb;
	while(in >> theNumb){
		numbs.push_back(theNumb);
	}
	in.close();
	
	double time;
	struct timeval beg, end;
	gettimeofday(&beg, NULL);

	quickSort(0, numbs.size(), numbs);
	
	gettimeofday(&end, NULL);
	time = (double)((end.tv_sec * 1000000 + end.tv_usec) - (beg.tv_sec * 1000000 + beg.tv_usec)) / 1000.0;

	out.open(outputFile);
	if(!out.is_open()){
		cerr << "output file cannot be found!" << endl;
		exit(-1);
	}
	for(int i = 0; i < numbs.size(); i++){
		out << numbs[i] << " ";
	}
	out.close();
	outputExecutionTime(numbs.size(), time);
}

int main(int argc, char* argv[]){
	if(argc < 3) {
		cerr << "Not enough arguments entered!" << endl;
		return -1;
	}
	sortIt(argv[1], argv[2]);
	outputAverageExecutionTime(); // Calculating AvgExecutionTime 
								//from executionTime file
	return 0;
}
