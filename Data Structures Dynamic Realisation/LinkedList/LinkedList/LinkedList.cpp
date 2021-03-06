#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T> class Node
{
public:
	//Refernce to the next element
	Node<T> *NextNode;
	//Refernce to the previous element
	Node<T> *PrevNode;
	//Value of elelement
	T value;

	//Constructor which initialize element and set value of the element
	Node(T value)
	{
		this->value = value;
		this->NextNode = NULL;
		this->PrevNode = NULL;
	}
};

//Doubly linked list
template<class T> class LinkedList
{
private:
	//Reference to the fitst element of the list
	Node<T> *head;
	//Reference to the last element of the list
	Node<T> *tail;
public:
	//Current number of elements in the list
	int Count;

	//Constructor
	LinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
		this->Count = 0;
	}

	//Add element at firts position
	void AddFirst(T value)
	{
		Node<T> *newNode;
		newNode = new Node<T>(value);

		if (this->Count == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			this->head->PrevNode = newNode;
			newNode->NextNode = this->head;
			this->head = newNode;
		}

		this->Count++;
	}

	//Add element at last position
	void AddLast(T value)
	{
		Node<T> *newNode;
		newNode = new Node<T>(value);

		if (this->Count == 0)
		{
			this->tail = newNode;
			this->head = this->tail;
		}
		else
		{
			this->tail->NextNode = newNode;
			newNode->PrevNode = this->tail;
			this->tail = newNode;
		}

		this->Count++;
	}

	//Remove element at first position in the list
	T RemoveFirst()
	{
		if (this->Count == 0)
		{
			cout << "List is empty!" << endl;
			return NULL;
		}

		Node<T> *firstElement = this->head;
		T element = firstElement->value;

		if (this->Count == 1)
		{
			this->head = NULL;
			this->tail = NULL;
		}
		else
		{
			this->head = this->head->NextNode;
			firstElement->NextNode = NULL;
			this->head->PrevNode = NULL;
		}

		this->Count--;
		return element;
	}

	//Remove element at last position in the list
	T RemoveLast()
	{
		if (this->Count == 0)
		{
			cout << "List is empty!" << endl;
			return NULL;
		}

		Node<T> *lastElement = this->tail;
		T element = lastElement->value;

		if (this->Count == 1)
		{
			this->head = NULL;
			this->tail = NULL;
		}
		else
		{
			this->tail = this->tail->PrevNode;
			lastElement->PrevNode = NULL;
			this->tail->NextNode = NULL;
		}

		this->Count--;
		return element;
	}

	bool IsEmpty()
	{
		return this->head == NULL;
	}

    //Print all element. Traverse from head to tail
	void Print()
	{
		Node<T> *current = this->head;

		while (current != NULL)
		{
			//print current value
			cout << current->value << endl;
			//Get next element
			current = current->NextNode;
		}
	}

	//Returns true if list contains the element.
	bool Contains(T element)
	{
		Node<T> *currentNode = this->head;

		while (currentNode != NULL)
		{
			if (element == currentNode->value)
			{
				return true;
			}
			currentNode = currentNode->NextNode;
		}

		return false;
	}

	//Return array of list elements.
	T *ToArray(T arr[])
	{
		int index = 0;
		Node<T> *currentNode = this->head;

		while (currentNode != NULL)
		{
			arr[index] = currentNode->value;
			index++;
			currentNode = currentNode->NextNode;
		}

		return arr;
	}
};

int main()
{
	LinkedList<int> list;
	list.AddLast(1);
	list.AddLast(2);
	list.AddLast(3);
	list.AddLast(4);

	list.Print();

	if (list.Contains(3))
	{
		cout << "List contains three"<<endl;
	}
	else 
	{
		cout << "List does not contain three" << endl;
	}

	cout << "Removed element" << endl;
	//cout << list.RemoveLast() << endl;
	cout << list.RemoveLast() << endl;
	cout << list.RemoveFirst() << endl;
	//cout << "Other elements" << endl;
	
	if (list.IsEmpty())
	{
		cout << "List is empty" << endl;
	}
	else 
	{
		cout << "List contains elements" << endl;
	}

	/*int elements[4];
	list.ToArray(elements);
	cout << "Array first element" << endl;
	cout << elements[0] << endl;
	cout << elements[1] << endl;
	cout << elements[2] << endl;
	cout << elements[3] << endl;*/

	cout << "Print elements" << endl;
	list.Print();
}

