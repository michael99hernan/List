//This class is a templated linked list adds a quicksort method
//
#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
template <class T>
struct Node
{
	T data;
	Node<T> * next;
	bool operator<(Node<T>);
	bool operator>(Node<T>);
};
template <class T>
class List
{
public:
	//The Iterator class is from https://www.geeksforgeeks.org/implementing-iterator-pattern-of-a-single-linked-list/
	//I used this code from the website and modified it to fit my list class
	class Iterator;

	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator(NULL);
	}
	class Iterator
	{
	public:
		Iterator() {
			currNode=head;
		}
		Iterator(const Node<T>*pNode) {
			currNode=pNode;
		}
		Iterator& operator=(Node<T>* pNode)
		{
			this->currNode = pNode;
			return *this;
		}	
		
		// Prefix ++ overload 
		Iterator& operator++()
		{
			if (currNode)
				currNode = currNode->next;
			return *this;
		}

		// Postfix ++ overload 
		Iterator operator++(int)
		{
			Iterator iterator = *this;
			++*this;
			return iterator;
		}
		bool operator!=(const Iterator& iterator)
		{
			return currNode != iterator.currNode;
		}

		T operator*()
		{
			return currNode->data;
		}


	private:
		const Node<T> * currNode;
	};
	List<T>();
	Node<T> * head;
	void append(T,Node<T>*&); //Basically pop_back
	void display(Node<T>*&); //Display list
	void insert(T); //Insert new data in order
	bool deleteNode(T); //delete a Node

	 //The code used in these functions are from the website https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
	Node<T>* partition(Node<T>*h, Node<T> *e, Node<T> **newHead, Node<T> **newEnd); // Gets the partition for quicksort
	void quicksort(); //used to call recursive quicksort function
	Node<T>* quicksortrec(Node<T>*,Node<T>*); //Main quicksort function
	Node<T> *getTail(Node<T> *cur); //Gets last element of list Node
	~List<T>();
};



#endif
