
/*
   - Algorithms
     - List of steps to solve a problem
   - Control Structures
     - A programming construct that dictates the order in which code instructions are executed
   - Data Structures
     - A specialized format for organizing, processing, retrieving, and storing data in a computer
*/

/*
  Invoice
  - invoiceID
  - First Name
  - Last Name
  - Item
  - Unit Cost
  - Quantity
*/

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

// constants
const int MAX_INVOICES = 100;

// structs
struct Invoice {
    int invoiceID;
    string customerFirst;
    string customerLast;
    string itemDescription;
    double itemCost;
    int quantity;
};

// functions
void readInvoices(Invoice inv[], int &num);
void newInvoice(Invoice inv[], int &num);
void printInvoices(const Invoice inv[], int num);
void sortByLastName(Invoice inv[], int num);
double findTotalCost(Invoice inv);

int main() {
    Invoice invoice[MAX_INVOICES];
    int numInvoices = 0;

    // print invoices
    readInvoices(invoice, numInvoices);
    printInvoices(invoice, numInvoices);

    // add new invoice
    cout << endl;
    cout << "New Invoice" << endl;
    cout << "-----------" << endl;
    newInvoice(invoice, numInvoices);

    // sort invoices by last name
    sortByLastName(invoice, numInvoices);
    cout << endl;
    cout << " Sorted" << endl;
    printInvoices(invoice, numInvoices);
    
return 0;
}

// Function: findTotalCost
double findTotalCost(Invoice inv) {
    const double FLORENCE_TAX_RATE = 0.095;
    double total = 0;

    total = inv.itemCost * inv.quantity;
    total *= (1 + FLORENCE_TAX_RATE);

return total;
}

// Function: newInvoice
void newInvoice(Invoice inv[], int &num) {

    cout << "Invoice ID: ";
    cin >> inv[num].invoiceID;
    
    cout << "Customer First Name: ";
    cin >> ws;
    getline(cin, inv[num].customerFirst);

    cout << "Customer Last Name: ";
    getline(cin, inv[num].customerLast);

    cout << "Item Description: ";
    getline(cin, inv[num].itemDescription);

    cout << "Item Cost: ";
    cin >> inv[num].itemCost;

    cout << "Quantity: ";
    cin >> inv[num].quantity;

    num++;
}

// Function: readInvoices
void readInvoices(Invoice inv[], int &num) {
    num = 0;
    ifstream inFile("invoices.txt");
    inFile >> inv[num].invoiceID;
    while (!inFile.eof()) {
        inFile >> ws; // ignore whitespace
        getline(inFile, inv[num].customerFirst);
        getline(inFile, inv[num].customerLast);
        getline(inFile, inv[num].itemDescription);
        inFile >> inv[num].itemCost;
        inFile >> inv[num].quantity;
        num++;
        inFile >> inv[num].invoiceID;
    }
    inFile.close();
}

// Function: printInvoices
void printInvoices(const Invoice inv[], int num) {
    cout << "Invoices" << endl;
    cout << "--------" << endl << endl;
    for (int i = 0; i < num; i++) {
        cout << setw(6) << inv[i].invoiceID << " ";
        cout << setw(10) << left << inv[i].customerFirst;
        cout << setw(12) << inv[i].customerLast;
        cout << setw(12) << inv[i].itemDescription;
        cout << setw(10) << right << setprecision(2) << fixed << inv[i].itemCost;
        cout << setw(6) << inv[i].quantity;
        cout << setw(8) << findTotalCost(inv[i]);
        cout << endl;
    }
}

void sortByLastName(Invoice inv[], int num) {
    int minIndex = 0;
    Invoice temp;

    for (int i = 0; i < num - 1; i++) {
        minIndex = i;
        for (int j = 1 + i; j < num; j++) {
            if (inv[j].customerLast < inv[minIndex].customerLast) {
                minIndex = j;
            }
        }
        temp = inv[i];
        inv[i] = inv[minIndex];
        inv[minIndex] = temp;
    }
}
