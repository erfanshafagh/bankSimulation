all: bsim

bsim: BankSimApp.o PriorityQueue.o BinaryHeap.o Queue.o Event.o EmptyDataCollectionException.o
	g++ -Wall -o bsim BankSimApp.o Event.o EmptyDataCollectionException.o Queue.o PriorityQueue.o BinaryHeap.o

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp

Event.o: Event.h Event.cpp
	g++ -Wall -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

Queue.o: Queue.h Queue.cpp
	g++ -Wall -c Queue.cpp
	
PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	g++ -Wall -c PriorityQueue.cpp

BinaryHeap.o: BinaryHeap.h BinaryHeap.cpp
	g++ -Wall -c BinaryHeap.cpp

clean:
	rm -f bsim *.o
