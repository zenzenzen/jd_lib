#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include <stdio.h>
#define PRINTDATA "\nThis node contains: %c\n"
#define ISEMPTY "\nThere are no nodes.\n"
#define NOWORK "\nEmpty list. Nothing to be done.\n"
#define NOMATCH "\nNo matching element found.\n"
#define MATCH   "\nMatch was found!\n"

struct DNode{
    char element;
    DNode *back;
    DNode *next;
};

class DoubleLinkedList{
    protected:
        DNode *head;
        DNode *tail;

    public:
        DoubleLinkedList(){
            head = tail = NULL;
        }
        ~DoubleLinkedList();

        // Works in O(1)
        void AppendTail(char input){
            DNode *newTail = new DNode;
                newTail->element = input;   // Establish default values
                newTail->next = NULL;
                newTail->back = NULL;
            if(tail){                       // In case list has items
                tail->next = newTail;       // Set tail to new node location
                newTail->back = tail;       // Set newTail back pointing to old tail
                tail = newTail;             // Set newTail as the New Tail!
            }
            else{ 
                head = tail = newTail;      // In case list is empty
            }
        }
        // Works in O(1)
        void AppendHead(char input){
            DNode *newHead = new DNode;
                newHead->element = input;   // Establish default values
                newHead->next = NULL;
                newHead->back = NULL;
            if(head){                       // In case list has items
                newHead->next = head;
                head->back = newHead;
                head = newHead;
            }
            else{ 
                head = tail = newHead;      // In case list is empty
            }
        }
        char RemoveTail(void){
            char buffer;
            if(tail){
                buffer = tail->element;     // Get value
                tail = tail->back;          // Move tail position back
                delete tail->next;          // Delete previous tail location
                tail->next = NULL;          // Cap the tail next pointer with NULL
                return buffer;
            }
            else{
                printf(NOWORK);
            }
        }
        char RemoveHead(void){
            char buffer;
            if(head){
                buffer = head->element;     // Get value
                head = head->next;          // Move head position forward
                delete head->back;          // Delete previous head position
                head->back = NULL;          // Cap head back pointer
                return buffer;
            }
            else{
                printf(NOWORK);
            }
        }
        void TraverseFwd(void){

        }
        void TraverseBwd(void){

        }
        bool IsEmpty(void);


};

#endif