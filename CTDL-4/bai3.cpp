#include <iostream>
using namespace std;
struct Tnode
{
    int key; // dữ liệu của nút
    struct Tnode *left;
    struct Tnode *right;
};
typedef struct Tnode treeNode;
typedef treeNode *TREE;
void CreateTree(TREE &T) {
    T = NULL;
}
Tnode *CreateTNode(int x)
{   Tnode *p;
    p = new Tnode; //cấp phát vùng nhớ động
    if(p==NULL)
        exit(1); // thoát
    else
    {   p->key = x; //gán trường dữ liệu của nút = x
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}
int insertNode(TREE &T, Tnode *p)
{
    if(T == NULL) // nếu cây rỗng
    {
        T = p; // thêm node p vào gốc
        return 1;
    }
    if(T->key == p->key) return 0; // nếu key đã tồn tại thì không thêm
    if(T->key > p->key) // nếu key của node gốc lớn hơn key của node p
        return insertNode(T->left, p); // thêm node p vào cây con bên trái của gốc
    else // nếu key của node gốc nhỏ hơn key của node p
        return insertNode(T->right, p); // thêm node p vào cây con bên phải của gốc
}
void Nhap(TREE &T, int x) {
    do {
        Tnode *p = CreateTNode(x);
        if(insertNode(T, p) == 0) break;
    }while(1);
}
int countLeaf(treeNode *Root) {
    if(Root == NULL) return 0;
    if(Root->left == NULL && Root->right == NULL) return 1;
    int LeftTree = countLeaf(Root->left);
    int RightTree = countLeaf(Root->right);
    return LeftTree + RightTree;
};
int OddSum(treeNode *Root) {
    int sum = 0;
    if(Root != NULL) {
        if(Root->key % 2 != 0) sum += Root->key;
        sum += OddSum(Root->left);
        sum += OddSum(Root->right);
    }
    return sum;
}
int Sum(treeNode *Root) {
    int sum = 0;
    if(Root != NULL) {
        sum += Root->key;
        sum += Sum(Root->left);
        sum += Sum(Root->right);
    }
    return sum;
}
int EvenLeaf(treeNode *Root) {
    int count = 0;
    if(Root != NULL) {
        if(Root->key % 2 == 0) count++;
        count += EvenLeaf(Root->left);
        count += EvenLeaf(Root->right);
    }
    return count;
}
int countNodes(treeNode *Root, int k) {
    int count = 0;
    if(Root != NULL) {
        if(Root->key > k) count++;
        count += countNodes(Root->left, k);
        count += countNodes(Root->right, k);
    }
    return count;
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
    cout << countNodes(T, 50);
    return 0;
}