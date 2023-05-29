//Create a Triangle class. 
// Add exception handling statements to ensure the following conditions:
// all sides are greater than 0
// sum of any two sides is greater than the third side. 
//The class should also have overloaded functions for calculating the area of a right angled triangle as well as using Heron's formula to calculate the area of any type of triangle.



#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// Class representing a Triangle
class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    // Constructor to initialize the Triangle object with side lengths
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        // Check for invalid side lengths
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw invalid_argument("Invalid side length. Side lengths must be greater than 0.");
        }
        // Check for invalid triangle sides using triangle inequality theorem
        if (side1 + side2 <= side3 || side2 + side3 <= side1 || side3 + side1 <= side2) {
            throw invalid_argument("Invalid side lengths. Sum of any two sides must be greater than the third side.");
        }
    }

    // Function to calculate the area of the triangle using Heron's formula
    double calculateArea() const {
        double semiPerimeter = (side1 + side2 + side3) / 2.0;
        double area = sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
        return area;
    }

    // Function to calculate the area of a right-angled triangle
    double calculateArea(double base, double height) const {
        // Check for invalid base or height
        if (base <= 0 || height <= 0) {
            throw invalid_argument("Invalid base or height. Base and height must be greater than 0.");
        }
        double area = 0.5 * base * height;
        return area;
    }
};

int main() {
    try {
        double side1, side2, side3;
        cout << "Enter the lengths of the sides of the triangle: ";
        cin >> side1 >> side2 >> side3;

        // Create a Triangle object with the provided side lengths
        Triangle triangle(side1, side2, side3);

        // Calculate and display the area of the triangle using Heron's formula
        double area = triangle.calculateArea();
        cout << "Area of the triangle using Heron's formula: " << area << endl;

        double base, height;
        cout << "Enter the base and height of the right-angled triangle: ";
        cin >> base >> height;

        // Calculate and display the area of the right-angled triangle
        area = triangle.calculateArea(base, height);
        cout << "Area of the right-angled triangle: " << area << endl;
    } catch (const invalid_argument& e) {
        // Handle and display any invalid argument exceptions
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
