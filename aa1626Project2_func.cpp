#include "aa1626Project2_header.h"


void add_Student(){ //done
	ofstream outF;
	Student student;
	outF.open("student.dat", ios_base::app);

	string temp; //temp string so that I can concatenate it to for the full name in the correct format
	//opening file to write
	if (outF.fail()){
		cout << "Error accessing student files." << endl;
		exit(EXIT_FAILURE);
	}
	outF<<endl;
	cout << "What is last name of the student? ";
	cin >> student.name;
	
	cout << "What is the first name of the student? ";
	cin >> temp;
	
	student.name = student.name +',' + temp; //concatenating temp string to make full name
	cout << "Enter the student's ID: ";
	cin >> student.id;
	cout << endl;
	
	outF << student.name << ',' << student.id << ',';//pushing data into the file
	cout << "How many tests taken? ";
	cin >> student.numtests;
	outF << student.numtests << ',';
	cout << endl;
	
	
	
	student.scores = new int[student.numtests];//making dynamic arrau

	for (int i=1; i <= student.numtests; ++i){
		cout << "Enter the score for test #" << i << ":";//asking for scores
		cin >> student.scores[i];
		cout << endl;
		outF << student.scores[i] <<",";//pushing score towards file and formatting it
	}
	
	outF.close();
	
}

int getNumber(){ //done
	ifstream fin;
	fin.open("student.dat");
	if (fin.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}
	int count=0;
	string line;
	while(!fin.eof())
	{
		getline(fin, line);
		++count;
	}
	
	fin.close();
	return(count);
	
}

void remove_Student(int id){ //done
	int size = getNumber();//to form dynamic arrays
	string fname;//temp variables to store parts of the name
	string lname;
	
	bool match = false;//boolean to see if id is found
	Student *array;
	array = new Student[size];
	
	ifstream inF; //opening file to write from
	inF.open("student.dat");
	if (inF.fail()){
		cout << "Error accessing student files." << endl;
		exit(EXIT_FAILURE);
	}
	string temp;//temp string
	int i=0;
	//loop to gather data from file
	while (i<size){
		getline(inF, lname, ',');
		getline(inF, fname, ',');
		array[i].name = lname + ',' + fname;//forming full name
		inF >> array[i].id;//getting id number
		getline(inF, temp, ',');//using temp string to bypass commas
		inF >> array[i].numtests;//getting numtests
		getline(inF, temp, ',');//using temp string to bypass commas
		array[i].scores = new int[array[i].numtests];
		for (int j=0; j < array[i].numtests; ++j){
			inF >> array[i].scores[j];
			getline(inF, temp, ',');//using temp string to bypass commas
		}
		//if statement to see if there is a match
		if (array[i].id == id){
			match = true;
		}
		++i;//updates loop
	}
	//if then statement to let user know if id didn't match
	if (match == true){
		ofstream outF;
		outF.open("student.dat");
		if (outF.fail()){
			cout << "Error accessing student files." << endl;
			exit(EXIT_FAILURE);
		}
		//loop to write data back to file
		for (i =0; i <size; ++i){
			if(array[i].id != id){
				outF << array[i].name;
				outF<< "," << array[i].id << ',' << array[i].numtests << ',';
				for (int j=0; j<array[i].numtests;++j){
					outF << array[i].scores[j] << ",";
				}
			}
		}
		outF.close();
	}	
	else{
		cout << "Student does not exist!" << endl;
	}
}

void display(){//done
	ifstream inF;
	inF.open("student.dat");
	Student *studentarray;
	int size = getNumber();//calling function for size
	string fname;
	string lname;
	string temp;
	studentarray = new Student[size];//dynamic array for students
	if (inF.fail()){
		cout << "Error accessing student files." << endl;
		exit(EXIT_FAILURE);
	}
	int i=0;
	while (i<size){
		getline(inF, lname, ',');
		getline(inF, fname, ',');
		studentarray[i].name = lname + ',' + fname;//forming full name
		inF >> studentarray[i].id;//getting id number
		getline(inF, temp, ',');//using temp string to bypass commas
		inF >> studentarray[i].numtests;//getting numtests
		getline(inF, temp, ',');//using temp string to bypass commas
		studentarray[i].scores = new int[studentarray[i].numtests];//second dynamic array for grades
		for (int j=0; j < studentarray[i].numtests; ++j){
			inF >> studentarray[i].scores[j];
			getline(inF, temp, ',');//using temp string to bypass commas
		}
		++i;//updates loop
	}
	//outputting first entry
	cout << left << setw(30) << studentarray[0].name;
	cout << setw(15) << studentarray[0].id;
	for (int j=0; j < studentarray[0].numtests; ++j){
			cout << setw(5) << studentarray[0].scores[j];
	}
	
	//loop that outputs all remaining students
	for(i=1; i<size; ++i){
		cout << left << setw(31) << studentarray[i].name;
		cout << setw(15) << studentarray[i].id;
		for (int j=0; j < studentarray[i].numtests; ++j){
			cout << setw(5) << studentarray[i].scores[j];
		}
	}
	
	inF.close();
}

