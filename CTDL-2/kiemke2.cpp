#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
typedef struct Goods {
    string Ma;
    int Soluong;
}G;
int compare(string s1, string s2) {
    if(s1.length() < s2.length()) return -1;
    else if(s1.length() == s2.length()) {
        if(s1 > s2) return 1;
        else if(s1 < s2) return -1;
        else return 0;
    }
    return 1;
}
void merge(G a[] , int l , int m, int r) {
    vector<G> x(a + l, a + m + 1);
    vector<G> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()) {
        if(x[i].Soluong > y[j].Soluong || (x[i].Soluong == y[j].Soluong && (compare(x[i].Ma, y[j].Ma) == - 1 || compare(x[i].Ma, y[j].Ma) == 0))) {
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
void MergeSort(G a[], int l, int r) {
    if(l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a , l , m);
    MergeSort(a , m + 1, r);
    merge(a, l, m, r);
}

void QuickSort(string a[] , int left , int right) {
    int i = left, j = right;
    string pivot = a[(left + right) / 2];
    while(i <= j) {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j) {
            swap(a[i] , a[j]);
            i++;     
            j--;
        }
    }
    if(i < right) QuickSort(a,i,right);
    if(j > left) QuickSort(a,left,j);
}
int main () {
    int n,count = 1;
    cin >> n;
    string *a = new string[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    G *b = new G[n];
    int Size = 0;
    QuickSort(a, 0, n - 1);
    for(int i=0;i<n;i++) {
        if(i == n - 1 || a[i] != a[i+1]) {
            b[Size].Ma = a[i];
            b[Size].Soluong = count;
            count = 1;
            Size++;
        }
        else count++;
    }
    MergeSort(b, 0, Size - 1);
    for(int i = 0;i<Size;i++) {
        cout << b[i].Ma << " " << b[i].Soluong << "\n";
    }
    delete []a;
    delete []b;
    return 0;
}