#include <iostream>
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
Node* CreateNode(int x) {
    Node* p;
    p = new Node;
    if(p == NULL) exit(1);
    p->Info = x;
    p->next = NULL;
    return p;
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
void RemoveHead(List &l) {
    if(l.head == NULL) return;
    Node* p = l.head;
    l.head = l.head->next;
    delete p;
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
void PrintHead(List l) {
    Node *p = l.head;
    while(p != NULL) {
        cout << p->Info << " ";
        p = p->next;
    }
    cout << endl;
}
void PrintTail(List l, Node *p) {
    if(p == NULL) return;
    PrintTail(l, p->next);
    cout << p->Info << " ";
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
void Insert(List &l, Node *p) {
    Node *q = l.head;
    if(l.head == NULL || l.head->Info > p->Info) {
        p->next = l.head;
        l.head = p;
    }
    else {
        while(q->next != NULL && q->next->Info < p->Info) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}
int main () {
    List l;
    int n;
    unsigned int s;
    Node *p = new Node();
    CreateList(l);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s;
        p = CreateNode(s);
        AddTail(l, p);
    }
    int x;
    cin >> x;
    Node *q = new Node();
    q = CreateNode(x);
    Insert(l, q);
    PrintHead(l);
    return 0;
}