# CS 300: Data Structures and Algorithms — Course Planner Portfolio Artifact

## Overview

This repository contains a portfolio artifact demonstrating my understanding of data structures and algorithmic design. The project is a command-line Course Planner implemented in C++. It reads course information from an external text file, stores the information in a Binary Search Tree (BST), and allows users to display courses in alphanumeric order or search for an individual course and its prerequisites.

## Problem Solved

The main objective of this project was to develop a program that could organize Computer Science course information and make it easier for an academic advisor or student to retrieve course details. The program needed to load course records, store course numbers and titles, manage prerequisites, display an alphabetized course list, and search for individual courses.

The software requirements included the ability to:

1. Read comma-separated course information from an external file.
2. Store course information in a suitable data structure.
3. Display the complete course list in alphanumeric order.
4. Retrieve an individual course and display its title and prerequisites.
5. Handle invalid input and course records without terminating unexpectedly.

## Algorithmic Approach and Reflection

### Why Data Structures Matter

Data structures are important because they affect how efficiently a program stores, searches, and organizes information. Choosing the right structure can improve performance and make a program easier to maintain. For example, an unsorted list may require checking each entry when searching for a course, while a Binary Search Tree can reduce the number of comparisons when the tree is reasonably balanced. However, a BST's performance depends on its structure, so it is important to consider both average-case and worst-case complexity.

### My Approach

I implemented a custom **Binary Search Tree (BST)** to store and organize the course records.

- **Dynamic Memory Management:** Each distinct course is stored in a dynamically allocated `Course` node. The node contains the course number, title, prerequisite vector, and pointers to its left and right children. The destructor releases the allocated nodes when the tree is destroyed.

- **Alphanumeric Ordering:** The `printInOrder()` function uses recursive in-order traversal, visiting the left subtree, current node, and right subtree. Because courses are inserted according to their course numbers, this traversal prints the course list in alphanumeric order without requiring a separate sorting algorithm.

- **Course Lookup:** The `search()` function compares the requested course number with the current node and follows the appropriate subtree. This takes approximately O(log N) time in a balanced tree, but can take O(N) time in the worst case if the tree becomes unbalanced.

- **File Processing and Validation:** The `loadCourses()` function reads records from `courses.txt`, separates comma-delimited fields, and stores the course information in the tree. The `trim()` helper removes extra whitespace, and basic validation checks whether each record contains a course number and title before it is inserted.

## Operational Complexity Breakdown (Project One Component)

The following analysis compares the expected and worst-case runtime of the BST operations.

| BST Method / Operation | Average Case | Worst Case | Explanation |
|---|---|---|---|
| `insertCourse()` / `insert()` | O(log N) | O(N) | In a reasonably balanced tree, insertion follows a path proportional to the tree's height. In an unbalanced tree, the path can grow to include nearly every existing node. |
| `printCourseList()` / `printInOrder()` | O(N) | O(N) | Every course node must be visited to print the complete list. |
| `printCourse()` / `search()` | O(log N) | O(N) | Searching follows one path through the tree. A balanced tree has logarithmic height, while an unbalanced tree can have linear height. |

### Memory Complexity

- **Structural Space Complexity: O(N)**

  The tree stores one node for each distinct course number. Each node contains course information, a prerequisite vector, and two child pointers. The total memory required grows with the number of courses and the amount of information stored in their fields.

- **Auxiliary Stack Space Complexity: O(H)**

  The recursive insertion, search, traversal, and destruction functions use call-stack space proportional to the height of the tree, represented by H. For a balanced tree, the height is approximately O(log N). For an unbalanced tree, it can grow to O(N).

These complexity estimates describe the BST operations and do not include all the additional memory required to read and parse the input file.

## Overcoming Roadblocks

One challenge was handling whitespace and validating course records loaded from the input file. Extra spaces and carriage-return characters can affect course numbers and titles, which may cause formatting or lookup problems. Missing fields can also lead to incomplete course records.

I addressed these issues by creating a `trim()` helper function using `find_first_not_of()` and `find_last_not_of()` to remove unnecessary whitespace. I also added validation checks in the file-loading function to skip empty or invalid records. These improvements made the input process more reliable and helped prevent incomplete records from being inserted into the tree.

Another important consideration was understanding how the order of inserted courses affects BST performance. Since the tree is not self-balancing, inserting courses in an unfavorable order can reduce its efficiency. This helped me understand why data structure selection must account for both typical and worst-case scenarios.

## Impact on Software Design

This project expanded my approach to software design by teaching me to consider efficiency, memory usage, and data organization before choosing an implementation. Instead of focusing only on whether a program produces the correct output, I now consider how its operations perform as the amount of data increases.

I also learned the value of separating responsibilities. The `CourseBST` class manages the tree, while the loading function handles file processing and the main function manages the user menu. This organization makes the program easier to understand, test, and update.

## Maintainability, Readability, and Adaptability

- **Maintainability:** I organized the program into separate functions and used the `CourseBST` class to manage tree operations. Private recursive functions handle insertion, searching, traversal, and cleanup, while public methods provide access to the required operations.

- **Readability:** I used descriptive variable and function names, consistent indentation, comments, and clear menu messages. I also included error messages for invalid menu input, missing files, and unsuccessful course searches.

- **Adaptability:** The `Course` structure uses a `std::vector` to store prerequisites, allowing courses to have different numbers of prerequisites without requiring a fixed-size array. The file-loading approach also makes it possible to update course information by modifying the input file rather than changing every course directly in the program.

Working on this project helped me understand how selecting appropriate data structures, analyzing complexity, validating input, and organizing code contribute to building maintainable and reliable software.

## Skills Demonstrated

- C++ programming and object-oriented design
- Binary Search Trees and recursive algorithms
- Runtime and memory complexity analysis
- Searching and in-order traversal
- File processing and data validation
- Dynamic memory management
- Debugging and maintainable code organization
