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
    int mindex = 0;
    int smallest = a[0];
    int smalldex; //track location of smallest

    while(mindex < setsize){
        
        for(int scan = mindex+1; scan < setsize; scan++){
            if(a[scan] < smallest){
                smallest = a[scan];
                smalldex = scan;
            }//if
        }//for
        if(a[smalldex]<a[mindex]){
            swap(&a[smalldex], &a[mindex]);
        }//if-swap
        mindex++;
        smallest = a[mindex];
    }
}