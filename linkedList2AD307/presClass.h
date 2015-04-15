/*-----------------------------------------------------------------------------
Class: presClass.h

Definition for the president class linkedlist.  Includes a struct with a string
variable data and a pointer.

Functions include:
				  Constructor
				  validateData
				  appendNode
				  validateDelete
				  du
				  displayList
				  deleteThese
-----------------------------------------------------------------------------*/
#ifndef PRESIDENTLIST_H
#define PRESIDENTLIST_H
#include <string>
using namespace std;

class presidentList
{
private:

	struct listNode
	{	
		string data;
		
		listNode * link;
	};
	
	listNode * head;
	
	listNode * current;
	
	listNode * trail;

public:
	
	presidentList();
	
	void validateData(ifstream& inputFile);
	
	void appendNode(string nvData);
	
	void validateDelete(ifstream& inputFile);
	
	void displayList();
	
	void deleteThese(string nvData);
	
	~presidentList();
};


#endif