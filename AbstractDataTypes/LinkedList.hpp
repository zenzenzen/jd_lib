#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdio.h>
#define PRINTDATA "\nThis node contains: %d\n"
#define ISEMPTY "\nThere are no nodes.\n"

struct Node{
    int *element;
    Node *next;
};

class LinkedList{

    protected:          // <-- Consistent variables to be inherited
        Node *head;
        Node *tail;

    public:
        LinkedList(){
            head = tail = NULL;
        }

        // Works in O(1) time
        bool IsEmpty(){
            if(head == tail){return true;}
            else{return false;}
        }// End IsEmpty

        // Works in O(1) time || Doesn't include "full" condition check, only "empty"
        void Append(int data){
            Node *addThis = new Node;  // Get node from heap

            addThis->next = NULL;      // Set next to NULL
            * addThis->element = data; // Add new data to new node.

            tail->next= addThis;       // Set current tail node to point to new tail.
            tail = addThis;            // Set LL tail pointer to new tail.

            if(head == NULL){          // Use null instead of IsEmpty() | less expensive
                head = addThis;     
            }
        }// End Append

        // Works in O(n)
        void Traverse(){
            Node *iterate = head;

            if(iterate == NULL){                        // Easy check first
                printf(ISEMPTY);                        // While won't run anyways
            }// End-If                                     in this NULL case.
            while(iterate){
                printf(PRINTDATA, iterate->element);
                iterate = iterate->next;
            }// End-While
        }// End Traverse

        // Works in O(1)
        int Remove(void){
            Node *temp;                         // Local scope is OK

            //  When empty
            if(head == tail){
                printf(ISEMPTY);
                return 0;
            }
            // General non-zero cases
            else
            { 
                temp->element = head->element;  // Copy head data first.             
                temp->next = head->next;        
                                                // No need to check one-node case
                delete head;                    // because operation for n = many
                head = temp->next;              // also works for n = 1.
                                                // If next is NULL, then head is NULL
                return *temp->element;          // it makes virtually no difference
            }// End-Else                           so I've dropped the condition checks.
        }

        int Find(int searchTerm){
            // Look for node with the term. 
            // return the value and delete from the list.
        }
};//End-LinkedList-Class


#endif