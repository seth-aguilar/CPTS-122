#include "QueueNode.h"

QueueNode::QueueNode()
{
	pData = new Data();
	pNext = nullptr;
}

QueueNode::QueueNode(const Data &newData)
{
	pData = new Data(newData);
	pNext = nullptr;
}

QueueNode::~QueueNode()
{
}

Data QueueNode::getData() const
{
	return *pData;
}

QueueNode* QueueNode::getNextPtr() const
{
	return pNext;
}

void QueueNode::setData(const Data newData)
{
	*pData = newData;
}

void QueueNode::setNextPtr(QueueNode* const pNewNext)
{
	pNext = pNewNext;
}

Data::Data()
{
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}

Data::Data(const int newCustomerNumber, const int newServiceTime)
{
	customerNumber = newCustomerNumber;
	serviceTime = newServiceTime;
	totalTime = 0;
}

int generateExpressTime(void)
{
	return rand() % 1 + 5;
}

int generateNormalTime(void)
{
	return rand() % 3 + 8;
}

void simulateLines(Queue** Express, Queue** Normal)
{
	int normalArrival = 0, normalService = 0, expressArrival = 0, expressService = 0, time = 0;

	std::cout << "How long do you want to run the simulation(minutes): " << std::endl;
	std::cin >> time;

	for(; time > 0 ; time--, normalArrival--, normalService--, expressArrival--, expressService--)
	{
		if (normalService == 0) // service finished
		{
			// isEmpty?
			// dequeue
			//normalService = generateNormalTime;
		}
		if (normalArrival == 0) // queue is empty
		{
			// enqueue
			//normalArrival = generateNormalTime;
		}
		if (expressService == 0) // service finished
		{
			// isEmpty?
			// dequeue
			//expressService = generateNormalTime;
		}
		if (expressArrival == 0) // queue is empty
		{
			// enqueue
			//expressArrival = generateNormalTime;
		}

	}
}

Queue::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

void Queue::enqueue(int newCustomerNumber, int newServiceTime, int newTotalTime)
{
	Data newData(newCustomerNumber, newServiceTime);
	QueueNode newNode(newData);

	if (isEmpty() == true)
	{
		setHead(&newNode);
	}

	newNode.setNextPtr(getTail());
	setTail(&newNode);
}

void Queue::dequeue()
{
	QueueNode *tempNode = getHead();

	
}

void Queue::printQueue()
{

}

bool Queue::isEmpty()
{
	if (getHead() == nullptr && getTail() == nullptr)
	{
		return false;
	}


	return true;
}

QueueNode* Queue::getHead() const
{
	return pHead;
}

QueueNode* Queue::getTail() const
{
	return pTail;
}

void Queue::setHead(QueueNode *newHead)
{
	pHead = newHead;
}

void Queue::setTail(QueueNode *newTail)
{
	pTail = newTail;
}
