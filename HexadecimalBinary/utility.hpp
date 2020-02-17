#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include "messages.hpp"
using namespace std;

int CountCharInputs(string input);

void InitializeArray(int array[], int size);

void ShowArray(int input[], int size);

//Displays 4-bit groups for easy Hexadecimal reading
void ShowBinaryArray(int input[], int size);

bool ContinuePrompt(void);

#endif