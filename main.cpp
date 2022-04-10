#include <iostream>
#include "generator.h"
#include "dynamic.h"
#include <fstream>
using namespace std;


int main() {
	cout << "Who's   " << "Price   " << "Weight  " << endl << endl;
	def a;
	//dynamic b;

	a.Read("input.txt");
	a.Add(0,0,"");
	a.Print();

	//b.Read("input.txt");
	//b.Add(0);
	//b.Print();
	return 0;
}