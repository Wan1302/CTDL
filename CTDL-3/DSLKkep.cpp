#include <iostream>
#include <vector>
using namespace std;
typedef struct tagDnode
{
    int Info;
    struct tagDnode *pPre;
    struct tagDnode *pNext;
}DNode;

typedef struct tagDList
{
    DNode *pHead;
    DNode *pTail;
}DList;

DNode *CreateDNode(int x) {
    DNode *tam;
    tam=new DNode;
    if(tam==NULL) {
        printf("khong con du bo nho");
        exit(1);
    }
    else {
        tam->Info=x;
        tam->pNext=NULL;
        tam->pPre=NULL;
        return tam;
    }
}

void AddFirst(DList &l, DNode *tam)
{
    if(l.pHead==NULL)//xau rong
    {
        l.pHead=tam;
        l.pTail=l.pHead;
    }
    else
    {
        tam->pNext=l.pHead;
        l.pHead->pPre=tam;
        l.pHead=tam;
    }
}
void AddEnd(DList &l,DNode *tam)
{
    if(l.pHead==NULL)
    {
        l.pHead=tam;
        l.pTail=l.pHead;
    }
    else
    {
        tam->pPre=l.pTail;
        l.pTail->pNext=tam;
        tam=l.pTail;
    }
}
void AddLastQ(DList &l,DNode *tam, DNode *q)
{
    DNode *p;
    p=q->pNext;
    if(q!=NULL) //them vao duoc
    {
        tam->pNext=p;
        tam->pPre=q;
        q->pNext=tam;
        if(p!=NULL) p->pPre=tam;
        if(q==l.pTail) l.pTail=tam;
    }
    else
        AddFirst(l,tam);
}

void AddBeforeQ(DList &l,DNode *tam,DNode *q)
{   DNode *p;
    p=q->pPre;
    if(q!=NULL)
    {
        tam->pNext=q;
        q->pPre=tam;
        tam->pPre=p;
        if(p!=NULL) p->pNext=tam;
        if(q==l.pHead) l.pHead = tam;
    }
    else
        AddEnd(l,tam);
}

void DeleteFirst(DList &l)
{
    DNode *p;
    if(l.pHead!=NULL)
    {
        p=l.pHead;
        l.pHead=l.pHead->pNext;
        l.pHead->pPre=NULL;
        delete p;
        if(l.pHead==NULL)
            l.pTail=NULL;
    }
}

void DeleteEnd(DList &l )
{
    DNode *p;
    if(l.pHead!=NULL)
    {
        p=l.pTail;
        l.pTail=l.pTail->pPre;
        l.pTail->pNext=NULL;
        delete p;
        if(l.pTail==NULL)
            l.pHead=NULL;
    }
}


void DeleteLastQ(DList &l, DNode* q)
{
    if(q->pNext==l.pTail)
    {
        DeleteEnd(l);
        return;
    }
    DNode* r=q->pNext;
    q->pNext=r->pNext;
    r->pNext->pPre=q;
    delete r;
}
int DeleteX(DList &l, int x)
{
    DNode *p, *q;
    q=NULL;
    p=l.pHead;
    while(p!=NULL)
    {
        if(p->Info==x) break;
        q=p; //q la Node co truong Info = x
        p=p->pNext;
    }
    if(q==NULL) return 0;
    if(q!=NULL)
        DeleteLastQ(l,q);
    else
        DeleteFirst(l);
    return 1;
}


void hoanvi(DNode *p, DNode *q) {
    int temp = p->Info;
    p->Info = q->Info;
    q->Info = temp;
}
void DoiChoTrucTiep(DList &l)
{   DNode *p,*q;
    p=l.pHead;
    while(p!=l.pTail)
    {
        q=p->pNext;
        while(q!=NULL)
    {
        if(p->Info > q->Info)
            hoanvi(p,q);
        q=q->pNext;
    }
    p=p->pNext;
    }
}