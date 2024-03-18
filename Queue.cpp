/*
 * Queue.cpp
 *
 * Description: Implementation of a dynamic circular queue.
 *
 * Class Invariant: FIFO or LILO order
 *                  The queue never runs out of space, and it dynamically adjusts its capacity as needed.
 *
 * Author: Erfan Shafagh / Takin Tabesh
 * Last Modified: November 2023
 */

#include "Queue.h"
#include "EmptyDataCollectionException.h"
#include <iostream>


// Description: Constructor
template <class ElementType>
Queue<ElementType>::Queue(){
    // Dynamically allcotace memory
    elements = new ElementType[INITIAL_CAPACITY];
}

// Destructor to release dynamically allocated memory
template <class ElementType>
Queue<ElementType>::~Queue(){
    delete[] elements;
}

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

// Description: Inserts newElement at the "back" of this Queue, returns true if successful, otherwise false.
// Time Efficiency: O(1) or O(n)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType & newElement) {
    // Handling the capacity O(n)
    if(elementCount == capacity -1){
        int newCapacity = capacity * 2;
        ElementType* newElements = new ElementType[newCapacity];
        for (unsigned int i = 0; i < elementCount; i++) {
            newElements[i] = elements[(frontindex + i) % capacity];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
        frontindex = 0;
        backindex = elementCount;
    }
    // Enqueue
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;
    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1) or O(n)
template <class ElementType>
void Queue<ElementType>::dequeue() {
    // When queue is empty
    if(isEmpty()){
        throw EmptyDataCollectionException("dequeue() called with empty queue!");
    }
    // Dequeue
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    // Handling the capacity O(n)
    if(elementCount < (capacity / 4) && INITIAL_CAPACITY <= (capacity / 2)){
        int newCapacity = capacity / 2;
        ElementType* newElements = new ElementType[newCapacity];
        for(unsigned int i = 0; i < elementCount; i++){
            newElements[i] = elements[(frontindex + i) % capacity];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
        frontindex = 0;
        backindex = elementCount;
    }
    return;
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & Queue<ElementType>::peek() const {
    // When queue is empty
    if(isEmpty()){
        throw EmptyDataCollectionException("peek() called with empty queue!");
    }
    // Peek
    return elements[frontindex];
}
