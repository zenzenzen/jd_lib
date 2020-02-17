#include "ToDecimal.hpp"

void ConvertToDecimal(void){
  
    string userEntered;
    int sizeOfInput;
    int decimalOutput = 0;

    cout << "Enter the binary number to convert: ";
    cin >> userEntered;
    cout << "You entered: " << userEntered << endl;
    
    sizeOfInput = CountCharInputs(userEntered);
    cout << "\nNumber of BIN inputs: " << sizeOfInput << endl;
    int * binaryElements = new int [sizeOfInput];
    //initialize all binary binaryElements to 0
    for (int i = 0; i < sizeOfInput; i++){
      binaryElements[i] = 0;
    }
    cout << "\nInitialization";
    ShowArray(binaryElements, sizeOfInput);

    for(int i = 0; i < sizeOfInput; i++){
         binaryElements[i] = (userEntered[i] - 48);
    }
    cout <<"\n\nData Buffered";
    ShowArray(binaryElements, sizeOfInput);

    // (int)pow(2,sizeOfInput - 1 - i) is used to reverse input size while incrementing i
    // and compensating for the offset of array size
    for(int i = 0; i < sizeOfInput; i++){
        decimalOutput += (binaryElements[i]) * (int)pow(2,sizeOfInput - 1 - i);
    }

    cout << "\n\nResulting decimal output: " << decimalOutput << endl;
   
    delete []binaryElements;
}

int CountCharInputs(string input)
{
    int numOfChar = 0;
    int i = 0;
    while(input[i] != '\0'){
      numOfChar++;
      i++;
    }
    return numOfChar;
}

void ShowArray(int input[], int size){
  cout << "\nARRAY READOUT: ";
  //Display in order of entry
  for(int i = 0; i < size; i++){
    cout << input[i];
  }
}
/*
void convertToDecimal(int inputArray[]){

    int * ToDecimal = new int;

    for(int i = 0; i < 10; i ++){
        *ToDecimal += inputArray[i] * (int)pow(2,i);
    }

    cout << "Is your number... " << *ToDecimal << "?" << endl;
}
*/