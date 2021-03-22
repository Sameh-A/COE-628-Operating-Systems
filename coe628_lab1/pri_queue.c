#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Sameh Ahmed 500907041
 */

void PQ_insert(int priority, char * data) {
    Node_ptr_t nodeOne = (Node_ptr_t)malloc(sizeof(Node_t));
    nodeOne -> data = data;
    nodeOne -> priority = priority;
//if the number inputed is higher then the input
   if(head == NULL || head->priority < priority){
        nodeOne -> next = head;
        head = nodeOne;
        
    }
//if the number inputed is lower then the input    
    else{
        Node_ptr_t temporary;
        temporary = (Node_ptr_t)malloc(sizeof(Node_t));
        temporary = head;
//goes through linked list         
        while(temporary -> next -> priority >= priority)
            {
            temporary = temporary->next;
            }
 //places the new priority in the correct place       
        nodeOne -> next = temporary -> next;
        temporary -> next = nodeOne;
        
    }
}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
   //temp Node pointer
    Node_ptr_t temporary2 = (Node_ptr_t)malloc(sizeof(Node_t));
    
    if (head!= NULL)
    {
        //place the head in the temporary holder pointer
        temporary2 = head;
        head = head -> next;
    }
    //returns the priority number removed 
    printf("the highest priority number which was deleted is : %d "+ temporary2->priority);
    //return the node
    return temporary2;
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
   
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}



