#ifndef CIRCLEPRIORITYQUEUE_HPP
#define CIRCLEPRIORITYQUEUE_HPP

#include "CircleQueue.hpp"

class CirclePriorityQueue : public CircleQueue{
    protected:
        // INHERITED FROM CIRCLEQUEUE
        // int size;    
        // int head;
        // int tail;
        // int numElements;
        // char *list;
        int position;

    public:
        CirclePriorityQueue(){
            position = head;
        }
            // Works O(n)
        void Enqueue(char input){
            if( tail == head){
                printf(FULL);
                return;
            }
            else{
                position = head;
                while(position != tail){      // While position isn't at tail
                    if(input > list[position]){    // Compare input to list position
                        for(int i = tail; i > position; i = (i-1)%size){
                            list[i] = list[(i-1)%size]; // Scoot down for room
                        }// End-For
                        list[position] = input;
                        numElements++;
                    }// End-If
                    else{
                        position = (position+1)%size; // Move position along towards end
                    }
                }// End-While: Position%size isn't at the tail%size
            }// End-Else: Do this if the PQ isn't full.
        }
            // Works O(1)
        char Dequeue(void){
            char temp;
            if(IsEmpty()){
                printf(EMPTY);
                return;
            }
            else{
                temp = list[head];
                head = -1;
                head = (head + 1) % size;
                tail = (tail + 1) % size;
                numElements--;
                return temp;
            }
        }//

        char Peek(void){
            return list[head];
        }
};

#endif