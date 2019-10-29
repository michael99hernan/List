//Michael Hernandez
//CS3377
//Assignment 9
//Source file for project and creates a list with int and strings
#include "List.h"
#include "List.cpp"// This was needed to fix a linker issue
#include <string>

int main()
{
	List<int> mylist;

	//Create list of ints
	mylist.append(50, mylist.head);
	mylist.append(60, mylist.head);
	mylist.append(70, mylist.head);
	//Insert 5 nodes
	mylist.insert(65);
	mylist.insert(200);
	mylist.insert(750);
	mylist.insert(300);
	mylist.insert(25);
	//Display and delete
	mylist.display(mylist.head);
	mylist.deleteNode(50);
	mylist.display(mylist.head);
	mylist.deleteNode(750);
	mylist.display(mylist.head);
	//Part Two
	List<string> myStringlist;
	//Create list of string
	myStringlist.append("Michael", myStringlist.head);
	myStringlist.append("Morgan", myStringlist.head);
	myStringlist.append("Pat", myStringlist.head);
	myStringlist.append("Sally", myStringlist.head);
	//Insert 5 nodes
	myStringlist.insert("Alice");
	myStringlist.insert("Zach");
	myStringlist.insert("Omer");
	myStringlist.insert("Blake");
	myStringlist.insert("Jim");
	//Display and delete
	myStringlist.display(myStringlist.head);
	myStringlist.deleteNode("Zach");
	myStringlist.display(myStringlist.head);
	myStringlist.deleteNode("Morgan");
	myStringlist.display(myStringlist.head);


	return 0;


}