#include <iostream>
using namespace std;

template<class data>
void swap(data * A, data * B){
    data temp = *B;
    *B = *A;
    *A = temp;
}

template<class data>
void selection_sort(data set[], int setsize)
{
    /*initialization block*/
    int mindex = 0;
    int smallest = a[0];
    int smalldex; //track location of smallest

    while(mindex < setsize){
        int scan = mindex+1;
        for(; scan < setsize; scan++){
            if(a[scan] < smallest){
                smallest = a[scan];
                smalldex = scan;
            }//if
        }//for
        if(a[smalldex]<a[mindex]){ // prevent errors on last indices
            swap(&a[smalldex], &a[mindex]);
        }//if-swap
        mindex++;
        smallest = a[mindex];
    }//end while
}

// this is the helper method
template<class data>
int partition(data set[], int start, int end){
// need a variable to keep track of pivot location
//need a way to tell when to swap two numbers.--can just swap around?
int pivot = *set[end];
int pivotIndex = end;
int index = start;
    for(;index < end; index++){
        if(set[index] < pivot){
            swap(set[index], set[pivotIndex - 1]);
            pivotIndex = index;
        }
        else if(set[index] > pivot){
            swap(set[index], set[pivotIndex + 1]);
            pivotIndex = index;
        }
    }//end for
}//end paritition function
/*
    In the base case of the partition, we need to get down
     to where there are no more comparisons to be made where
     the pivot number is the same as the end and the start. Or, 
     in other words, end - start = 0;
    In other cases, like with only two numbers, we would like to
    figure out if the number 
*/

// this is what's known as the wrapper method
template<class data>
void quick_sort(data set[], int start, int end){
    int pivot = partition(set, start, end);
    quick_sort(set, pivot + 1, end);
    quick_sort(set, start, pivot - 1);

}