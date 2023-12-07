#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#define MAX_SYMBOLS 100

struct SymbolTable {
    char name[20];
    int value;
};

SymbolTable symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

void add_symbol(const char* name, int value) {
    if (symbol_count < MAX_SYMBOLS) {
        strcpy(symbol_table[symbol_count].name, name);
        symbol_table[symbol_count].value = value;
        symbol_count++;
    } else {
        cerr << "Error: Symbol table is full." << endl;
    }
}

void display_symbol_table() {
    cout << "Symbol Table:\n";
    cout << setw(10) << "Name" << setw(10) << "Value" << endl;

    for (int i = 0; i < symbol_count; i++) {
        cout << setw(10) << symbol_table[i].name << setw(10) << symbol_table[i].value << endl;
    }
}

int main() {
    // Add symbols to the symbol table.
    add_symbol("a", 10);
    add_symbol("b", 20);
    add_symbol("c", 30);

    // Display the symbol table.
    display_symbol_table();

    return 0;
}
