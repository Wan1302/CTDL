#include <iostream>
#include <string>
using namespace std;

struct Data {
    unsigned int MSSV;
    string HoTen;
    double Diem;
};

struct TNode {
    Data Info;
    TNode* pLeft;
    TNode* pRight;
};

typedef TNode* TREE;

void CreateTree(TREE& T) {
    T = NULL;
}

TNode* CreateTNode(int x, string s, double y) {
    TNode* p = new TNode;
    if (p == NULL) {
        exit(1);
    }
    else {
        p->Info.MSSV = x;
        p->Info.HoTen = s;
        p->Info.Diem = y;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}

int insertNode(TREE& T, TNode* p) {
    if (T == NULL) {
        T = p;
        return 1;
    }
    if (T->Info.MSSV == p->Info.MSSV) {
        return 0;
    }
    if (T->Info.MSSV > p->Info.MSSV) {
        return insertNode(T->pLeft, p);
    }
    else {
        return insertNode(T->pRight, p);
    }
}

void Nhap(TREE& T, int n) {
    TNode* p;
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

void RNL(TREE T) {
    if (T != NULL) {
        RNL(T->pRight);
        cout << T->Info.MSSV << " " << T->Info.HoTen << " " << T->Info.Diem << endl;
        RNL(T->pLeft);
    }
}

int main() {
    TREE T;
    CreateTree(T);
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    Nhap(T, n);
    RNL(T);
    return 0;
}
