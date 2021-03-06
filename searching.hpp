#include <iostream>
#include <cmath>
#include <vector>
using namespace std; 


/*
* binary search function
* General breakdown is that I halve the size of the data,
* that half is equal to the pivot, I check the value at the pivot and then half the 
* data size again and check again.
*
* need to also write a guard against a failed search
* condition where number is between end and start and doesn't
* exist.
*   produced for lab 09 of CISP 301 @ Sacramentor City College
*/
/*
template<class data>
bool binary_search(data search, data set[], int start, int end){
   int pivot = start + floor(end - start)/2;
   if(search == set[pivot]){
       return true;
   }
   else if(end - start == 1 && search != pivot){
       return false;
   }
   else{
       if(search > set[pivot]){
           return binary_search(search, set, pivot, end);
       }
       else{
           return binary_search(search, set, start, pivot);
       }
   }//end else
}
    function works, but will remain commented out to prevent
    function call  ambiguity. It will serve as a template.*/

//this function will return an integer of the index where
//the search term was found. Assumes a sorted array.

template<class data>
int binary_search(data search, data set[], int start, int end){
int pivot = start + floor(end - start)/2;
    if(search == set[pivot]){
        return pivot;
    }
    else if(end - start == 1 && search != pivot){
        return -1;
    }       //end-guard
    else if(search < set[start] || search > set[end]){
        return -1;
    }       //fast-fail
    else{
        if(search > set[pivot]){
            return binary_search(search, set, pivot, end);
        }
        else{
            return binary_search(search, set, start, pivot);
        } //end else-else
    }// end else
}

template<class data> //trying out non-recusive binary search
bool binary_search_nonrec(data search, data set[], int size){
    //dont need to determine iterations, just need to establish
    //essential cases:
    // 1. search == pivot 2. search > pivot 3. search < pivot
    // 4. search != pivot && end - start == 1
    int pivot = size/2;
    int start = 0, end = size;
    while(pivot < end && pivot > start){
        if(search ==  set[pivot]){
            return true;
        }
        else if(search > set[pivot]){
            start = pivot+1;
            pivot = start + ((end - start)/2);
        }
        else{
            end = pivot-1;
            pivot = end/2;
        }
    }
    return false;
} // need to test

template<class data>
bool linear_search(data search, data set[], int size){
    for(int go = 0; go < size; go++){
        if(set[go] == search){
            return true;
        }
    }//end for
    return false; // if loop ends, then nothing has been found
}//end line search

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

// find the largest value in an array
// without regard to negative or positive
template<class data>
int find_max(int arr[], int elems){
    int *iptr = new int &thing;
    *iptr = arr[0];
    for(int i = 0; i < elems; i ++){
        if(*iptr < a[i]){
            *iptr = a[i];
        }
    }
}