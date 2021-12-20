#include "aa1626Project2_header.h"

int main(){
	cout <<"Computer Science and Engineering Department\n" << "CSCE 1030.001\n" << "Name: Aaron Alexander" << endl << "EUID: aa1626" << endl << "Email: aaronalexander2@my.unt.edu" << endl;

	bool gChoice = false;
	Student student;
	int choice =0;
	do {
		cout << endl << endl;
		cout << "1.Add \n2.Remove \n3.Display \n4.Search \n5.Results \n6.Quit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice){
			case 1:
				add_Student();

				break;
			case 2:
				cout << "Enter the ID of the student: " << endl;
				cin >> student.id;
				remove_Student(student.id);

				break;
			case 3:
				display();

				break;
			case 4:
				cout << "Enter the ID of the student: " << endl;
				cin >> student.id;
	
				search(student.id);
				break;
			case 5:
				exportResults();
				break;
			case 6:
				cout << "Goodbye!" << endl;
				exit(EXIT_SUCCESS);
				break;
			default:
				cout << "Please choose a valid choice!" << endl;
				gChoice = false;
				break;
		}
		
	}while (gChoice == false);
	return 0;
}
