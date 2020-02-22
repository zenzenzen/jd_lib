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
// void printMatrix(int rowSize, int colSize, int rowDomain[], int inMatrix[rowSize][colSize]){
//     for(int i = 0; i < rowSize; i++){
//     cout << rowDomain[i] << ":" << setw(6);
//     for(int j = 0; j < colSize; j++){
//       inMatrix[i][j] = 0;
//       cout << setw(6) << inMatrix[i][j];
//     }
//     cout <<endl;
//   }
// }
#endif