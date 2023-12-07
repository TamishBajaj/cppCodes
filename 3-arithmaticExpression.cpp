#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isspace(char c)
{
return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

bool isValidArithmeticExpression(const char* expression) {
    int length = strlen(expression);
    bool expectingDigit = true;

    for (int i = 0; i < length; i++) {
        char c = expression[i];

        if (isspace(c)) {
            continue;
        }

        if ((isDigit(c) && !expectingDigit) || (isOperator(c) && expectingDigit)) {
            return false;
        }

        expectingDigit = !expectingDigit;
    }

    return !expectingDigit;
}

int main() {
    const int maxSize = 100;
    char expression[maxSize];

    cout << "Enter an arithmetic expression: ";
    cin.getline(expression, maxSize);

    if (isValidArithmeticExpression(expression)) {
        cout << "Valid arithmetic expression." << endl;
    } else {
        cout << "Invalid arithmetic expression." << endl;
    }

    return 0;
}
