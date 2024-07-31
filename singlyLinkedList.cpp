#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList {
        private:
        Node* head;

        public:
        LinkedList() {
            this->head = NULL;
        }

        //Insert Data at the Beginning of the list
        void insertAtBeginning(int data) {
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
        }

        //Insert Data at the n'th Position of the list
        void insertAtPosition(int data, int position){
            if(position == 1){
                insertAtBeginning(data);
                return;
            }

            Node* temp = head;
            int count =1;

            while(count<position-1){
                temp = temp->next;
                count++;
            }

            Node* nodeToInsert = new Node(data);

            nodeToInsert->next = temp->next;
            temp->next = nodeToInsert;
        }

        //Insert Data at the End of the list.
        void insertAtEnd(int data){
            if (head == NULL) {
                head = new Node(data);
                return;
            }

            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            Node* nodeToInsert = new Node(data);
            temp->next = nodeToInsert;
            temp = temp->next;
        }

        //Delete Data from the Beginning of the list
        void deleteFromBeginning() {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        //Delete Data from n'th Position of the list
        void deleteFromPosition(int position){
            if(position == 1){
                deleteFromBeginning();
                return;
            }

            Node* prev = NULL;
            Node* curr = head;
            int count = 1;

            while(count < position){
                prev = curr;
                curr = curr->next;
                count++;
            }

            prev->next = curr->next;
            delete curr;
        }

        //Delete Data from the end of the List
        void deleteFromEnd(){
           if (head->next == NULL) {
                delete head;
                head = NULL;
                return;
            }

            Node* temp = head;

            while (temp->next->next != NULL){
                temp = temp->next;
            }

            delete temp->next;
            temp->next = NULL;
        }

        //Search Elements from the Linked List
        void search(int target){
            Node* temp = head;
            while (temp != NULL) {
                if (temp->data == target) {
                    cout << "Found" << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Not Found" << endl;
        }

        //Print the Data of this list
        void print() {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl; 
            cout << endl;
        }
};

int main() {
    int position;

    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(8);
    list.insertAtBeginning(6);
    list.insertAtBeginning(4);
    list.insertAtBeginning(2);
    cout<<"After insert data at the Beginning of the linked list:"<<" ";
    list.print();

    list.insertAtPosition(100,3);
    list.insertAtPosition(20,1);
    cout<<"After insert data at the n'th Position of the linked list:"<<" ";
    list.print();


    list.insertAtEnd(500);
    cout<<"After insert data at the End of the linked list:"<<" ";
    list.print();

    list.deleteFromBeginning();
    cout<<"After removing data at the Beginning of the linked list:"<<" ";
    list.print();

    list.deleteFromPosition(3);
    cout<<"After removing data at the n'th Position of the linked list:"<<" ";
    list.print();

    list.deleteFromPosition(1);
    cout<<"After removing data at the n'th Position of the linked list:"<<" ";
    list.print();

    list.deleteFromEnd();
    cout<<"After removing data at the End of the linked list:"<<" ";
    list.print();

    int target;
    cout<<"Enter the Element for searched:"<<" ";
    cin>>target;

    list.search(target);
    list.print();

    return 0;
}
