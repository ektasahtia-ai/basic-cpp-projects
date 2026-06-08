#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Expense {
public:
    string category;
    double amount;

    Expense(string c, double a) {
        category = c;
        amount = a;
    }
};

vector<Expense> expenses;

void saveExpenses() {
    ofstream file("expenses.txt");

    for (const auto& expense : expenses) {
        file << expense.category << " " << expense.amount << endl;
    }

    file.close();
}

void loadExpenses() {
    ifstream file("expenses.txt");

    string category;
    double amount;

    while (file >> category >> amount) {
        expenses.push_back(Expense(category, amount));
    }

    file.close();
}

void addExpense() {
    string category;
    double amount;

    cout << "\nEnter Category: ";
    cin >> category;

    cout << "Enter Amount: ";
    cin >> amount;

    expenses.push_back(Expense(category, amount));
    saveExpenses();

    cout << "Expense Added Successfully!\n";
}

void viewExpenses() {
    if (expenses.empty()) {
        cout << "\nNo expenses found.\n";
        return;
    }

    cout << "\n===== Expense List =====\n";
    cout << left << setw(20) << "Category"
         << setw(10) << "Amount" << endl;

    cout << "----------------------------\n";

    for (const auto& expense : expenses) {
        cout << left << setw(20)
             << expense.category
             << setw(10)
             << expense.amount << endl;
    }
}

void totalExpense() {
    double total = 0;

    for (const auto& expense : expenses) {
        total += expense.amount;
    }

    cout << "\nTotal Expenses: ₹" << total << endl;
}

int main() {
    loadExpenses();

    int choice;

    do {
        cout << "\n====== Expense Tracker ======\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Total Expense\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addExpense();
            break;

        case 2:
            viewExpenses();
            break;

        case 3:
            totalExpense();
            break;

        case 4:
            cout << "\nThank You for Using Expense Tracker!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}