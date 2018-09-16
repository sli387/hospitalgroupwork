#include <iostream>
using namespace std;

//function for Sequence
void fibSeq(int choice)
{
        int fibSequence[choice];
	fibSequence[0] = 0;
	fibSequence[1] = 1;
	
        for (int j = 0; j < choice; j++)
        {
               	for(int i = 1; i < j; i++)
                {
                        fibSequence[j]  = fibSequence[i-1] + fibSequence[i];
		}
		cout << fibSequence[j] << " ";
	}
	cout << endl;
        return;
}

//main function to call the fibSeq
int main()
{
	int choice;
	cout << "This program is for printing out the fibonacci sequence to the amount you input" << endl;
	cout << "Input Amount: " << endl;
	cin >> choice;
	fibSeq(choice);
	return 0;
}
