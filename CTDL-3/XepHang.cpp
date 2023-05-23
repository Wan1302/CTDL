// #include <iostream>
// using namespace std;
// struct Node {
//     int Info;
//     Node* next;
// };
// struct List {
//     Node* head;
//     Node* tail;
// };
// void CreateList(List &l) {
//     l.head = NULL;
//     l.tail = NULL;
// }
// Node* CreateNode(int x) {
//     Node* p;
//     p = new Node;
//     if(p == NULL) exit(1);
//     p->Info = x;
//     p->next = NULL;
//     return p;
// }
// void AddTail(List &l, Node *p) {
//     if(l.head == NULL) {
//         l.head = p;
//         l.tail = l.head;
//     }
//     else {
//         l.tail->next = p;
//         l.tail = p;
//     }
// }
// void Print(List l) {
//     Node *p = l.head;
//     while(p != NULL) {
//         cout << p->Info << " ";
//         p = p->next;
//     }
//     cout << endl;
// }
// void Call(List &l, int x) {
//     Node *q = NULL;
//     Node *p = l.head;
//     while(p->next != NULL && p->Info != x) {
//         q = p;
//         p = p->next;
//     }
//     if(p == NULL) return;
//     if(q != NULL) {
//         if(p->next == NULL) {
//             q->next = NULL;
//             l.tail = q;
//             p->next = l.head;
//             l.head = p;
//         }
//         else {
//             q->next = p->next;
//             p->next = l.head;
//             l.head = p;
//         }
//     }
// }
// int main () {
//     int n, m, s;
//     List l;
//     Node *p = new Node();
//     Node* *arr = new Node*[n + 1];
//     CreateList(l);
//     cin >> n >> m;
//     for(int i=1;i<=n;i++) {
//         p = CreateNode(i);
//         AddTail(l, p);
//         arr[i] = l.tail;
//     }
//     for(int i=0;i<m;i++) {
//         cin >> s;
//         Call(l, s);
//         cout << l.tail->Info << " ";
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

struct Node {
    int Info;
    Node* next;
    Node* prev; // Thêm con trỏ prev
};

struct List {
    Node* head;
    Node* tail;
};

void CreateList(List& l) {
    l.head = NULL;
    l.tail = NULL;
}

Node* CreateNode(int x) {
    Node* p;
    p = new Node;
    if (p == NULL) exit(1);
    p->Info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void AddTail(List& l, Node* p) {
    if (l.head == NULL) {
        l.head = p;
        l.tail = l.head;
    }
    else {
        l.tail->next = p;
        p->prev = l.tail;
        l.tail = p;
    }
}

void Call(List& l, Node** arr, int x) {
    Node* p = arr[x-1];
    if (p == NULL) return;

    if (p != l.head) {
        p->prev->next = p->next;
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        else {
            l.tail = p->prev;
        }
        p->next = l.head;
        p->prev = NULL;
        l.head->prev = p;
        l.head = p;
    }
}

int main() {
    int n, m, s;
    List l;
    Node* p = new Node();
    CreateList(l);
    cin >> n >> m;
    Node* *arr = new Node*[n];
    for (int i = 1; i <= n; i++) {
        p = CreateNode(i);
        AddTail(l, p);
        arr[i-1] = l.tail;
    }

    for (int i = 0; i < m; i++) {
        cin >> s;
        Call(l, arr, s);
        cout << l.tail->Info << " ";
    }
    delete[] arr;
    return 0;
}
