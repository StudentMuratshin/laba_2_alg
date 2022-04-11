#include <iostream>
#include "generator.h"
#include "dynamic.h"
#include <fstream>
#include <iomanip>
using namespace std;


int main() {
	cout << "Who's" << setw(17) << "Weight" << setw(11) <<  "Price   " << endl << endl;
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