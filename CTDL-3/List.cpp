#include <iostream>
#include <string.h>
using namespace std;
struct Node {
    int Info;
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
void CreateList(List &l) {
    l.head = NULL;
    l.tail = NULL;
}
void RemoveList(List &l) {
    Node *p;
    while(l.head !=NULL) {
        p = l.head;
        l.head = p->next;
        delete p;
    }
    l.tail = NULL;
}
Node* CreateNode(int x) {
    Node* p;
    p = new Node;
    if(p == NULL) exit(1);
    p->Info = x;
    p->next = NULL;
    return p;
}
void AddHead(List &l, Node* p) {
    if(l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    }
    else {
        p->next = l.head;
        l.head = p;
    }
}
void AddTail(List &l, Node *p) {
    if(l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
void InsertAfter(List &l, Node *q, Node *p) {
    if(q != NULL) {
        p->next = q->next;
        q->next = p;
        if(l.tail == q) {
            l.tail = p;
        }
    }
    else {
        AddTail(l, p);
    }
}
void RemoveHead(List &l) {
    if(l.head == NULL) return;
    Node* p = l.head;
    l.head = l.head->next;
    delete p;
}
void RemoveAfter(List &l, Node *q) {
    Node *p = l.head;
    if(q != NULL) {
        p = q->next;
        if(p != NULL) {
            q->next = p->next;
            if(p == l.tail)
                l.tail = q;
            delete p;
        }
    }
}
void RemoveX(List &l, int x) {
    Node *p, *q = NULL;
    p = l.head;
    while((p != NULL) && p->next->Info != x) {
        q = p;
        p = p->next;
    }
    if(p == NULL) 
        cout << "Khong tim thay";
    else {
        if(q == NULL) RemoveHead(l);
        else {
            q->next = p->next; 
            if(p == l.tail) 
                l.tail = q;
            delete p;
        }
    }
}
bool Search(List &l, int x) {
    Node *p;
    p = l.head;
    while(p != NULL) {
        if(p->Info == x) return 1;
        p = p->next;
    }
    return 0;
}
void SelectionSort(List &l) {
    Node *p, *q, *min;
    for(p = l.head; p->next != NULL; p = p->next) {
        min = p;
        for(q = p->next; q != NULL; q = q->next) {
            if(q->Info < min->Info)
                min = q;
        }
        swap(min->Info , p->Info);
    } 
}
void Print(List l) {
    Node *p = l.head;
    while(p != NULL) {
        cout << p->Info << " ";
        p = p->next;
    }
    cout << endl;
}
void Insert(List &l, Node* p) {
    Node *k = l.head;
    while(k->next != NULL) {
        if(k->Info <= p->Info && k->next->Info >= p->Info) {
            InsertAfter(l , k , p);
            return;
        }
        k = k->next;
    }
    AddTail(l, p);
}
int main () {
    List l;
    int n;
    unsigned int s;
    Node *p = new Node();
    CreateList(l);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        p = CreateNode(s);
        AddTail(l , p);
    }
    Print(l);
    int x;
    cin >> x;
    cout << Search(l ,x) << endl;
    RemoveHead(l);
    RemoveX(l, x);
    SelectionSort(l);
    Print(l);
    cin >> s;
    p = CreateNode(s);
    Insert(l, p);
    Print(l);
    return 0;
}