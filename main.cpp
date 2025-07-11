/**** Problem 7.9 - Chapter 7, Project A
*---------------------------------------------
***** Enhance the program in Programming Project 7.20.8 so that each student has ten quiz scores.
***** The input contains the student names and quiz scores but no course grades.
***** The program should compute the course grade.
***** If the sum of the quiz scores is at least 90, the grade is an A.
***** If the sum is at least 80, the grade is a B, and so on.
***** Then print all students with grade A together with their individual quiz scores,
***** followed by all students with grade B, and so on. */

// Programmer - Ashley Jacobson
// Tester - Audrey Tapia (TESTED)
// Group Project A //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student
{
    string firstName;
    string lastName;
    char courseGrade;
    int quizScores[10];

};
/******* Reads student info from "input.txt" *******/

void readStudents(vector<Student> &students, ifstream& file)
{
string line;
    Student s;
    if (file.fail())
    {
        cout << "Cannot read from input.txt" << endl;
    }
    else
    {
        while(file >> s.firstName)
        {

            file >> s.lastName;

                for(int i = 0; i < 10; i++)
                {
                    file >> s.quizScores[i];
                }

            students.push_back(s);
        }
    }
}
/******* Calculates grade based on sum of quiz scores *******/
char calculateGrade(const Student& s)
{
    const int SIZE = 10;
    int sum = 0;
    char grade;
    for(int i = 0; i < SIZE; i++)
    {
        sum += s.quizScores[i];
    }
    if(sum >= 90)
    {
        grade = 'A';
    }
    else if(sum >= 80)
    {
        grade = 'B';
    }
    else if(sum >= 70)
    {
        grade = 'C';
    }
    else if(sum  >= 60)
    {
        grade = 'D';
    }
    else if(sum < 60)
    {
        grade = 'F';
    }
    return grade;

}

/******* Prints students based on their grade group *******/
void printStudents(vector<Student> &students)
{
    for(int i=0; i < students.size(); i++)
    {
        cout << students[i].firstName << " " << students[i].lastName;
        for(int j = 0; j < 10; j++)
        {
            cout << " " << students[i].quizScores[j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<Student> students;
    vector<Student> studentsA;
    vector<Student> studentsB;
    vector<Student> studentsC;
    vector<Student> studentsD;
    vector<Student> studentsF;
    ifstream file;
    file.open("input.txt");
    readStudents(students, file);

    /******* Groups students into grade groups *******/
    for(int i = 0; i < students.size(); i++)
    {
        students.at(i).courseGrade = calculateGrade(students.at(i));
        if(students.at(i).courseGrade == 'A')
        {
            studentsA.push_back(students.at(i));
        }
        else if(students.at(i).courseGrade == 'B')
        {
            studentsB.push_back(students.at(i));
        }
        else if(students.at(i).courseGrade == 'C')
        {
            studentsC.push_back(students.at(i));
        }
        else if(students.at(i).courseGrade == 'D')
        {
            studentsD.push_back(students.at(i));
        }
        else if(students.at(i).courseGrade == 'F')
        {
            studentsF.push_back(students.at(i));
        }
    }

    /******* Output student info *******/
    cout << "******Students with an A ******" << endl;
    printStudents(studentsA);
    cout << "******Students with a B ******" << endl;
    printStudents(studentsB);
    cout << "******Students with a C ******" << endl;
    printStudents(studentsC);
    cout << "******Students with a D ******" << endl;
    printStudents(studentsD);
    cout << "******Students with an F ******" << endl;
    printStudents(studentsF);
    file.close();
    return 0;
}
