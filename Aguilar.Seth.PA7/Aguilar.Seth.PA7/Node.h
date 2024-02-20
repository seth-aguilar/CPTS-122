#pragma once
#include <iostream>
#include <fstream>
#include <string>


template <class T >
class Node
{
public:
	Node(const T& data, Node<T>* next = nullptr);

	T getData() const;
	void setData(const T newData);

	void setPNext(Node<T>* newNext);
private:
	T Data;
	Node<T>* pNext;
};

template<class T>
inline Node<T>::Node(const T& data, Node<T>* next)
{
	Data = data;
}

template<class T>
inline T Node<T>::getData() const
{
	return Data;
}

template<class T>
inline void Node<T>::setData(const T newData)
{
	Data = newData;
}

template<class T>
inline void Node<T>::setPNext(Node<T>* newNext)
{
	pNext = newNext;
}
