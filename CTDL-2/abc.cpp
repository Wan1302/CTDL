#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
typedef struct Goods {
    string Ma;
    int Soluong;
}G;
int check(G b[], int n, string x) {
    for(int i = 0;i < n;i++) {
        if(b[i].Ma == x) return 1;
    }
    return 0;
}
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
        if(x[i].Soluong > y[j].Soluong || (x[i].Soluong == y[j].Soluong && compare(x[i].Ma, y[j].Ma) == - 1)) {
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
int main () {
    int n,count = 0;
    cin >> n;
    string *a = new string[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    G *b = new G[n];
    int Size = 0;
    for(int i=0;i<n;i++) {
        if(check(b , Size, a[i]) == 0) {
            b[Size].Ma = a[i];
            count = 0;
            for(int j=i;j<n;j++) {
                if(a[j] == b[Size].Ma) count++;
            }
            b[Size].Soluong = count;
            Size++;
        }
    }
    MergeSort(b, 0, Size - 1);
    for(int i = 0;i<Size;i++) {
        cout << b[i].Ma << " " << b[i].Soluong <<"\n";
    }
    return 0;
}