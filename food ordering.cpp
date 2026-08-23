#include <iostream>
using namespace std;

int main() {
    int choice, quantity;
    float total = 0;

    do {
        cout << "\n===== FOOD ORDERING SYSTEM =====\n";
        cout << "1. Pizza - Rs. 200\n";
        cout << "2. Burger - Rs. 100\n";
        cout << "3. Pasta - Rs. 150\n";
        cout << "4. Coke - Rs. 50\n";
        cout << "5. Checkout\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter quantity: ";
            cin >> quantity;
        }

        switch (choice) {
            case 1:
                total += 200 * quantity;
                cout << "Pizza added!\n";
                break;

            case 2:
                total += 100 * quantity;
                cout << "Burger added!\n";
                break;

            case 3:
                total += 150 * quantity;
                cout << "Pasta added!\n";
                break;

            case 4:
                total += 50 * quantity;
                cout << "Coke added!\n";
                break;

            case 5:
                cout << "\n===== BILL =====\n";
                cout << "Total Amount: Rs. " << total << endl;
                cout << "Thank you for ordering!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}