# CLI Personal Finance Tracker

## Motivation and Goal

This project aims to build a command-line personal finance tracker that helps users record daily income and expenses.

The goal is to provide a simple and efficient tool for managing personal financial records, searching past transactions, sorting records, and analyzing spending habits. In addition to implementing basic finance tracking functions, this project will also compare different data structures and algorithms used in the record searching process.

For example, the prototype will compare linear search on unsorted transaction records with binary search on sorted transaction records. By measuring and comparing their execution time under different numbers of records, the project can analyze how different algorithm choices affect search performance.

## Expected Features

- Add income or expense records
- Delete or modify existing records
- Search records by date, category, or keyword
- Sort records by date or amount
- Show financial summaries such as total income, total expenses, and balance
- Save data to files and load data from files
- Compare the performance of different search methods

## Prototype Expected Verification

The prototype is expected to verify the following functions:

- Users can add income and expense records through the command-line interface.
- Users can view all existing financial records.
- Users can search records by date, category, or keyword.
- Users can sort records by date or amount.
- Users can save records to a file and load records from a file.
- The system can compare at least two searching methods, such as linear search and binary search, and display their execution time.
- The system can demonstrate how the number of records affects search performance.

## Competitive Analysis

There are already many tools for personal finance tracking, such as spreadsheet software, mobile finance apps, and simple text-based record keeping. However, this project focuses on a command-line interface and data-structure-based implementation.

Compared with spreadsheet software such as Excel or Google Sheets, this project provides a more structured way to store and manage financial records. Users do not need to manually design tables or formulas. The program can directly provide searching, sorting, and summary functions.

Compared with mobile finance apps, this project is simpler and more suitable for users who prefer lightweight tools. It does not require an account, internet connection, or complex user interface. The data can be stored locally through files.

Compared with simple text files, this project provides better organization and retrieval. Instead of manually reading and editing raw text, users can use commands to add, search, sort, and analyze records.

The main difference of this project is that it not only provides finance tracking functions, but also demonstrates how different data structures and algorithms affect actual program performance.

## Technologies / Programming Language

- C++
- Command-line interface
- File input and output
- Object-oriented programming
- Dynamic memory allocation
- Searching algorithms
- Sorting algorithms

## Related Data Structures / Algorithms

This project may involve the following concepts:

- Dynamic array: used to store multiple financial records.
- Structures / classes: used to organize each financial record clearly.
- Linear search: used to search records in an unsorted list.
- Binary search: used to search records after sorting by a specific key.
- Sorting algorithms: used to arrange records by date or amount.
- File handling: used to store records persistently for future use.

The main algorithm comparison in this project will focus on searching transaction records. Linear search has a time complexity of O(n), while binary search has a time complexity of O(log n) after the records are sorted. The prototype will compare these methods using different input sizes and show the performance difference.
