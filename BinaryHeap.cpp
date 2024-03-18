/*
 * BinaryHeap.cpp
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a minimum Binary Heap.
 *                   never runs out of space.
 *
 * Author: Erfan Shafagh / Takin Tabesh
 * Last Modification: November 2023
 */

#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
#include <cmath>
#include <iostream>


// Description: Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(){
   // Dynamically allcotace memory
   elements = new ElementType[INITIAL_CAPACITY];
}

// Description: Destructor to release dynamically allocated memory.
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){
   delete[] elements;
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const{
   return this->elementCount;
}

// Description: Inserts newElement into the Binary Heap.
//              It returns true if successful, otherwise false.
// Time Efficiency: O(log2 n) or O(n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement){
   // Handling the capacity O(n)
   if(elementCount == capacity -1){
      unsigned int newCapacity = capacity * 2;
      ElementType* newElements = new ElementType[newCapacity];
      if(newElements == nullptr){
         return false;
      }
      for (unsigned int i = 0; i < elementCount; i++) {
         newElements[i] = elements[i];
      }
      delete[] elements;
      elements = newElements;
      capacity = newCapacity;
   }
   // Enqueue
   elementCount++;
   elements[elementCount - 1] = newElement;
   reHeapUp(elementCount - 1);

   return true;
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {
   if(elementCount == 0){
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");
   }
   elements[0] = elements[elementCount - 1];
   elementCount--;
   reHeapDown(0);

   return;
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const{
   if(elementCount == 0){
     throw EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.");
   }
   return elements[0];
}

// Utility method
// Description: Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {
   unsigned int indexOfMinChild = indexOfRoot;

   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount-1) {
      return;
   }

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) ){
      indexOfMinChild = indexOfLeftChild;
   }

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) ){
         indexOfMinChild = indexOfRightChild;
         }
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;

      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
}

// Utility method
// Description: Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {
   if(indexOfBottom > 0){
     unsigned int indexOfParent = std::floor((indexOfBottom - 1) / 2);

     if(elements[indexOfBottom] <= elements[indexOfParent]){
       ElementType temp = elements[indexOfBottom];
       elements[indexOfBottom] = elements[indexOfParent];
       elements[indexOfParent] = temp;
       reHeapUp(indexOfParent);
     }
   }
   return;
}
