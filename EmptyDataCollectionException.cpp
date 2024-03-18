/*
 * EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when data collection is empty.
 *
 * Author: Erfan Shafagh / Takin Tabesh
 *         
 */
 
#include "EmptyDataCollectionException.h"  

// Constructor
EmptyDataCollectionException::EmptyDataCollectionException(const string& message): 
logic_error("EmptyDataCollectionException: " + message) {}  