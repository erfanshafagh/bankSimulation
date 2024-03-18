# Bank Simulation Project

Bank simulation system that takes care of customer arrivals and departures using priority queues

## Table of Contents
- [Introduction](#introduction)
- [Files](#files)
- [Class Invariants and Functionality](#class-invariants-and-functionality)
- [How to Use](#how-to-use)
- [Contributors](#contributors)

## Introduction
This project implements a bank simulation system in C++. It simulates a bank system with customer arrivals and departures using priority queues and queues to manage events.

## Files
- **BankSimApp.cpp**: Main application for simulating bank operations.
- **BinaryHeap.h** and **BinaryHeap.cpp**: Minimum binary heap ADT class.
- **EmptyDataCollectionException.h** and **EmptyDataCollectionException.cpp**: Exception class for empty data collections.
- **Event.h** and **Event.cpp**: Class representing arrival and departure events in the bank simulation.
- **PriorityQueue.h** and **PriorityQueue.cpp**: Priority queue class using a binary heap.
- **Queue.h** and **Queue.cpp**: Dynamic circular queue implementation.

## Class Invariants and Functionality
- **BankSimApp**: Simulates customer arrivals and departures in a bank system using priority queues and queues.
- **BinaryHeap**: Implements a minimum binary heap ADT class with insertion and removal methods.
- **EmptyDataCollectionException**: Exception class thrown when a data collection is empty.
- **Event**: Represents arrival and departure events in the bank simulation with methods for retrieving event properties.
- **PriorityQueue**: Priority queue class using a binary heap with methods for enqueueing, dequeuing, and peeking.
- **Queue**: Dynamic circular queue implementation with methods for enqueueing, dequeuing, and peeking.

## How to Use
- To use the bank simulation application, compile all the source files together. You can use the provided makefile (`make bsim`) to compile the project. Run the compiled executable (`./bsim`) to start the bank simulation.
- The input data for customer arrivals and processing times is provided in pairs, with each pair representing an arrival event.

## Contributors
- **Erfan Shafagh**
- **Takin Tabesh**
- If you find any issues or have suggestions for improvement, feel free to open an [issue](https://github.com/erfanshafagh/bankSimulation/issues) or create a [pull request](https://github.com/erfanshafagh/bankSimulation/pulls).

