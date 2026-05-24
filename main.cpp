#include <iostream>
using namespace std;

void showMenu();

int main(){
    int choice = -1;

    while(choice != 0){
        showMenu();
        cin >> choice;

        if(choice == 1){
            cout << "Add transaction function\n";
        }
        else if(choice == 2){
            cout << "View all transactions function\n";
        }
        else if(choice == 3){
            cout << "Search transactions function\n";
        }
        else if(choice == 4){
            cout << "Summary function\n";
        }
        else if(choice == 0){
            cout << "Program ended.\n";
        }
        else{
            cout << "Invalid choice.\n";
        }

        cout << "\n";
    }

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
