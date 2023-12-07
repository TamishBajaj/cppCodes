#include <iostream>
using namespace std;

int main() {
    int n, i, k, flag = 0;
    char vari[15], typ[15], b[15], c;

    cout << "Enter the number of variables: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter the variable[" << i << "]: ";
        cin >> vari[i];
        cout << "Enter the variable-type[" << i << "] (float-f, int-i): ";
        cin >> typ[i];

        if (typ[i] == 'f') {
            flag = 1;
        }
    }

    cout << "Enter the Expression (end with $): ";
    i = 0;
    getchar(); // Ignore newline from previous input
    while ((c = getchar()) != '$') {
        b[i] = c;
        i++;
    }
    k = i;

    for (i = 0; i < k; i++) {
        if (b[i] == '/') {
            flag = 1;
            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (b[0] == vari[i]) {
            if (flag == 1) {
                if (typ[i] == 'f') {
                    cout << "\nthe datatype is correctly defined..!\n";
                    break;
                } else {
                    cout << "Identifier " << vari[i] << " must be a float type..!\n";
                    break;
                }
            } else {
                cout << "\nthe datatype is correctly defined..!\n";
                break;
            }
        }
    }

    return 0;
}
