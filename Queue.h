/*
 * Queue.h
 *
 * Description: Implementation of a dynamic circular queue.
 *
 * Class Invariant: FIFO or LILO order.
 *                  The queue never runs out of space, and it dynamically adjusts its capacity as needed.
 *
 *
 * Author: Erfan Shafagh / Takin Tabesh
 * Last Modified: November 2023
 */

#ifndef QUEUE_H
#define QUEUE_H


template <class ElementType>
class Queue{

private:
   ElementType * elements;
   static unsigned int const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
   unsigned int elementCount = 0;                  // Number of elements in the Queue
   unsigned int capacity = INITIAL_CAPACITY;       // Actual capacity of the data structure (number of cells in the array)
   unsigned int frontindex = 0;                    // Index of front element (next dequeued/peeked element)
   unsigned int backindex = 0;

public:
   /******* Start of Queue Public Interface *******/

   // Description: Constructor
   Queue();
   // Description: Destructor to release dynamically allocated memory.
   ~Queue();

   // Description: Returns true if this Queue is empty, otherwise false.
   // Postcondition: This Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement at the "back" of this Queue
   //              (not necessarily the "back" of this Queue's data structure)
   //              and returns true if successful, otherwise false.
   // Time Efficiency: O(1)
   bool enqueue(ElementType & newElement);

   // Description: Removes (but does not return) the element at the "front" of this Queue
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   void dequeue();

   // Description: Returns (but does not remove) the element at the "front" of this Queue
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType & peek() const;

   /******* End of Queue Public Interface *******/
};
#endif
