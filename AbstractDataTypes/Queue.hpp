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
            backOfLine = tail;   // Queue grows to the 'right'| people line up
            frontOfLine = head;    // and shortens at the 'left' | people leave
        }

        char Dequeue(void){
            Remove();       //
            frontOfLine = head;
        }

        //modified to only check Queue specific values.
        bool IsEmpty(){
            bool output;
            (frontOfLine == backOfLine) ? (output = true): (output = false);
            return output;
        }
};