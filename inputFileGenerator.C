#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int MAX = 10000;

int main(){
	ofstream out;
	for(int i = 10; i <= 100000; i = i*10){
		srand((unsigned)time(NULL));
		for(int j = 1; j <= 100; j++){
			string fileName = "inputfiles/" + to_string(i) + "_" + to_string(j);
			out.open(fileName.data());
			if(!out.is_open())
				return 0;
			for(int k = 0; k < i;k++){
				out << rand() % MAX + rand() % MAX * 1.0 / (double)(MAX) << " ";
			}
			out.close();
		}
	}	
	return 0;
}
