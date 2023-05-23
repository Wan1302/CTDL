#include <iostream>
#include <string.h>
using namespace std;
struct HH {
    string Ten;
    double Gia;
    int Remain;
    HH *next;
};
struct List {
    HH* head;
    HH* tail;
};
void CreateList(List &l) {
    l.head = NULL;
    l.tail = NULL;
}
HH* CreateNode(string s, double x, int y) {
    HH *p;
    p = new HH();
    if(p == NULL) exit(1);
    p->Ten = s;
    p->Gia = x;
    p->Remain = y;
    p->next = NULL;
    return p;
}
void AddTail(List &l, HH *p) {
    if(l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
void Swap(HH *p , HH *q) {
    swap(p->Ten, q->Ten);
    swap(p->Gia, q->Gia);
    swap(p->Remain, q->Remain);
}
void SelectionSort(List &l) {
    HH *p, *q, *min;
    for (p = l.head; p != NULL; p = p->next) {
        min = p;
        for (q = p->next; q != NULL; q = q->next) {
            if (q->Gia < min->Gia || (q->Gia == min->Gia && q->Ten.compare(min->Ten) < 0)) {
                min = q;
            }
        }
        Swap(min, p);
    }
}
void PrintHead(List l) {
    HH *p = l.head;
    while(p != NULL) {
        cout << p->Ten << endl;
        p = p->next;
    }
    cout << endl;
}
void Print(List l, int x, int y) {
    HH *p = l.head;
    while(p != NULL) {
        if(p->Remain > x && p->Remain < y) cout << p->Ten << endl;
        p = p->next;
    }
    cout << endl;
}
int main () {
    List l;
    int n,x,y;
    string s; // ten
    double a; // gia
    int b;    // soluong
    cin >> n;
    cin.ignore();
    CreateList(l);
    HH* p = new HH();
    for(int i=0;i<n;i++) {
        getline(cin, s);
        cin >> a >> b;
        cin.ignore();
        p = CreateNode(s, a, b);
        AddTail(l , p);
    }
    SelectionSort(l);
    PrintHead(l);
    do {
        cin >> x >> y;
    }while(x < y);
    Print(l, x, y);
    return 0;
}