#include <iostream>
using namespace std;

#ifndef MATHEMATICAL_HPP
#define MATHEMATICAL_HPP

int Fibbonacci(int n){
  //Stopping condition
  if(n <= 0){
    return 0;
  }
  //Base case for working
  n = Fibbonacci(n-2) + Fibbonacci(n - 1); 
  return n;
}

int Factorial(int n){
    if(n==0){
        return 1;
    }
    return n *= Factorial(n - 1);
}


int GreatestCommonDenominator(int dividend, int divisor){
    if(divisor == 0){
        return dividend;
    }
    return GreatestCommonDenominator(divisor, dividend % divisor);
}



#endif