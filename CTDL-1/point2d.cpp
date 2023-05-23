#include <iostream>
#include <algorithm>
using namespace std;
struct Point {
    int x,y;
};
bool sosanh(Point a , Point b) {
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}
// void quickSort(Point p[] , int left , int right) {
//     int i = left, j = right;
//     int mid = (left + right) / 2;
//     int pivot = p[mid].x;
//     while(i <= j) {
//         while(p[i].x < pivot) i++;
//         while(p[j].x > pivot) j--;
//         if(i <= j) {
//             swap(p[i], p[j]);
//             i++;
//             j--;
//         }
//     }
//      if(i <= right) quickSort(p,i,right);
//     if(j >= left) quickSort(p,left,j);
// }
// void sapxep(Point p[] , int n) {
//     for(int i=0;i<n;i++) {
//         if((p[i].x == p[i+1].x) && (p[i].y < p[i+1].y)) {
//             swap(p[i] , p[i+1]);
//             if(i > 0) i--;
//         }  
//     }
// }
int main () {
    int n;
    cin >> n;
    Point *p = new Point[n];
    for(int i=0;i<n;i++) 
        cin >> p[i].x >> p[i].y;
    // quickSort(p,0,n-1);
    // sapxep(p,n);
    sort(p , p + n , sosanh);
    for(int i=0;i<n;i++)
        cout << p[i].x << " " << p[i].y << "\n";
    delete []p;
    return 0;
}