/*-----------------------------------------------------------------------------
Class:  presPres

Implementation of the presClass.h file.
-----------------------------------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "presClass.h"

using namespace std;
/*-----------------------------------------------------------------------------
Function:     Constructor

Instantiates a new presidentList, and sets head, current, and trail nodes = to 
NULL.
-----------------------------------------------------------------------------*/
presidentList::presidentList()
{  
	head = NULL;
	
	current = NULL;
	
	trail = NULL;
}

/*-----------------------------------------------------------------------------
Function:     validateData

Inputs:       inputFile stream variable reference inputFile

Loops through the file, grabs one line at a time.  If the line is blank, it 
skips to the next line.  Since we know the data must have two blanks to be valid,
we search for two blanks in a line.  If two are found, search the list to make
sure the data has not already been added.  If already there, it is reported and
skipped, else it is passed to the append function.
-----------------------------------------------------------------------------*/
void presidentList::validateData(ifstream& inputFile)
{	
	string  nameAndAge;
	
	while (inputFile.good())
	{
		
		string duplicate = "";
		
		int count = 0;
		
		getline(inputFile, nameAndAge);
		
		if (nameAndAge == "") continue;
		
		for (int i = 0; i < nameAndAge.size(); i++)
		{
			if (nameAndAge[i] == ' ') count++;
		}
		
		if (count == 2)
		{
			
			if (head != NULL)
			{
				current = head;
				
				while (current != NULL)
				{
					if (current->data == nameAndAge)
					{	
						cout << nameAndAge << " is already in the list, it will not be added again." << endl;
						
						cout << endl;

					    duplicate = current->data;
						
						break;
					}
					    current = current->link;
				}
			}
			
			if (duplicate == nameAndAge) 
				continue; 
			
				appendNode(nameAndAge);
		}
		
		else if (count != 2)
		{
			cout << nameAndAge << " is not a valid input.  It will not be added to the list" << endl;
			
			cout << endl;

			continue;
	    }
	}
}

/*-----------------------------------------------------------------------------
Function:     ValidateDelete

Inputs:       inputFile stream variable reference to deleteThese.in

Validates the data to be deleted by counting spaces.  If a blank line is 
encountered, it is skipped.  If it doesn't contain two spaces, it is reported
as invalid and skipped, else it is passed to the deleteThese function.
-----------------------------------------------------------------------------*/
void presidentList::validateDelete(ifstream& inputFile)
{
	string  nameAndAge;

	while (inputFile.good())
	{
		int count = 0;
		
		getline(inputFile, nameAndAge);
		
		if (nameAndAge == "") continue;
		
		for (int i = 0; i < nameAndAge.size(); i++)
		{
			if (nameAndAge[i] == ' ') count++;
		}

		if (count != 2)
		{
			cout << nameAndAge << " is not valid data.  It will not be deleted." << endl;
			
			continue;
		}
		
		else if (count == 2)  deleteThese(nameAndAge);
	}
}
/*-----------------------------------------------------------------------------
Function:     appendNode

inputs:       string nvData

Creates a new node and sets its data to nvString.  Then searches the list until
the correct location for the node is found and the node is inserted.
-----------------------------------------------------------------------------*/

void presidentList::appendNode(string nvData)
{
	
	bool found;
	
	listNode * n = new listNode;
	
	n->data = nvData;
	
	n->link = NULL;
	
	if (head == NULL)
	{
		head = n;
	}
	
	else
	{
		current = head;
		
		found = false;

		while (current != NULL && !found)
		
			if (current->data > nvData)
			{	
				found = true;
			}
			else 
			{	
				trail = current;
				
				current = current->link;
			}
			
			if (current == head)
			{	
				n->link = current;
				
				head = n;
			}
			else
			{
				n->link = current;
				
				trail->link = n;
			}
		}
}

/*-----------------------------------------------------------------------------
Function:     displayList

Inputs:       None

Loops through the linked list and prints all of the string vales once they have
been sorted.
-----------------------------------------------------------------------------*/
void presidentList::displayList()
{
	if (head == NULL)
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		
		current = head;
		
		cout << endl;
		
		cout << "The current List: " << endl;
		
		cout << endl;
		
		while (current != NULL)
		{
			cout << current->data << endl;
			
			current = current->link;
		}
	}
}
/*-----------------------------------------------------------------------------
Function:     DeleteThese

Inputs:       string delData (data to be deleted)

Loops through the list to find the correct node to delete.  Upon deletion, the
delete is reported to the terminal.  If the value is not found, it is reported
that it is not in the list.
-----------------------------------------------------------------------------*/
void presidentList::deleteThese(string delData)
{
	
	bool found;
	
	if (head == NULL)
	{	
		cout << "The list is empty.  Cannot delete from an empty list" << endl;
	}

	else
	{
		current = head;
	
		found = false;
		
		while (current != NULL && !found)
		if (current->data >= delData)
			found = true;
			
		else
		{	
			trail = current;
			current = current->link;
		}

		if (current == NULL)
		{	
			cout << delData << " is not in the list. It cannot be deleted" << endl;
		
			cout << endl;
		}
		
		else
			if (current->data == delData)
			{
				if (head == current)
				{	
					head = head->link;
				
					cout << current->data << " Has been deleted" << endl;
				
					cout << endl;

					delete current;
				}
				else
				{
					trail->link = current->link;

					cout << current->data << " has been deleted" << endl;
					
					cout << endl;

					delete current;
				}
			}
			else
			cout << delData << " is not in the list. It cannot be deleted" << endl;
	}
}
/*-----------------------------------------------------------------------------
Destructor:  Loops through and deletes the entire linked list.  After deletion,
it sets head to NULL, deletes current, and reports to the user the list has
been deleted.
-----------------------------------------------------------------------------*/
presidentList::~presidentList()
{
	while (current != NULL)
	{ 
		listNode * temporary = new listNode;
		
		temporary = current;
		
		current = current->link;
		
		delete temporary;
	}
	
	head = NULL;

	delete current;

	cout << "The list has been deleted" << endl;
}