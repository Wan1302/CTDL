#include <iostream>
#include <math.h>
using namespace std;
void nhap(int a[] , int &n) {
    cin >> n;
    for(int i=0;i<n;i++) 
        cin >> a[i];
}
void doi(int a[] , int n) {
    int max=a[1], min=a[0] , index1 , index2;
    for(int i=0;i<n;i++) {
        if(i % 2 == 0 && a[i] <= min) {
            min = a[i];
            index1 = i;
        }
        if(i % 2 != 0 && a[i] >= max) {
            max = a[i];
            index2 = i;
        }
    }
    if(a[index1] < a[index2]) swap(a[index1] , a[index2]);
}
int sum(int a[] , int n) {
    int sum = 0;
    if(n % 2 == 0) {
        for(int i=0;i < n/2;i++) {
            sum += pow(-1,i)*a[i];
            if(n-i-1 < n && n-i-1 != i) sum += pow(-1,n-i-1)*a[n-i-1];
        }
    }
    if(n % 2 != 0) {
        for(int i=0;i <= n/2;i++) {
            sum += pow(-1,i)*a[i];
            if(n-i-1 < n && n-i-1 != i) sum += pow(-1,n-i-1)*a[n-i-1];
        }
    }
    return sum;
}
int main () {
    int n , a[100000];
    nhap(a,n);
    doi(a,n);
    cout << sum(a,n);
    return 0;
}