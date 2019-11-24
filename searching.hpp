#include <iostream>
#include <vector>
using namespace std; 

template<class data>
bool binary_search(data search, data set[], int start, int end){
   int pivot = (end - start))/2;
   if(search == set[pivot]){
       return true;
   }
   else if(end - start == 1 && search != pivot){
       return false;
   }
   else{
       if(search > set[pivot]){
           return binary_search(search, set[], pivot+1, end);
       }
       else{
           return binary_search( search, set[], start, pivot-1);
       }
   }
/*
*
* General breakdown is that I half the size of the data,
that half is equal to the pivot,
I check the value at the pivot and then half the 
data size again and check again.
*
need to also write a guard against a failed search
condition where number is between end and start and doesn't
exist.
*
*/
    return false;
}

