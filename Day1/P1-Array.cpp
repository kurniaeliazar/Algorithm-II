#include <iostream>

using namespace std;

int main(){

	//Single dimension array
	int array[] = {1,2,3};

	//Multiple dimeension array
	int arrayM [2][2] = {{1,2},{3,4}};

	//array of char
	char question1[] = "-What is your name?-";
	char *strs[3] = {"Str1", "Str2", "Str3"}; // Depcrecated
	string name[3] = {"Asep", "Dadan", "Ujang"};

	//char questions[][] = {{"What is your name? "};

	cout << "-Before values change-" << endl;
	cout << array[0] << endl;
	cout << arrayM[1][1] << endl;

	//Change array value
	array[0] = 10;
	arrayM[1][1] = 25;

	cout << "After values change" << endl;
	cout << array[0] << endl;
	cout << arrayM[1][1] << endl;

	cout << "Hello, " << question1 << endl;
	cout << name[2] << endl;
	cout << strs[2] << endl;


	return 0;
}

