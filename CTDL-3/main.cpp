
#include <iostream>
using namespace std;

struct node{
    unsigned  int info;
    node *next;
};
struct List{
    node *head;
    node *tail;
};
List L;
node * create(unsigned int x){
    node *p = new node();
    p->info = x;
    p->next = NULL;
    return p;
}
void AddFirst(List &L, node *x){
    if (L.head == NULL){
        L.head = x;
        L.tail = L.head;
    }
    else {
        x->next=L.head;
        L.head = x;
    }
}
void AddLast(List &L, node *x){
    if (L.head != NULL){
        L.tail->next = x;
        L.tail = x;
        }
    else AddFirst(L,x);
}
void AddAfter(List &L, node *p, node *q){
    if (q != NULL){
        p->next = q->next;
        q->next = p;
        if(q == L.tail) L.tail = p;
    }
    else AddFirst(L,p);
}
void DeleteFirst(List &L){
    node *p = L.head;
    L.head = L.head -> next;
    delete p;
}
void DeleteLast(List &L){
    node *p = L.head;
    while (p -> next -> next !=NULL)
        p = p->next;
    L.tail = p;
    L.tail->next = NULL;
}
void DeleteNode(List &L, unsigned int x){
    node *k = L.head;
    node *q;
    if (L.head ->info == x) {DeleteFirst(L);return;}
    while( k ->next != NULL ){
        if ( q -> next -> info == x) {
            node * temp = k -> next;
            k -> next = k -> next -> next;
            delete temp;
            return;
                    }
    else k = k -> next;
    }
     return;
    }
void printReverse(node * head)
{
    if (head == NULL)
    return;

    // print the list after head node
    printReverse(head -> next);

    // After everything else is printed, print head
    cout << head ->  info << " ";
}
void Print(List L){
    node *p = L.head;
	while (p!=NULL){
        cout << p -> info << " ";
        p = p -> next;
}
}
void selectionSort(List &L)
{
    node *i = L.head, *j = NULL, *min_idx = NULL;
    // One by one move boundary of
    // unsorted subarray
    while(i != NULL)
    {
        min_idx = i;
        j = i->next;
        while (j != NULL){
          if (j ->info < min_idx -> info)
              min_idx = j;
          j = j -> next;
        }
        if (min_idx!=i)
            swap(min_idx -> info, i -> info);
        i = i -> next;
    }
}
bool finding(List L, unsigned int x){
    node *p = L.head;
    while (p != NULL){
        if (p->info == x) return 1;
        p = p -> next;
    }
    return 0;
}
void Chen(List &L, node *p){
    node * k = L.head;
    while(k != NULL){
        if (k->info <= p ->info && k->next->info >= p->info)
            {AddAfter(L,p,k);return;}
    k = k ->next;
    }
    if (k == NULL) AddLast(L,p);
    return;
}
int main()
{
	List L;
	int n;
	unsigned int s;
	node *p = new node();
	L.head = NULL;
	cin >>n;
	for (int i = 0; i < n; i++){
        cin >> s;
         p = create(s);
         if (L.head == NULL) AddFirst(L,p);
         else AddAfter(L,p,L.tail);
	}
    DeleteFirst(L);
    Print(L);
    cout << endl;
    selectionSort(L);
    Print(L);
    cout << endl;
    cin >> s;
    p = create(s);
    Chen(L,p);
    Print(L);
    return 0;
}
