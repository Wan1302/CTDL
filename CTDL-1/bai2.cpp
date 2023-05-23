#include <iostream>
#include <algorithm>
using namespace std;
void nhap(int **a, int n, int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
}
void xuat(int **a, int n, int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int Max(int **a, int n, int m) {
    int max = a[0][0];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] > max) max = a[i][j];
        }
    }
    return max;
}
int Min(int **a, int n, int m) {
    int min = a[0][0];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] > min) min = a[i][j];
        }
    }
    return min;
}
void zigzagSort(int **a, int n, int m) {
    int  b[n*m];
    int index = 0;
    for(int i=0;i<n;i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < m; j++) {
                b[index++] = a[i][j];
            }
        }
        else {
            for(int j = m - 1; j >= 0; j--) {
                b[index++] = a[i][j];
            }
        }
    }

    sort(b, b + n*m);
    index = 0;
    for(int i=0;i<n;i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < m; j++) {
                a[i][j] = b[index++];
            }
        }
        else {
            for(int j = m - 1;j>=0;j--) {
                a[i][j] = b[index++];
            }
        }
    }
}
void spiralSort(int **a, int n, int m) {
    int b[n*m];
    int index = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            b[index++] = a[i][j];
        }
    }
    sort(b , b + n*m);
    index = 0;
    int h1 = 0, h2 = n -1, c1 = 0, c2 = m - 1;
    while(h1 <= h2 && c1 <= c2) {
        for(int i=c1;i<=c2;i++) {
            a[h1][i] = b[index++];
        }
        ++h1;
        for(int i=h1;i<=h2;i++) {
            a[i][c2] = b[index++];
        }
        --c2;
        if(c1 <= c2) {
            for(int i=c2;i>=c1;i--) {
                a[h2][i] = b[index++];
            }
            --h2;
        }
        if(h1 <= h2) {
            for(int i=h2;i>=h1;i--) {
                a[i][c1] = b[index++];
            }
            ++c1;
        }
    }

}
void Insert(int **a, int &n, int m) {
    n++;
    a[n-1] = new int[m];
    for(int i=0;i<m;i++) {
        cin >> a[n-1][i];
    }
}
void RemoveLine(int **a, int &n, int m, int k) {
    for(int i=k;i<n-1;i++) {
        for(int j=0;j<n;j++)
            a[i][j] = a[i+1][j];
    }
    n--;
}
void RemoveColumn(int **a, int n, int &m, int k) {
    for(int i=k;i<m-1;i++) {
        for(int j=0;j<n;j++)
            a[j][i] = a[j][i+1];
    }
    m--;
}
void FindMaxMin(int **a, int n, int m) {
    int index1, index2;
    for(int i=0;i<n;i++) {
        int max = a[i][0];
        for(int j=1;j<m;j++) {
            if(a[i][j] > max) {
                max = a[i][j];
                index1 = j;
                index2 = i;
            }
        }
        int k = 0;
        for(;k<n;k++) {
            if(a[k][index1] < max) {
                cout << -1 << endl;
                break;
            }
        }
        if(k == n) cout << index2 << " " << index1 << endl;
    }
}
void PhepCong(int **a, int n, int m, int **b, int l, int k) {
    int sum = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            sum = a[i][j] + b[i][j];
            cout << sum << " ";
            sum = 0;
        }
        cout << endl;
    }
}
void PhepNhan(int **a, int n, int m, int **b, int l, int k) {
    int sum = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j < k;j++) {
            for (int o=0;o<m;o++) {
                sum+= a[i][o] * b[o][j];
            }
            cout << sum << " ";
            sum = 0;
        }
        cout << endl;
    }
}
void SumLine(int **a, int m, int k) {
    int sum = 0;
    for(int i=0;i<m;i++) {
        sum += a[k][i];
    }
    cout << sum << endl;
}
void SumColumn(int **a, int n, int k) {
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += a[i][k];
    }
    cout << sum << endl;
}
int main() {
    int n, m;
    cin >> n >> m;
    int **a;
    a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    nhap(a, n, m);
    // Insert(a, n, m);
    // RemoveLine(a, n, m, 2);
    // RemoveColumn(a, n, m, 3);
    //spiralSort(a,n,m);
    // FindMaxMin(a, n, m);
    // xuat(a, n, m);
    // int l,k;
    // cin >> l >> k;
    // int **b;
    // b = new int *[l];
    // for(int i=0;i<l;i++) {
    //     b[i] = new int[k];
    // }
    // nhap(b, l, k);
    // PhepCong(a, n, m, b, l, k);
    // PhepNhan(a, n, m, b, l, k);
    // SumLine(a, m, 2);
    // SumColumn(a, n, 2);
    return 0;
}