//Name: Michael Olaoye

#include<iostream>
#include<string>
#include <iomanip>

using namespace std;  //introduces namespace std

const int STUDENTS = 3;
const int COURSES = 5;
const int CREDITS = 3;

struct StudentRecord
{
	int ID; //user entered member 
	string name; //user entered member 
	double GPA; //calculated member
};

void getStudentInfo(StudentRecord[]);
void calculateGPA(StudentRecord[]);
void displayStudentInfo(StudentRecord student[]);


int main()
{
	StudentRecord student[STUDENTS];

	getStudentInfo(student);
	calculateGPA(student);
	displayStudentInfo(student);

	cout << endl << endl;
	return 0;
}

void getStudentInfo(StudentRecord student[])
{
	string dummy;
	for (int i = 0; i < STUDENTS; i++)
	{
		cout << "Enter Student " << i + 1 << " ID: ";
		cin >> student[i].ID;
		getline(cin, dummy);
		cout << "Enter Student " << i + 1 << " name: ";
		getline(cin, student[i].name);
		cout << endl << endl;
	}
}

void calculateGPA(StudentRecord student[])
{
	char letterGrade = 0;
	double totalPts = 0;
	int i = 0;


	for (int m = 0; m < STUDENTS; m++)
	{
		totalPts = 0;
		//Prompt for each students' letter grade by using student name
		cout << "Enter " << student[m].name << ": ";
		for (i = 0; i < COURSES; i++)
		{
			cout << "\nCourse # " << i + 1 << " : ";
			cin >> letterGrade;
			if (letterGrade == 'A' || letterGrade == 'a')
				totalPts = totalPts + 4;
			else if (letterGrade == 'B' || letterGrade == 'b')
				totalPts = totalPts + 3;
			else if (letterGrade == 'C' || letterGrade == 'c')
				totalPts = totalPts + 2;
			else if (letterGrade == 'D' || letterGrade == 'd')
				totalPts = totalPts + 1;
			else if (letterGrade == 'F' || letterGrade == 'f')
				totalPts = totalPts + 0;
		}
		//calculate GPA and store in GPA Structure member
		student[m].GPA = totalPts /COURSES;
	}
}

void displayStudentInfo(StudentRecord student[])
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n\nID     Name     GPA" << endl;
	for (int i = 0; i < STUDENTS; i++)
	{
		cout << setw(5) << left << student[i].ID;
		cout << setw(12) << student[i].name;
		cout << setw(7) << student[i].GPA;
		cout << endl;
	}
}
