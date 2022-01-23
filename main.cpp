// Leetcode problem. Checks whether a string is an email. Planning on having program check whether user string is an email or phone number. 
#include <iostream>
#include <string>
#include <string.h> 
#include <cmath> 

using namespace std; 

int totalFound(string email, char character); 
void dotPos(int atPos); 
bool checkEmail(string email); 
void checkNum(string phone); 

int main(){
  int inputSize; 
  bool answer; 
  string userInput; 

  cout << "Enter email: "; 
  cin >> userInput; 
  
  answer = checkEmail(userInput); 
  if(answer == true)
   // Email
    cout << "String is an email."; 
  else 
    cout << "String is not an email."; 
  return 0; 
} 

bool checkEmail(string email){
  char ate = '@'; 
  char dot = '.'; 
  int totalAt, totalDot, foundAt, foundDot; 

  if(email.find('@') != string::npos) //|| email.find(".") != string::npos)
  {
    foundAt = email.find(ate);
    totalAt = totalFound(email, ate); 
    foundDot = email.find(dot);
    totalDot = totalFound(email, dot); 
    if(totalAt == 1 and totalDot == 1 and foundAt < foundDot)
      return true; 
  }
  return false;  
}

int totalFound(string email, char character){
  int total = 0; 
  for(int counter = 0; counter <= email.size(); counter++)
  {
    if (email[counter] == character)
      total++; 
  }
  return total; 
} 