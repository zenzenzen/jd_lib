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
            if(tail){
                tail->element = input;
            }
            else{ printf(NOWORK);}
        }
        // Works in O(1)
        void AppendHead(char input){
            if(head){
                head->element = input;
            }
            else{ printf(NOWORK);}
        }
        char RemoveTail(void);
        char RemoveHead(void);
        void TraverseFwd(void);
        void TraverseBwd(void);
        bool IsEmpty(void);


};

#endif