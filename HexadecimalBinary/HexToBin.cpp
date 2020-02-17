#include "HexToBin.hpp"
#include "utility.hpp"
#include "messages.hpp"


void StringToDecimal(string input, int stringSize, int decimalOutput[]){
 //iterate through string and validate each entry
 //and output conversion results
 for(int i = 0; i < stringSize; i++){
    if(isalpha(input[i])){
      input[i] = toupper(input[i]);
      if(input[i]>=65 && input[i]<=70){
        decimalOutput[i] = input[i] - 55;
      }
      else{
        decimalOutput[i] = 0;
      }//end-else
    }//end-if--alphabet-validation

    else if (isdigit(input[i])){
      decimalOutput[i] = input[i]-48;
    }//end-else-if
 }//for
}//end-StringToDecimal


void ConvertToBinary(int outputBinary[], int outputSize, int inputDecimal[], int inputSize){
  /*
  * + Outer loop moves through decimal values array
  * + Inner loop converts decimal values to binary
  *     and increments through outputBinary array.
  * + The inner loop jumps to the end of the bit-group
  *     and converts the group in reverse order so that
  *     it appears 'in order' when read through by a normal
  *     print-for-loop.
  *     ++For Example: initially, A3, if conventionally converting to
  *       binary in a straight loop would be stored in the array as
  *            0101 1100 
  *       which is 10 and 3 in binary...and backwards.
  *       So to remedy that, I needed to write each respective group 
  *       backwards so the data could be read linearly.
  */
  int temp; 
  int result;
  for(int k = 1; k < inputSize+1; k++){
    temp = inputDecimal[k-1];
    for(int j = (k*4)-1; j > (k-1)*4-1; j--){
      outputBinary[j] = temp % 2;
      result = temp/2;
      temp = result;
    }//inner-loop (start at end of group and move back)
  }//outer-loop (determines bit group inner loop is at)
}//ConvertToBinary

void ConvertHexToBin(void){
    int binArrSize = 0;
    string input;

    cout << "Enter a hexadecimal number to convert: ";
    getline(cin, input);

    cout << "You entered: " << input << endl;

    int numOfChar = 0;
    numOfChar = CountCharInputs(input);
    binArrSize = numOfChar * 4;
    cout << "You have this many inputs: " << numOfChar;

    //dynamically create new array for decimal
    int * inputAsDec = new int[numOfChar];
    StringToDecimal(input, numOfChar, inputAsDec);
    cout << "\n\nString conversion results";
    ShowArray(inputAsDec, numOfChar);

    //dynamically create new array for binary
    int * binaryArray = new int[binArrSize];
    cout << "\n\nBIN ARRAY INIT: ";
    InitializeArray(binaryArray, binArrSize);
    ShowArray(binaryArray, binArrSize);

    ConvertToBinary(binaryArray, binArrSize, inputAsDec, numOfChar);
    cout << "\n\nBIN CONVERSION: ";
    ShowBinaryArray(binaryArray, binArrSize);

    //[complete] convert the char inputs into decimal
    //[complete] convert the decimal into binary
    //[complete] find a way to keep track of and pass the binary into the larger binary array.

    
    //figure out how to delete new array
     delete []binaryArray;
     delete []inputAsDec;
  
}

