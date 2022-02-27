#include <Python.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;

	return _PyLong_AsInt(presult);
}

//Display menu offers users options and runs Python functions applicable to the user's requested task
int displayMenu() {
	int userInput = 0;
	int loopRun = 0;
	string userItem = "";
	do {
		//Clear screen. If loopRun is >= 1, user inputted improper value for first attempt. Prompt with error message for correction
		system("CLS");
		if (loopRun >= 1) {
			cout << "Please input a valid entry (1, 2, 3, or 4)" << endl;
			cout << endl;
		}
		cout << "***************************************" << endl;
		cout << "1: Display List of Items Purchased    *" << endl;
		cout << "2: Display Number for Specific Item   *" << endl;
		cout << "3: Display Item Histogram             *" << endl;
		cout << "4: Exit Program                       *" << endl;
		cout << "***************************************" << endl;
		cout << "Enter your selection as 1, 2, 3, or 4..." << endl;
		cin >> userInput;
		loopRun++;
	} while ((userInput != 1) && (userInput != 2) && (userInput != 3) && (userInput != 4)); // Loop continues while user fails to select 1, 2, 3, or 4
	system("CLS");

	//If userInput is 1, display list of Items Purchased using CallProcedure for Python function
	if (userInput == 1) {
		system("CLS");
		cout << "Items Purchased... " << endl << endl;
		CallProcedure("ListItemQuantities");

	}

	//If userInput is 2, display number for specific item
	else if (userInput == 2) {
		system("CLS");
		cout << "Input the item to search... "; //Prompt user for item to specify
		cin >> userItem;
		system("CLS");
		//Run callIntFunc to return quantity of item passed into Python. Format with C++ for output to console
		cout << "Number of " << userItem << ": " << callIntFunc("ListSpecificItem", userItem);
	}

	//If userInput is 3, create and write to new file in Python, then read file with C++ to display item histogram in console
	else if (userInput == 3) {	
		string itemName = "";
		int itemFreq = 0;
		system("CLS");
		//Run CallProcedure to create new file with items and quantities with Python
		CallProcedure("CreateQuantityFile");
		//Open file created with Python function and verify successful open
		ifstream inFS;
		inFS.open("frequency.dat");
		if (!inFS.is_open()) {
			cout << "Could not open file 'frequency.dat'." << endl;
			return 1;
		}
		cout << "Quantities:" << endl << endl;
		int i;
		//While file contains data (avoids duplicate iteration for last line)
		//Loops through each line, inputs first string and the frequency into itemName and itemFreq
		while (inFS >> itemName >> itemFreq) {
			cout << itemName << " ";
			for (i = 0; i < itemFreq; i++) {
				cout << "*";
			}
			cout << endl;
		}
		//Closes and removes file
		inFS.close();
		remove("frequency.dat");
	}
	
	//If userInput is 4, exit program
	else if (userInput == 4) {
		cout << "Exiting program...";
		std::exit(1);
	}
	return userInput;
}
//Main calls displayMenu function which handles function calls based on user input
void main(){
	displayMenu();
}