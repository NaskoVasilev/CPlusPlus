#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template<class T> class Queue
{
private:
	T data;
	Queue<T> *next;
	Queue<T> *head;
	Queue<T> *tail;
public:
	Queue();
	void Enqueue(T element);
	bool IsEmpty();
	T Dequeue();
	int Count;
};

//Empty contructor
template<class T> Queue<T>::Queue()
{
}

template <class T> bool Queue<T>::IsEmpty() 
{
	return head == NULL;
}

//Add element to the queue
template <class T> void Queue<T>::Enqueue(T element)
{
	Queue<T> *temp;
	temp = new Queue<T>;
	temp->data = element;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}
	tail = temp;
	this->Count++;
}

//Remove element form the queue
template <class T> T Queue<T>::Dequeue()
{
	Queue<T> *temp;
	temp = head;
	head = head->next;
	this->Count--;
	return temp->data;
}

int main()
{
	Queue<string> queue;
	queue.Enqueue("Atanas");

	cout << queue.Count << endl;
	bool isEmpty = queue.IsEmpty();

	if (isEmpty)
	{
		cout << "Queue is empty" << endl;
	}
	else {
		cout << "Queue is not empty" << endl;
	}

}

