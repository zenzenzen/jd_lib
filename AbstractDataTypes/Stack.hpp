#ifndef STACK_HPP
#define STACK_HPP

#include "LinkedList.hpp"

class Stack : public LinkedList{
    protected:
        Node * top;

    public:
        Stack(){
            top = head = tail = NULL;   // Prevent uninitialized value access
        }
        ~Stack();

        // Works in O(1) time
        void Push(char data);                       // is going to be at the TOP.

        // Works in O(1) time
        char Pop();

        // Works in O(1) time
        char Peek();

        // Works in O(1) time
        bool IsEmpty();

        // Works in O(n) time
        void ShowStack();
};


            Stack::Stack(){
                top = head = tail = NULL;   // Prevent uninitialized value access
            }
            Stack::~Stack(){
                cout << "Removing Stack" << endl;
            }


        // Works in O(1) time
        void Stack::Push(char data){
            Node *stackThis = new Node;  // Get node from heap

            stackThis->next = top;       // Set next to last Top
            * stackThis->element = data; // Add new data to new node.

             head = top = stackThis;     // No matter what, new item
        }                                // is going to be at the TOP.

        // Works in O(1) time
        char Stack::Pop(){
            char temp;
            temp = *top->element;       // Copy return data
            top = top->next;            // Set new TOP
            delete head;                // Get rid of old TOP
            head = top;                 // Update background head
            return temp;
        }

        // Works in O(1) time
        char Stack::Peek(){
            return *top->element;
        }

        // Works in O(1) time
        bool Stack::IsEmpty(){
            bool x;
            (top == NULL) ? x = true : x = false ;  // Had to try it out.
            return x;                               // Same as if-else.
        }

        void Stack::ShowStack(){
            string output = "Top -> ";
            if(IsEmpty()){
                output += "NULL";
                cout << output << endl;
            }
            else{
                Node *iterator = top;
                while(iterator){
                    output = output + iterator->element + " -> ";
                    cout << output << endl;
                    iterator = iterator->next;
                }
                output += "(Bottom of stack)";
                cout << output << endl;
            }
        }
#endif