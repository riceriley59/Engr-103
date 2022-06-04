#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Student{
	unsigned int id;
	string name;
	string major;
	float gpa;
};

void populate_student_db_info(Student std_arr[], int n, ifstream& myfile){
	for(int i = 0; i < n; i++){
		myfile >> std_arr[i].id;
		myfile >> std_arr[i].name;
		myfile >> std_arr[i].major;
		myfile >> std_arr[i].gpa;
	}		
}

float calculate_highest_gpa(Student students[], int n){
   	float highest = 0;

	for(int i = 0; i < n; i++){
		float gpa = students[i].gpa;
		if(gpa >= highest){
			highest = gpa;		
		}
	}	

	return highest;
}

float calculate_average_gpa(Student students[], int n){
   	float sum_gpa = 0;	

	for(int i = 0; i < n; i++){
		sum_gpa += students[i].gpa;
	}

	return (sum_gpa / n);
}

int calculate_number_of_cs(Student students[], int n){
   	int number = 0;	

	for(int i = 0; i < n; i++){
		if(students[i].major == "CS"){
			number++;
		}	
	}

	return number;
}

int main(){
	ifstream myfile;
	myfile.open("input.txt");
	
	if(!myfile.is_open()){	
		cout << "\nError opening the file. \n";
		return 1;
	}	

	int total_students;
	myfile >> total_students;

	Student students[50];
	
	populate_student_db_info(students, total_students, myfile);
	float highest_gpa = calculate_highest_gpa(students, total_students);
	float average_gpa = calculate_average_gpa(students, total_students);
	int csnumber = calculate_number_of_cs(students, total_students);

	ofstream ofile("results.txt");
	ofile << setprecision(3) << highest_gpa << "\n";
     	ofile << average_gpa << "\n";
	ofile << csnumber << "\n";
	
	ofile.close();
	myfile.close();
	return 0;
}
