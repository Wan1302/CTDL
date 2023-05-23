#include <iostream>
#include <stack>
using namespace std;

void DecimalToBinary(int number) {
    int temp = abs(number);
    stack<int> binaryDigits;

    while (temp > 0) {
        int digit = temp % 2;
        binaryDigits.push(digit);
        temp /= 2;
    }

    cout << "So nhi phan: ";
    while (!binaryDigits.empty()) {
        int digit = binaryDigits.top();
        if(number < 0) {
            if(digit == 1) digit = 0;
            else if(digit == 0) digit = 1;
        }
        binaryDigits.pop();
        cout << digit;
    }
    cout << endl;
}

void DecimalToHexadecimal(int number) {
    stack<int> binaryDigits;

    while (number > 0) {
        int digit = number % 16;
        binaryDigits.push(digit);
        number /= 16;
    }

    cout << "So thap luc phan: ";
    while (!binaryDigits.empty()) {
        int digit = binaryDigits.top();
        binaryDigits.pop();
        cout << digit;
    }
    cout << endl;
}

void DecimalToOctal(int number) {
    stack<int> binaryDigits;

    while (number > 0) {
        int digit = number % 8;
        binaryDigits.push(digit);
        number /= 8;
    }

    cout << "So thap luc phan: ";
    while (!binaryDigits.empty()) {
        int digit = binaryDigits.top();
        binaryDigits.pop();
        cout << digit;
    }
    cout << endl;
}
int main() {
    int temp;
    cout << "Nhap mot so nguyen: ";
    cin >> temp;

    DecimalToHexadecimal(temp);

    return 0;
}