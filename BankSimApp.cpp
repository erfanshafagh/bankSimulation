/*
 * BankSimApp.cpp
 *
 * Description: This program simulates a bank system with customer arrivals and departures.
 *                It uses a priority queue to manage events such as customer arrivals and departures,
 *                a queue to represent the bank line, and various data structures for handling events.
 *
 * Class Invariant: The program assumes that the input for arrival and processing times is provided in pairs,
 *                     with each pair representing an arrival event. The input is read until there is no more data.
 *                  The program uses a priority queue (EventPriorityQueue) to manage events based on their time.
 *
 * Author: Erfan Shafagh / Takin Tabesh
 * Last Modification: November 2023
 */

#include <iostream>
#include <iomanip>
#include "PriorityQueue.h"
#include "PriorityQueue.cpp"
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "Event.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;
using std::cin;
using std::setw;


/****** Bank simulation application main test function ******/
int main(){

    cout << "Simulation Begins" << endl;

    // defining the structures
    Queue<Event> *bankLine = new Queue<Event>();
    PriorityQueue<Event> EventPriorityQueue;
    PriorityQueue<Event> EventPQ;
    bool tellerAvailable = true;

    // Saving arrival in pq
    int A_Time = 0;
    int T_Time = 0;
    while (cin >> A_Time >> T_Time) {
      Event newArrivalEvent = Event('A', A_Time, T_Time);
      if(!EventPriorityQueue.enqueue(newArrivalEvent)){
        cout << "enqueue was failed!" << endl;
      }
      if(!EventPQ.enqueue(newArrivalEvent)){
        cout << "enqueue was failed!" << endl;
      }
    }

    // Managing customers
    while (!EventPriorityQueue.isEmpty()) {
      Event nextCustomer = EventPriorityQueue.peek();
      int CurrentTime = nextCustomer.getTime();

      if(nextCustomer.getType() == 'A'){
        EventPriorityQueue.dequeue();
        if(tellerAvailable == true && bankLine->isEmpty()){
          int departureTime = CurrentTime + nextCustomer.getLength();
          Event departureEvent = Event('D', departureTime);
          EventPriorityQueue.enqueue(departureEvent);
          EventPQ.enqueue(departureEvent);
          tellerAvailable = false;
        }else{
          bankLine->enqueue(nextCustomer);
        }
      }else{
        EventPriorityQueue.dequeue();
        if(!bankLine->isEmpty()){
          Event costumer = bankLine->peek();
          bankLine->dequeue();
          int departureTime = CurrentTime + costumer.getLength();
          Event departureEvent = Event('D', departureTime);
          EventPriorityQueue.enqueue(departureEvent);
          EventPQ.enqueue(departureEvent);
        }else{
          tellerAvailable = true;
        }
      }
    }

    // Printing the output
    unsigned int numPeople = 0;
    int timeSpentA = 0;
    int timeSpentD = 0;
    int timeSpentj = 0;
    while (!EventPQ.isEmpty()) {
        try {
            Event E = EventPQ.peek();
            numPeople++;
            try {
                EventPQ.dequeue();
                if(E.getType() == 'A'){
                  cout << "Processing an arrival event at time: " << setw(5) << E.getTime() <<endl;
                  timeSpentA = timeSpentA + E.getTime();
                  timeSpentj = timeSpentj + E.getLength();
                }else{
                  cout << "Processing a departure event at time: " << setw(4) <<E.getTime() << endl;
                  timeSpentD = timeSpentD + E.getTime();
                }
            }
            catch (EmptyDataCollectionException& anException) {
                cout << "Dequeue failed because " << anException.what();
            }
        }
        catch (EmptyDataCollectionException& anException) {
            cout << "Peek failed because " << anException.what() << endl;
        }
    }

    // some Statistics
    double ave = double(((timeSpentD-timeSpentA-timeSpentj) * 1.0 )/ (numPeople / 2));
    cout << "Simulation Ends" << endl;
    cout << endl;
    cout << "Final Statistics:" << endl;
    cout << endl;
    cout << "\tTotal number of people processed: " << (numPeople / 2) <<endl;
    cout << "\tAverage amount of time spent waiting: " << ave << endl;

    // free the allocation
    delete bankLine;

    return 0;
}
