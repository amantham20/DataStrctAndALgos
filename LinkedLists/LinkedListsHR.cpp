#include <bits/stdc++.h>

using namespace std;


#define SLL SinglyLinkedListNode // cuz it is better like that who in the world types the entire damm thingy

// Their code havent touched it LMAO
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

// ^^ why the F*** here i havent used it yetlmao.

// Print out the linked list

void printLinkedList(SinglyLinkedListNode* head) {
    while(head != nullptr){
        cout << head->data << endl;
        head = head->next;
    }
}

// !doing it normally
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SLL* start = head;
    SLL* insert = new SLL(data);

    if(head == nullptr){
        return insert;
    }

    SLL* temp = head;

   while(temp->next != nullptr){
       temp = temp->next;
   }
   temp->next = insert;

   return start;
}

// ? You little cheeky bastard 
SinglyLinkedListNode* insertNodeAtTailR(SinglyLinkedListNode* head, int data) {
    if(head == nullptr){
        SLL* temp = new SLL(data);
        return temp;
    }
    else{
        head->next = insertNodeAtTailR(head->next, data);
    }
    return head;
}


// ! the only way is the normal way and it is SIMPLE(french accent) NOT FLIPPIN WITCHCRAFT required
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SLL* head = new SLL(data);
    head->next = llist;
    return head;
}


// ! the normalish WAY??
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    
    int tracker = 1;
    SLL* Insert = new SLL(data);

    if(position == 0){
        Insert->next = llist;    
    }
    else{
        SLL* temp = llist;
        while(position>1){
            position--;
            temp = temp->next;
        }
        Insert->next = temp->next;
        temp->next = Insert;
    }
  
    return llist;
}

// ? What the WITCHCRAFT is goin on hera??
SinglyLinkedListNode* insertNodeAtPositionR(SinglyLinkedListNode* llist, int data, int position) {
    if(position == 0){
        SLL* temp = new SLL(data);
        temp->next = llist;
        return temp;
    }
    else{
        llist->next = insertNodeAtPositionR(llist->next, data, position-1);
    }
    return llist;
}

// ! havent found the cheeky way yet.
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    
    SLL *temp = llist;
    
    if(position == 0){
        llist = llist->next;
        delete(temp);
    }
    else{
        SLL* tempD = llist;
        while(position > 1){
            position--;
            tempD = tempD->next;
        }
        if(tempD->next->next != nullptr){
            SLL *del = tempD->next;
            tempD->next = tempD->next->next;
            delete(del);
        }
        else{
            tempD->next = nullptr;
        }
    }
    
    
    return llist;
}

// ! the non cheeky way
void reversePrint(SinglyLinkedListNode* llist) {
    SLL* currNode = llist;
    SLL* nextNode = llist->next;
    
    currNode->next = nullptr;
    SLL* prevNode = currNode;
    
    while(nextNode != nullptr){
        // cout << nextNode->data << " -> ";
        currNode = nextNode;
        nextNode = nextNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
    }
    
    // cout << endl;
    
    while(prevNode != nullptr){
        cout << prevNode->data <<endl;;
        prevNode= prevNode->next;
    }
    
}

// ! here is the cheeky way.
void reversePrintR(SinglyLinkedListNode* llist){
    if(llist != nullptr){
        reversePrintR(llist->next);
        cout << llist->data << endl;
    }
}


// !myway this was first try
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SLL* currNode = llist;
    SLL* nextNode = llist->next;
    
    currNode->next = nullptr;
    
    SLL*prevNode = currNode;
    
    while(nextNode != nullptr){
        
        currNode = nextNode;
        nextNode = nextNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
    }
    
    return prevNode;
}

// ? the cheeky way
SinglyLinkedListNode* reverseR(SinglyLinkedListNode* llist) {
    if(llist == nullptr || llist->next == nullptr){
        return llist;
    }

    SLL* rest = reverseR(llist->next);
    llist->next->next = llist;

    llist->next = nullptr;

    return rest;
}


// ! dont bother about the cheeky way for this one!!!
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while(head1 != nullptr && head2 != nullptr){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1 != nullptr || head2 != nullptr){
        return false;
    }
    return true;
}

// ! i did this cheeky way or at least @rajmeet did.
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  SLL* result = nullptr;
  if(head1 == nullptr){
      return head2;
  }
  if(head2 == nullptr){
      return head1;
  }
  
  if(head1->data < head2->data){
        result = head1;
        result->next = mergeLists(head1->next, head2);  
  }
  else{
      result = head2;
      result->next = mergeLists(head1, head2->next);
  }
  
  return result;
}


