#include "LinkedList.hpp"

class Stack : public LinkedList{
    protected:
        Node * top;

    public:
        Stack(){
            top = head = tail = NULL;   // Prevent uninitialized value access
        }
        ~Stack();

        void Push(char data){
            Node *stackThis = new Node;  // Get node from heap

            stackThis->next = top;       // Set next to last Top
            * stackThis->element = data; // Add new data to new node.

             head = top = stackThis;     // No matter what, new item
        }                                // is going to be at the TOP.

        char Pop(){
            char temp;
            temp = *top->element;       // Copy return data
            top = top->next;            // Set new TOP
            delete head;                // Get rid of old TOP
            head = top;                 // Update background head
            return temp;
        }

        char Peek(){
            return *top->element;
        }

        bool IsEmpty(){
            bool x;
            (top == NULL) ? x = true : x = false ;  // Had to try it out.
            return x;                               // Same as if-else.
        }
};