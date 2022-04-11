#include <iostream>
#include "generator.h"
#include "dynamic.h"
#include <fstream>
#include <iomanip>
using namespace std;


int main() {
	cout << "Who's" << setw(16) << "Price" << setw(12) <<  "Weight  " << endl << endl;
	def a;
	dynamic b;

	a.Read("input.txt");
	a.Add(0,0,"");
	a.Print();
	cout << endl << endl;


	b.Read("input.txt");
	b.Add(0);
	b.Print();
	return 0;
}