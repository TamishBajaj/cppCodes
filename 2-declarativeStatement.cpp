#include <iostream>
#include <string>
#include <regex>
using namespace std;
bool is_declarative_statement(const string &code)
{
    regex
        variable_declaration_regex("\\s*\\w+\\s+\\w+\\s*;"); // e.g., int x;
    regex
        function_declaration_regex("\\s*\\w+\\s+\\w+\\s*\\(.*\\)\\s*;"); // e.g., void myFunction();
    return regex_match(code, variable_declaration_regex) || regex_match(code, function_declaration_regex);
}
int main()
{
    cout << "Enter C++ code. Enter 'exit' to quit." << endl;
    string code;
    while (true)
    {
        cout << "> ";
        getline(cin, code);
        if (code == "exit")
        {
            break;
        }
        if (is_declarative_statement(code))
        {
            cout << "This is a declarative statement." << endl;
        }
        else
        {
            cout << "This is not a declarative statement." << endl;
        }
    }
    return 0;
}