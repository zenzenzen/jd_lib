#ifndef CIRCLEQUEUE_HPP
#define CIRCLEQUEUE_HPP

#include <iostream>
#include <stdio.h>
#include "CircleList.hpp"



class CircleQueue : public CircleList{

    protected:
        // INHERITED FROM CIRCLELIST
        // int size;    
        // int head;
        // int tail;
        // int numElements;
        // char *list;

    public:
        CircleQueue(){
            size = head = tail = numElements = 0;
        }
        CircleQueue(int initSize){
           CircleList(initSize);
        }
        ~CircleQueue();

        void Enqueue(char input){
            if((tail+1)%size==head){    // Check for full condition
                printf(FULL);           // Doesn't matter if empty
                return;
            }
            else{
                tail = (tail+1)%size;   // Move tail one over
                tail = input;           // Insert element
                numElements++;          // Increase count
            }
        }
        
        char Dequeue(void){
            char temp;
            if(!IsEmpty()){
                temp = list[head];          // Copy value
                head = -1;
                head = (head + 1)% size;    // Increment head position
                tail = (tail + 1)% size;    // Increment tail position
                numElements--;
            }
            else{
                printf(EMPTY);
                return -1;
            }
        }
            // Works in O(1)
            // bool IsEmpty() - Inherited from CircleList

};





#endif