
/*
   - Algorithms
     - List of steps to solve a problem
   - Control Structures
     - The order that code is executed
     - A programming construct that dictates the order in which code instructions are executed
   - Data Structures
     - ...
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
#include <iostream>
using namespace std;

const int MAX_INVOICES = 100;

struct Invoice {
    int invoiceID;
    string customerFirst;
    string customerLast;
    string itemDescription;
    double itemCost;
    int quantity;

};

void readInvoices(Invoice inv[], int &num);
void printInvoices(const Invoice inv[], int num);

int main() {
    Invoice invoice[MAX_INVOICES];
    int numInvoices = 0;

    readInvoices(invoice, numInvoices);
    printInvoices(invoice, numInvoices);
    
return 0;
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
        cout << inv[i].invoiceID << " |  ";
        cout << inv[i].customerFirst << " | ";
        cout << inv[i].customerLast << " | ";
        cout << inv[i].itemDescription << " | ";
        cout << "$" << inv[i].itemCost << " | ";
        cout << inv[i].quantity << " | ";
        cout << endl;
    }

}
