#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void merge(int a[], int n , int  b[] , int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n || j < m) {
        if (i < n && j < m) {
            if (a[i] <= b[j]) {
                c[k] = a[i];
                i++;
            } else {
                c[k] = b[j];
                j++;
            }
        } else if (i < n) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
}


int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> m;
    int *b = new int[m];
    for(int i=0;i<m;i++)
        cin >> b[i];
    int *c = new int[n + m];
	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
        return 0;
    }