#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Module.h"
using namespace std; 

int main(){
	Tree* _TargetTree;
	char _filename[100];
	string Targets[10];
	int NumOfKeys = 0;

	// Get the Name file that the user want to create.
	printf("\n\t Enter the file name u search in:\n");
	scanf("%s", &_filename);

	// Get the string the user want to insert to the text.

	/*printf("\n\t Enter the string you want to put into the text file:\n");
	scanf("%s", &input);*/

	fflush(stdin);
	cout << "\n\t Enter the number of the keywords you want to insert: \n" ;
	cin >> NumOfKeys;
	fflush(stdin);

	for (int i = 0; i < NumOfKeys; i++)
	{
		cout << "\n\t Enter the target KeyWord: \n" ;
		cin >> Targets[i];
	}
	

	scanString(_filename, Targets[0]);

	// Creating the file and inserting the wanted text.
	//createFile(_filename, input);

	cout << "Starting To build the tree\n";
	_TargetTree = Algorithm(Targets, NumOfKeys);
	
}