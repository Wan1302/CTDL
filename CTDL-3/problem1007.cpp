#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
void Insert(SinhVien A[], int x) {
    char a[10],b[100],c[12];
    char d;
    float e,f,g;
    cin.getline(a, 10);
    cin.getline(b, 100);
    cin.getline(c, 12);
    cin >> d;
    cin >> e >> f >> g;
    cin.ignore();
    strcpy(A[x].MASV, a);
    strcpy(A[x].HoTen, b);
    strcpy(A[x].NgaySinh, c);
    A[x].GioiTinh = d;
    A[x].DiemToan = e;
    A[x].DiemLy = f;
    A[x].DiemHoa = g;
    A[x].DTB = (e + f + g) / 3;
}
void Nhap(SinhVien A[], int &n) {
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++) {
        Insert(A, i);
    }
}
void Swap(SinhVien &A, SinhVien &B) {
    swap(A.MASV, B.MASV);
    swap(A.HoTen, B.HoTen);
    swap(A.NgaySinh, B.NgaySinh);
    swap(A.GioiTinh, B.GioiTinh);
    swap(A.DiemToan, B.DiemToan);
    swap(A.DiemLy, B.DiemLy);
    swap(A.DiemHoa, B.DiemHoa);
    swap(A.DTB, B.DTB);
}
void SapXepGiamTheoMASV(SinhVien A[], int n) {
    int max, i, j;
    for(i = 0;i < n;i++) {
        max = i;
        for(int j = i + 1;j<n;j++) {
            if(stoi(A[max].MASV) < stoi(A[j].MASV))
                max = j;
        }
        Swap(A[max] , A[i]);
    }
}
void Xuat(SinhVien A[], int &n) {
    for(int i=0;i<n;i++) {
        cout << A[i].MASV << "\t" << A[i].HoTen << "\t" << A[i].NgaySinh << "\t" << A[i].GioiTinh << "\t" << setprecision(3) << A[i].DiemToan << "\t" << A[i].DiemLy << "\t" << A[i].DiemHoa << "\t" << A[i].DTB << endl; 
    }
}
int main() {
    SinhVien A[MAXN];
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}