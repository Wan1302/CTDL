// #include <iostream>
// #include <stack>
// using namespace std;

// int ReverseNumber(int number) {
//     stack<int> digits;

//     // Đưa các chữ số của số nguyên vào ngăn xếp
//     while (number > 0) {
//         int digit = number % 10;
//         digits.push(digit);
//         number /= 10;
//     }

    
//     int reversedNumber = 0;
//     int multiplier = 1;
//     while (!digits.empty()) {
//         int digit = digits.top();
//         digits.pop();
//         reversedNumber += digit * multiplier;
//         multiplier *= 10;
//     }

//     return reversedNumber;
// }

// int main() {
//     int number;
//     cout << "Nhap vao mot so nguyen khong am: ";
//     cin >> number;

//     int reversedNumber = ReverseNumber(number);

//     cout << "So dao nguoc: " << reversedNumber << endl;

//     return 0;
// }


#include <iostream>
#include <queue>
using namespace std;

int ReverseNumber(int number) {
    queue<int> digits;

    while (number > 0) {
        int digit = number % 10;
        digits.push(digit);
        number /= 10;
    }

    int reversedNumber = 0;
    int multiplier = 1;
    while (!digits.empty()) {
        int digit = digits.front();
        digits.pop();
        reversedNumber = reversedNumber * 10 + digit;
    }

    return reversedNumber;
}

int main() {
    int number;
    cout << "Nhap vao mot so nguyen khong am: ";
    cin >> number;

    int reversedNumber = ReverseNumber(number);

    cout << "So dao nguoc: " << reversedNumber << endl;

    return 0;
}