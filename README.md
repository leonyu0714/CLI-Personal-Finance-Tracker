# CLI Personal Finance Tracker

## Final Report

### 1. Project Description

CLI Personal Finance Tracker is a command-line personal finance management system written in C++.

The program allows users to record daily income and expenses, view transaction history, delete records, calculate financial summaries, search transactions, compare search performance, and find the largest expense records.

The main goal of this project is not only to build a simple finance tracker, but also to demonstrate how data structures and algorithms can be applied in a real program. The project uses dynamic memory allocation, file input/output, sorting, searching, and a heap-based priority structure.

---

### 2. Motivation and Goal

Managing personal financial records is an important daily habit. However, using a spreadsheet or manually editing a text file can be inconvenient for simple daily tracking.

This project provides a lightweight command-line tool that helps users:

- Add income and expense records
- Store records locally in a file
- View all transaction records in date order
- Delete specific transactions
- Clear all historical data
- Search transactions by category
- Compare linear search and binary search performance
- Display the top K largest expenses

The goal is to create a practical program while also applying the data structure and algorithm concepts learned in class.

---

### 3. Features

The final version of the program includes the following functions:

1. **Add transaction**
   - Add a new income or expense record.
   - The user enters date, type, category, amount, and note.
   - The date format is shown as `YYYY-MM-DD`.
   - The transaction type only accepts `income` or `expense`.

2. **Delete transaction**
   - Display all existing transactions.
   - Let the user choose a transaction number to delete.
   - The selected transaction is removed from memory and the data file.

3. **View all transactions**
   - Display all transactions in a formatted table.
   - Transactions are shown in date order.

4. **Show summary**
   - Calculate total income.
   - Calculate total expenses.
   - Calculate the final balance.

5. **Delete all historical data**
   - Remove all transaction records.
   - Clear the saved data file.

6. **Linear search by category**
   - Search transactions by category using linear search.
   - Display all matching records.
   - Show the number of comparisons.

7. **Binary search by category**
   - Sort transactions by category first.
   - Search transactions using binary search.
   - Display all matching records.
   - Show the number of comparisons.

8. **Compare search performance**
   - Compare linear search with binary search.
   - Show linear search comparisons.
   - Show selection sort comparisons.
   - Show binary search comparisons.
   - Show total sort plus binary search cost.

9. **Show top K largest expenses**
   - Use a max heap to find the largest expense records.
   - Display the top K expenses from largest to smallest.

10. **Exit**
   - End the program safely.

---

### 4. Technologies Used

- C++
- Command-line interface
- Object-oriented programming
- Dynamic memory allocation
- File input and output
- Linear search
- Selection sort
- Binary search
- Max heap
- Basic performance analysis

---

### 5. Data Structure Design

Each transaction is stored as a `Transaction` object containing:

```cpp
string date;
string type;
string category;
double amount;
string note;
```

The program stores all transactions in a dynamically allocated array.

```cpp
Transaction* transactions;
```

The array is managed inside the `FinanceTracker` class. When the number of transactions exceeds the current capacity, the program creates a larger dynamic array, copies the old data, and releases the old memory.

This design demonstrates dynamic memory allocation using `new` and `delete[]`.

---

### 6. Class Design

The main class of the project is:

```cpp
class FinanceTracker
```

This class is responsible for:

- Storing transaction records
- Loading data from file
- Saving data to file
- Adding transactions
- Deleting transactions
- Viewing all transactions
- Showing financial summaries
- Performing linear search
- Performing binary search
- Comparing search performance
- Displaying top K largest expenses

The project also uses a separate max heap structure to support the top K expense feature.

```cpp
class MaxHeap
```

The max heap stores expense transactions and removes the largest amount first.

---

### 7. File Storage

The program saves transaction records in a local text file:

```text
transactions.txt
```

Each record is stored in the following format:

```text
date|type|category|amount|note
```

Example:

```text
2026-05-28|expense|food|120|lunch
2026-05-28|income|salary|5000|part-time job
```

When the program starts, it automatically loads existing records from `transactions.txt`.

When the user adds, deletes, or clears records, the file is updated automatically.

The program also supports older space-separated records by loading them with an empty note field.

---

### 8. Algorithms Used

#### 8.1 Linear Search

Linear search checks each transaction one by one until all matching categories are found.

If there are `n` records, the time complexity is:

```text
O(n)
```

Linear search works on unsorted data and does not require preprocessing.

---

#### 8.2 Selection Sort

Before binary search can be used, transactions must be sorted by category.

The program uses selection sort for this step.

