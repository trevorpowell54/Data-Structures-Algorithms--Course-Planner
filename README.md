# CS 300: Data Structures and Algorithms — Course Planner Portfolio

## Overview

This repository contains portfolio artifacts from CS 300: Data Structures and Algorithms. The projects focus on designing a course planner in C++ that organizes Computer Science course information, searches for individual courses, and displays the course list in alphanumeric order.

The portfolio includes my analysis of different data structures, including vectors, hash tables, and binary search trees, along with my Project Two course planner implementation. These projects demonstrate my understanding of algorithmic efficiency, memory usage, data organization, and software development practices.

## Project One: Runtime and Memory Analysis

### Problem Solved

The goal of Project One was to determine which data structure would work best for a Computer Science course advisor program. The program needed to load course information, store course numbers and titles, manage prerequisites, search for individual courses, and display courses in alphanumeric order.

I compared three data structures: vectors, hash tables, and binary search trees. Each structure has different strengths and limitations depending on how information needs to be stored, searched, and displayed.

### Data Structure Comparison

| Operation | Vector | Hash Table | Binary Search Tree |
|---|---|---|---|
| Load courses | O(n) amortized, excluding validation | O(n) average | O(n log n) average |
| Search for a course | O(n) | O(1) average | O(log n) average |
| Print sorted courses | O(n log n) if sorting is required | O(n log n) if sorting is required | O(n) using in-order traversal |
| Memory usage | O(n) | O(n) | O(n) |

The worst-case runtime for hash table operations can increase because of collisions. A regular binary search tree can also become unbalanced, resulting in O(n) search and insertion times and O(n²) total loading time in the worst case.

All three structures require O(n) structural memory to store the course records. However, a binary search tree requires additional memory for its child pointers, while a hash table requires storage for its buckets and collision management.

### Recommendation

I recommended using a binary search tree because it supports both individual course searches and displaying the course list in alphanumeric order. In-order traversal visits each node once and prints the courses in sorted order without requiring a separate sorting operation.

The main limitation is that a regular binary search tree does not automatically balance itself. A self-balancing tree, such as an AVL tree, could provide more consistent performance for larger course catalogs.

The full analysis is available in `ProjectOne_Runtime_Memory_Analysis.md`.

## Project Two: Computer Science Course Planner

### Overview

For Project Two, I developed a command-line Course Planner in C++. The program loads course information from `courses.txt`, stores courses in a Binary Search Tree, and allows users to display the complete course list or look up an individual course and its prerequisites.

### Implementation

The program uses a `Course` structure to store the course number, course title, prerequisite vector, and pointers to the left and right child nodes. The `CourseBST` class manages the tree and includes functions for inserting courses, searching for a course, printing the course list, and releasing allocated memory.

The program reads comma-separated course records from an external text file. It includes a `trim()` helper function to remove extra whitespace and basic validation to skip records that are missing a course number or title.

The menu provides three main options:

1. Load the course data.
2. Print the course list in alphanumeric order.
3. Search for a course and display its prerequisites.

Option 9 exits the program.

### Data Structures and Algorithms

The program uses a Binary Search Tree to organize courses by course number. Its recursive `insert()` function places courses in the appropriate subtree, and its `search()` function follows the tree according to the course number being searched.

The `printInOrder()` function visits the left subtree, current node, and right subtree. This traversal displays courses in alphanumeric order in O(n) time because each node is visited once.

Searching and insertion take approximately O(log n) time when the tree is reasonably balanced. However, because the tree does not automatically balance itself, these operations can take O(n) time in the worst case.

The tree requires O(n) structural memory, while recursive operations use additional call-stack space proportional to the tree's height.

### Skills Demonstrated

- C++ programming and object-oriented design
- Binary Search Trees and recursive algorithms
- Runtime and memory complexity analysis
- Searching and in-order traversal
- File processing and input validation
- Dynamic memory management
- Debugging and code organization

## Reflection

### What problem were you solving in these projects?

The main problem was developing a course planner that could organize Computer Science course information and make it easy to retrieve. The program needed to load course records, store prerequisites, search for individual courses, and display the course list in the correct order. These requirements helped me understand how data structures can solve practical programming problems.

### How did you approach the problem?

I compared vectors, hash tables, and binary search trees to understand how each structure affects runtime, memory usage, and searching. I then applied my understanding of data structures and algorithms to the course planner by using a Binary Search Tree to organize and retrieve course information. This helped me understand why it is important to choose a data structure based on the requirements of the program rather than simply choosing the easiest option.

### How did you overcome roadblocks?

One challenge was processing course information from a file and making sure the records were valid. Extra whitespace, missing fields, and incorrect course information could cause problems during loading or searching. I addressed these issues by using a `trim()` helper function, adding validation checks, and reviewing the program logic. Breaking the program into smaller functions also made it easier to identify and correct problems.

### How has this project expanded your approach to software design?

This project taught me to consider efficiency and memory usage when designing software. I learned that a program can produce the correct output but still have performance limitations depending on the data structure being used. Comparing the different structures helped me understand how algorithmic complexity affects scalability and how choosing the right approach can improve a program's performance.

### How has this project improved your ability to write maintainable, readable, and adaptable programs?

I learned the importance of using meaningful variable names, organizing code into separate functions, and keeping related operations together in a class. I also gained experience with input validation, recursion, and dynamic memory management. Using a vector to store prerequisites makes the program adaptable to courses with different numbers of prerequisites. These practices will help me write programs that are easier to understand, test, maintain, and update as requirements change.

## Repository Contents

- `README.md` — Project overview, reflection, and summary of skills demonstrated.
- `ProjectOne_Runtime_Memory_Analysis.md` — Comparison of data structures, runtime complexity, memory usage, and recommendation.
- `main.cpp` — C++ implementation of the course planner.
- `courses.txt` — Input file containing course records, if included in the repository.

## Conclusion

Completing these projects helped me develop a stronger understanding of data structures, algorithmic complexity, and software design. I learned how vectors, hash tables, and binary search trees differ in performance and memory usage, and how those differences influence implementation decisions. I also gained experience organizing C++ code, validating file input, using recursion, and designing a program that is easier to maintain and adapt. These skills will be useful in future software development projects.
