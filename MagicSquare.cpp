#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//Function Prototypes
int askSize();
void makeSquare(int);

int main(){
    
    int size;
    
    do {                                                        //loop allows for multiple squares until user enters 0
        size = askSize();                                       //asks user for square size
        makeSquare(size);                                       //creates the appropriate magic square and outputs the magic sum
    } while (size);

    return 0;
}

void makeSquare(int size)                                       //function creates the magic square based on the inputted size
{
   
    int magicSquare[size][size];                                //creates a array to hold the magic square numbers
    int sizeSqr = size * size;
    int i=0, j=size/2;                                          //specifies where the first number is located
    int magicSum = 0;                                           //initializes the magic sum to 0
    
    for (int k = 1; k <= sizeSqr; k++)                          //loops through each number, starting at 1, until it reaches the max number
    {
        magicSquare[i][j] = k;                                  //places first number in the top row, center column
        
        i--;
        j++;
        
        if (k % size == 0)                                      //moves to the next spot (up and to the right)
        {
            i += 2;                                             //if the next spot is already taken, moves down one spot
            --j;
        }
        else                                                    //if the spot goes beyond the square, wraps around to the opposite side
        {
            if (j == size)
                j -= size;
            else if (i < 0)
                i += size;
        }
    }
    
    for (int i = 0; i < size; i++){                             //prints out the magic square
        for (int j = 0; j < size; j++){
            cout << setw(4) << left << magicSquare[i][j];
        }
        cout << endl;
        magicSum += magicSquare[i][j];                          //adds up the values in a row and finds the magic sum
    }
    
    cout << "Magic Sum: " << magicSum;                          //outputs the magic sum
    cout << endl << endl;
}

int askSize(){                                                  //Function asks user for table size
    
    int size;
    
    cout << "Enter an odd number greater than or equal to 3 (Enter 0 to exit): ";
    cin >> size;
    
    if (size == 0)                                              //if user enters 0, program exits
        exit(0);
    
    while (size % 2 == 0 || size < 3){                          //if user enters invalid number, asks to try again
        if (size == 0)
            exit(0);
        cout << "Sorry, that is an invalid number.  Try Again." << endl;
        cout << "Enter an odd number greater than or equal to 3 (Enter 0 to exit): ";
        cin >> size;
    }
    
    cout << endl;
    return size;                                                //returns the valid size entered
}

