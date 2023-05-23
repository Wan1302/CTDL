#include <iostream>
#include <stack>
using namespace std;

// Hàm đệ quy để di chuyển các đĩa từ cột nguồn sang cột đích, sử dụng cột trung gian
void TowerOfHanoi(int n, stack<int>& CotNguon, stack<int>& CotTrungGian, stack<int>& CotDich) {
    if (n > 0) {
        // Di chuyển n-1 đĩa từ cột nguồn sang cột trung gian, sử dụng cột đích làm cột trung gian
        TowerOfHanoi(n - 1, CotNguon, CotDich, CotTrungGian);

        // Di chuyển đĩa cuối cùng từ cột nguồn sang cột đích
        int disk = CotNguon.top();
        CotNguon.pop();
        CotTrungGian.push(disk);
        // Di chuyển n-1 đĩa từ cột trung gian sang cột đích, sử dụng cột nguồn làm cột trung gian
        TowerOfHanoi(n - 1, CotDich, CotTrungGian, CotNguon);
    }
}

int main() {
    int n;
    cout << "Nhap so luong dia: ";
    cin >> n;

    stack<int> CotNguon, CotTrungGian, CotDich;

    // Khởi tạo cột nguồn ban đầu
    for (int i = n; i >= 1; i--) {
        CotNguon.push(i);
    }

    // Gọi hàm đệ quy để di chuyển các đĩa từ cột nguồn sang cột đích, sử dụng cột trung gian
    TowerOfHanoi(n, CotNguon, CotTrungGian, CotDich);

    // Hiển thị kết quả cuối cùng
    cout << "Cot dich chua cac dia theo thu tu: ";
    while (!CotTrungGian.empty()) {
        cout << CotTrungGian.top() << " ";
        CotTrungGian.pop();
    }
    cout << endl;

    return 0;
}