void search(int id){//done
	Student *student, s;
	student=&s;
	ifstream inF;
	int size = getNumber();
	string lname;
	string fname;
	string fullname;
	string temp;
	bool found = false;
	inF.open("student.dat");
	if (inF.fail()){
		cout << "Error accessing student files." << endl;
		exit(EXIT_FAILURE);
	}
	int i=0;
	
	while (i<size){
		getline(inF, lname, ',');
		getline(inF, fname, ',');
		fullname = lname + ',' + fname;//forming full name
		student->name = fullname;//assigning pointer to fullname
		inF >> student->id;//getting id number
		getline(inF, temp, ',');//using temp string to bypass commas
		inF >> (*student).numtests;//getting numtests
		getline(inF, temp, ',');//using temp string to bypass commas
		(*student).scores = new int[(*student).numtests];//second dynamic array for grades
		for (int j=0; j < (*student).numtests; ++j){
			inF >> (*student).scores[j];//assigning grades to array
			getline(inF, temp, ',');//using temp string to bypass commas
		}
		++i;//updates loop
		if ((*student).id == id){//checks if id was found
			found = true;
			break;//breaks loop if found
		}
	}
	if (found == true){
		cout << left << setw(30) << (*student).name;//formatting output
		cout << setw(15) << (*student).id;
		for (int j=0; j < (*student).numtests; ++j){
				cout << setw(5) << (*student).scores[j];
		}
	}else{
		cout << "No match found!" << endl;
	}
	inF.close();
}

int findMinimum(int array[], int size){//done
	int i=0;
	float min;
	if (size <= 4){
		min =0;
	}else{
		for (i =0; i<size; ++i){
			if (min>array[i]){//finding minimum
				min = array[i];
			}
		}
	}
	return min;
}

void exportResults(){//done
	int size = getNumber();//to form dynamic arrays
	string fname;//temp variables to store parts of the name
	string lname;
	ifstream inF; //opening file to write from
	ofstream outF;
	inF.open("student.dat");
	if (inF.fail()){
		cout << "Error accessing student files." << endl;
		exit(EXIT_FAILURE);
	}
	outF.open("averages.dat");
	if (outF.fail()){
		cout << "Error accessing student files." << endl;
		exit(EXIT_FAILURE);
	}
	Student *resultarray;//creating array
	resultarray = new Student[size];
	string temp;//temp string
	int i=0;
	while (i<size){
		getline(inF, lname, ',');
		getline(inF, fname, ',');
		resultarray[i].name = lname + ',' + fname;//forming full name
		inF >> resultarray[i].id;//getting id number
		getline(inF, temp, ',');//using temp string to bypass commas
		inF >> resultarray[i].numtests;//getting numtests
		getline(inF, temp, ',');//using temp string to bypass commas
		resultarray[i].scores = new int[resultarray[i].numtests];//second dynamic array for grades
		for (int j=0; j < resultarray[i].numtests; ++j){
			inF >> resultarray[i].scores[j];
			getline(inF, temp, ',');//using temp string to bypass commas
		}
		++i;//updates loop
	}
	double sum=0;
	for (i=0; i<size; ++i){
		sum=0;
		for(int j=0; j < resultarray[i].numtests; ++j){
			sum = sum + resultarray[i].scores[j];
		}
		sum = sum - findMinimum(resultarray[i].scores,resultarray[i].numtests);
		
		//writing data to file
		outF << resultarray[i].id << "\t";
		outF.setf(ios::fixed);//making sure only one decimal digit shows
		outF.setf(ios::showpoint);
		outF.precision(1);
		outF << sum/(static_cast<double>(resultarray[i].numtests)) << endl;
	}
}
