#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
	long int num1, i, level, result;
	
	//to get the desired level of output
	cout << "How many levels of the pyramid would you like to print out? (Please input a number from 1 - 7)" << endl;
	cin >> level;
	
	if(level >= 1 && level <= 7)
	{
		//to get the numbers to times
		for(i = 0; i < level; i++)
		{
			//equation for the level
			num1 = num1 + pow(10, i);

			//find out how to make the pyramid with the numbers and equation to center
			//figure out a way to make the numbers non-scientific	

			//print out the number and answer for each level
			result = pow(num1, 2);
			cout << setw(15)  << num1 << " * " << num1 << " = " << setw(15)  << result  << endl;
		}
	}
	else
	{
		cout << "Input Valid Number" << endl;
	}
	return 0;
}
