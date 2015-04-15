/*-----------------------------------------------------------------------------
Programmer:  Andrew Douglas

Program:     Program that pulls a list of US presidents names and ages from a 
		     file via command line(namesAndAges.in).  The program determines if
			 the data is valid:  Washington George 57 is an example of valid 
			 data.  If a name or the age is missing it is invalid.  When valid,
			 the data is sorted and stored in a linked list.

			 After the data is in the list, a second file(deleteThese.in) is 
			 used to determine which names should be deleted from the list.
			 The delete file data must also be validated.

Class:       CSC 307 - Data Structures using C++

Instructor:  Tom Rishel

Files:       presClass.h, presListImp.cpp
-----------------------------------------------------------------------------*/

#include <iostream>         
#include <fstream>
#include <cstdlib>
#include <string>
#include "presClass.h"
using namespace std;

int main(int argc, char *argv[])
{
	/*-------------------------------------------------------------------------
	USAGE STATEMENT:  lets the user know which files and which order they need 
	to pass them in to run the program
	-------------------------------------------------------------------------*/
	
	if (argc != 3)
	{   
		cout << "Usage statement: To use this program, you must pass two input files. First file: nameAndAges.in. Second file: deleteThese.in. The program will exit.  Please try again." << endl;
		system("pause");
		return 0; 
	}


	/*-------------------------------------------------------------------------
	If the correct parameters have been passed, open the first file and validate
	the data.  Then, print the output on the sorted linked list.
	-------------------------------------------------------------------------*/
	ifstream inputFile1;
	
	ifstream inputFile2;
	
	presidentList List;

	inputFile1.open(argv[1]);
	
	
	if (!inputFile1.is_open())
	{
		cout << "Could not open the file" << endl;
		return 1;
	}
	
	else
	{   
		List.validateData(inputFile1);
    }

	List.displayList();


	/*-------------------------------------------------------------------------
	Now, open the delete file and validate it.  Delete the data and reprint the 
	list.
	-------------------------------------------------------------------------*/
	inputFile2.open(argv[2]);
	
	if (!inputFile2.is_open())
	{	
		cout << "Could not open the file" << endl;
		return 1;
	}

	else
	{	
		List.validateDelete(inputFile2);
	}
	/*-------------------------------------------------------------------------
	Now reprint the list, delete the entire list, and reprint the empty list.
	-------------------------------------------------------------------------*/
	
	List.displayList();
	
	List.~presidentList();
	
	List.displayList();
	
	
	cin.get();
	return 0;
}