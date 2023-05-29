//Define a class Person having name as a data member. 
//Inherit two classes Student and Employee from Person. 
//Student has additional attributes as course, marks and year and Employee has department and salary.
//Write display() method in all the three classes to display the corresponding attributes.
//Provide the necessary methods to show runtime polymorphism.


#include <iostream>
#include <string>

using namespace std;

// Base class for a Person
class Person {
protected:
    string name;

public:
    Person(string name) : name(name) {}

    // Display function to be overridden by derived classes
    virtual void display() const {
        cout << "Name: " << name << endl;
    }
};

// Derived class representing a Student
class Student : public Person {
private:
    string course;
    int marks;
    int year;

public:
    // Constructor for initializing Student object
    Student(const string& name, const string& course, int marks, int year)
        : Person(name), course(course), marks(marks), year(year) {}

    // Override the display function to include additional information for Student
    void display() const override {
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class representing an Employee
class Employee : public Person {
private:
    string department;
    double salary;

public:
    // Constructor for initializing Employee object
    Employee(const string& name, const string& department, double salary)
        : Person(name), department(department), salary(salary) {}

    // Override the display function to include additional information for Employee
    void display() const override {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Create objects of Person, Student, and Employee using dynamic polymorphism
    Person* person1 = new Person("Sam");
    Person* person2 = new Student("Shivam", "Computer Science", 90, 2022);
    Person* person3 = new Employee("Riya", "HR", 5000);

    // Call the display function for each object
    person1->display();
    cout << endl;

    person2->display();
    cout << endl;

    person3->display();
    cout << endl;

    // Delete the dynamically allocated objects
    delete person1;
    delete person2;
    delete person3;

    return 0;
}

