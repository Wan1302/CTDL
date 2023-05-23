#include <iostream>
#include <ctime>
using namespace std;
void Xuat(int a[], int n) {
    for(int i=0;i<n;i++)
        cout <<  a[i] << " ";
}
void Xoa(int a[], int &n, int x) {
    for(int i=0;i<n;i++) {
        if(a[i] == x) {
            for(int j=i;j<n-1;j++) {
                a[j] = a[j+1];
            }
            n--;
        }
    }
}
void Insert(int a[], int &n, int x, int y) {
    for(int i=n-1;i>=y;i--) {
        a[i+1] = a[i];
    }
    a[y] = x;
    n++;
}
void Max(int a[], int n) {
    int max = 0;
    for(int i=0;i<n;i++) {
        if(a[i] > max) max = a[i];
    }
    for(int i=0;i<n;i++) {
        if(a[i] == max) cout << i << " ";
    }
}
void Min(int a[], int n) {
    int min = 0;
    for(int i=0;i<n;i++) {
        if(a[i] < min) min = a[i];
    }
    for(int i=0;i<n;i++) {
        if(a[i] == min) cout << i << " ";
    }
}
int Positive(int a[], int n) {
    int count = 0;
    for(int i=0;i<n;i++) {
        if(a[i] > 0) count++;
    }
    return count;
}
int Negative(int a[], int n) {
    int count = 0;
    for(int i=0;i<n;i++) {
        if(a[i] < 0) count++;
    }
    return count;
}
int maxPositive(int a[], int n) {
    int max = 0;
    for(int i=0;i<n;i++) {
        if(a[i] > 0 && a[i] > max) max = a[i];
    }
    return max;
}
int maxNegative(int a[], int n) {
    int max = 0;
    for(int i=0;i<n;i++) {
        if(a[i] < 0 && a[i] > max) max = a[i];
    }
    return max;
}
int find(int a[], int n, int x) {
    for(int i=0;i<n;i++) {
        if(a[i] == x) return 1;
    }
    return 0;
}
void CountX(int a[], int n, int x) {
    int count = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == x) count++;
    }
    if(count == 0) cout << "Khong co phan tu X";
    else cout << "Co " << count << " phan tu bang X";
}
int main() {
    int x;
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0;i<n;i++) {
        x = -100 + rand() % 201;
        a[i] = x;
    }
    Xuat(a, n);
    cout << endl;
    cout << maxPositive(a, n);
    return 0;
}