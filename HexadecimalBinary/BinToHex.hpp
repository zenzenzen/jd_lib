#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

//Displays 4-bit groups for easy Hexadecimal reading
void ShowBinaryArray(int input[], int size);

// Assumes input char is '1' or '0'
// Assumes ASCII table conversion
void CharToBits(string input, int output[], int size);

// Converts 4bit binary groups into decimal elements
void PrepareBinaryForHexOutput(int inputBinary[], int decimalOutput[], int bitGroups);

// Self-contained function for IO
void BinaryToHexadecimal(void);