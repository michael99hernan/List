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


	return 0;


}