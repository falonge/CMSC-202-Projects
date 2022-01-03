/*
 * lab2.cpp
 * This program tests skills regarding input/output, loops, functions in C++.
 */

#include <iostream>
using namespace std;
/****************************************************************
 *   FUNCTION PROTOTYPES FOR multiplyByThree() and divisibleByNine() GO HERE     *
 ****************************************************************/
int multiplyByThree(int numbers){
  int response;
  int total = 0;
  for(int i=0;i<numbers;i++){
    cout << "Enter an integer: ";
    cin >> response;
    total += response;
    cout << endl;
  }
  total *= 3;
  cout << "Total: " << total << endl;
  return total;
}

void divisibleByNine(int number){
  if(number % 9 == 0){
    cout << "The final value is divisible by 9.";
  }
  else{
    cout << "The final value is not divisible by 9.";
  }
}

//Add Constants Here


int main() {
	/****************************************************************
	 *             CODE TO INVOKE FUNCTIONS GOES HERE               *
	 * Note: the user should enter 3 numbers, and the program will  *
	 * display the sum of those numbers multiplied by 3. It finally *
         * indicates if that result is divisible by 3.                  *
         *           MUST BE IMPLEMENTED IN ONE LINE.                   *
	 ****************************************************************/

  divisibleByNine(multiplyByThree(3));
  return 0;
}


//Name: multiplyByThree
//Purpose: Given the number of integers to enter as a parameter, the function
//	   will request the user to enter that many integers. The function
//         then multiplies the sum by 3 and displays that result. Finally,
//         the function returns the result.
/****************************************************************
 *           IMPLEMENTATION FOR multiplyByThree() GOES HERE             *
 ****************************************************************/


//Name: divisibleByNine()
//Purpose: Given an integer as a parameter, the function will say
//         if divisible by nine or not.
/****************************************************************
 *           IMPLEMENTATION FOR divisibleByNine() GOES HERE     *
 ****************************************************************/
