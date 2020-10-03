#include <vector>
#include <tuple>
#include <string>
#include <iostream>
using namespace std;

class Allocator {
    public:
        Allocator();

        //value constructor for allocator 
        Allocator(vector<tuple<string, int>> staffVec, vector<tuple<int, string, int, string>> proVec, vector<tuple<string, int, int, int, int>> stuVec){
            //deep copies the 3 vectors
            for(int i = 0; i < staffVec.size(); i++){
                staff.push_back(staffVec[i]);
            }
            for(int i = 0; i < proVec.size(); i++){
                projects.push_back(proVec[i]);
            }
            for(int i = 0; i < stuVec.size(); i++){
                students.push_back(stuVec[i]);
            }
        }

        vector<tuple<string, int>> allocate(){
            //initializes variables to check if a project has been allocated and what project has been allocated
            int temp = -1;
            bool allocated = false;
            string projectStaff = "";
            for(int i = 0; i < students.size(); i++){
                //resets allocated to false when moving onto the next student
                allocated = false;
                //gets first student choice
                temp = get<1>(students[i]);
                //loops through projects to see if first choice is avaliable
                for(int j = 0; j < projects.size(); j++){
                    if(get<0>(projects[j]) == temp && get<2>(projects[j]) > 0){
                        get<2>(projects[j]) = get<2>(projects[j]) - 1;
                        projectStaff = get<1>(projects[j]);
                        break;
                    }
                }
                //loops through staff to see if they have effort left and if so allocates project
                for(int k = 0; k < staff.size(); k++){
                    if(get<0>(staff[k]) == projectStaff && get<1>(staff[k]) > 0){
                        get<1>(staff[k]) = get<1>(staff[k]) - 1;
                        allocation.push_back(make_tuple(get<0>(students[i]),temp));
                        allocated = true;
                        projectStaff = "";
                        break;
                    }
                }
                //checks if a project has been allocated
                if (allocated == false){
                    //gets second student choice
                    temp = get<2>(students[i]);
                     //loops through projects to see if second choice is avaliable
                    for(int j = 0; j < projects.size(); j++){
                        if(get<0>(projects[j]) == temp && get<2>(projects[j]) > 0){
                            get<2>(projects[j]) = get<2>(projects[j]) - 1;
                            projectStaff = get<1>(projects[j]);
                            break;
                        }
                    }
                    //loops through staff to see if they have effort left and if so allocates project
                    for(int k = 0; k < staff.size(); k++){
                        if(get<0>(staff[k]) == projectStaff && get<1>(staff[k]) > 0){
                            get<1>(staff[k]) = get<1>(staff[k]) - 1;
                            allocation.push_back(make_tuple(get<0>(students[i]),temp));
                            allocated = true;
                            projectStaff = "";
                            break;
                        }
                    }
                }
                //checks if a project has been allocated
                if (allocated == false){
                    //gets third student choice
                    temp = get<3>(students[i]);
                     //loops through projects to see if third choice is avaliable
                    for(int j = 0; j < projects.size(); j++){
                        if(get<0>(projects[j]) == temp && get<2>(projects[j]) > 0){
                            get<2>(projects[j]) = get<2>(projects[j]) - 1;
                            projectStaff = get<1>(projects[j]);
                            break;
                        }
                    }
                    //loops through staff to see if they have effort left and if so allocates project
                    for(int k = 0; k < staff.size(); k++){
                        if(get<0>(staff[k]) == projectStaff && get<1>(staff[k]) > 0){
                            get<1>(staff[k]) = get<1>(staff[k]) - 1;
                            allocation.push_back(make_tuple(get<0>(students[i]),temp));
                            allocated = true;
                            projectStaff = "";
                            break;
                        }
                    }
                }
                //checks if a project has been allocated
                if (allocated == false){ 
                    //gets last student choice
                    temp = get<4>(students[i]);
                     //loops through projects to see if last choice is avaliable
                    for(int j = 0; j < projects.size(); j++){
                        if(get<0>(projects[j]) == temp && get<2>(projects[j]) > 0){
                            get<2>(projects[j]) = get<2>(projects[j]) - 1;
                            projectStaff = get<1>(projects[j]);
                            break;
                        }
                    }
                    //loops through staff to see if they have effort left and if so allocates project
                    for(int k = 0; k < staff.size(); k++){
                        if(get<0>(staff[k]) == projectStaff && get<1>(staff[k]) > 0){
                            get<1>(staff[k]) = get<1>(staff[k]) - 1;
                            allocation.push_back(make_tuple(get<0>(students[i]),temp));
                            allocated = true;
                            projectStaff = "";
                            break;
                        }
                    }
                }
                //checks if a project has been allocated
                if(allocated == false){
                    //if not allocates 0
                    allocation.push_back(make_tuple(get<0>(students[i]), 0));
                }
            }
            //returns the allocation
            return allocation;
        }

        int getScore(){
            //sets score to 0;
            score = 0;
            string temp = "";
            for(int i = 0; i < allocation.size(); i++){
                //grabs student name from allocation
                temp = get<0>(allocation[i]);
                for (int j = 0; j < students.size(); j++){
                    //checks for correct student
                    if(get<0>(students[j]) == temp){
                        //if the allocated project matches first choice adds 4 to score
                        if(get<1>(students[j]) == get<1>(allocation[i])){
                            score = score + 4;
                        }
                        //if the allocated project matches second choice adds 3 to score
                        else if(get<2>(students[j]) == get<1>(allocation[i])){
                            score = score + 3;
                        }
                        //if the allocated project matches third choice adds 2 to score
                        else if(get<3>(students[j]) == get<1>(allocation[i])){
                            score = score + 2;
                        }
                        //if the allocated project matches final choice adds 1 to score
                        else if(get<4>(students[j]) == get<1>(allocation[i])){
                            score = score + 1;
                        }
                    }
                }
            }
            //returns the score
            return score;
        }
        
    private:
    //private variables for allocator
        vector<tuple<string, int>> staff;
        vector<tuple<int, string, int, string>> projects;
        vector<tuple<string, int, int, int, int>> students;
        vector<tuple<string, int>> allocation;
        int score;
};