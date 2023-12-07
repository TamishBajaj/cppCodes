#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_SYMBOLS 100
using namespace std;

struct SymbolTable {
    char name[20];
    int value;
    int defined;
};

SymbolTable symbol_table[MAX_SYMBOLS];
int symbol_count = 1;

void add_symbol(const char* name, int value) {
    if (symbol_count < MAX_SYMBOLS) {
        strcpy(symbol_table[symbol_count].name, name);
        symbol_table[symbol_count].value = value;
        symbol_table[symbol_count].defined = 1;
        symbol_count++;
    } else {
        cerr << "Error: Symbol table is full." << endl;
        exit(1);
    }
}

int find_symbol(const char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char input[100];
    char symbol_name[20];
    int symbol_value;

    cout << "Enter assembly-like code (Enter 'quit' to exit):\n";

    while (true) {
        cout << "> ";
        cin.getline(input, sizeof(input));

        if (strcmp(input, "quit") == 0) {
            break;
        }

        if (sscanf(input, "%s %d", symbol_name, &symbol_value) == 2) {
            int symbol_index = find_symbol(symbol_name);

            if (symbol_index == -1) {
                add_symbol(symbol_name, symbol_value);
                cout << "Symbol " << symbol_name << " defined." << endl;
            } else {
                cout << "Error: Symbol " << symbol_name << " redefined." << endl;
            }
        } else {
            int symbol_index = find_symbol(input);

            if (symbol_index == -1) {
                cout << "Error: Symbol " << input << " used but not defined." << endl;
            } else {
                cout << "Symbol " << input << " has a value of " << symbol_table[symbol_index].value << ".\n";
            }
        }
    }

    return 0;
}
