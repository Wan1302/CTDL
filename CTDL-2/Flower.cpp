#include <iostream>
#include <vector>
using namespace std;
void Merge(int a[] , int l , int m, int r) {
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()) {
        if(x[i] <= y[j]) {
            a[l] = x[i];
            ++l;
            ++i;
        }
        else {
            a[l] = y[j];
            ++l;
            ++j;
        }
    }
    while(i < x.size()) {
        a[l] = x[i];
        ++l;
        ++i;
    }
    while(j < y.size()) {
        a[l] = y[j];
        ++l;
        ++j;
    }
}
void MergeSort(int a[], int l, int r) {
    if(l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a , l , m);
    MergeSort(a , m + 1, r);
    Merge(a, l, m, r);
}
int main () {
    int n,k;
    cin >> n >> k;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    MergeSort(a , 0 , n - 1);
    cout << a[0] << ' ';
    a[0] = -a[0];
    int count = 1;
    for (int i = 1; i < n && count < k; i++) {
        if (a[i] != abs(a[i - 1])) {
            cout << a[i] << ' ';
            a[i] *= -1;
            count++;
        }
    }

    for (int i = n - 1; i >= 0 && count < k; i--) {
        if (a[i] > 0) {
            cout << a[i] << ' ';
            count++;
        }
    }
    return 0;
}