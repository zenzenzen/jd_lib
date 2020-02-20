#include <iostream>
#include <iomanip>
using namespace std;

#ifndef MatrixUtil_hpp
#define MatrixUtil_hpp

void printColumnHead(char set[], int size){
  cout << "  ";
  for(int i = 0; i < size; i++){cout << setw(6) << set[i];}
  cout << endl;
  cout << "___________________" << endl;
}

#endif