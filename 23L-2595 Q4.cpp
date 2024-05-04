#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
   int id;
   string name;
   int discount;
public:
   Customer() {}
   Customer(int id, string name, int discount) {
       this->id = id;
       this->name = name;
       this->discount = discount;
   }
   int getId() {
       return id;
   }
   string getName() {
       return name;
   }
   int getDiscount() {
       return discount;
   }
   void setDiscount(int discount) {
       this->discount = discount;
   }
   string toString() {
       return "Customer [ID: " + to_string(id) + ", Name: " + name + ", Discount: " + to_string(discount) + "%]";
   }
};


class Invoice {
private:
   int id;
   Customer* customer;
   double amount;

public:
   Invoice(int id, Customer* customer, double amount) {
       this->id = id;
       this->customer = customer; 
       this->amount = amount;
   }

   ~Invoice() {    }

   int getId() {
       return id;
   }

   Customer* getCustomer() {
       return customer;
   }

   void setCustomer(Customer* customer) {
       this->customer = customer;
   }

   double getAmount() {
       return amount;
   }

   void setAmount(double amount) {
       this->amount = amount;
   }

   double getAmountAfterDiscount() {
       return amount - (amount * customer->getDiscount() / 100.0);
   }

   string toString() {
       return "Invoice [ID: " + to_string(id) + ", Customer: " + customer->getName() + ", Amount: $" + to_string(amount) + "]";
   }
};

int main() {
   int customerId, customerDiscount;
   string customerName;
   cout << "Enter Customer ID: ";
   cin >> customerId;
   cout << "Enter Customer Name: ";
   cin.ignore();
   getline(cin, customerName);
   cout << "Enter Customer Discount (%): ";
   cin >> customerDiscount;

   Customer* customer = new Customer(customerId, customerName, customerDiscount); 

   int invoiceId;
   double invoiceAmount;
   cout << "\nEnter Invoice ID: ";
   cin >> invoiceId;
   cout << "Enter Invoice Amount: $";
   cin >> invoiceAmount;

   Invoice invoice(invoiceId, customer, invoiceAmount);

   cout << "\nCustomer Details:\n";
   cout << customer->toString() << endl;

   cout << "\nInvoice Details:\n";
   cout << invoice.toString() << endl;
   cout << "Amount after discount: $" << invoice.getAmountAfterDiscount() << endl;

   delete customer; 

   return 0;
}
