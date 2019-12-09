#include <iostream>
using namespace std;


/*
 * Standard linear array sum function.
 * Returns sum of all elements in array.
*/
template<class data>
data addit(data a[], data size){
    data sum = 0, i = 0;
    for(; i < size; i++){
        sum += a[i];
    }
    return sum;
}

/*  A recursive function to add all elements
 *   in an array and then return the size. 
 */
template<class data>
data addit(data a[], data size, data sum){
  if(size > 0){
    sum = a[size-1];
    return sum + addit(a,size - 1, sum );
  }
  else{
    return 0;
  }
}