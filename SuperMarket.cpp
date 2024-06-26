#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct storeitem {
    string name;
    int id;
    int price;
    int quantity;
    string expirationdate;
};

struct customeritem {
    string name;
    int quantity;
};

class product {
public:
    vector<storeitem> items;

    void additem(int id,  string& name, int price, int quantity,  string& expirationdate) {
        storeitem item{name, id, price, quantity, expirationdate};
        items.push_back(item);
    }

    void DisplayList() {
        if (items.size() > 0) {
            for (int i = 0; i < items.size(); ++i) {
                cout << i + 1 << ".  " << "id: " << items[i].id << "  "
                     << "name: " << items[i].name << "  "
                     << "price: " << items[i].price << "  "
                     << "quantity: " << items[i].quantity << "  "
                     << "expirationdate: " << items[i].expirationdate << endl;
            }
        } else {
            cout << "ERROR: no product available." << endl;
        }
    }
};

class order {
private:
    string cusname;
    vector<customeritem> cusitems;

public:
    void additem(product& prod) {
        cout << "Enter customer name: ";
        cin >> cusname;
        cout << cusname << ", please enter the product name you want to buy: " << endl;
        prod.DisplayList();

        string prodname;
        int quantity;
        cout << "Enter product name: ";
        cin >> prodname;
        cout << "Enter quantity: ";
        cin >> quantity;

        bool found = false;
        for (auto& item : prod.items) {
            if (item.name == prodname) {
                if (item.quantity >= quantity) {
                    item.quantity -= quantity;
                    customeritem cusitem{prodname, quantity};
                    cusitems.push_back(cusitem);
                    found = true;
                    cout << "Order added successfully!" << endl;
                } else {
                    cout << "Not enough quantity available." << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "Product not found." << endl;
        }
    }

    void DisplayOrder() {
        if (cusitems.size() > 0) {
            cout << "Customer name: " << cusname << endl;
            for (int i = 0; i < cusitems.size(); ++i) {
                cout << i + 1 << ". " << "Product name: " << cusitems[i].name << "  "
                     << "Quantity: " << cusitems[i].quantity << endl;
            }
        } else {
            cout << "No orders available." << endl;
        }
    }
};

int main() {
    product p1;
    order o1;
    char choice;

    while (choice != '5') {
        cout << endl << "Grocery Store Management System";
        cout << endl << "1. Add Product " << endl;
        cout << "2. Create Order " << endl;
        cout << "3. Display All Products" << endl;
        cout << "4. Display All Orders" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice) {
            case '1': {
                
                int choose;
                string NameProduct, ExpirationDate;
                int Id, Price, Quantity;
                cout << "1. Perishable" << endl << "2. Imperishable" << endl << "Choose your option: " << endl;
                cin >> choose;
                cout << "Enter the NameProduct: " << endl;
                cin >> NameProduct;
                cout << "Enter the product Id: ";
                cin >> Id;
                cout << "Enter the product Price: ";
                cin >> Price;
                cout << "Enter the product Quantity: ";
                cin >> Quantity;
                if (choose == 1) {
                    cout << "Enter the product ExpirationDate: ";
                    cin >> ExpirationDate;
                } else {
                    ExpirationDate = "N/A";
                }
                p1.additem(Id, NameProduct, Price, Quantity, ExpirationDate);
                break;
            }
            case '2': {
                o1.additem(p1);
                break;
            }
            case '3': {
                p1.DisplayList();
                break;
            }
            case '4': {
                o1.DisplayOrder();
                break;
            }
            case '5': {
                cout << "EXIT." << endl;
                break;
            }
            default: {
                cout << "Invalid Choice!" << endl;
                cout << "Please Choose Again" << endl;
            }
        }
    }
    return 0;
}
