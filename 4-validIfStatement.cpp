#include <iostream>
#include <cstring>

bool isValidIfStatement(const char* line) {
    int length = strlen(line);
    bool foundIfKeyword = false;
    bool foundOpeningBrace = false;
    bool foundClosingBrace = false;

    for (int i = 0; i < length; i++) {
        char c = line[i];

        if (c == ' ' || c == '\t') {
            continue;
        }

        if (!foundIfKeyword) {
            if (c == 'i' && line[i + 1] == 'f' && (line[i + 2] == ' ' || line[i + 2] == '(')) {
                foundIfKeyword = true;
                i += 2;
                continue;
            } else {
                return false;
            }
        }

        if (foundIfKeyword && !foundOpeningBrace) {
            if (c == '(') {
                foundOpeningBrace = true;
                continue;
            } else {
                return false;
            }
        }

        if (foundIfKeyword && foundOpeningBrace && !foundClosingBrace) {
            if (c == ')') {
                foundClosingBrace = true;
                continue;
            }
        }
    }

    return foundIfKeyword && foundOpeningBrace && foundClosingBrace;
}

int main() {
    const int maxSize = 100;
    char line[maxSize];

    std::cout << "Enter a line of C++ code: ";
    std::cin.getline(line, maxSize);

    if (isValidIfStatement(line)) {
        std::cout << "Valid if statement." << std::endl;
    } else {
        std::cout << "Invalid if statement." << std::endl;
    }

    return 0;
}
