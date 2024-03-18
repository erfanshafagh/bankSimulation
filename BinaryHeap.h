/*
 * BinaryHeap.h
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a minimum Binary Heap.
 *                   never runs out of space.
 *
 * Author: Erfan Shafagh / Takin Tabesh 
 * Last Modification: November 2023
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H


template <class ElementType>
class BinaryHeap {

private:
   ElementType * elements;
   static unsigned int const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
   unsigned int elementCount = 0;                  // Number of elements in the Queue
   unsigned int capacity = INITIAL_CAPACITY;       // Actual capacity of the data structure (number of cells in the array)

   void reHeapDown(unsigned int indexOfRoot);
   void reHeapUp(unsigned int indexOfBottom);

public:
   /******* Start of Binary Heap  Public Interface *******/

   // Description: Constructor
   BinaryHeap();
   // Description: Destructor to release dynamically allocated memory.
   ~BinaryHeap();

   // Description: Returns the number of elements in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   unsigned int getElementCount() const;

   // Description: Inserts newElement into the Binary Heap.
   //              It returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
   bool insert(ElementType & newElement);

   // Description: Removes (but does not return) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(log2 n)
   void remove();

   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1)
   ElementType & retrieve() const;

   /******* End of Binary Heap Public Interface *******/
};
#endif
