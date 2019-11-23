#include "List.h"

template<class T>
inline bool Node<T>::operator<(Node<T> n)
{
	if (this->data < n->data)
		return true;
	else
		return false;
}

template<class T>
inline bool Node<T>::operator>(Node<T> n)
{
	if (this > n)
		return true;
	else
		return false;
}

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
		if (h->next != NULL)
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



template<class T>
Node<T>* List<T>::partition(Node<T>*head,Node<T> *end,Node<T> **newHead,Node<T> **newEnd)
{
	Node<T> *pivot = end;
	Node<T> *prev = NULL, *cur = head, *tail = pivot;

	// During partition, both the head and end of the list might change 
	// which is updated in the newHead and newEnd variables 
	while (cur != pivot)
	{
		if (cur->data < pivot->data)
		{
			// First node that has a value less than the pivot - becomes 
			// the new head 
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot 
		{
			// Move cur node to next of tail, and change tail 
			if (prev)
				prev->next = cur->next;
			Node<T> *tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node 
	(*newEnd) = tail;

	// Return the pivot node 
	return pivot;
}

template<class T>
void List<T>::quicksort()
{
	head = quicksortrec(head, getTail(head));
	return;
}


template<class T>
Node<T>* List<T>::quicksortrec(Node<T> *h,Node<T> *e)
{
	if (!h || h == e)
		return h;
	Node<T> *newHead = NULL, *newEnd = NULL;

	// Partition the list, newHead and newEnd will be updated 
	// by the partition function 
	Node<T> *pivot = partition(h, e, &newHead, &newEnd);

	// Partition the list, newHead and newEnd will be updated 
	// by the partition function 
	if (newHead != pivot)
	{
		// Set the node before the pivot node as NULL 
		Node<T> *tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		// Recur for the list before pivot 
		newHead = quicksortrec(newHead, tmp);
		// Change next of last node of the left half to pivot 
		tmp = getTail(newHead);
		tmp->next = pivot;
	}
	pivot->next = quicksortrec(pivot->next, newEnd);

	return newHead;
	
}

template<class T>
Node<T>* List<T>::getTail(Node<T>* cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
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
