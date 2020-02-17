#include "BinToHex.hpp"
#include "utility.hpp"
using namespace std;


// Assumes input char is '1' or '0'
// Assumes ASCII table conversion
void CharToBits(string input, int output[], int size){
  for(int i = 0; i < size; i++){
         output[i] = (input[i] - 48);
    }
}

// Converts 4bit binary groups into decimal elements
void PrepareBinaryForHexOutput(int inputBinary[], int decimalOutput[], int bitGroups){
   int exponent = 3;
  for(int k = 1; k < bitGroups +1; k++){
        exponent = 3;
      for(int i = (k-1)*4; i < (k*4); i++){
          decimalOutput[k-1] += (inputBinary[i]) * (int)pow(2, exponent);
          exponent--;
      }//innerloop
    }//outerloop
}

void BinaryToHexadecimal(void){
    string userEntered;
    int sizeOfInput;
    int bitGroups;

    cout << "Enter the binary number to convert: ";
    cin >> userEntered;
    cout << "You entered: " << userEntered << endl;
    
    sizeOfInput = CountCharInputs(userEntered);
    bitGroups = sizeOfInput/4;
    cout << "\nNumber of BIN inputs: " << sizeOfInput << endl;

    //[not yet] Throw error if BIN input is not x/4
    //      * minimize garbage input/ throw it all out?
    //[not yet] Throw error if anything not 1/0 entered
    //      * recommend using ASCII table values

    int * binaryElements = new int [sizeOfInput];
    int * decimalOutput = new int [bitGroups];
 
    InitializeArray(binaryElements, sizeOfInput);
    CharToBits(userEntered, binaryElements, sizeOfInput);
    PrepareBinaryForHexOutput(binaryElements, decimalOutput, bitGroups);
    cout <<"\n\nDecimal Buffer:";
    ShowArray(decimalOutput, bitGroups);

    cout <<"\n\nHexadecimal output: ";
    for(int i = 0; i < bitGroups; i++){
      if(decimalOutput[i] < 10){
        cout << static_cast<char>(decimalOutput[i]+48);
      }
      else if(decimalOutput[i] >= 10 && decimalOutput[i] <=15){
        cout << static_cast<char>(decimalOutput[i]+55);
      }
    }
   
    delete []binaryElements;
    delete []decimalOutput;
}