// *my way was to create a buffer so that i can have the second pointer come untill the buffer
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SLL* buffer = llist;
    SLL* currNode = llist;
    
    int currentBufferDistance = 0;
    
    while(currNode != nullptr){
        if(currentBufferDistance == positionFromTail+1){
            buffer = buffer->next;
        }
        else{
            currentBufferDistance++;
        }
        currNode = currNode->next;
    }
    
    
    return buffer->data;
}


// * just a smart buffer system
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SLL* right = llist;
    for (int i = 0; i < positionFromTail; i++)
    {
        right = right ? right->next : nullptr;
    }
    SLL* left = llist;
    while(right && right->next){
        right = right->next;
        left = left->next;
    }

    return left ? left->data : 0;
    

}

// **removes the duplicates in a sorted linked lists of values??
//! there isnt exactly a faster CHEEKY way to solve this problem
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* head = llist;
    
    while(llist != nullptr && llist->next != nullptr){
        
        if(llist->data == llist->next->data){
            SinglyLinkedListNode* temp = llist->next;
            llist->next = llist->next->next;
            delete(temp);
        }else{
            llist = llist->next;
        }
        
    }
    
    return head;
}


// !! kinda a brillant way to approach this problem therefore I AM THE CHEEKY BASTARD for tis one.
// ! tortoise hare algorithm kinda fun NGL
bool has_cycle(SinglyLinkedListNode* head) {
    SLL* fast = head->next;
    SLL* slow = head;
    if(head == nullptr){
        return false;
    }
    while(fast != nullptr && fast->next != nullptr && slow != nullptr){
        if(fast == slow){
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;

}

// ** this is the helper funciton for the function below
int LengthOfLL(SLL* head){
    int length = 0;
    while(head != nullptr){
        length++;
        head = head->next;
    }
    return length;
}

// ** i am the function below i think i spelled below wrong but wat evr
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int len1 = LengthOfLL(head1);
    int len2 = LengthOfLL(head2);
    
    int lenDelta = len2 - len1;
    
    if(len1 > len2){
        swap(head1, head2);
        lenDelta = len1 - len2;
    }
    
    for (int i = 0; i < lenDelta; i++) {
        head2 = head2->next;
    }
    
    while(head1 != nullptr && head2 != nullptr){
        if(head1 == head2){
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return -69420;
    

}


//************************************************************************************************
//************************************************************************************************
int FindMergeNode(SLL *headA, SLL *headB){
    int a=0,b=0;
    for(SLL *z=headA;z;a++)z=z->next;
    for(SLL *z=headB;z;b++)z=z->next;
    for(;a>b;a--)headA=headA->next;
    for(;a<b;b--)headB=headB->next;
    for(;headA->data!=headB->data;)headA=headA->next,headB=headB->next;
    return headA->data;
}
//! this cheeky little bastard WHAT the flip is this this is absymal
//************************************************************************************************
//************************************************************************************************

//!===============================================================================================
//!===============================================================================================


class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

#define DLL DoublyLinkedListNode


//!! my way
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DLL* head = llist;
    DLL* insert = new DLL(data);
    // bool isItAtTheEnd = 1;
    if(llist == nullptr){
        return insert;
    }
    else if(llist->data > data){
        insert->next = llist;
        llist->prev = insert;
        return insert;
    }
    else{
        while(llist->data < data){
            if(llist->next == nullptr){
                llist->next = insert;
                insert->prev = llist;
                return head;
            }else{
                llist = llist->next;
            }
        }
        
        llist->prev->next = insert;
        insert->prev = llist->prev;
        llist->prev = insert;
        insert->next = llist;
        return head;
    }


}
// almost there with recursion
//! not there tho maybe it isnt possible
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {

    if(llist->data > data){
        cout << "stop -> " << llist->data << " <- here" << endl;
        DLL* insert = new DLL(data);
        insert->next = llist->next;
        insert->prev = llist;
        llist->next->prev = insert;
        llist->next = insert;
        return insert;
    }
    else{
        cout  << llist->data << endl;        
        llist->next = sortedInsert(llist->next, data);
    }
    return llist;

}


// ! my way would day that it is preety efficeient 
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DLL* curr = llist;
    DLL* prev = nullptr;
    
    while(curr != nullptr){
        swap(curr->next, curr->prev);      
        prev = curr;
        curr = curr->prev;
    }
    
    if (prev != NULL) {
        llist = prev;
    }
    
    return llist;
}






