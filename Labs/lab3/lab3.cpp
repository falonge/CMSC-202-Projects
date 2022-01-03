#include <iostream>
using namespace std;

//smallestNum: returns the smallest number within the array
int smallestNum(int array[], int size){
  int smallestNumber = array[0];
  for(int i=0;i<size;i++){
    if(array[i] < smallestNumber){
      smallestNumber = array[i];
    }
  }
  return smallestNumber;
}
//largestNum: returns the largest number within the array
int largestNum(int array[], int size){
  int largestNumber = array[0];
  for(int i=0;i<size;i++){
    if(array[i] > largestNumber){
      largestNumber = array[i];
    }
  }
  return largestNumber;
}
//avgNum: returns the average (or the mean) of the array
int avgNum(int array[], int size){
  int sum = 0;
  for(int i=0;i<size;i++){
    sum += array[i];
  }
  sum /= size;
  return sum;
}

int main(){
  const int MAXSIZE = 100;      //Constant maximum size of the array
  int myArray[MAXSIZE] = {0};   //Initializes the values of the array to 0's (default number)
  int currSize = 0;      //Keeps track of current size of the array
  int inputValue;       //Used to get the input in order to store it in the array
  cout << "Enter a number (0 when done): ";
    cin >> inputValue;
    if(inputValue != 0){
      myArray[currSize] = inputValue;
      currSize++;
    }
    while(inputValue !=0){
      cout << "Enter a number (0 when done): ";
      cin >> inputValue;
      if(inputValue != 0){
        myArray[currSize] = inputValue;
	currSize++;
      }
    }
    cout << "Original Array: ";
    for(int i=0;i<currSize;i++){
      cout << myArray[i] << " ";
    }
   cout << "\nSmallest number in the array: " << smallestNum(myArray, currSize);
   cout << "\nLargest number in the array: " << largestNum(myArray, currSize);
   cout << "\nAverage of the array: " << avgNum(myArray, currSize);

  //Code up the user's input, print out the array and then call the functions and return the expected output
  
  return 0;
}

//implement smallestNum function
//implement largestNum function
//implement avgNum function
