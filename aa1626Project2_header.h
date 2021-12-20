#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <stdlib.h>

using namespace std;

const int numtests = 5;
enum decision {Add = 1, Remove=2, Display=3, Search=4, Results=5, Quit = 6};
struct Student{
	string name;
	int id;
	int numtests;
	int *scores;
	double average;
};
int getNumber();
void add_Student();
void remove_Student(int id);
void display();
void search(int id);
int findMinimum(int array[], int size);
void exportResults();