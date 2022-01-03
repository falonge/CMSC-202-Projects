/**************
 * File: lab5.cpp
 * The user creates this file to demonstrate use of a course.
 *************/

#include <iostream>
#include "Course.h"
using namespace std;

int main() {
  //**Student Requirement**
  //Part 1: Create 2 courses by instantiating them
  Course course1;
  Course course2;

  //**Student Requirement**
  //Part 2: Set their values for course name, section number, and enrolled students.
  course1.setCourse("Biology");
  course1.setSectionNum(1);
  course1.setEnrolledStudents(60);
  course2.setCourse("Calculus");
  course2.setSectionNum(2);
  course2.setEnrolledStudents(20);
  

  // //**Student Requirement**
  // //Part 3: Output their information:  Name, section, and enrolled students
  cout << "Data of course1:\n";
  cout << "Course name: " << course1.getCourse() << endl << "Number of students enrolled: " << course1.getEnrolledStudents() << endl << "Section number: " << course1.getSectionNum() << endl;


  cout << "Data of course2:\n";
  cout << "Course name: " << course2.getCourse() << endl << "Number of students enrolled: " << course2.getEnrolledStudents() << endl << "Section number: " <<  course2.getSectionNum() << endl;


  //**Student Requirement**
  //Part 4: Call a custom function: Check if courses are large or not
  course1.checkLarge();
  course2.checkLarge();


  //**Student Requirement**
  //Part 5: Update data members with custom function: Drop a student from each course
  //Display updated enrolled students
  course1.dropStudent();
  course2.dropStudent();
  cout << course1.getEnrolledStudents() << endl << course2.getEnrolledStudents() << endl;

  
  return 0;
}
