#ifndef HEXTOBIN_HPP
#define HEXTOBIN_HPP

#include <iostream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;


void StringToDecimal(string input, int stringSize, int decimalOutput[]);
void ConvertToBinary(int outputBinary[], int outputSize, 
                        int inputDecimal[], int inputSize);
void ConvertHexToBin(void);

#endif