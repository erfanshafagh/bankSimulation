/*
 * PriorityQueue.h
 *
 * Description:This file implements the PriorityQueue class, which represents a priority queue using a binary heap.
 *              It provides methods to check if the priority queue is empty, enqueue a new element, dequeue the element with the highest priority,
 *                and peek at the element with the highest priority without removing it
 *
 * Class Invariant:
 *       The PriorityQueue is implemented using a BinaryHeap.
 *       The Priority Queue is empty if and only if the element count in 'TheHeap' is zero.
 *
 *
 * Author: Erfan Shafagh / Takin Tabesh
 * Last Modification: November 2023
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "BinaryHeap.h"


template <class ElementType>
class PriorityQueue{

private:
   BinaryHeap<ElementType> TheHeap;

public:
   /******* Start of Priority Queue Public Interface *******/

   // Description: Returns true if this Priority Queue is empty, otherwise false.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in this Priority Queue and
   //              returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
   bool enqueue(ElementType & newElement);

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   // Time Efficiency: O(log2 n)
   void dequeue();

   // Description: Returns (but does not remove) the element with the next
   //              "highest" priority from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   ElementType & peek() const;

   /*******  End of Priority Queue Public Interface *******/
};
#endif
