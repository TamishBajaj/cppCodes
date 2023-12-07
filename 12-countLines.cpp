#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter multiple lines of text (terminate with an empty line):\n";

    string input;
    int lineCount = 0;
    int spaceCount = 0;

    while (true) {
        getline(cin, input);

        // Check for termination condition (empty line)
        if (input.empty()) {
            break;
        }

        // Count lines and spaces
        lineCount++;
        for (char c : input) {
            if (isspace(c)) {
                spaceCount++;
            }
        }
    }

    // Output the results
    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of spaces: " << spaceCount << endl;

    return 0;
}
