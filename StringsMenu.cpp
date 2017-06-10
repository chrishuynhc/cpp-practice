#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void sumDigits(string);                                                             //Function Prototypes
void sumCons(string);
void sumVowels(string);
void sumWhite(string);

int main(){
    
    char choice;
    string input;
    
    cout << "Function Menu" << endl;                                                //Outputs menu with 4 option
    cout << "_____________" << endl << endl;
    cout << "A. Sum digits" << endl;                                                //Option 1 - sums digits in string
    cout << "B. Count consonants" << endl;                                          //Option 2 - total consonants in string
    cout << "C. Count vowels" << endl;                                              //Option 3 - total vowels in string
    cout << "D. Count whitespace" << endl << endl;                                  //Option 4 - total whitespace in string
    cout << "Choose from the above menu (A,B,C,or D): ";
    cin >> choice;
    
    while (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' &&      //If choice not valid, try again
           choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd'){
        cout << "Sorry, that is an invalid choice.  Try again." << endl;
        cout << "Choose from the above menu (A,B,C,or D): ";
        cin >> choice;
    }
    cout << "Please enter a string: ";                                              //after choosing option, user asked to input string
    cin.ignore();
    getline(cin, input);
    
    for (int i = 0; i < input.size(); i++){                                         //converts string to all lowercase
        tolower(input[i]);
    }
   
    if (choice == 'A' || choice == 'a'){                                            //if choice A was chosen, sum digits
        sumDigits(input);
    }
    else if (choice == 'B' || choice == 'b'){                                       //if choice B was chosen, find total consonants
        sumCons(input);
    }
    else if (choice == 'C' || choice == 'c'){                                       //if choice C was chosen, find total vowels
        sumVowels(input);
    }
    else if (choice == 'D' || choice == 'd'){                                       //if choice D was chosen, find total whitespace
        sumWhite(input);
    }
    
    return 0;
}

void sumDigits(string input){                                                       //function adds together the digits within the string
    int total = 0;
    
    for (int i = 0; i < input.size(); i++){                                         //sorts through each character in string
        if (isdigit(input[i])){                                                     //if character is a number, add to running total
            total += input[i] - '0';
        }
    }
    cout << "Sum of Digits: " << total << endl;                                     //outputs sum of digits
}
void sumCons(string input){                                                         //function finds total number of consonants within the string
    int total = 0;
    
    for (int i = 0; i < input.size(); i++){                                         //sorts through each character within the string
        if (isalpha(input[i]) && input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && (input[i] != 'o') && input[i] != 'u'){
            total += 1;                                                             //if the character is a letter and not a vowel, add one to the running total
        }
    }
    cout << "Number of Consonants: " << total << endl;                              //outputs total number of consonants
}
void sumVowels(string input){                                                       //function finds total number of vowels within the string
    int total = 0;
    
    for (int i = 0; i < input.size(); i++){                                         //sorts through each character in the string
        if (isalpha(input[i]) && (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'y')){
            total += 1;                                                             //if the character is a letter and also a vowel, add one to the running total
        }
    }
    cout << "Number of Vowels: " << total << endl;                                  //outputs total number of vowels
}

void sumWhite(string input){                                                        //function finds total number of whitespaces within the string
    int total = 0;
    
    for (int i = 0; i < input.size(); i++){                                         //sorts through each character in the string
        if (isspace(input[i])){                                                     //if a whitespace is found, add one to the running total
            total += 1;
        }
    }
    cout << "Number of Whitespace: " << total + 1 << endl;                          //outputs total whitespaces (accounts for ignored whitespace method)
}
