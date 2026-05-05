# CLI Personal Finance Tracker

## Proposal Report

### Motivation and Goal

This project aims to build a command-line personal finance tracker that helps users record daily income and expenses.

The goal is to provide a simple and efficient tool for managing personal financial records, including adding records, searching past transactions, sorting records, and analyzing spending habits.

In addition to basic finance tracking functions, this project will include at least one function flow that compares different data structures or algorithms. The main comparison will focus on transaction searching. The system will compare linear search on unsorted records with binary search on sorted records, and analyze their performance under different numbers of transaction records.

### Competitive Analysis

There are already many tools for personal finance tracking, such as spreadsheet software, mobile finance apps, and simple text-based record keeping.

Compared with spreadsheet software such as Excel or Google Sheets, this project provides a more structured way to manage financial records. Users do not need to manually design tables, formulas, or filters. The program can directly provide adding, searching, sorting, and summary functions through commands.

Compared with mobile finance apps, this project is simpler and more lightweight. It does not require an account, internet connection, or a complex graphical user interface. The data can be stored locally through files.

Compared with simple text files, this project provides better organization and retrieval. Instead of manually reading and editing raw text, users can use commands to add, search, sort, and analyze records.

The main difference of this project is that it not only provides finance tracking functions, but also demonstrates how different data structures and algorithms affect actual program performance.

### Expected Features

- Add income or expense records
- Delete or modify existing records
- Search records by date, category, or keyword
- Sort records by date or amount
- Show financial summaries such as total income, total expenses, and balance
- Save data to files and load data from files
- Compare the performance of different search methods

### Technologies

- C++
- Command-line interface
- File input and output
- Object-oriented programming
- Dynamic memory allocation
- Searching algorithms
- Sorting algorithms

### Prototype Expected Verification

The prototype is expected to verify the following functions:

- Users can add income and expense records through the command-line interface.
- Users can view all existing financial records.
- Users can search records by date, category, or keyword.
- Users can sort records by date or amount.
- Users can save records to a file and load records from a file.
- The system can compare at least two searching methods, such as linear search and binary search.
- The system can display or report the execution time of different search methods.
- The system can demonstrate how the number of records affects search performance.

## Prototype Report

### Current Progress

The project proposal and README structure have been revised according to the required template.

The current design of the system includes a command-line menu that allows users to manage financial records. Each transaction record will contain information such as type, date, category, amount, and description.

The planned data storage method is to use a dynamically allocated array to store multiple transaction records. The program will also include file input and output so that records can be saved and loaded between executions.

The prototype will focus on implementing the basic record management functions first, including adding records, viewing records, searching records, sorting records, and saving/loading records.

### Difficulties Encountered

One difficulty is deciding how to organize transaction records so that the program can support both basic record management and algorithm performance comparison.

Another difficulty is designing a fair comparison between different searching methods. For example, linear search can be directly applied to unsorted records, but binary search requires the records to be sorted first. Therefore, the prototype needs to clearly separate the sorting process and the searching process when comparing their performance.

File input and output also need to be carefully designed so that the saved data can be correctly loaded back into the program.

### Next Step

The next step is to implement the basic transaction record structure and the main command-line menu.

After that, the project will implement the add, view, search, sort, and summary functions. Then, file saving and loading will be added.

Finally, the prototype will include a performance comparison function. This function will generate or load different numbers of transaction records and compare the execution time of linear search and binary search. The result will be used to explain how different algorithms affect actual program performance.

## Final Report

### Project Description

To be completed after the prototype is finished.

### Usage

To be completed after the prototype is finished.
