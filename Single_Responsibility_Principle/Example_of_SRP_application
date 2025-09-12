#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string customerName;
    double amount;

public:
    Invoice(string name, double amt) : customerName(name), amount(amt) {}

    //هنا اول مسئوليه حساب الضرايب 
    double calculateTax() {
        return amount * 0.14; // 14% tax
    }

    //المسئوليه الثانيه طباعه 
    void printInvoice() {
        cout << "Invoice for " << customerName << endl;
        cout << "Amount: " << amount << endl;
        cout << "Tax: " << calculateTax() << endl;
    }

    // الثالثه حفظ في قاعده البيانات
    void saveToDatabase() {
        cout << "Saving invoice to database..." << endl;
    }
};

int main() {
    Invoice invoice("Ali", 1000);
    invoice.printInvoice();
    invoice.saveToDatabase();
}

//<----------------------------------Solution with SRP-------------------------------->


#include <iostream>
#include <string>
using namespace std;

// مسؤولية: إدارة بيانات الفاتورة لوحدها
class Invoice {
private:
    string customerName;
    double amount;

public:
    Invoice(string name, double amt) : customerName(name), amount(amt) {}
    string getCustomerName() { return customerName; }
    double getAmount() { return amount; }
};

// مسؤولية: حساب الضريبة لوحدها
class TaxCalculator {
public:
    double calculateTax(double amount) {
        return amount * 0.14; // 14% tax
    }
};

// مسؤولية: الطباعة لوحدها
class InvoicePrinter {
public:
    void printInvoice(Invoice& invoice, TaxCalculator& taxCalc) {
        cout << "Invoice for " << invoice.getCustomerName() << endl;
        cout << "Amount: " << invoice.getAmount() << endl;
        cout << "Tax: " << taxCalc.calculateTax(invoice.getAmount()) << endl;
    }
};

// مسؤولية: التعامل مع قاعدة البيانات لوحدها
class InvoiceRepository {
public:
    void saveToDatabase(Invoice& invoice) {
        cout << "Saving invoice for " << invoice.getCustomerName()
             << " to database..." << endl;
    }
};

int main() {
    Invoice invoice("Ali", 1000);
    TaxCalculator taxCalc;
    InvoicePrinter printer;
    InvoiceRepository repo;

    printer.printInvoice(invoice, taxCalc);
    repo.saveToDatabase(invoice);
}
