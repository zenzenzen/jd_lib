#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdio.h>
using namespace std;

#define PRINTDATA "\nThis node contains: %c\n"
#define ISEMPTY "\nThere are no nodes.\n"
#define NOMATCH "\nNo matching element found.\n"
#define MATCH   "\nMatch was found!\n"

struct Node{
    char *element;
    Node *next;
};

class LinkedList{

    protected:          // <-- Consistent variables to be inherited
        Node *head;
        Node *tail;

    public:
        LinkedList();
        ~LinkedList();
        // Works in O(1) time
        bool IsEmpty();

        // Works in O(1) time || Doesn't include "full" condition check, only "empty"
        void Append(char data);

        // Works in O(n)
        void Traverse();

        // Works in O(1)
        char Remove(void);

        //Works in O(N)
        bool Find(char searchTerm);

};//End-LinkedList-Class-Declaration

    LinkedList::LinkedList(){
            head = tail = NULL;
        }
    LinkedList::~LinkedList(){
        cout << "Deleting nodes..." << endl;
    }

bool LinkedList::IsEmpty(){
            if(head == tail){return true;}
            else{return false;}
        }// End IsEmpty

void LinkedList::Append(char data){
            Node *addThis = new Node;  // Get node from heap
            * addThis->element = data; // Add new data to new node.
            addThis->next = NULL;      // Set next to NULL
            tail->next= addThis;       // Set current tail node to point to new tail.
            tail = addThis;            // Set LL tail pointer to new tail.

            if(head == NULL){          // Use null instead of IsEmpty() | less expensive
                head = addThis;     
            }
        }// End Append

// Works in O(n)
void LinkedList:: Traverse(){
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
char LinkedList::Remove(void){
            Node *temp;                         // Local scope is OK

            //  When empty
            if(head == tail){
                printf(ISEMPTY);
                return -1;
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
            //Time complexity is O(N)
bool LinkedList::Find(char searchTerm){
            
            Node * trailingPtr;
            Node * leadingPtr;
            trailingPtr = head;
            
            if(*trailingPtr->element == searchTerm){
                leadingPtr->next = head->next;
                delete head;
                head = leadingPtr->next; //Also works for one node case (set head = NULL)
                printf(MATCH);
                return true;
            }
            else if(*trailingPtr->element != searchTerm){
                while(leadingPtr){
                    if(*leadingPtr->element == searchTerm){         
                        trailingPtr->next = leadingPtr->next;   // Bridge gap b/w nodes
                        delete leadingPtr;                      // Remove found element
                        printf(MATCH);
                        return true;
                    }// end-if: Stop and quit scope
                    else{
                        trailingPtr = leadingPtr;
                        leadingPtr = leadingPtr->next;
                    }// end-else: Set up next loop
                }//end-while

                printf(NOMATCH);    //If nothing found in the list...
                return false;
            }
        }// End-Find


#endif