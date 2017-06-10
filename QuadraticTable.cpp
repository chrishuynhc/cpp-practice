#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

int menuSelection();                                //Function prototypes
void quadraticSolver();
void quadraticTable();
void formTable(int, int, double, double, double);

int main() {
    
    int choice = menuSelection();                   //stores menu option user selections
    
    if (choice == 1){                               //if user selects option 1, open quadratic formula solver
        quadraticSolver();
    }
    else if (choice == 2){                          //if user selects option 2, open quadratic xy table maker
        quadraticTable();
    }
    else if (choice == 3){                          //if user selects option 3, program closes
        exit(1);
    }
    return 0;
}

int menuSelection(){                                //function presents menu and stores user selection
    
    int choice;
    
    cout << "Menu Options" << endl;                 //outputs menu information and asks user to select
    cout << "1. Quadratic Formula Solver" << endl;
    cout << "2. Quadratic XY Table" << endl;
    cout << "3. Exit Program" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    
    while (choice < 1 || choice > 3) {              //if input is invalid, ask user to try again
        cout << "Sorry, that option is invalid.  Try again." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return choice;
}

void quadraticSolver(){                             //function finds x values of a given quadratic equation
    
    double a, b, c, x1, x2, xPartOne, xPartTwo, rootValue;
    
    cout << "Option 1 - Quadratic Formula Solver" << endl;                              //outputs program function and asks user for a, b, and c values
    cout << "This program solves for x1 and x2." << endl << endl;
    cout << "Please enter the 'a' value for the quadratic equation: ";
    cin >> a;
    cout << "Please enter the 'b' value for the quadratic equation: ";
    cin >> b;
    cout << "Please enter the 'c' value for the quadratic equation: ";
    cin >> c;
    cout << endl;
    
    cout << "Equation: (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0" << endl;  //presents the given equation
    
    rootValue = pow(b,2) - (4 * a * c);                                                 //finds value inside square root of formula
    
    if (rootValue >= 0){                                                                //if value in sqrt is positive, present data normally
        x1 = (-(b) - sqrt(rootValue)) / (2 * a);                                        //calculates first value with quadratic formula
        x2 = (-(b) + sqrt(rootValue)) / (2 * a);                                        //calculates second value with quadratic formula
        cout << "x1 = " << fixed << setprecision(2) << x1 << endl;
        cout << "x2 = " << fixed << setprecision(2) << x2 << endl;
    }
    else if (rootValue < 0){                                                            //if value in sqrt is negative, present data as imaginary number
        xPartOne = (-(b)/ (2 * a));                                                     //calculates first part of quadratic formula
        xPartTwo = (sqrt((4 * a * c) - pow(b,2)) / (2 * a));                            //calculates second part (imaginary number) of quadratic formula
        cout << fixed << setprecision(2) << "x1 = " << xPartOne << " - " << xPartTwo << "i" << endl;    //presents x values as imaginary number using i (split into two parts)
        cout << fixed << setprecision(2) << "x2 = " << xPartOne << " + " << xPartTwo << "i" << endl;
    }
}

void quadraticTable(){                                                  //function gets a, b, and c values for the quadratic eq and makes a table of x and y values
    
    double a, b, c;
    int xmin, xmax;
    
    cout << "Option 2 - Quadratic XY Table" << endl;                    //outputs information and asks user to enter the three values
    cout << "This program will display the x and y values for a given quadratic equation." << endl << endl;
    cout << "Please enter the 'a' value for the quadratic equation: ";
    cin >> a;
    cout << "Please enter the 'b' value for the quadratic equation: ";
    cin >> b;
    cout << "Please enter the 'c' value for the quadratic equation: ";
    cin >> c;
    cout << endl;
    cout << "Please enter the range for x values(integers)." << endl;
    cout << "Enter the minimum x value: ";                              //asks user for the range of values
    cin >> xmin;
    cout << "Enter the maximum x value: ";
    cin >> xmax;
    cout << endl;
    
    formTable(xmin, xmax, a, b, c);                                     //creates a table of x and y values for the given quadratic equation
}

void formTable(int min, int max, double a, double b, double c){         //function forms the xy table from the quadratic equation
    
    double y;
    cout << "Values Table" << endl;
    cout << "------------" << endl;
    cout << setw(5) << left << "X" << "Y" << endl;
    
    for (int i = min; i <= max; i++){                                   //loops formulates xy table based on given range
        cout << setw(5) << left << i;
        y = (a * pow(i,2)) + (b * i) + c;                               //calculates values for quadratic eq and prints out two columns, x and y, respectively
        cout << fixed << setprecision(2) << y << endl;
    }
}

