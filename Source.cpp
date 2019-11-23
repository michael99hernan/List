//Michael Hernandez
//Assignment 11
#include "List.h"
#include "List.cpp"// This was needed to fix a linker issue
#include <string>

int main()
{
	List<int> mylist;


	mylist.append(50, mylist.head);
	mylist.append(60, mylist.head);
	mylist.append(70, mylist.head);

	mylist.insert(65);
	mylist.insert(200);
	mylist.insert(750);
	mylist.insert(300);
	mylist.insert(25);

	mylist.display(mylist.head);
	mylist.deleteNode(50);
	mylist.display(mylist.head);
	mylist.deleteNode(750);
	mylist.display(mylist.head);
	//Part Two
	List<string> myStringlist;

	myStringlist.append("Michael", myStringlist.head);
	myStringlist.append("Morgan", myStringlist.head);
	myStringlist.append("Pat", myStringlist.head);
	myStringlist.append("Sally", myStringlist.head);

	myStringlist.insert("Alice");
	myStringlist.insert("Zach");
	myStringlist.insert("Omer");
	myStringlist.insert("Blake");
	myStringlist.insert("Jim");

	myStringlist.display(myStringlist.head);
	myStringlist.deleteNode("Zach");

	myStringlist.display(myStringlist.head);
	myStringlist.deleteNode("Morgan");
	myStringlist.display(myStringlist.head);

	cout << "\n\n\nPART 2" << endl;

	cout << "=========================================" << endl;
	for (List<int>::Iterator it = mylist.begin(); it != mylist.end(); it++)
		cout << *it << " ";
	for (List<string>::Iterator it = myStringlist.begin(); it != myStringlist.end(); it++)
		cout << *it << " ";

	cout << "\n=========================================" << endl;

	//Part 3
	cout << "\n\n\nPART 3" << endl;

	cout << "=========================================" << endl;
	List<int> myIntlist;
	myIntlist.append(3, myIntlist.head);
	myIntlist.append(2, myIntlist.head);

	myIntlist.append(6, myIntlist.head);
	myIntlist.append(5, myIntlist.head);
	myIntlist.append(8, myIntlist.head);
	myIntlist.append(10, myIntlist.head);
	myIntlist.append(4, myIntlist.head);
	cout << "\nUnsorted List" << endl;
	for (List<int>::Iterator it = myIntlist.begin(); it != myIntlist.end(); it++)
	{
		cout << *it << " ";
	}
	myIntlist.quicksort();
	cout << "\nSorted List" << endl;
	for (List<int>::Iterator it = myIntlist.begin(); it != myIntlist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;



}