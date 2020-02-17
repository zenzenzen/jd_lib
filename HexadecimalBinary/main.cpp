#include <iostream>
#include <string>
#include "messages.hpp"
using namespace std;

extern void ConvertHexToBin(void);
extern bool ContinuePrompt(void);
extern void BinaryToHexadecimal(void);

int main(void){

  bool keepGoing = true;
  char userChoice;

  while(keepGoing){
    cout << GREETING;
    cout << PROMPT;
    cin >> userChoice;
    cin.clear();
    cin.ignore(324456,'\n');

    switch (toupper(userChoice))
    {
    case 'A':
      ConvertHexToBin();
      break;
    
    case 'B':
      BinaryToHexadecimal();
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

