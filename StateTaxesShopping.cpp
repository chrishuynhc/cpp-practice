#include <iostream>
#include <iomanip>
using namespace std;

float calcCost(string, float, int, float);          //function prototypes
void determineState(float, float, string, string);

int main() {
    
    float unitPrice, taxFirst, taxSecond;
    int numberOfItems;
    string nameFirst, nameSecond;
    
    cout << "Enter the unit price of the item and the number of items you wish to purchase(separated by a space): ";    //displays and asks user to input unit item prices and amount of items to purchase
    cin >> unitPrice >> numberOfItems;
    
    cout << "Enter the name of the first state and its tax rate(separated by a space): ";       //displays and asks user to input a state and its tax rate
    cin >> nameFirst >> taxFirst;
    
    cout << "Enter the name of the second state and its tax rate(separated by a space): ";      //displays and asks user to input another state and its tax rate
    cin >> nameSecond >> taxSecond;
    
    cout << endl;
    cout << "Unit Price: $" << fixed << setprecision(2) << unitPrice << endl;                   //displays a summary of information user inputted
    cout << "Number of Items: " << numberOfItems << endl;                                       //
    cout << "First State and Tax Amount: " << nameFirst << " " << taxFirst << endl;             //
    cout << "Second State and Tax Amount: " << nameSecond << " " << taxSecond << endl << endl;  //
    
    float firstTotal = calcCost(nameFirst, taxFirst, numberOfItems, unitPrice);                 //calculates total amount for the first state
    float secondTotal = calcCost(nameSecond, taxSecond, numberOfItems, unitPrice);              //calculates total amount for the second state
    
    determineState(firstTotal, secondTotal, nameFirst, nameSecond);                             //determines which state has a lower total and tells shopper to shop there
    
    return 0;
}

float calcCost(string state, float tax, int units, float price){                                //calculates cost for each state by multiplying unit price by the amount of units total
    
    float cost = units * price;
    float total = cost * tax;
    return total;
}

void determineState(float first, float second, string firstState, string secondState){          //determines which state has a lower total by comparing the total costs with eachother
    
    if (first < second)
        cout << "You should shop in " << firstState << "." << endl;
    else if (first > second)
        cout << "You should shop in " << secondState << "." << endl;
    else if (first == second)
        cout << "You can shop in either state." << endl;
}





