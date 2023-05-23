#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};
void AddTail(DATHUC &B, Node* p) {
    if(p->data->heso != 0) {
        if (B.head == NULL) {
            B.head = p;
            B.tail = B.head;
        }
        else {
            B.tail->next = p;
            B.tail = p;
        }
    }
}
void Nhap(DATHUC& B, double heso, int somu) {
    DONTHUC* p = new DONTHUC(heso, somu);
    Node* newNode = new Node(p);
    AddTail(B, newNode);
}
void Xuat(DATHUC& B) {
    if(B.head == NULL) cout << 0;
    else {
    Node* p = B.head;
    while (p != nullptr) {
        if(p->data->heso == 0) {
            p = p->next;
            continue;
        }
        if(p == B.head) {
            if(p->data->heso == 1) {
                if(p->data->somu == 0) cout << 1;
                else if(p->data->somu == 1) cout << "x";
                else cout << "x^" << p->data->somu;
            }
            else if(p->data->heso == -1) {
                if(p->data->somu == 0) cout << -1;
                else if(p->data->somu == 1) cout << "-x";
                else cout << "-x^" << p->data->somu;
            }
            else {
                if(p->data->somu == 0) cout << p->data->heso;
                else if(p->data->somu == 1) cout << p->data->heso << "x";
                else cout << p->data->heso << "x^" << p->data->somu;
            }
        }
        else {
            if(p->data->heso == 1) {
                if(p->data->somu == 0) cout << "+1";
                else if(p->data->somu == 1) cout << "+x";
                else cout << "+x^" << p->data->somu;
            }
            else if(p->data->heso == -1) {
                if(p->data->somu == 0) cout << "-1";
                else if(p->data->somu == 1) cout << "-x";
                else cout << "-x^" << p->data->somu;
            }
            else if(p->data->heso > 0) {
                if(p->data->somu == 0) cout << "+" << p->data->heso;
                else if(p->data->somu == 1) cout << "+" << p->data->heso << "x";
                else cout << "+" << p->data->heso << "x^" << p->data->somu;
            }
            else {
                if(p->data->somu == 0) cout << p->data->heso;
                else if(p->data->somu == 1) cout << p->data->heso << "x";
                else cout << p->data->heso << "x^" << p->data->somu;
            }
        }
        p = p->next;
    }
    }
}

double TinhDaThuc(DATHUC& B, double x) {
    double result = 0;
    Node* p = B.head;
    while (p != nullptr) {
        result += p->data->heso * pow(x, p->data->somu);
        p = p->next;
    }
    return result;
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
