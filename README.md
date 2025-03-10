# INET 3101 Lab2 - Memory and Structure
# Author: Tswjkeng Lee

## Description:
This program manages an in-memory database of part records using dynamic memory allocation in C. Each record stores a part number, part name, part size, part size metric, and part cost. The database grows or shrinks as records are added or deleted. Additionally, the program tracks the number of modifications made to the database (adds or deletes) using a static counter.

## Menu Options:
1. Print all records  
   - Displays every record stored in the database, showing part number, name, size, metric, and cost.  
   - If no records exist, an appropriate message is displayed.

2. Add a record  
   - Prompts the user for values for part number, part name, part size, part size metric, and part cost.  
   - Dynamically allocates additional memory to store the new record and prints a confirmation message.

3. Delete the last record  
   - Removes the last record from the database.  
   - Reallocates memory accordingly to prevent memory leaks and confirms the deletion.

4. Print number of records  
   - Displays the current count of records stored in the database.

5. Print database size  
   - Displays the total size of the database in bytes, calculated as the number of records multiplied by the size of a record.

6. Print number of changes  
   - Uses a static variable to track the total number of modifications (adds or deletes) made to the database.  
   - Accepts an integer parameter:  
     - 1: prints the total number of changes  
     - 0: increments the change counter

7. Exit  
   - Exits the program after freeing all allocated memory.

## Functions and Their Behavior:
void printAllRecords()
  - Input: None  
  - Output: Prints all records stored in the database or a message if there are no records.  
  - Description: Iterates over the dynamic array to display each record’s details.

void addRecord()
  - Input: User inputs values for:
      • Part number (integer)
      • Part name (string)
      • Part size (float)
      • Part size metric (string)
      • Part cost (float)
  - Output: Prints a confirmation message that the record has been added.
  - Description: Uses realloc() to dynamically increase the size of the database, then adds the new record.

void deleteRecord()
  - Input: None  
  - Output: Prints a confirmation message upon deleting the last record.
  - Description: Reduces the size of the database by one record using realloc() and frees unused memory.

void printNumRecords()
  - Input: None  
  - Output: Displays the current number of records.
  - Description: Simply outputs the record counter.

void printDatabaseSize()
  - Input: None  
  - Output: Displays the total database size in bytes.
  - Description: Calculates the memory footprint using sizeof() multiplied by the number of records.

int printNumChanges(int print)
  - Input: An integer (1 for print, 0 for increment)
  - Output: If print is 1, prints the total number of database modifications.  
            If 0, increments the modification counter.
  - Description: Tracks the number of changes (additions or deletions) using a static variable.

## Files in the Project:
1. Lab2.c  
   - The main source file containing the full program logic and function definitions.

2. README.txt  
   - This design document explaining how the program works and its features.

## Compilation:
Compile the program using the gcc compiler:
    gcc Lab2.c -o lab2

Example usage:
    ./lab2
