#include <iostream>
#include <vector>
using namespace std; 


/*
*
* General breakdown is that I halve the size of the data,
* that half is equal to the pivot, I check the value at the pivot and then half the 
* data size again and check again.
*
* need to also write a guard against a failed search
* condition where number is between end and start and doesn't
* exist.
*   produced for lab 09 of CISP 301 @ Sacramentor City College
*/

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
    return false;
}

template<class data>
bool linear_search(data search, data set[], int size){
    int go = 0;
    for(; go < size; go++){
        if(set[go] == search){
            return true;
        }
    }
    return false; // if loop ends, then nothing has been found
}

template<class data>
bool linear_search(data search, vector<data>set){
    int go = 0;
    for(; go < set.size(); go++){
        if(set[go] == search){
            return true;
        }
    }
    return false;
}