#include <iostream>
#include "ToBinary.hpp"
#include "messages.hpp"
using namespace std;


void ConvertToBinary(){
  int  output[10] = {0,0,0,0,0,0,0,0,0,0};
  int * number = new int;
  cout << "\nPlease enter a base-10 number to convert: ";
  cin >> *number;
  cin.clear();


  int Result = -1;
  int j = 0;
  while(Result != 0){
    output[j] = *number% 2;
    Result = *number/2;
    *number = Result;
    j++;
  }
  PrintArray(output,10);

  delete number;
}

void PrintArray(int input[], int size){
  cout << "\nAnd the result is... ";
  //display elements in reverse for correct order
  for(int i = size-1; i >-1; i--){
    cout << input[i];
  }
}

bool ContinuePrompt(void){
    bool output;
    string keyPress;
    cout << CONTINUEASK;
    cin >> keyPress;
    cin.clear();
    cin.ignore(326586, '\n');

    if(toupper(keyPress[0])=='Y'){
        output = true;
        return output;
    }
    else{
        output = false;
        return output;
    }
}