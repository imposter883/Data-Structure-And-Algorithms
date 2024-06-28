#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node*& head, int data) 
{
    Node* temp = new Node(data);
    temp->next = head;   
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node*& tail, int data)
 {
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count <position-1){
       temp =  temp->next;
       count++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp ->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleting(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* pre = NULL;

        int count = 1;
        while(count<position){
            pre = curr;
            curr = curr->next;
            count++;
        }
    curr->prev = NULL;
    pre->next = curr->next;
    curr->next = NULL;

    delete curr;

    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;

    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);

    print(head);

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);

    print(head);

    insertAtPosition(head,tail,7,55);
    insertAtPosition(head,tail,3,75);
    insertAtPosition(head,tail,1,34);

    print(head);

    deleting(head,5);
    deleting(head,1);
    deleting(head,7);

    print(head);
    return 0;
}
