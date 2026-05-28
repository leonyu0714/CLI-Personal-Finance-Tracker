#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct Transaction{
    string date;
    string type;
    string category;
    double amount;
    string note;
};

class MaxHeap{
private:
    Transaction* data;
    int size;
    int capacity;

    void swapTransaction(Transaction& a, Transaction& b){
        Transaction temp = a;
        a = b;
        b = temp;
    }

    void bubbleUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;

            if(data[index].amount > data[parent].amount){
                swapTransaction(data[index], data[parent]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    void heapifyDown(int index){
        while(true){
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int largest = index;

            if(left < size && data[left].amount > data[largest].amount){
                largest = left;
            }

            if(right < size && data[right].amount > data[largest].amount){
                largest = right;
            }

            if(largest != index){
                swapTransaction(data[index], data[largest]);
                index = largest;
            }
            else{
                break;
            }
        }
    }

public:
    MaxHeap(int capacity){
        this->capacity = capacity;
        this->size = 0;
        data = new Transaction[capacity];
    }

    ~MaxHeap(){
        delete[] data;
    }

    bool isEmpty(){
        return size == 0;
    }

    void add(Transaction transaction){
        if(size >= capacity){
            return;
        }

        data[size] = transaction;
        bubbleUp(size);
        size++;
    }

    Transaction remove(){
        Transaction root = data[0];

        data[0] = data[size - 1];
        size--;

        if(size > 0){
            heapifyDown(0);
        }

        return root;
    }
};

class FinanceTracker{
private:
    Transaction* transactions;
    int size;
    int capacity;

    void resize(){
        capacity *= 2;
        Transaction* newTransactions = new Transaction[capacity];

        for(int i = 0; i < size; i++){
            newTransactions[i] = transactions[i];
        }

        delete[] transactions;
        transactions = newTransactions;
    }

    void loadFromFile(){
        ifstream file("transactions.txt");

        if(!file){
            return;
        }

        string line;

        while(getline(file, line)){
            if(line == ""){
                continue;
            }

            if(size == capacity){
                resize();
            }

            if(line.find('|') != string::npos){
                string amountText;
                stringstream ss(line);

                getline(ss, transactions[size].date, '|');
                getline(ss, transactions[size].type, '|');
                getline(ss, transactions[size].category, '|');
                getline(ss, amountText, '|');
                getline(ss, transactions[size].note);

                transactions[size].amount = stod(amountText);
            }
            else{
                stringstream ss(line);

                ss >> transactions[size].date
                   >> transactions[size].type
                   >> transactions[size].category
                   >> transactions[size].amount;

                transactions[size].note = "";
            }

            size++;
        }

        file.close();
    }

    void saveToFile(){
        ofstream file("transactions.txt");

        for(int i = 0; i < size; i++){
            file << transactions[i].date << "|"
                 << transactions[i].type << "|"
                 << transactions[i].category << "|"
                 << transactions[i].amount << "|"
                 << transactions[i].note << endl;
        }

        file.close();
    }

    void clearFile(){
        ofstream fout("transactions.txt");
        fout.close();
    }

    void swapTransaction(Transaction& a, Transaction& b){
        Transaction temp = a;
        a = b;
        b = temp;
    }

    void sortByDate(){
        for(int i = 0; i < size - 1; i++){
            int minIndex = i;

            for(int j = i + 1; j < size; j++){
                if(transactions[j].date < transactions[minIndex].date){
                    minIndex = j;
                }
            }

            if(minIndex != i){
                swapTransaction(transactions[i], transactions[minIndex]);
            }
        }
    }

    int selectionSortByCategory(){
        int comparisons = 0;

        for(int i = 0; i < size - 1; i++){
            int minIndex = i;

            for(int j = i + 1; j < size; j++){
                comparisons++;

                if(transactions[j].category < transactions[minIndex].category){
                    minIndex = j;
                }
            }

            if(minIndex != i){
                swapTransaction(transactions[i], transactions[minIndex]);
            }
        }

        return comparisons;
    }

    bool isValidType(string type){
        return type == "income" || type == "expense";
    }

    bool isValidDateFormat(string date){
        if(date.length() != 10){
            return false;
        }

        if(date[4] != '-' || date[7] != '-'){
            return false;
        }

        for(int i = 0; i < 10; i++){
            if(i == 4 || i == 7){
                continue;
            }

            if(date[i] < '0' || date[i] > '9'){
                return false;
            }
        }

        return true;
    }

    void printTransactionHeader(){
        cout << left
             << setw(5) << "No."
             << setw(15) << "Date"
             << setw(12) << "Type"
             << setw(15) << "Category"
             << setw(12) << "Amount"
             << "Note" << endl;

        cout << "----------------------------------------------------------------\n";
    }

    void printTransactionRow(int index){
        cout << left
             << setw(5) << index + 1
             << setw(15) << transactions[index].date
             << setw(12) << transactions[index].type
             << setw(15) << transactions[index].category
             << setw(12) << transactions[index].amount
             << transactions[index].note << endl;
    }

    void printTransactionData(int number, Transaction transaction){
        cout << left
             << setw(5) << number
             << setw(15) << transaction.date
             << setw(12) << transaction.type
             << setw(15) << transaction.category
             << setw(12) << transaction.amount
             << transaction.note << endl;
    }

public:
    FinanceTracker(){
        size = 0;
        capacity = 10;
        transactions = new Transaction[capacity];
        loadFromFile();
    }

    ~FinanceTracker(){
        saveToFile();
        delete[] transactions;
    }

    void run(){
        int choice;

        while(true){
            cout << "\n===== CLI Personal Finance Tracker =====\n";
            cout << "1. Add transaction\n";
            cout << "2. Delete transaction\n";
            cout << "3. View all transactions\n";
            cout << "4. Show summary\n";
            cout << "5. Delete all historical data\n";
            cout << "6. Linear search by category\n";
            cout << "7. Binary search by category\n";
            cout << "8. Compare search performance\n";
            cout << "9. Show top K largest expenses\n";
            cout << "10. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice){
                case 1:
                    addTransaction();
                    break;
                case 2:
                    deleteTransaction();
                    break;
                case 3:
                    viewAllTransactions();
                    break;
                case 4:
                    showSummary();
                    break;
                case 5:
                    deleteAllHistoricalData();
                    break;
                case 6:
                    linearSearchByCategory();
                    break;
                case 7:
                    binarySearchByCategory();
                    break;
                case 8:
                    compareSearchPerformance();
                    break;
                case 9:
                    showTopKExpenses();
                    break;
                case 10:
                    return;
                default:
                    cout << "Invalid choice.\n";
            }
        }
    }

    void addTransaction(){
        if(size == capacity){
            resize();
        }

        cout << "\n=== Add Transaction ===\n";

        cout << "Enter date (YYYY-MM-DD): ";
        cin >> transactions[size].date;

        while(!isValidDateFormat(transactions[size].date)){
            cout << "Invalid date format. Please enter again (YYYY-MM-DD): ";
            cin >> transactions[size].date;
        }

        cout << "Enter type (income / expense): ";
        cin >> transactions[size].type;

        while(!isValidType(transactions[size].type)){
            cout << "Invalid type. Please enter only income or expense: ";
            cin >> transactions[size].type;
        }

        cout << "Enter category: ";
        cin >> transactions[size].category;

        cout << "Enter amount: ";
        cin >> transactions[size].amount;

        cin.ignore();

        cout << "Enter note: ";
        getline(cin, transactions[size].note);

        size++;

        saveToFile();

        cout << "Transaction added successfully.\n";
    }

    void deleteTransaction(){
        if(size == 0){
            cout << "\nNo transactions to delete.\n";
            return;
        }

        sortByDate();

        cout << "\n=== Delete Transaction ===\n";
        printTransactionHeader();

        for(int i = 0; i < size; i++){
            printTransactionRow(i);
        }

        int index;

        cout << "\nEnter transaction number to delete: ";
        cin >> index;

        if(index < 1 || index > size){
            cout << "Invalid transaction number.\n";
            return;
        }

        for(int i = index - 1; i < size - 1; i++){
            transactions[i] = transactions[i + 1];
        }

        size--;

        saveToFile();

        cout << "Transaction deleted successfully.\n";
    }

    void viewAllTransactions(){
        if(size == 0){
            cout << "\nNo transactions found.\n";
            return;
        }

        sortByDate();

        cout << "\n=== All Transactions ===\n";
        printTransactionHeader();

        for(int i = 0; i < size; i++){
            printTransactionRow(i);
        }
    }

    void showSummary(){
        double income = 0;
        double expense = 0;

        for(int i = 0; i < size; i++){
            if(transactions[i].type == "income"){
                income += transactions[i].amount;
            }
            else if(transactions[i].type == "expense"){
                expense += transactions[i].amount;
            }
        }

        cout << "\n=== Summary ===\n";
        cout << "Total income: " << income << endl;
        cout << "Total expense: " << expense << endl;
        cout << "Balance: " << income - expense << endl;
    }

    void deleteAllHistoricalData(){
        if(size == 0){
            cout << "\nNo historical data to delete.\n";
            clearFile();
            return;
        }

        string confirm;

        cout << "\n=== Delete All Historical Data ===\n";
        cout << "This will delete all historical transaction data.\n";
        cout << "Type YES to confirm: ";
        cin >> confirm;

        if(confirm != "YES"){
            cout << "Delete all operation cancelled.\n";
            return;
        }

        size = 0;
        clearFile();

        cout << "All historical data deleted successfully.\n";
    }

    void linearSearchByCategory(){
        if(size == 0){
            cout << "\nNo transactions found.\n";
            return;
        }

        string targetCategory;
        int comparisons = 0;
        bool found = false;

        cout << "\n=== Linear Search by Category ===\n";
        cout << "Enter category to search: ";
        cin >> targetCategory;

        cout << "\n=== Search Results ===\n";
        printTransactionHeader();

        for(int i = 0; i < size; i++){
            comparisons++;

            if(transactions[i].category == targetCategory){
                printTransactionRow(i);
                found = true;
            }
        }

        if(!found){
            cout << "No matching transactions found.\n";
        }

        cout << "\nLinear search comparisons: " << comparisons << endl;
    }

    void binarySearchByCategory(){
        if(size == 0){
            cout << "\nNo transactions found.\n";
            return;
        }

        string targetCategory;
        int comparisons = 0;
        bool found = false;

        cout << "\n=== Binary Search by Category ===\n";
        cout << "Enter category to search: ";
        cin >> targetCategory;

        selectionSortByCategory();

        int left = 0;
        int right = size - 1;
        int mid = -1;

        while(left <= right){
            mid = (left + right) / 2;
            comparisons++;

            if(transactions[mid].category == targetCategory){
                found = true;
                break;
            }
            else if(transactions[mid].category < targetCategory){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        cout << "\n=== Search Results ===\n";

        if(found){
            int start = mid;
            int end = mid;

            while(start - 1 >= 0 && transactions[start - 1].category == targetCategory){
                comparisons++;
                start--;
            }

            while(end + 1 < size && transactions[end + 1].category == targetCategory){
                comparisons++;
                end++;
            }

            printTransactionHeader();

            for(int i = start; i <= end; i++){
                printTransactionRow(i);
            }
        }
        else{
            cout << "No matching transactions found.\n";
        }

        cout << "\nBinary search comparisons: " << comparisons << endl;
    }

    void compareSearchPerformance(){
        if(size == 0){
            cout << "\nNo transactions found.\n";
            return;
        }

        string targetCategory;

        cout << "\n=== Compare Search Performance ===\n";
        cout << "Enter category to search: ";
        cin >> targetCategory;

        int linearComparisons = 0;
        int linearMatches = 0;

        for(int i = 0; i < size; i++){
            linearComparisons++;

            if(transactions[i].category == targetCategory){
                linearMatches++;
            }
        }

        int sortComparisons = selectionSortByCategory();

        int binaryComparisons = 0;
        int left = 0;
        int right = size - 1;
        int mid = -1;
        bool found = false;

        while(left <= right){
            mid = (left + right) / 2;
            binaryComparisons++;

            if(transactions[mid].category == targetCategory){
                found = true;
                break;
            }
            else if(transactions[mid].category < targetCategory){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        int binaryMatches = 0;

        if(found){
            int start = mid;
            int end = mid;

            while(start - 1 >= 0 && transactions[start - 1].category == targetCategory){
                binaryComparisons++;
                start--;
            }

            while(end + 1 < size && transactions[end + 1].category == targetCategory){
                binaryComparisons++;
                end++;
            }

            binaryMatches = end - start + 1;
        }

        cout << "\n=== Performance Result ===\n";
        cout << "Target category: " << targetCategory << endl;
        cout << "Total transactions: " << size << endl;
        cout << "Matching transactions: " << linearMatches << endl;

        cout << "\nLinear search comparisons: " << linearComparisons << endl;
        cout << "Selection sort comparisons: " << sortComparisons << endl;
        cout << "Binary search comparisons: " << binaryComparisons << endl;
        cout << "Total cost for sort + binary search: "
             << sortComparisons + binaryComparisons << endl;

        if(linearMatches == 0){
            cout << "\nNo matching transactions found.\n";
        }
    }

    void showTopKExpenses(){
        if(size == 0){
            cout << "\nNo transactions found.\n";
            return;
        }

        int k;

        cout << "\n=== Top K Largest Expenses ===\n";
        cout << "Enter K: ";
        cin >> k;

        if(k <= 0){
            cout << "Invalid K value.\n";
            return;
        }

        MaxHeap heap(size);

        for(int i = 0; i < size; i++){
            if(transactions[i].type == "expense"){
                heap.add(transactions[i]);
            }
        }

        if(heap.isEmpty()){
            cout << "No expense transactions found.\n";
            return;
        }

        cout << "\n=== Top Expenses ===\n";
        printTransactionHeader();

        int count = 0;

        while(!heap.isEmpty() && count < k){
            Transaction top = heap.remove();
            printTransactionData(count + 1, top);
            count++;
        }
    }
};

int main(){
    FinanceTracker tracker;
    tracker.run();

    return 0;
}