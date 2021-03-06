#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

template <class T> class Stack
{
private:
	T data;
	Stack<T> *previous;
	Stack<T> *tail;
	//Stack<T> *head;
public:
	Stack();
	void Push(T element);
	T Pop();
	int Count;
	bool IsEmpty();
};

template<class T> Stack<T>::Stack()
{
}

template <class T> bool Stack<T>::IsEmpty()
{
	return tail == NULL;
}

template<class T> void Stack<T>::Push(T element)
{
	Stack<T> *temp;
	temp = new Stack<T>;
	temp->data = element;
	temp->previous = NULL;
	if (tail == NULL)
	{
		tail = temp;
	}
	else
	{
		temp->previous = tail;
	}

	tail = temp;
	this->Count++;
}

template <class T> T Stack<T>::Pop()
{
	Stack<T> *temp;
	temp = tail;
	tail = tail->previous;
	temp->previous = NULL;
	this->Count--;
	return temp->data;
}

int main()
{
	Stack<int> stack;


	for (int i = 0;i < 10;i++)
	{
		stack.Push(i);
	}

	for (int i = 0;i < 10;i++)
	{
		cout << stack.Pop() << endl;
	}

	cout << "Stack count" << endl;
	cout << stack.Count << endl;

	if (stack.IsEmpty())
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		cout << "Stack is not empty" << endl;
	}

}

