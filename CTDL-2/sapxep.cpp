#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
void QuickSort(int a[] , int left , int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];
    while(i <= j) {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j) {
            swap(a[i] , a[j]);
            i++;     
            j--;
        }
    }
    if(i < right) QuickSort(a,i,right);
    if(j > left) QuickSort(a,left,j);
}

void InsertionSort(int a[] , int n) {
    int i, key, j;
    for(int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
    while(j >= 0 && a[j] > key) {
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = key;
    }
}


void SelectionSort(int a[], int n) {
    int min, i, j;
    for(i = 0;i < n;i++) {
        min = i;
        for(int j = i + 1;j<n;j++) {
            if(a[min] > a[j])
                min = j;
        }
        swap(a[min] , a[i]);
    }
}

void CountingSort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);

    // Đếm số lần xuất hiện của từng phần tử trong mảng
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    // Cập nhật lại mảng count với số lần xuất hiện tích lũy
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    // Tạo mảng kết quả đã sắp xếp
    vector<int> result(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Gán giá trị của mảng kết quả đã sắp xếp vào mảng ban đầu
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = result[i];
    }
}


void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void RadixSort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int max = *max_element(arr , arr + n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


void merge(int a[] , int l , int m, int r) {
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()) {
        if(x[i] <= y[j]) {
            a[l] = x[i];
            ++l;
            ++i;
        }
        else {
            a[l] = y[j];
            ++l;
            ++j;
        }
    }
    while(i < x.size()) {
        a[l] = x[i];
        ++l;
        ++i;
    }
    while(j < y.size()) {
        a[l] = y[j];
        ++l;
        ++j;
    }
}
void MergeSort(int a[], int l, int r) {
    if(l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a , l , m);
    MergeSort(a , m + 1, r);
    merge(a, l, m, r);
}



void Heapify(int a[], int n, int i) {
    int max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && a[l] > a[max])
        max = l;
    if(r < n && a[r] > a[max]) 
        max = r;
    if(max != i) {
        swap(a[i] , a[max]);
        Heapify(a, n, max);
    }
}
void HeapSort(int a[], int n) {
    for(int i = n/2-1; i>=0; i--) {
        Heapify(a,n,i);
    }
    for(int i = n - 1; i >= 0;i--) {
        swap(a[i] , a[0]);
        Heapify(a,i,0);
    }
}

void InterchangeSort(int a[] , int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[j] < a[i]) {
                swap(a[i],a[j]);
            }
        }
    }
}

void BubbleSort(int a[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=n-1;j>i;j--) {
            if(a[j] < a[j-1]) {
                swap(a[j] , a[j-1]);
            }
        }
    }
}
int main () {
    int n;
    cin >> n;
    clock_t start, end;
    int *a = new int[n];
    srand(time(NULL));
    for(int i=0;i<n;i++) {
        a[i] = rand() % 1000;
    }
    start = clock();
    RadixSort(a, n);
    end = clock();
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    double time_use;
    time_use = double(end - start) / CLOCKS_PER_SEC;
    cout << time_use;
    return 0;
}