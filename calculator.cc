#include <iostream>
#include <cmath> //for pow
using namespace std;

int main()
{
	float num1, num2, result;
	int choice;
	cout << "Enter a Choice" <<endl;
	cout << "1. Addition" << endl;
        cout << "2. Subtration" <<endl;
        cout << "3. Multiplication" <<endl;
        cout << "4. Division" <<endl;
        cout << "5. Square" <<endl;
        cout << "6. Cube" <<endl;
        cout << "7. Square Root" <<endl;
        cout << "8. Cube Root" <<endl;
        cout << "9. Power" <<endl;
	cin >> choice;
if(choice > 0 && choice < 10 )
{
	switch (choice)
	{
                case 1:
                        //do addition
                        cout << "Enter First Number " << endl;
                        cin >> num1;

                        cout << "Enter Second Number " << endl;
                        cin >> num2;

                        result = num1 + num2;
                        cout << "The Result is " << result<<endl;
			break;

                case 2:
                        //do subtration
                        cout << "Enter First Number " << endl;
                        cin >> num1;

                        cout << "Enter Second Number " << endl;
                        cin >> num2;

                        result = num1 - num2;
                        cout << "The Result is " << result<<endl;
               	 
                break;

                case 3:
                        //do multiplication
                        cout << "Enter First Number " << endl;
                        cin >> num1;

                        cout << "Enter Second Number " << endl;
                        cin >> num2;

                        result = num1 * num2;
                        cout << "The Result is " << result<<endl;
               	
                        break;

                case 4:
                        //do division
                        cout << "Enter First Number " << endl;
                        cin >> num1;

                        cout << "Enter Second Number " << endl;
                        cin >> num2;

                if (num2 == 0)
                {
                    cout << "You cannot divide a number by Zero" << endl;
                }
                else
                {
                    result = num1 / num2;
                    cout << "The Result is " << result<<endl;
			    }
                break;

                case 5:
                //do square
                cout << "Enter Number " << endl;
                cin >> num1;

                result = num1 * num1;
                cout << "The Result is " << result<<endl;
            
                break;

                case 6:
                        //do cube
                        cout << "Enter Number" << endl;
                        cin >> num1;

                        result = num1 * num1 * num1;
                        cout  << "The Result is " << result<<endl;
                        break;

                case 7:
                        //do square root
                        cout << "Enter Number" << endl;
                        cin >> num1;

                        result = pow(num1, 0.5);
                        cout  << "The Result is " << result << endl;
                        break;

                case 8:
                        //do cube root
                        cout << "Enter Number" << endl;
                        cin >> num1;

                        result = cbrt(num1);
                        cout  << "The Result is " << result<<endl;
                        break;

                case 9:
                        //do power
                        cout << "Enter Number" << endl;
                        cin >> num1;
            
                        cout << "Enter Degree of Power" << endl;
                        cin >> num2;
			
                        result = pow(num1, num2);
                        cout << "The Result is " << result << endl;
                        break;

    }
        }
	    else
        {
            cout << "Please intput a number listed above" << endl;
        }
	return 0;
	
}

