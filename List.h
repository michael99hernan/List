#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
template <class T>
struct Node
{
	T data;
	Node<T> * next;
};
template <class T>
class List
{
public:
	List<T>();
	Node<T> * head;
	void append(T,Node<T>*&);
	void display(Node<T>*&);
	void insert(T);
	bool deleteNode(T);
	~List<T>();
};

#endif