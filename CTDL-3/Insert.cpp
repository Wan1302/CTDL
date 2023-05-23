#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode* head) {
    while (head != NULL){
        cout<<head->data;
        head = head->next;
    }
}


// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertSortedLinkedList(SinglyLinkedListNode* head, int x) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(x);
    SinglyLinkedListNode *k = head;
    if (head == nullptr || head->data >= x) {
        node->next = head;
        head = node;
    }
    else {
    while(k->next != nullptr && k->next->data < x) {
        k = k->next;
    }
    node->next = k->next;
    k->next = node;
}
    return head; 
}



    // SinglyLinkedListNode *p = new SinglyLinkedListNode(x);
    // if (head == NULL || head->data>x){
    //     p->next = head;
    //     head = p;
    // }
    // else{
    //     SinglyLinkedListNode * q = head;
    //     while (q->next != NULL && q->next->data < x){
    //         q = q->next;
    //     }
    //     p->next = q->next;
    //     q->next = p;
    // }
    // return head;


    // SinglyLinkedListNode* newNode = new SinglyLinkedListNode(x);

    // if (head == nullptr) {
    //     newNode->next = nullptr;
    //     return newNode;
    // }

    // if (x < head->data) {
    //     newNode->next = head;
    //     return newNode;
    // }

    // SinglyLinkedListNode* prev = head;
    // SinglyLinkedListNode* current = head->next;

    // while (current != nullptr && current->data < x) {
    //     prev = current;
    //     current = current->next;
    // }

    // newNode->next = current;
    // prev->next = newNode;

    // return head;


int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    cin >> x;
    llist->head = insertSortedLinkedList(llist->head, x);
    printLinkedList(llist->head);

    return 0;
}
