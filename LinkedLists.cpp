#include <bits/stdc++.h>
// this is an example of a singly Linked Lists
class SLLNode{
    public:
        int data;
        SLLNode* next;

        SLLNode(int val){
            data = val;
            next = nullptr;
        }
};

void insertAtTail(SLLNode* &head, int val){
    SLLNode* n = new SLLNode(val);
    if(head == nullptr){
        head = n;
        return;
    }

    SLLNode* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head;

}

void insertAtHead(SLLNode* head, int val){
    SLLNode* n = new SLLNode(val);
    n->next = head;
    
}


SLLNode* InsertNth(SLLNode *head, int data, int position)
{
  
    SLLNode * a = new SLLNode(data);
    
    if(position==0){
        a->next = head;
        head = a;
    }else{
         SLLNode *tmp = head;
        while(position>1){
            position--;
            tmp = tmp->next;
        }
        a->next = tmp->next;
        tmp->next = a;
    }
    return head;
}



int main(){


    return 0;
}