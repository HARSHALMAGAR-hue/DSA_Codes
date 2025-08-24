#include<iostream>
#include<string>
using namespace std;

struct node {
    string data;
    int price;
    int quantity;
    node* next;
};

class cart {
    node* head;
public:
    cart() { head = NULL; }

    void display() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        node* p = head;
        cout << "Items in cart:\n";
        while (p) {
            cout << "Name: " << p->data
                 << ", Price: " << p->price
                 << ", Quantity: " << p->quantity
                 << ", Total: " << (p->price * p->quantity)
                 << endl;
            p = p->next;
        }
        cout << endl;
    }

    void append(string key, int price, int quantity) {
        node* nn = new node;
        nn->data = key;
        nn->price = price;
        nn->quantity = quantity;
        nn->next = NULL;

        if (!head) {
            head = nn;
            return;
        }
        node* p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = nn;
    }

    void remove(string item) {
        node* p1 = head;
        node* p2 = NULL;
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        while (p1 && p1->data != item) {
            p2 = p1;
            p1 = p1->next;
        }
        if (!p1) {
            cout << "Item not found.\n";
            return;
        }
        if (p1 == head) {
            head = head->next;
            delete p1;
            return;
        }
        p2->next = p1->next;
        delete p1;
    }

    void displayByType(string item) {
        node* p = head;
        bool found = false;
        while (p) {
            if (p->data == item) {
                cout << "Name: " << p->data
                     << ", Price: " << p->price
                     << ", Quantity: " << p->quantity
                     << ", Total: " << (p->price * p->quantity) << endl;
                found = true;
            }
            p = p->next;
        }
        if (!found) cout << "No item of type '" << item << "' found.\n";
    }

    int calculateTotal() {
        int total = 0;
        node* p = head;
        while (p) {
            total += p->price * p->quantity;
            p = p->next;
        }
        return total;
    }

    void getBill() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "\n******* Bill *******\n";
        node* p = head;
        while (p) {
            cout << p->data << " x " << p->quantity << " = " << (p->price * p->quantity) << endl;
            p = p->next;
        }
        cout << "---------------------\n";
        cout << "Total: " << calculateTotal() << endl;
    }

    void checkItem(string item) {
        node* p = head;
        while (p) {
            if (p->data == item) {
                cout << "Item found: " << p->data << ", Quantity: " << p->quantity << endl;
                return;
            }
            p = p->next;
        }
        cout << "Item not in cart.\n";
    }

    void emptyCart() {
        node* p = head;
        while (p) {
            node* temp = p;
            p = p->next;
            delete temp;
        }
        head = NULL;
        cout << "Cart emptied successfully.\n";
    }
};

int main() {
    cart mycart;
    int ch;
    do {
        cout << "\n************ Menu ************\n";
        cout << "1. Add item\n";
        cout << "2. Display items\n";
        cout << "3. Remove item\n";
        cout << "4. Display by Type\n";
        cout << "5. Calculate Total cost\n";
        cout << "6. Get Bill\n";
        cout << "7. Check Cart for an item\n";
        cout << "8. Empty Cart\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1: {
            string key; int price, quantity;
            cout << "Enter item to add: "; cin >> key;
            cout << "Enter the price: "; cin >> price;
            cout << "Enter the quantity: "; cin >> quantity;
            mycart.append(key, price, quantity);
            break;
        }
        case 2:
            mycart.display();
            break;
        case 3: {
            string item; cout << "Enter item to remove: "; cin >> item;
            mycart.remove(item);
            break;
        }
        case 4: {
            string item; cout << "Enter item type to display: "; cin >> item;
            mycart.displayByType(item);
            break;
        }
        case 5:
            cout << "Total cost: " << mycart.calculateTotal() << endl;
            break;
        case 6:
            mycart.getBill();
            break;
        case 7: {
            string item; cout << "Enter item to check: "; cin >> item;
            mycart.checkItem(item);
            break;
        }
        case 8:
            mycart.emptyCart();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (ch != 9);

    return 0;
}
