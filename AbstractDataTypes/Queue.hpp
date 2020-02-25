#include "LinkedList.hpp"

class Queue : public LinkedList{
    protected:
        Node * front;
        Node * back;

    public:
        Queue(){
            front = back = NULL;
        }
        ~Queue();

        Queue(char input){
            Append(input);
            front = tail;   // Queue grows to the 'right'
            back = head;    // and shortens from the 'left'
        }

        char Dequeue(void){
            
        }
};