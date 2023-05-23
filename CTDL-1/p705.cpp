#include <iostream>
using namespace std;
int main () {
    int n , m;
    double sum = 0;
    cin >> n >> m;
    double **a = new double *[n];
    for(int i=0;i<n;i++) {
        a[i] = new double[m];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i == j) sum += a[i][j];
        }
    }
    cout << sum;
    return 0;
}