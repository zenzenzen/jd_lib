#ifndef CIRCLESTACK_HPP
#define CIRCLESTACK_HPP

#include <iostream>
#include <stdio.h>
#include "CircleList.hpp"


class CircleStack : public CircleList{
    protected:
        // INHERITED FROM CIRCLELIST
        // int size;    
        // int head;
        // int tail;
        // int numElements;
        // char *list;
    public:
        
        CircleStack(int initSize){
           CircleList(initSize);
        }
        ~CircleStack();

            // Works in O(1)
        char Pop(void){
            char temp;
            if(!IsEmpty()){
                temp = list[head];
                head = (head + 1) % size; // Overwrite head
                numElements--;            // Decrease list elem
                return temp;              // Exit method
            }
            else{
                printf(EMPTY);
                return -1;
            }
        }
            // Works in O(1)
        void Push(char input){
            if(numElements == 0){       // Check if empty
                list[head] = input;
            }
            if((tail+1)%size==head){    // Check if full
                printf(FULL);
                return;                 // Quit method
            }
            head = (head + 1) % size;   // Increment tail by 1
            list[head] = input;         // Push element onto stack
            numElements++;              // Keep count of elements
        }
            // Works in O(1)
        char Peek(void){
            return list[head];
        }

        bool Find(char searchTerm){
            int position = head;
            if(!IsEmpty()){
                // Iterate through array
                do{
                    if(list[position] == searchTerm){
                        while(position != tail){    // Scoot all items up 1 space
                            list[position] = list[(position +1)%size];
                            position = (position + 1) % size;
                        }// End-While: Scooting variables up one space
                        tail--;
                        numElements--;
                        if(tail < 0){
                            tail = size - 1;
                        }
                        printf(FOUND);
                        return true;
                    }// End-if: Found the search term
                }
                while(position != (tail + 1)% size);

                printf(NOTFOUND);
                return false;
            }
            else{
                printf(EMPTY);
                return false;
            }
        }
            // Works in O(1)
            // bool IsEmpty() - Inherited from CircleList
};


#endif