#include "Course.h"

//Constructor -- Already Implemented
Course::Course() {
  cout << "Creating a course..." << endl;
  m_courseName = "CMSC 202";
  m_sectionNum = 1;
  m_enrolledStudents = 50;
}

//Here is an example for a getter and a setter

int Course::getEnrolledStudents() {
  return m_enrolledStudents;
}

void Course::setEnrolledStudents(int numStudents) {
  //If number of students is negative, set to 0.
  if (numStudents < 0){
    m_enrolledStudents = 0;
  } else {
    m_enrolledStudents = numStudents;
  }
}

//**Student Requirement**
//Implement getters and setters for courseName and sectionNum here
string  Course::getCourse(){
  return m_courseName;
}

void Course::setCourse(string courseName){
  m_courseName = courseName;
}

int Course::getSectionNum(){
  return m_sectionNum;
}

void Course::setSectionNum(int sectionNum){
  m_sectionNum = sectionNum;
}


//**Student Requirement**
//Custom Functions -- Implement checkLarge and dropStudent
void Course::checkLarge(){
  if(m_enrolledStudents > 40){
    cout << m_courseName << " Section " << m_sectionNum << " is a large course!\n";
  }
  else{
    cout << m_courseName << " Section " << m_sectionNum << "is a small course!\n";
  }
}

bool Course::dropStudent(){
  if(m_enrolledStudents >= 1){
    m_enrolledStudents -= 1;
    return true;
  }
  else{
    return false;
  }
}
