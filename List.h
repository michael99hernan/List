//Michael Hernandez
//CS3377
//Assignment 9
//This demonstates a template for link list
#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
template <class T>
struct Node
{
	T data;
	Node<T> * next; //Pointer to next node
};
template <class T>
class List
{
public:
	List<T>();
	Node<T> * head;//Head to list
	void append(T,Node<T>*&);//Create List recursivly
	void display(Node<T>*&);//Display list recursivly
	void insert(T); //Inserting a node in the right order
	bool deleteNode(T); //Remove Node
	~List<T>(); //Deletes head
};

#endif