#include <iostream>
#include <time.h>
#include <vector>
#include "mergeSort.cpp"

using namespace std;

int main(){
	int n = 10;
	srand(time(NULL));
	vector<int> v;

	for(int i = 0; i<n; i++){
		v.push_back(rand()%100);
	}

	for(int i:v){
		cout << i << ' ';
	}

	mergeSort(v,0,v.size()-1);
	cout << endl;

	for(int i:v){
		cout << i << ' ';
	}

	cout << endl;
}