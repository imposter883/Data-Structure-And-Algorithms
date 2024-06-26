#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void innsertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleting(Node* &head, int position){
    // Deleting the first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;


    innsertAtPosition(head,tail,1,8);
    innsertAtPosition(head,tail,2,7);
    innsertAtPosition(head,tail,3,6);
    innsertAtPosition(head,tail,5,11);
    print(head);

    deleting(head,1);
    print(head);

    deleting(head,3);
    print(head);

    return 0;
}