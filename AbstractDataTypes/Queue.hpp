#include "LinkedList.hpp"

class Queue : public LinkedList{
        //Inherited: head and tail
    protected:
        Node * frontOfLine;
        Node * backOfLine;

    public:
        Queue(){
            frontOfLine = backOfLine = NULL;
        }
        ~Queue();

        Queue(char input){
            Append(input);
            backOfLine = tail;   // Queue grows to the 'right'
            frontOfLine = head;    // and shortens from the 'left'
        }

        char Dequeue(void){
            Remove();       //
            frontOfLine = head;
        }
        
};