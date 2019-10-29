#include "List.h"

template <class T>


List<T>::List()
{
	head = NULL;

}
template <class T>

void List<T>::append(T num,Node<T> *& h)
{

	if (h == NULL)
	{
		h = new Node<T>;
		h->data = num;
		h->next = NULL;
	}
	else {
		append(num, h->next);
	}
}
template <class T>

void List<T>::display(Node<T> *& h)
{
	if (h == NULL)
	{
		return;
	}
	else {
		cout << h->data << ", " << endl;
		if (h->next != NULL);
		display(h->next);
		return;
	}
}

template<class T>
void List<T>::insert(T num)
{
	Node<T> *newNode;
	Node<T> *ptrNode;
	Node<T> *prevNode = NULL;

	newNode = new Node<T>;
	newNode->data = num;

	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		ptrNode = head;

		prevNode = NULL;
		while (ptrNode != NULL && ptrNode->data < num)
		{
			prevNode = ptrNode;
			ptrNode = ptrNode->next;
		}
		if (prevNode == NULL)
		{
			head = newNode;
			newNode->next = ptrNode;
		}
		else
		{
			prevNode->next = newNode;
			newNode->next = ptrNode;
		}
	}
}




template<class T>
bool List<T>::deleteNode(T num)
{
	Node<T> * ptrNode;
	Node<T> * prevNode=NULL;
	if (head == NULL) {
		return false;
	}
	if (head->data == num)
	{
		ptrNode = head->next;
		delete head;
		head = ptrNode;
	}
	else
	{
		ptrNode = head;
		while (ptrNode != NULL && ptrNode->data != num)
		{
			prevNode = ptrNode;
			ptrNode = ptrNode->next;
		}
		if (ptrNode)
		{
			prevNode->next = ptrNode->next;
			delete ptrNode;
			cout << "Deleting " << num << endl;
		}
	}
}

template <class T>
List<T>::~List()
{
	Node<T> * ptrNode;
	Node<T> * nextNode;
	ptrNode = head;

		while (ptrNode != NULL)
		{
			nextNode = ptrNode->next;
			delete ptrNode;

			ptrNode = nextNode;
		}
		cout << "List Destroyed" << endl;
}

