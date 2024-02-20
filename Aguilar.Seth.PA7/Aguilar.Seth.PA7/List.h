#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

template <class T>
class List
{
public:
	List();
	~List();

	Node<T>* getHead() const;
	void setHead(const Node<T>* newHead);

	void insertAtFront(const T& data);
	void display() const;
private:
	Node<T>* head;
};

template<class T>
inline List<T>::List()
{
	head = nullptr;
}

template<class T>
inline List<T>::~List()
{
}

template<class T>
inline Node<T>* List<T>::getHead() const
{
	return head;
}

template<class T>
inline void List<T>::setHead(const Node<T>* newHead)
{
	head = newHead;
}

template<class T>
inline void List<T>::insertAtFront(const T& data)
{
	head->pNext = head;
	head(data);
}

template<class T>
inline void List<T>::display() const
{
}
