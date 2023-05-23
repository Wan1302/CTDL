#include <iostream>
#include <string.h>
using namespace std;
struct Data {
    unsigned int MSSV;
    string HoTen;
    double Diem;
};
typedef struct tagTNode
{
    Data Info;
    struct tagTNode *pLeft;
    struct tagTNode *pRight;
}TNode;

typedef TNode *TREE;
void CreateTree(TREE &T) {
    T = NULL;
}
TNode *CreateTNode(int x, string s, double y)
{   TNode *p;
    p = new TNode; //cấp phát vùng nhớ động
    if(p==NULL)
        exit(1); // thoát
    else
    {   p->Info.MSSV = x;
        p->Info.HoTen = s;
        p->Info.Diem = y;
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
    if(T->Info.MSSV == p->Info.MSSV) return 0; // nếu key đã tồn tại thì không thêm
    if(T->Info.MSSV > p->Info.MSSV) // nếu key của node gốc lớn hơn key của node p
        return insertNode(T->pLeft, p); // thêm node p vào cây con bên trái của gốc
    else // nếu key của node gốc nhỏ hơn key của node p
        return insertNode(T->pRight, p); // thêm node p vào cây con bên phải của gốc
}
void Nhap(TREE &T, int n) {
    TNode *p;
    int x;
    double y;
    string s;
    for (int i = 0; i < n; i++) {
        cout << "Nhap MSSV: ";
        cin >> x;
        cin.ignore();
        cout << "Nhap Ten: ";
        getline(cin, s);
        cout << "Nhap Diem: ";
        cin >> y;
        p = CreateTNode(x, s, y);
        if (insertNode(T, p) == 0) {
            delete p;
        }
    }
}
int SearchTNode(TREE T, int x)
{   if(T!=NULL)
    {   if(T->Info.MSSV==x)
            return 1;
        else {
            if(x > T->Info.MSSV) return SearchTNode(T->pRight,x);
            else return SearchTNode(T->pLeft,x);
        }
    }
    return 0;
}
void TheMang(TREE &T, TREE &R) {
    if(T->pLeft != NULL) 
        TheMang(T, R->pLeft);
    else {
        T->Info = R->Info;
        T = R;
        R = R->pRight;
    }
}
void DeleteNodeX1(TREE &T, double x)
{   if(T!=NULL)
    {   if(T->Info.Diem < x) DeleteNodeX1(T->pRight,x);
        else
        {   if(T->Info.Diem > x) DeleteNodeX1(T->pLeft,x);
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
void RNL(TREE T) {
    if(T != NULL) {
        RNL(T->pRight);
        cout << T->Info.MSSV << " " << T->Info.HoTen << " " << T->Info.Diem << endl;
        RNL(T->pLeft);
    }
}
int Height(TREE T) {
    if(T == NULL) return 0;
    int LeftHeight = Height(T->pLeft);
    int RightHeight = Height(T->pRight);
    return max(LeftHeight, RightHeight) + 1;
}
int CountDegree(TNode* node) {
    if (node == NULL) {
        return 0;  // Node không tồn tại, số bậc bằng 0
    }
    
    int degree = 0;
    if (node->pLeft != NULL) {
        degree++;  // Tăng số bậc nếu tồn tại cây con trái
    }
    if (node->pRight != NULL) {
        degree++;  // Tăng số bậc nếu tồn tại cây con phải
    }
    
    return degree;
}
int NutBac0(TREE T) {
    if (T == NULL) {
        return 0;  // Cây rỗng, không có nút nào
    }

    int count = 0;
    if (T->pLeft == NULL && T->pRight == NULL) {
        count++;  // Tăng biến đếm nếu chỉ có một cây con (bậc 1)
    }
    
    // Đệ quy qua cây con trái và cây con phải để đếm số nút có bậc 1 trong các cây con
    count += NutBac0(T->pLeft);
    count += NutBac0(T->pRight);
    
    return count;
}
int NutBac1(TREE T) {
    if (T == NULL) {
        return 0;  // Cây rỗng, không có nút nào
    }

    int count = 0;
    if ((T->pLeft == NULL && T->pRight != NULL) || (T->pLeft != NULL && T->pRight == NULL)) {
        count++;  // Tăng biến đếm nếu chỉ có một cây con (bậc 1)
    }
    
    // Đệ quy qua cây con trái và cây con phải để đếm số nút có bậc 1 trong các cây con
    count += NutBac1(T->pLeft);
    count += NutBac1(T->pRight);
    
    return count;
}
int NutBac2(TREE T) {
    if (T == NULL) {
        return 0;  // Cây rỗng, không có nút nào
    }

    int count = 0;
    if (T->pLeft != NULL && T->pRight != NULL) {
        count++;  // Tăng biến đếm nếu chỉ có một cây con (bậc 1)
    }
    
    // Đệ quy qua cây con trái và cây con phải để đếm số nút có bậc 1 trong các cây con
    count += NutBac2(T->pLeft);
    count += NutBac2(T->pRight);
    
    return count;
}
int main() {
    TREE T;
    CreateTree(T);
    int n;
    cin >> n;
    Nhap(T, n);
    DeleteNodeX1(T, 5.0);
    RNL(T);
    return 0;
}