// #include <iostream>
// using namespace std;

// const int MAX_SIZE = 100;

// struct Queue {
//     int data[MAX_SIZE];
//     int front;
//     int rear;
// };

// void Initialize(Queue& queue) {
//     queue.front = -1;
//     queue.rear = -1;
// }

// bool IsEmpty(const Queue& queue) {
//     return queue.front == -1;
// }

// bool IsFull(const Queue& queue) {
//     return (queue.rear + 1) % MAX_SIZE == queue.front;
// }

// void Enqueue(Queue& queue, int value) {
//     if (IsFull(queue)) {
//         cout << "Queue overflow!" << endl;
//         return;
//     }
//     if (IsEmpty(queue))
//         queue.front = 0;
//     queue.rear = (queue.rear + 1) % MAX_SIZE;
//     queue.data[queue.rear] = value;
// }

// void Dequeue(Queue& queue) {
//     if (IsEmpty(queue)) {
//         cout << "Queue underflow!" << endl;
//         return;
//     }
//     if (queue.front == queue.rear)
//         queue.front = queue.rear = -1;
//     else
//         queue.front = (queue.front + 1) % MAX_SIZE;
// }

// int Front(const Queue& queue) {
//     if (IsEmpty(queue)) {
//         cout << "Queue is empty!" << endl;
//         return -1;
//     }
//     return queue.data[queue.front];
// }

// int main() {
//     Queue queue;
//     Initialize(queue);
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++) {
//         int s;
//         cin >> s;
//         Enqueue(queue, s);
//     }
//     cout << "Front element: " << Front(queue) << endl;
//     Dequeue(queue);
//     cout << "Front element: " << Front(queue) << endl;
//     return 0;
// }


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void Initialize(Queue& queue) {
    queue.front = nullptr;
    queue.rear = nullptr;
}

bool IsEmpty(const Queue& queue) {
    return queue.front == nullptr;
}

void Enqueue(Queue& queue, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (IsEmpty(queue)) {
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

void Dequeue(Queue& queue) {
    if (IsEmpty(queue)) {
        cout << "Queue underflow!" << endl;
        return;
    }

    Node* temp = queue.front;
    queue.front = queue.front->next;
    if (queue.front == nullptr)
        queue.rear = nullptr;

    delete temp;
}

int Front(const Queue& queue) {
    if (IsEmpty(queue)) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return queue.front->data;
}

int main() {
    Queue queue;
    Initialize(queue);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int s;
        cin >> s;
        Enqueue(queue, s);
    }
    cout << "Front element: " << Front(queue) << endl;
    Dequeue(queue);
    cout << "Front element: " << Front(queue) << endl;
    return 0;
}