Selection sort repeatedly finds the smallest category in the unsorted part and moves it to the correct position.

The time complexity is:

```text
O(n^2)
```

Although selection sort is not the fastest sorting algorithm, it is simple and suitable for demonstrating sorting logic in this project.

---

#### 8.3 Binary Search

Binary search is used after transactions are sorted by category.

It repeatedly compares the target category with the middle element and eliminates half of the search range.

The time complexity is:

```text
O(log n)
```

However, binary search requires sorted data. Therefore, when comparing total cost, the sorting cost should also be considered.

---

#### 8.4 Max Heap

The top K largest expenses function uses a max heap.

A max heap keeps the largest value at the root. In this project, the transaction with the largest expense amount has the highest priority.

Important heap operations:

- Insert expense transaction into heap
- Remove the largest expense from heap
- Repeat K times to display the top K expenses

The time complexity of each heap insertion and removal is:

```text
O(log n)
```

This demonstrates how a priority queue concept can be used to solve a practical problem.

---

### 9. Search Performance Comparison

The project compares two searching methods:

1. Linear search on unsorted data
2. Binary search on sorted data

The program displays:

- Linear search comparisons
- Selection sort comparisons
- Binary search comparisons
- Total sort plus binary search cost

This comparison shows an important idea:

Linear search is simple and does not require sorting, but it may become slower when the number of records increases.

Binary search is much faster after sorting, but sorting itself has an extra cost. Therefore, binary search is more useful when the data is already sorted or when many searches are performed after one sorting process.

In this project, the performance difference between linear search and binary search may not be very obvious when there are only a few transaction records. To observe a clearer difference between the two algorithms, users should enter at least one year of transaction data. With a larger number of records, the comparison function can better demonstrate how linear search, sorting, and binary search behave differently.

---

### 10. Example Menu

When the program runs, the user sees a menu similar to this:

```text
===== CLI Personal Finance Tracker =====
1. Add transaction
2. Delete transaction
3. View all transactions
4. Show summary
5. Delete all historical data
6. Linear search by category
7. Binary search by category
8. Compare search performance
9. Show top K largest expenses
10. Exit
Enter your choice:
```

---

### 11. How to Use

#### Step 1: Compile the program

Use a C++ compiler such as `g++`.

```bash
g++ main.cpp -o finance_tracker
```

#### Step 2: Run the program

```bash
./finance_tracker
```

On Windows, the executable may be run as:

```bash
finance_tracker.exe
```

#### Step 3: Choose a function from the menu

For example, to add a transaction:

```text
Enter date (YYYY-MM-DD): 2026-05-28
Enter type (income/expense): expense
Enter category: food
Enter amount: 120
Enter note: lunch
```

The transaction will be saved automatically.

---

### 12. Testing and Verification

The final program was tested with the following operations:

- Add income records
- Add expense records
- Add notes to transactions
- Reject invalid transaction types
- View all transactions in date order
- Delete a selected transaction
- Delete all historical data
- Save records to `transactions.txt`
- Load records from `transactions.txt`
- Search transactions by category using linear search
- Search transactions by category using binary search
- Compare search performance
- Display top K largest expenses using a max heap

The program successfully performs the required functions and updates the saved file correctly.

---

### 13. Difficulties Encountered

One difficulty was designing the file format. The program needs to save multiple fields for each transaction, including a note that may contain spaces. To solve this problem, the final version uses the `|` symbol as a delimiter.

Another difficulty was comparing linear search and binary search fairly. Binary search is fast, but it requires sorted data first. Therefore, the program shows both the binary search comparisons and the total cost including selection sort.

A third difficulty was managing dynamic memory safely. Since the project uses dynamic arrays, the program must correctly resize arrays and release memory to avoid memory leaks.

---

### 14. What I Learned

Through this project, I learned how to apply data structures and algorithms in a practical program.

I practiced:

- Designing a class-based C++ program
- Using dynamic memory allocation
- Reading from and writing to files
- Formatting command-line output
- Implementing linear search
- Implementing selection sort
- Implementing binary search
- Implementing a max heap
- Comparing algorithm performance
- Organizing a larger C++ project

This project helped me understand that different algorithms have different advantages depending on the situation.

---

### 15. Conclusion

The final version of CLI Personal Finance Tracker successfully combines a practical finance tracking system with data structure and algorithm concepts.

The program allows users to manage transaction records and also demonstrates important computer science ideas such as searching, sorting, heap operations, file storage, object-oriented programming, and dynamic memory allocation.

This project shows how basic data structures and algorithms can be used to build a useful real-world command-line application.