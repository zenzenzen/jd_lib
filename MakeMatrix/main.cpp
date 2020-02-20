#include <iostream>
#include <iomanip>
#include "MatrixUtil.hpp"
using namespace std;

struct icPair{
  int first;
  char second;
};

int main() {
  int sizeA = 4;
  int sizeB = 3;
  int setA[] = {1, 2, 3, 4};

  int numPairs = 5;
  char setB[] = {'a','b','c'};

  int R[sizeA][sizeB];
  cout << "\nInitialised matrix:"<< endl;
  printColumnHead(setB, sizeB);
  for(int i = 0; i < sizeA; i++){
    cout << setA[i] << ":" << setw(6);
    for(int j = 0; j < sizeB; j++){
      R[i][j] = 0;
      cout << setw(6) << R[i][j];
    }
    cout <<endl;
  }
 
 struct icPair relations[5] = {{1,'a'}, {2, 'c'}, {3,'b'}, {4,'b'}, {1,'c'}};

                                  // Where relations[i].first = setA...
 for(int i = 0; i < numPairs; i++){  // i should match num of pairs
   for(int j = 0; j < sizeA; j ++){ //Iterate through setA for match
      if(relations[i].first == setA[j]){
        for(int k = 0; k < sizeB; k++){// Search for matching B elem
          if(relations[i].second == setB[k]){
              R[j][k] = 1; //create 1 for successful match
              break; //no need to continue k-loop
          }//if-matchB
        }//end-matchB-for
      }//end-if
   }//end-for-intJ
 }//end-for-intI

 cout << "\nFinished matrix:"<< endl;
 printColumnHead(setB, sizeB);
  for(int i = 0; i < sizeA; i++){
    cout << setA[i] << ":" << setw(6);
    for(int j = 0; j < sizeB; j++){
      cout << setw(6) << R[i][j];
    }
    cout <<endl;
  }
  return 0;
}

