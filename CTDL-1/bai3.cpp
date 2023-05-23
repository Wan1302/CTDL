#include <iostream>
#include <vector>
using namespace std;
void nhap(vector<int> &a , int n) {
    for(int i=0;i<n;i++) {
       int x;
       cin >> x;
       a.push_back(x);
    }
}
void xuat(vector<int> a , int n) {
    for(int i=0;i<n;i++)
        cout  << a[i] << " ";
}
int LinerSearch(vector<int> a , int x) {
    int n = a.size();
    for(int i=0;i<n;i++) {
        if(a[i] == x ) return i;
    }
    return -1;
}
int BinarySearch(vector<int> a , int left , int right , int x) {
    int n = a.size();
    int mid;
    mid = (left + right) / 2;
    for(int i=0;i<n;i++) {
        if(a[mid] == x) return mid;
        else if(a[mid] < x) {return BinarySearch(a,mid+1,right,x);}
        else {return BinarySearch(a,left,mid-1,x);}
    }
    return -1;
}
int InterpolationSearch(vector<int> a , int x) {
    int n = a.size();
    int mid , left = 0 , right = n - 1;
    do {
        mid = left + (((right-left)*(x - a[left])) / (a[right] - a[left]));
        if(a[mid] == x) return mid;
        else {
            if(a[mid] < x) left = mid + 1;
            else right = mid - 1;
        }
    }while(left <= right);
    return -1;
}
int main () {
    vector<int> a;
    int n , x;
    cin >> n;
    nhap(a,n);
    cin >> x;
    cout << LinerSearch(a,x) << endl;
    cout << BinarySearch(a,0,n-1,x) << endl;
    cout << InterpolationSearch(a,x) << endl;
    return 0;
}