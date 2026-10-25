#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Structure for storing course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
    Course* left;
    Course* right;

    // Converted nullptr to NULL for older compiler compatibility
    Course() : left(NULL), right(NULL) {}
};

// Binary Search Tree for storing courses
class CourseBST {
private:
    Course* root;

    Course* insert(Course* node, Course* course) {
        if (node == NULL) {
            return course;
        }

        if (course->courseNumber < node->courseNumber) {
            node->left = insert(node->left, course);
        }
        else if (course->courseNumber > node->courseNumber) {
            node->right = insert(node->right, course);
        }
        else {
            node->courseTitle = course->courseTitle;
            node->prerequisites = course->prerequisites;
            delete course;
        }

        return node;
    }

    void printInOrder(Course* node) const {
        if (node == NULL) {
            return;
        }

        printInOrder(node->left);

        cout << node->courseNumber << ", "
             << node->courseTitle << endl;

        printInOrder(node->right);
    }

    Course* search(Course* node, const string& number) const {
        if (node == NULL || node->courseNumber == number) {
            return node;
        }

        if (number < node->courseNumber) {
            return search(node->left, number);
        }

        return search(node->right, number);
    }

    void destroyTree(Course* node) {
        if (node == NULL) {
            return;
        }

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    CourseBST() : root(NULL) {}

    ~CourseBST() {
        destroyTree(root);
    }

    void insertCourse(Course* course) {
        root = insert(root, course);
    }

    void printCourseList() const {
        if (root == NULL) {
            cout << "No course data is loaded." << endl;
            return;
        }

        cout << "Here is a sample schedule:" << endl;
        printInOrder(root);
    }

    void printCourse(const string& number) const {
        Course* course = search(root, number);

        if (course == NULL) {
            cout << "Course not found." << endl;
            return;
        }

        cout << course->courseNumber << ", "
             << course->courseTitle << endl;

        if (course->prerequisites.empty()) {
            cout << "Prerequisites: None" << endl;
        }
        else {
            cout << "Prerequisites: ";

            for (size_t i = 0;
                 i < course->prerequisites.size(); ++i) {
                cout << course->prerequisites[i];

                if (i + 1 < course->prerequisites.size()) {
                    cout << ", ";
                }
            }

            cout << endl;
        }
    }
};

// Remove extra spaces from CSV fields
string trim(const string& value) {
    size_t first = value.find_first_not_of(" \t\r\n");

    if (first == string::npos) {
        return "";
    }

    size_t last = value.find_last_not_of(" \t\r\n");

    return value.substr(first, last - first + 1);
}

// Load courses from a CSV file
bool loadCourses(const string& filename, CourseBST& courses) {
    ifstream file(filename.c_str());

    if (!file.is_open()) {
        cout << "Error: Unable to open file "
             << filename << "." << endl;
        return false;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        if (trim(line).empty()) {
            continue;
        }

        stringstream stream(line);
        vector<string> fields;
        string field;

        while (getline(stream, field, ',')) {
            fields.push_back(trim(field));
        }

        if (fields.size() < 2 ||
            fields[0].empty() || fields[1].empty()) {
            cout << "Skipping invalid course record." << endl;
            continue;
        }

        Course* course = new Course();
        course->courseNumber = fields[0];
        course->courseTitle = fields[1];

        // Store all remaining fields as prerequisites
        for (size_t i = 2; i < fields.size(); ++i) {
            if (!fields[i].empty()) {
                course->prerequisites.push_back(fields[i]);
            }
        }

        courses.insertCourse(course);
        ++count;
    }

    file.close();

    if (count == 0) {
        cout << "No course records were loaded." << endl;
        return false;
    }

    cout << "Data loaded successfully." << endl;
    return true;
}

// Main program
int main() {
    CourseBST courses;
    int choice = 0;
    bool dataLoaded = false;
    string filename;
    string courseNumber;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        cout << "\n1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a menu option."
                 << endl;
            continue;
        }

        switch (choice) {
        case 1:
            // Hardcoded to automatically load the file without prompt
            filename = "courses.txt";
            dataLoaded = loadCourses(filename, courses);
            break;

        case 2:
            if (!dataLoaded) {
                cout << "Please load the data structure first."
                     << endl;
            }
            else {
                courses.printCourseList();
            }
            break;

        case 3:
            if (!dataLoaded) {
                cout << "Please load the data structure first."
                     << endl;
            }
            else {
                cout << "What course do you want to know about? ";
                cin >> courseNumber;

                // Standard loop conversion for compatibility
                for (size_t i = 0; i < courseNumber.length(); ++i) {
                    courseNumber[i] = toupper(courseNumber[i]);
                }

                courses.printCourse(courseNumber);
            }
            break;

        case 9:
            cout << "Thank you for using the course planner!"
                 << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
            break;
        }
    }

    return 0;
}
