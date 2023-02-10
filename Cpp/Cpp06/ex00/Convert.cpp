#include <iostream>
#include <limits>
#include <cfloat>
#include <cstdlib>
#include <climits>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Please provide a valid literal as an argument." << endl;
        return 1;
    }

    string input = argv[1];

    // Detect the type of the literal
    if (input.length() == 1 and ((input[0] <= 47 and input[0] >= 32) or (input[0] <= 126 and input[0] >= 58))) {
        char c = input[0];
        cout << "Char: " << c << endl;
        {
            int i = c;
            cout << "Int: " << i << endl;
            float f = c;
            cout << "Float: " << f << endl;
            double d = c;
            cout << "Double: " << d << endl;
        }
    } else {
        char* end;
        double d = strtod(input.c_str(), &end);
        if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff" || *end) {
            cout << input << " is not a valid number and cannot be converted to int, float, or double." << endl;
        } else {
            if (d > INT_MAX || d < INT_MIN) {
                cout << "Number is too large or too small to be converted to int." << endl;
            } else {
                int i = d;
                cout << "Int: " << i << endl;
            }
            if (d > FLT_MAX || d < -FLT_MAX) {
                cout << "Number is too large or too small to be converted to float." << endl;
            } else {
                float f = d;
                cout << "Float: " << f << endl;
            }
            cout << "Double: " << d << endl;
        }
    }

    return 0;
}