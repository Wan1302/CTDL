#include <iostream>
using namespace std;
int main() {
    unsigned long long a, b, k, m, n;
    cin >> a >> k >> b >> m >> n;

    __int128 socay , mid , left = 1 , right = n , ngay = n;
    do {
        mid = (left + right)  / 2;
        socay = mid*a - (mid/k)*a + mid*b - (mid/m)*b;
        if(socay >= n) {
            ngay = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }while(left <= right);
    cout << (unsigned long long) ngay;
    return 0;
}
