#include <iostream>
#include <sstream>
#include <string>
#include "stack.h"

using namespace std;

int main() {
    Stack s;
    init(&s);

    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line);
    string token;

    try {
        while (ss >> token) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (isEmpty(&s)) throw runtime_error("Operand kurang");
                int b = peek(&s); pop(&s);

                if (isEmpty(&s)) throw runtime_error("Operand kurang");
                int a = peek(&s); pop(&s);

                int result;

                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else {
                    if (b == 0) throw runtime_error("Pembagian nol");
                    result = a / b;
                }

                push(&s, result);
            }
            else {
                int num = stoi(token);
                push(&s, num);
            }
        }

        if (isEmpty(&s)) throw runtime_error("Stack kosong");

        int hasil = peek(&s);
        pop(&s);

        if (!isEmpty(&s)) throw runtime_error("Ekspresi tidak valid");

        cout << hasil << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}