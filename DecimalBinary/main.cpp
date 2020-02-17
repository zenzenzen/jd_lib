#include <iostream>
#include <ctype.h>
#include "messages.hpp"

using namespace std;

extern bool ContinuePrompt(void);
extern void ConvertToDecimal(void);
extern void ConvertToBinary();
extern void PrintArray(int input[], int size);
/*
  1. Write a C++ program to convert a decimal number into binary
  2. Write a C++ program to convert a binary number into decimal
*/

#define ARRSIZE 10
int main() {
  bool keepGoing = true;
  char userChoice;

  while(keepGoing){
    cout << GREETING;
    cout << PROMPT;
    cin >> userChoice;
    cin.clear();

    switch (toupper(userChoice))
    {
    case 'A':
      ConvertToBinary();
      break;
    
    case 'B':
      ConvertToDecimal();
      break;

    case 'Q':
      keepGoing = false;
      break;

    default:
      cout << ERROR;
      break;
    }//switch

    keepGoing = ContinuePrompt();
  }//while
  cout << GOODBYE << endl;

  return 0;
}