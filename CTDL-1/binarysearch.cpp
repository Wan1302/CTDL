#include <iostream>
using namespace std;
void quickSort (int  a[] , int left , int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];
    while(i <= j) {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j) {
            swap(a[i] , a[j]);
            i++;
            j--;
        }
    }
    if(i < right) quickSort(a,i,right);
    if(j > left) quickSort(a,left,j);
}
int BinarySearch (int a[] , int n , int x) {
    int mid,left=0,right=n-1;
    do {
        mid = (left+ right) / 2;
        if(a[mid] == x) return mid;
        else {
            if(a[mid] < x) left = mid + 1;
            else right = mid - 1;
        }
    }while(left <= right);
    return -1;
}
int main () {
    int n,q;
    cin >> n >> q;
    int *p = new int [n];
    int *a = new int [q];
    for(int i=0;i<n;i++)
        cin >> p[i];
    for(int i=0;i<q;i++)
        cin >> a[i];
    quickSort(p,0,n-1);
    for(int i=0;i<q;i++) {
        if(BinarySearch(p,n,a[i]) != -1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    delete []p;
    delete []a;
    return 0;
}