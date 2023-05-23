#include <iostream>
#include <string.h>
using namespace std;
struct PhieuDK {
    string HoTen;
    string CMND;
    string Address;
    int SoLuong;
    PhieuDK *next;
};
struct List {
    PhieuDK *head;
    PhieuDK *tail;
    int GheTrong;
    int SoLuongVe;
};
void CreateList(List &l) {
    l.head = NULL;
    l.tail = NULL;
}
PhieuDK* CreateNode(string x, string y, string z, int t) {
    PhieuDK *p;
    p = new PhieuDK();
    if(p == NULL) exit(1);
    p->HoTen = x;
    p->CMND = y;
    p->Address = z;
    p->SoLuong = t;
    p->next = NULL;
    return p;
}
void AddTail(List &l, PhieuDK *p) {
    if(l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
    l.GheTrong -= p->SoLuong;
    l.SoLuongVe -= p->SoLuong;
}
void DuyetBanVe(List &l) {
    while (l.GheTrong > 0 && l.SoLuongVe > 0) {
        string hoTen, soCMND, diaChi;
        int soLuong;
        int flag = 0;
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap so CMND: ";
        getline(cin, soCMND);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap so luong ve: ";
        cin >> soLuong;
        cin.ignore();

        PhieuDK *p = l.head;
        while(p != NULL) {
            if(p->CMND == soCMND) {
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(flag == 1) {
            l.SoLuongVe -= soLuong;
            continue;
        }
        else {
            PhieuDK *q = new PhieuDK();
            q = CreateNode(hoTen, soCMND, diaChi, soLuong);
            AddTail(l, q);
        }
    }
}
void Print(List l) {
    PhieuDK *p = l.head;
    while(p != NULL) {
        cout << p->HoTen << " " << p->SoLuong << endl;
        p = p->next;
    }
}
int main() {
    List l;
    CreateList(l);
    l.GheTrong = 15000;
    l.SoLuongVe = 10000;
    DuyetBanVe(l);
    Print(l);
    return 0;
}