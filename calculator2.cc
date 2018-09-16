#include <iostream>
#include <cmath>
using namespace std;

//*******************
//Prototypes to call
//*******************

void showMenu();
void sumNum(double, double);
void subNum(double, double);
void multiNum(double, double);
void divNum(double, double);
void sqNum(double);
void cubNum(double);
void sqrtNum(double);
void cbrtNum(double);
void prNum(double, double);
void exit();

void oneNum(int);
void twoNum(int);

//**************
//Main Function
//**************

int main()
{
    int choice;
    double num1, num2;
    showMenu();
    cin >> choice;
    if (choice == 0)
    {
        exit();
    }
    else
    {
        if ((choice >= 1 && choice <= 4) || choice == 9)
        {
            twoNum(choice);
        }
        else if(choice >= 5 && choice <= 8)
        {
            oneNum(choice);
        }
        else
        {
            exit();
        }
    }
    return 0;
}

//*****************************
//Functions for the Calculator
//*****************************

void oneNum(int choice)
{
    double num1;
    cout << "Input A Number" << endl;
    cin >> num1;
    switch (choice)
    {
        case 5:
            sqNum(num1);
            break;
        case 6:
            cubNum(num1);
            break;
        case 7:
            sqrtNum(num1);
            break;
        case 8:
            cbrtNum(num1);
            break;
    }
}

void twoNum(int choice)
{
    double num1, num2;
    cout << "Input Two Numbers" << endl;
    cin >> num1 >> num2;
    switch (choice)
    {
        case 1: 
            sumNum(num1,num2);
            break;
        case 2:
            subNum(num1, num2);
            break;
        case 3:
            multiNum(num1,num2);
            break;
        case 4:
            divNum(num1, num2);
            break;
        case 9:
            prNum(num1, num2);
            break;
    }
}

void showMenu()
{
    cout << "Calculator" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Square" << endl;
    cout << "6. Cube" << endl;
    cout << "7. Square Root" << endl;
    cout << "8. Cube Root" << endl;
    cout << "9. Power" << endl;
    cout << "0. Exit" << endl;
}

void sumNum(double num1, double num2)
{
    double result;
    result = num1 + num2;
    cout << "The result is: " << result << endl;
    return;
}

void subNum(double num1, double num2)
{
    double result;
    result = num1 - num2;
    cout << "The result is: " << result << endl;
    return;
}

void multiNum(double num1, double num2)
{
    double result;
    result = num1 * num2;
    cout << "The result is: " << result << endl;
    return;
}

void divNum(double num1, double num2)
{
    double result;
    result = num1 / num2;
    cout << "The result is: " << result << endl;
    return;
}

void sqNum(double num1)
{
    double result;
    result = pow(num1, 2);
    cout << "The result is: " << result << endl;
    return;
}

void cubNum(double num1)
{
    double result;
    result = pow(num1, 3);
    cout << "The result is: " << result << endl;
    return;
}

void sqrtNum(double num1)
{
    double result;
    result = pow(num1, 0.5);
    cout << "The result is: " << result << endl;
    return;
}

void cbrtNum(double num1)
{
    double result;
    result = pow(num1, 3);
    cout << "The result is: " << result << endl;
    return;
}

void prNum(double num1, double num2)
{
    double result;
    result = pow(num1, num2);
    cout << "The result is: " << result << endl;
    return;
}

void exit()
{
    cout << "Exiting Calculator. . ." << endl;
}
