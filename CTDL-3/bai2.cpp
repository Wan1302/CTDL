#include <iostream>
#include <cstring>
using namespace std;
struct NS
{
    int maso; // lưu thông tin mã số nhân sự
    char * hoten ; // lưu thông tin họ và tên nhân sự
    int thamnien; // lưu thông tin số năm thâm niên
    float hesoluong ; // lưu thông tin hệ số lương
    float luongcoban ; // lưu thông tin lương cơ bản
    struct NS *next;
};
struct List {
    NS* head;
    NS* tail;
};
void CreateList(List &l) {
    l.head = NULL;
    l.tail = NULL;
}
NS *CreateNode(int x, char* c, int y, float z, float t) {
    NS *p;
    p = new NS();
    if(p == NULL) exit(1);
    p->maso = x;

    p->hoten = new char[strlen(c) + 1];
    strcpy(p->hoten, c);

    p->thamnien = y;
    p->hesoluong = z;
    p->luongcoban = t;
    p->next = NULL;
    return p;
}
void AddTail(List &l, NS *p) {
    if(l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
void PrintHead(List l, int limit) {
    NS *p = l.head;
    int count = 0;
    while(p != NULL && count < limit) {
        cout << p->hoten << endl;
        p = p->next;
        count++;
    }
    cout << endl;
}
void Swap(NS *p , NS *q) {
    swap(p->maso, q->maso);
    swap(p->hoten, q->hoten);
    swap(p->thamnien, q->thamnien);
    swap(p->hesoluong, q->hesoluong);
    swap(p->luongcoban, q->luongcoban);
}
void SelectionSortTN(List &l) {
    NS *p, *q, *max;
    for (p = l.head; p != NULL; p = p->next) {
        max = p;
        for (q = p->next; q != NULL; q = q->next) {
            if (q->thamnien >= max->thamnien) {
                max = q;
            }
        }
        Swap(max, p);
    }
}
void SelectionSortLuong(List &l) {
    NS *p, *q, *max;
    for (p = l.head; p != NULL; p = p->next) {
        max = p;
        for (q = p->next; q != NULL; q = q->next) {
            float l1 = q->hesoluong*q->luongcoban;
            float l2 = max->hesoluong*max->luongcoban;
            if (l1 >= l2) {
                max = q;
            }
        }
        Swap(max, p);
    }
}
void TinhLuong(List l) {
    NS *p = l.head;
    while(p != NULL) {
        cout << p->hoten << " " << p->hesoluong*p->luongcoban << endl;
        p = p->next;
    }
    cout << endl;
}
int main() {
    List l;
    int n;
    int x,y; // maSo, thamnien
    char c[100]; // ten
    float z,t; // heSoLuong, LuongCB
    cin >> n;
    CreateList(l);
    NS *p = new NS();
    for(int i=0;i<n;i++) {
        cin >> x;
        cin.ignore();
        cin.getline(c , 100);
        cin >> y >> z >> t;
        p = CreateNode(x, c, y, z, t);
        AddTail(l, p);
    }
    SelectionSortLuong(l);
    //TinhLuong(l);
    //SelectionSortTN(l);
    PrintHead(l, 5);
    return 0;
}