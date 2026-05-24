#include <iostream>
#include <string>
using namespace std;

struct Transaction{
    int id;
    string date;
    string type;
    string category;
    int amount;
    string note;
};

void showMenu();
void addTransaction(Transaction*& records, int& size, int& capacity, int& nextId);
void viewTransactions(Transaction* records, int size);
void expandCapacity(Transaction*& records, int& capacity);

int main(){
    Transaction* records = new Transaction[10];
    int size = 0;
    int capacity = 10;
    int nextId = 1;
    int choice = -1;

    while(choice != 0){
        showMenu();
        cin >> choice;

        if(choice == 1){
            addTransaction(records, size, capacity, nextId);
        }
        else if(choice == 2){
            viewTransactions(records, size);
        }
        else if(choice == 3){
            cout << "Search function will be added later.\n";
        }
        else if(choice == 4){
            cout << "Summary function will be added later.\n";
        }
        else if(choice == 0){
            cout << "Program ended.\n";
        }
        else{
            cout << "Invalid choice.\n";
        }

        cout << "\n";
    }

    delete[] records;
    return 0;
}

void showMenu(){
    cout << "===== CLI Personal Finance Tracker =====\n";
    cout << "1. Add transaction\n";
    cout << "2. View all transactions\n";
    cout << "3. Search transactions\n";
    cout << "4. Show summary\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void addTransaction(Transaction*& records, int& size, int& capacity, int& nextId){
    if(size == capacity){
        expandCapacity(records, capacity);
    }

    records[size].id = nextId;
    nextId++;

    cout << "Enter date YYYY-MM-DD: ";
    cin >> records[size].date;

    cout << "Enter type income/expense: ";
    cin >> records[size].type;

    cout << "Enter category: ";
    cin >> records[size].category;

    cout << "Enter amount: ";
    cin >> records[size].amount;

    cin.ignore();

    cout << "Enter note: ";
    getline(cin, records[size].note);

    size++;

    cout << "Transaction added successfully.\n";
}

void viewTransactions(Transaction* records, int size){
    if(size == 0){
        cout << "No transactions found.\n";
        return;
    }

    cout << "ID | Date | Type | Category | Amount | Note\n";
    cout << "--------------------------------------------------\n";

    for(int i = 0; i < size; i++){
        cout << records[i].id << " | ";
        cout << records[i].date << " | ";
        cout << records[i].type << " | ";
        cout << records[i].category << " | ";
        cout << records[i].amount << " | ";
        cout << records[i].note << "\n";
    }
}

void expandCapacity(Transaction*& records, int& capacity){
    int newCapacity = capacity * 2;
    Transaction* temp = new Transaction[newCapacity];

    for(int i = 0; i < capacity; i++){
        temp[i] = records[i];
    }

    delete[] records;
    records = temp;
    capacity = newCapacity;
}
