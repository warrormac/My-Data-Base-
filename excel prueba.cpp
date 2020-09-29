// ConsoleApplication82.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



int main()
{
	ofstream fout;
	int t;
	cin >> t;

	fout.open("pruebas.csv", ios::app);
	fout << t << endl;
	fout << "jaja" << "\t" << "lol";

	fout.close();

}
