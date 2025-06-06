#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

int countNode(Node* &head){
    Node* temp = head;

    int count = 0;

    while(temp){
        count++;
        temp= temp->next;
    }

    return count;

}

int main(){
    Node* head = new Node(10);
    head->next = new Node(12);

    cout<<countNode(head)<<endl;
    return 0;

}