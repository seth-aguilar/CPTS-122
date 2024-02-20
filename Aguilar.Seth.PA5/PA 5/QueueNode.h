#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <ctime> 

class Data
{
public: // Member functions
	Data();
	Data(const int newCustomerNumber, const int newServiceTime);

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; // This memory needs to be allocated on the heap!

class QueueNode
{
public: // Member functions
	// constructors
	QueueNode();
	QueueNode(const Data &newData);

	// destructor
	~QueueNode();
	
	// getters
	Data getData() const;
	QueueNode* getNextPtr() const;

	// setters
	void setData(const Data newData);
	void setNextPtr(QueueNode* const pNewNext);


private:
	Data* pData;    // The memory for Data will need to be allocated on the heap as well!
	QueueNode * pNext;
};

class Queue
{
public: // Member functions

	Queue();
	
	void enqueue(int newCustomerNumber, int newServiceTime, int newTotalTime); // inserts new data at front of queue
	void dequeue(); // delete
	void printQueue();
	bool isEmpty();

	QueueNode* getHead() const;
	QueueNode* getTail() const;

	void setHead(QueueNode* newHead);
	void setTail(QueueNode* newTail);

private:
	QueueNode* pHead;
	QueueNode* pTail;
};

int generateExpressTime(void);

int generateNormalTime(void);

void simulateLines(Queue** Express, Queue** Normal);