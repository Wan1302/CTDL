#include <iostream>
#include <vector>
using namespace std;
typedef struct Point {
    int x,y,z;
} P;
void merge(P a[] , int l , int m, int r) {
    vector<P> x(a + l, a + m + 1);
    vector<P> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()) {
        if(x[i].x < y[j].x || (x[i].x == y[j].x && x[i].y > y[j].y) || (x[i].x == y[j].x && x[i].y == y[j].y && x[i].z < y[j].z)) {
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
void MergeSort(P a[], int l, int r) {
    if(l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a , l , m);
    MergeSort(a , m + 1, r);
    merge(a, l, m, r);
}
int main () {
    int n;
    cin >> n;
    P *a = new P[n];
    for(int i=0;i<n;i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    MergeSort(a , 0 , n - 1);
    for(int i=0;i<n;i++) {
        cout << a[i].x << " " <<  a[i].y << " " <<  a[i].z << endl;;
    }
    return 0;
}