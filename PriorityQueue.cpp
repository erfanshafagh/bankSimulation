/*
 * PriorityQueue.cpp
 *
 * Description:This file implements the PriorityQueue class, which represents a priority queue using a binary heap.
 *              It provides methods to check if the priority queue is empty, enqueue a new element, dequeue the element with the highest priority,
 *                and peek at the element with the highest priority without removing it
 *
 * Class Invariant:
 *       The PriorityQueue is implemented using a BinaryHeap.
 *       The Priority Queue is empty if and only if the element count in 'TheHeap' is zero.
 *
 * Author: Erfan Shafagh / Takin Tabesh
 * Last Modification: November 2023
 */

#include <iostream>
#include "PriorityQueue.h"
#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"


// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    return (TheHeap.getElementCount() == 0);
}

// Description: Inserts newElement in this Priority Queue and
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
    return (TheHeap.insert(newElement));
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue(){
    return (TheHeap.remove());
}

// Description: Returns (but does not remove) the element with the next
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const{
    return (TheHeap.retrieve());
}
