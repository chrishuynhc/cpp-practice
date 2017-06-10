#include <iostream>
using namespace std;

// function prototypes
// read the number and validate it
int getNumber();
// calculate the factorial (up to 20)
unsigned long long int calculateFactorial(int value);


int main()
{
    int number = 1;
    while (number != 0){
        number = getNumber();
        unsigned long long int factorial = calculateFactorial(number);
        cout << number << "! is " << factorial << endl;
    }
    return 0;
}

// get a number between 0 and 20 inclusive.
int getNumber()
{
    int number;
    
    do {
        cout << "Enter 0 to quit or a number n to be used for n! up to 20!: ";
        cin >> number;
        
        if (number < 0 || number > 20){
            cout << "The value must be greater than or equal to 0 and less than 21." << endl;
        }
        else if (number == 0){
            exit(0);
        }
        
    } while (number < 0 || number > 20);
    return number;
}

// calculate n! for the case where n is value.
unsigned long long int calculateFactorial(int value)
{
    unsigned long long int factorial = 1;
    
    for (int i = 1; i <= value; i++){
        
        factorial *= i;
    }
    
    return factorial;
}

