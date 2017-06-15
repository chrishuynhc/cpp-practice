//Checkout

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Function Prototypes
bool readInventory(string);
double checkout();
bool updateInventory(string);

struct Product {                                                //data about a product
    int plu;
    string name;
    int salesType;
    double price;
    double inventory;
};

int counter = 0;                                                //holds number of products in file
const int SIZE = 100;
Product **arrayProducts = new Product*[SIZE];                   //dynamic array of pointers to structures
                                                                //holds product info from file
int main() {
   
    char choice;
    
    ifstream input;                                             //opens file and reads in information
    if (readInventory("products.txt") == false){                //if file cannot open, error, exit
        cout << "Error: File could not be opened." << endl;
        exit(0);
    }
                                                                //if file opened, continue
    cout << "Choose an Option Below: " << endl;                 //Presents menu option w/ 2 choices
    cout << "----------------------" << endl;
    cout << "A. Check Out" << endl;                             //choice A: checkout
    cout << "B. Close the store and exit" << endl << endl;      //choice B: exit
    cout << "Enter A or B: ";
    cin >> choice;
    
    if (choice == 'a' || choice == 'A'){                        //if user picks A, run checkout
        checkout();
    }
    else if (choice == 'b' || choice == 'B'){                   //if user picks B, exit
        exit(0);
    }
    updateInventory("products.txt");                            //updates inventory amount of each product after checkout
    return 0;
}

bool readInventory(string filename){                            //function opens file and stores in information to array of pointers to structures

    bool status = false;
    ifstream input;
    input.open(filename);
    
    if (input){
        status = true;
        for (int i = 0; i < 100; i++){
            Product *temp = new Product;                        //loops through each line for each value
            if (input >> temp->plu >> temp->name >> temp->salesType >> temp->price >> temp->inventory){
                counter++;
            }
            arrayProducts[i] = temp;
        }
    } else {
        status = false;
    }
    return status;                                              //returns true if read in successful, false if not
}

double checkout(){                                              //function calculates total cost of items a customer wishes to purchase
    
    int plu = 1;
    double weight, units, price = 0, total = 0;
    string item = "";
    
    while (plu != 0) {
        cout << "Enter the PLU code of your product(0 to checkout): ";                              //asks user for plu number of a product
        cin >> plu;
        if (plu == 0)                                                                               //if plu invalid, try again
            break;
        
        for (int i = 0; i < SIZE; i++){                                                             //if valid plu, loop through each product plu to see a match
            
            if (plu == arrayProducts[i]->plu){                                                      //if match occurs, perform calculations
            
                if (arrayProducts[i]->salesType == 0){                                              //if sales type is based on units
                    cout << "Enter number of units you wish to purchase: ";                         //ask user for number of units
                    cin >> units;
                    if (units < arrayProducts[i]->inventory){
                        price = units * arrayProducts[i]->price;                                    //calculates price by multiplying units and price per unit
                        item.append(arrayProducts[i]->name);
                        item.append("  ");
                        arrayProducts[i]->inventory -= units;                                       //updates inventory depending on how much customer buys
                    } else {
                        while (units > arrayProducts[i]->inventory){                                //validates that there are enough products to purchase, if not, try again
                            cout << "Error: Not enough product in stock. Try again." << endl;
                            cout << "Enter number of units you wish to purchase: ";
                            cin >> units;
                        }
                        price = units * arrayProducts[i]->price;
                        item.append(arrayProducts[i]->name);
                        item.append("  ");
                        arrayProducts[i]->inventory -= units;
                    }
                }
                if (arrayProducts[i]->salesType == 1){                                              //if sales type is based on weight
                    cout << "Enter the weight of product you wish to purchase: ";                   //ask user for weight they wish to purchase
                    cin >> weight;
                    if (weight < arrayProducts[i]->inventory){
                        price = weight * arrayProducts[i]->price;                                   //calculates price by multiplying weight and price per weight
                        item.append(arrayProducts[i]->name);
                        item.append("  ");
                        arrayProducts[i]->inventory -= weight;                                      //updates inventory depending on how much customer buys
                    } else {
                        while (weight > arrayProducts[i]->inventory){                               //validates that there are enough products to purchase, if not, try again
                            cout << "Error: Not enough product in stock. Try again." << endl;
                            cout << "Enter the weight of product you wish to purchase: ";
                            cin >> weight;
                        }
                        price = weight * arrayProducts[i]->price;
                        item.append(arrayProducts[i]->name);
                        item.append("  ");
                        arrayProducts[i]->inventory -= weight;
                    }
                }
            }
        }
        total += price;                                                                             //updates total price
    }
    cout << endl;
    cout << "Summary" << endl;                                                                      //prints out summary of checkout
    cout << "-------" << endl;
    cout << "Items: " << item << endl;                                                              //shows which items customer chose
    cout << "Total Before Discount: $" << fixed << setprecision(2) << total << endl;                //shows total before discount
    if (total > 50){                                                                                //if customer spent over $50
        cout << "~A 5% discount has been applied!~" << endl;
        total -= (.05 * total);
    }
    cout << "Total After Discount: $" << fixed << setprecision(2) << total << endl;             //shows total after discount(if any)
    return total;
}

bool updateInventory(string filename) {                                                     //updates inventory to file
    
    ofstream output;
    output.open(filename);
    
    for (int i = 0; i < counter; i++){                                                      //rewrites file with new information and updated inventory
        output << arrayProducts[i]->plu << " " << arrayProducts[i]->name << " " << arrayProducts[i]->salesType << " " <<
        arrayProducts[i]->price << " " << arrayProducts[i]->inventory << endl;
    }
    return true;
}




















