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

        void Enqueue(char input){
            Append(input);       // Go to end, add node, set next to NULL.
            backOfLine = tail;   // Queue grows to the 'right'| people line up
            frontOfLine = head;  // and shortens at the 'left' | people leave
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

class PriorityQueue : public Queue{
        // Inherited values: head, tail,frontOfLine, and backOfLine
    private:
        Node *previousNode;        // Main distinct sub-class features used
        Node *currentNode;         // for traversing the Priority Queue
    public:
        PriorityQueue(){
            head = tail =
            frontOfLine = backOfLine =
            previousNode = currentNode = NULL;
        }
        ~PriorityQueue();

        //  Returns copy of Front of Queue node element
        //  Works in O(1)
        char Peek(void){
            if(frontOfLine){
                return *frontOfLine->element;
            }
            else{
                return -1;
            }
        }

        //  Remove the front of the line.
        //  Works in O(1) complexity
        char Dequeue(void){
            // Remove the head and return data
            Node buffer;
            if(frontOfLine){
                buffer.element = frontOfLine->element;
                buffer.next = frontOfLine->next;
                delete frontOfLine;
                frontOfLine = buffer.next;
                return *buffer.element;
            }
            else{
                return -1;
            }
        }

        // insert(char data): inserts data in sorted order
        // Largest elements are at the front.
        // Works in O(N) Time
        void Insert(char input){
            currentNode = frontOfLine;
            Node *freshInsert = new Node;              // Grab from heap;
                *freshInsert->element = input;         // Assign element
                freshInsert->next = NULL;              // Prevent weird errors

            if(IsEmpty()){
                frontOfLine = head =
                backOfLine = tail = freshInsert;       // Maintain inherited values
            }
            else if(input > *frontOfLine->element){     
                    freshInsert->next = frontOfLine;
                    head = frontOfLine = freshInsert;
                }// End-Else-If
            else{        
                while(currentNode){
                    previousNode = currentNode;
                    currentNode = currentNode->next;      // Move to next position

                    if(input > *currentNode->element){
                        previousNode->next = freshInsert; // Insert link here
                        freshInsert->next = currentNode;  // Point new node to next
                        break;                            // Quickly quit loop.
                    }// End-If: Check queue middle values
                    else if(currentNode->next == NULL){
                        currentNode->next = freshInsert;
                        tail = backOfLine = freshInsert;  // Maintain correct end-points
                        break;
                    }// End Else-If: Reached end of Queue
                }// End-While: traverse queue for insertpoint
            }// End-Else
            currentNode = previousNode = NULL;            // Reset traversal values
        }// End-Insert-Method declaration

        

};