#include <iostream>
using namespace std;
typedef struct tagTNode
{
    int Key; //trường dữ liệu là 1 số nguyên
    struct tagTNode *pLeft;
    struct tagTNode *pRight;
}TNode;

typedef TNode *TREE;
void CreateTree(TREE &T) {
    T = NULL;
}
TNode *CreateTNode(int x)
{   TNode *p;
    p = new TNode; //cấp phát vùng nhớ động
    if(p==NULL)
        exit(1); // thoát
    else
    {   p->Key = x; //gán trường dữ liệu của nút = x
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}
int insertNode(TREE &T, TNode *p)
{
    if(T == NULL) // nếu cây rỗng
    {
        T = p; // thêm node p vào gốc
        return 1;
    }
    if(T->Key == p->Key) return 0; // nếu key đã tồn tại thì không thêm
    if(T->Key > p->Key) // nếu key của node gốc lớn hơn key của node p
        return insertNode(T->pLeft, p); // thêm node p vào cây con bên trái của gốc
    else // nếu key của node gốc nhỏ hơn key của node p
        return insertNode(T->pRight, p); // thêm node p vào cây con bên phải của gốc
}
void Nhap(TREE &T, int x) {
    do {
        TNode *p = CreateTNode(x);
        if(insertNode(T, p) == 0) break;
    }while(1);
}
void LNR(TREE T) {
    if(T != NULL) {
        LNR(T->pLeft);
        cout << T->Key << " ";
        LNR(T->pRight);
    }
}
void LRN(TREE T) {
    if(T != NULL) {
        LRN(T->pLeft);
        LRN(T->pRight);
        cout << T->Key << " ";
    }
}
void NLR(TREE T) {
    if(T != NULL) {
        cout << T->Key << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}
void NRL(TREE T) {
    if(T != NULL) {
        cout << T->Key << " ";
        NRL(T->pRight);
        NRL(T->pLeft);
    }
}
void RNL(TREE T) {
    if(T != NULL) {
        RNL(T->pRight);
        cout << T->Key << " ";
        RNL(T->pLeft);
    }
}
void RLN(TREE T) {
    if(T != NULL) {
        RNL(T->pLeft);
        cout << T->Key << " ";
        RNL(T->pRight);
    }
}
int SoNguyenTo(int x) {
    if(x <= 1) return 0;
    for(int i=2;i<=x;i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
void TheMang(TREE &T, TREE &R) {
    if(T->pLeft != NULL) 
        TheMang(T, R->pLeft);
    else {
        T->Key = R->Key;
        T = R;
        R = R->pRight;
    }
}
void DeleteNodeX1(TREE &T,int x)
{   if(T!=NULL)
    {   if(T->Key<x) DeleteNodeX1(T->pRight,x);
        else
        {   if(T->Key>x) DeleteNodeX1(T->pLeft,x);
            else //tim thấy Node có trường dữ liệu = x
            {   TNode *p;
                p=T;
                if (T->pLeft==NULL) T = T->pRight;
                else
                {   if(T->pRight==NULL) T=T->pLeft;
                    else TheMang(p, T->pRight);// tìm bên cây con phải
                }
                delete p;
            }
        }
    }
    else printf("Khong tim thay phan can xoa tu");
}
TNode *SearchTNode(TREE T, int x)
{   if(T!=NULL)
    {   if(T->Key==x)
            return T;
        else {
            if(x>T->Key) return SearchTNode(T->pRight,x);
            else return SearchTNode(T->pLeft,x);
        }
    }
    return NULL;
}
int DemSoNut(TREE t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + DemSoNut(t->pLeft) + DemSoNut(t->pRight);
    }
}
int DemSoNutCoDu2(TREE T) {
    if(T == NULL) {
        return 0;
    }
    int count = 0;
    if(T->pLeft != NULL && T->pRight) count = 1;
    count += DemSoNutCoDu2(T->pLeft) + DemSoNutCoDu2(T->pRight);
    return count;
}
int DemNutLa(TREE T) {
    if(T == NULL) return 0;
    if(T->pLeft == NULL && T->pRight == NULL) return 1;
    int LeftTree = DemNutLa(T->pLeft);
    int RightTree = DemNutLa(T->pRight);
    return LeftTree + RightTree;
}
int Height(TREE T) {
    if(T == NULL) return 0;
    int LeftHeight = Height(T->pLeft);
    int RightHeight = Height(T->pRight);
    return max(LeftHeight, RightHeight) + 1;
}
int main () {
    TREE T;
    CreateTree(T);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        Nhap(T, x);
    }
    int y = DemNutLa(T);
    cout << y;
    return 0;
}