/**********
* File: Course.h
* Intended for Lab 5: Classes
**********/

#ifndef COURSE_H //Header or Include Guards
#define COURSE_H //Header or Include Guards

#include <iostream>
#include <string>
using namespace std;

class Course {
public:
  //Default constructor, already implemented.
  Course();
  
  //**Student Requirement**
  //Do the prototype for each of the functions described in the lab document
  string getCourse();
  //Returns name of the course

  void setCourse(string);
  //Sets name of the course

  int getSectionNum();
  //Returns the course's section number

  void setSectionNum(int);
  //Sets the course's section number

  int getEnrolledStudents();
  //Returns course's enrolled students

  void setEnrolledStudents(int);
  //Sets course's enrolled students

  void checkLarge();
  //Outputs whether the course is large or not

  bool dropStudent();
  //Removes one student from the course

private:
  //**Student Requirement**
  //Create the member variables below as described in the lab document
  string m_courseName;
    //name of course
  int m_sectionNum;
    //section number
  int m_enrolledStudents;
    //enrolled students
};

#endif //End of Header Guard
