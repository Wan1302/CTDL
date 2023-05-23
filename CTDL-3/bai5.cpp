// #include <iostream>
// using namespace std;

// const int MAX_SIZE = 100;

// struct Stack {
//     int data[MAX_SIZE];
//     int top;
// };

// void Initialize(Stack& stack) {
//     stack.top = -1;
// }

// bool IsEmpty(const Stack& stack) {
//     return stack.top == -1;
// }

// bool IsFull(const Stack& stack) {
//     return stack.top == MAX_SIZE - 1;
// }

// void Push(Stack& stack, int value) {
//     if (IsFull(stack)) {
//         cout << "Stack overflow!" << endl;
//         return;
//     }
//     stack.data[++stack.top] = value;
// }

// void Pop(Stack& stack) {
//     if (IsEmpty(stack)) {
//         cout << "Stack underflow!" << endl;
//         return;
//     }
//     stack.top--;
// }

// int Top(const Stack& stack) {
//     if (IsEmpty(stack)) {
//         cout << "Stack is empty!" << endl;
//         return -1;
//     }
//     return stack.data[stack.top];
// }

// int main() {
//     Stack stack;
//     Initialize(stack);
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++) {
//         int s;
//         cin >> s;
//         Push(stack, s);
//     }
//     cout << "Top element: " << Top(stack) << endl;
//     Pop(stack);
//     cout << "Top element: " << Top(stack) << endl;
//     return 0;
// }



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void Initialize(Stack& stack) {
    stack.top = nullptr;
}

bool IsEmpty(const Stack& stack) {
    return stack.top == nullptr;
}

void Push(Stack& stack, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode;
}

void Pop(Stack& stack) {
    if (IsEmpty(stack)) {
        cout << "Stack underflow!" << endl;
        return;
    }
    Node* temp = stack.top;
    stack.top = stack.top->next;
    delete temp;
}

int Top(const Stack& stack) {
    if (IsEmpty(stack)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return stack.top->data;
}

int main() {
    Stack stack;
    Initialize(stack);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int s;
        cin >> s;
        Push(stack, s);
    }
    cout << "Top element: " << Top(stack) << endl;
    Pop(stack);
    cout << "Top element: " << Top(stack) << endl;

    return 0;
}