#ifndef CIRCLELIST_HPP
#define CIRCLELIST_HPP

#include <iostream>
#include <stdio.h>

#define FULL "\nError: List is full.\nNothing added.\n\n"
#define EMPTY "\nError: List empty. Nothing was done.\n\n"
#define FOUND "\nQuery returned a positive result\n\n"
#define NOTFOUND "\nQuery returned no results.\n\n"

class CircleList{
    protected:
        int size;
        int head;
        int tail;
        int numElements;
        char *list;
    public:
            // Default object constructors
        CircleList(){
            head = tail = numElements =
            size = 0;
        }
        CircleList(int initSize){
            head = tail = numElements = 0;
            size = initSize;
            list = new char[size];
        }
        ~CircleList();

            // Necessary mutator methods for
            // quality of life improvements.
            // Getters/Setters
        void SetSize(int input){    // Dynamically re-size list.
            size = input;           // Will delete current elements.
            ListInit(size);
        }

        void ListInit(int input){   // *Helper function for SetSize
            if(list != NULL){       // In case I want to quickly reset a list
                delete list;        // and change it's size on the go.
            }
            list = new char[size]; 
        }
        int CountElements(void){
            return numElements;
        }

            // Begin Class Generic Interface
        char Remove(void){
            char temp;
            if(!IsEmpty()){
                temp = list[head];
                head = (head + 1) % size; // Overwrite head
                numElements--;            // Decrease list elem
                return temp;
            }
            else{
                printf(EMPTY);
                return -1;
            }
        }

        void Append(char input){
            if(numElements == 0){       // Check if empty
                list[tail] = input;
            }
            if((tail+1)%size==head){    // Check if full
                printf(FULL);
                return;
            }
            tail = (tail + 1) % size;   // Increment tail by 1
            list[tail] = input;         // Add element
            numElements++;              // Keep count of elements
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
        void Traverse(void){
            if(!IsEmpty()){

            }
            else{
                printf(EMPTY);
            }
        }

        //Works in O(1)
        bool IsEmpty(void){
            if(numElements){
                return false;
            }
            else{
                return true;
            }
        }
};


#endif