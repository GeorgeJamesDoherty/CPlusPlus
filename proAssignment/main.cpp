#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <tuple>
#include "Allocator.h"
using namespace std;

int main (int x, char *argv[]){
    //initializes strings for files to be read
    string staffTxt    = "";
    string projectsTxt = "";
    string studentsTxt = "";
    //reads arguments given to the program
    try{
        staffTxt    = argv[1];
        projectsTxt = argv[2];
        studentsTxt = argv[3];
    }
    //catches incorrect arguments
    catch(exception e){
        cout << "Incorrect arguments" << endl;
    }
    //opens first input file
    ifstream inputFile;
    inputFile.open(staffTxt.c_str());

    //sets up ffor irst read of file
    const char delimiter = ' ';
    string staffText = "";
    int effort = -1;
    //initializes vector to hold staff information
    vector<tuple<string, int>> staff;

    //first read of the file, takes first line
    getline(inputFile, staffText, delimiter);
    inputFile >> effort;
    inputFile.ignore(INT16_MAX, '\n');

    while (inputFile){
        //pushes line into the vector and grabs remaining lines
        staff.push_back(make_tuple(staffText, effort));
        getline(inputFile, staffText, delimiter);
        inputFile >> effort;
        inputFile.ignore(INT16_MAX, '\n');
    }
    //closes and clears the input file
    inputFile.close();
    inputFile.clear();
    //opens project file
    inputFile.open(projectsTxt.c_str());

    //sets up first read for project
    int projectNo = -1;
    string projectStaff = "";
    int projectAvalible = -1;
    string projectName = "";
    //initializes vector to hold project information
    vector<tuple<int, string, int, string>> projects;

    //first read for project infomation
    inputFile >> projectNo;
    inputFile.ignore(INT16_MAX, ' ');
    getline(inputFile, projectStaff, delimiter);
    inputFile >> projectAvalible;
    inputFile.ignore(INT16_MAX, ' ');
    getline(inputFile, projectName, '\n');

    while (inputFile){
        //stores first read and all after in a tuple
        projects.push_back(make_tuple(projectNo, projectStaff, projectAvalible, projectName)); 
        inputFile >> projectNo;
        inputFile.ignore(INT16_MAX, ' ');
        getline(inputFile, projectStaff, delimiter);
        inputFile >> projectAvalible;
        inputFile.ignore(INT16_MAX, ' ');
        getline(inputFile, projectName, '\n');
    }
    //closes and clears the input file
    inputFile.close();
    inputFile.clear();
    //opens the student file
    inputFile.open(studentsTxt.c_str());

    //sets up first read for student file
    string stuName = "";
    int choice1 = -1;
    int choice2 = -1;
    int choice3 = -1;
    int choice4 = -1;
    //initializes vector to hold student information
    vector<tuple<string, int, int, int, int>> students;

    //first read for student file
    getline(inputFile, stuName, delimiter);
    inputFile >> choice1;
    inputFile >> choice2;
    inputFile >> choice3;
    inputFile >> choice4;
    inputFile.ignore(INT16_MAX, '\n');

    while(inputFile){
        //stores first read in vector and all after
        students.push_back(make_tuple(stuName,choice1,choice2,choice3,choice4));
        getline(inputFile, stuName, delimiter);
        inputFile >> choice1;
        inputFile >> choice2;
        inputFile >> choice3;
        inputFile >> choice4;
        inputFile.ignore(INT16_MAX, '\n');
    }
    //closes and clears the input file
    inputFile.close();
    inputFile.clear();

    //makes a new allocator to allocate the project
    Allocator allocate = Allocator(staff, projects, students);
    //gets the allocation from the allocator
    vector<tuple<string,int>> allocation = allocate.allocate();
    //opens an output file to write to
    ofstream finalAllocation("alloc.txt");
    for(int i = 0; i < allocation.size(); i++){
        //writes each line of the allocation to the file
        finalAllocation << get<0>(allocation[i]) << " " << get<1>(allocation[i]) << endl;
    }
    //writes the score to the file
    finalAllocation << allocate.getScore() << endl;
    //closes the file
    finalAllocation.close();
}