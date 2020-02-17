#include "utility.hpp"

int CountCharInputs(string input){
    int numOfChar = 0;
    int i = 0;
    while(input[i] != '\0'){
      numOfChar++;
      i++;
    }
    return numOfChar;
}

void InitializeArray(int array[], int size){
  for(int i = 0; i < size; i ++)
    array[i] = 0;
}

void ShowArray(int input[], int size){
  cout << "\nARRAY READOUT: ";
  //Display in order of entry
  for(int i = 0; i < size; i++){
    cout << input[i] << ", ";
  }
}

//Displays 4-bit groups for easy Hexadecimal reading
void ShowBinaryArray(int input[], int size){
  cout << "\nARRAY READOUT: ";
  //Display in order of entry
  for(int i = 0; i < size; i++){
    cout << input[i];
    if(i != 0 && (i+1)%4 == 0){
      cout << " ";
    }//end-if
  }//end-for
}//end-ShowBinaryArray

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
}//end-ContinuePrompt