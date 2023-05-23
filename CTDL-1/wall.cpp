
// #include <iostream>
// using namespace std;

// long n, m, count = 0;

// long checkValidHeight(long a[], long b[], long height) {
//     long res = 0;
//     for (long i = 0, j = 0; i < n; i++) {
//         if (a[i] >= height) {
//             continue;
//         }
//         while (a[i] + b[j] < height && j < m) {
//             j++;
//         }
//         if (j >= m) {
//             return 0;
//         }
//         res++;
//         j++;
//     }
//     return res;
// }

// long binarySearchHeight(long a[], long b[]) {
//     long low = 2e8, high = 2e8;

//     for (long i = 0; i < n; i++) {
//         low = min(low, a[i]);
//     }

//     long ans = low, mid, tempCount;
//     while (low <= high) {
//         mid = low + (high - low) / 2;
//         tempCount = checkValidHeight(a, b, mid);

//         if (!tempCount) {
//             high = mid - 1;
//         } else {
//             if (mid > ans) {
//                 ans = mid;
//                 count = tempCount;
//             }
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n;
//     long a[100000];
//     for (long i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     cin >> m;
//     long b[100000];
//     for (long i = 0; i < m; i++) {
//         cin >> b[i];
//     }

//     long ans = binarySearchHeight(a, b);

//     cout << ans << ' ' << count << endl;
//     for (long i = 0, j = 0; i < n; i++) {
//         if (a[i] >= ans) {
//             continue;
//         }
//         while (a[i] + b[j] < ans) {
//             j++;
//         }
//         cout << i + 1 << ' ' << j + 1 << '\n';
//         j++;
//     }
//     return 0;
// }





#include <iostream>
using namespace std;
long n , m , count = 0;
long check(long a[] , long b[] , long height) {
    long res = 0;
    for(int i = 0, j = 0; i < n; i++) {
        if(a[i] >= height) continue;
        while(a[i] + b[j] < height && j < m) {
            j++;
        }
        if(j >= m) return 0;
        res++;
        j++;
    }
    return res;
}
long BinarySearchHeight(long a[] , long b[]) {
    long left = 2e8, right = 2e8, mid , max , tempCount = 0;
    for(int i=0;i<n;i++) {
        left = min(left , a[i]);
    }
    long max2 = a[0];
    for(int i=1;i<n;i++) {
        if(max2 < a[i]) max2 = a[i];
    }
    long max1 = b[0];
    for(int i=1;i<m;i++) {
        if(max1 < b[i]) max1 = b[i];
    }
    right = max1 + max2;
    max = left;
    while(left <= right) {
        mid = (left + right) / 2;
        tempCount = check(a , b , mid);
        if(tempCount == 0) {
            right = mid - 1;
        }
        else {
            if(mid > max) {
                max = mid;
                count = tempCount;
            }
            left = mid + 1;
        }
    }
    return max;
}
int main () {
    cin >> n;
    long *a = new long[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];
    cin >> m;
    long *b = new long[m];
    for(int i = 0;i < m;i++)
        cin >> b[i];
    long max = BinarySearchHeight(a , b);
    cout << max << " " << count << "\n";
    for(int i = 0 , j = 0; i < n; i++) {
        if(a[i] >= max) continue;
        while(a[i] + b[j] < max) {
            j++;
        }
        cout << i + 1 << " " << j + 1 << "\n";
        j++;
    }
    return 0;
}