#include <iostream>
#include <cstring>

bool hasUnterminatedComment(const char* code) {
    bool inComment = false;
    int length = strlen(code);

    for (int i = 0; i < length - 1; i++) {
        if (code[i] == '/' && code[i + 1] == '*') {
            inComment = true;
            i++;
        } else if (code[i] == '*' && code[i + 1] == '/') {
            inComment = false;
            i++;
        }
    }

    return inComment;
}

int main() {
    const int maxSize = 1000;
    char code[maxSize] = {0}; // Initialize the array to avoid undefined behavior

    std::cout << "Enter your C++ code (terminate input with a period '.' on a line by itself):\n";

    while (true) {
        char line[100];
        std::cin.getline(line, sizeof(line));

        if (line[0] == '.' && line[1] == '\0') {
            break;
        }

        strcat(code, line);
    }

    if (hasUnterminatedComment(code)) {
        std::cout << "Error: Unterminated multi-line comment found.\n";
    } else {
        std::cout << "No unterminated multi-line comments found.\n";
    }

    return 0;
}
