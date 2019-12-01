//
//  main.cpp
//  ListNodeList
//
//  Created by hapii on 2019/10/29.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <iostream>
//节点
//class ListNode{
//public:
//    int val;
//    ListNode *next;
//    
//    ListNode (int da = 0, ListNode *p = NULL){
//        this->val = da;
//        this->next = p;
//    }
//};

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


//列表
class List{
private:
    ListNode *head,*tail;
    int position;
public:
    List() { head = tail = NULL; };
    
    ~List() {
        delete head;
        delete tail;
       };

       void print();
    ListNode * Insert(int da = 0);
    void Delete(int da = 0);
    void Search(int da = 0);
    int getValueAt(int position);
    void setValueAt(int position,int da);
    void deleteAtIndex(int position);
};

int List::getValueAt(int position){
    ListNode *p = head;
    if (p == NULL) {
        std::cout<<"l链表为空";
    }else{
        int posi = 0;
        while (p != NULL && posi != position) {
            posi++;
            p = p->next;
        }
    }
    if (p == NULL) {
        std::cout<<"找不到改位置";
    }
    return p->val;
};

void List::setValueAt(int position, int da){
    ListNode *p = head;
    if (p == NULL) {
        std::cout<<"链表为空";
    }else{
        int posi = 0;
        while (p!= NULL && posi!= position) {
            posi ++;
            p = p->next;
        }
    }
    
    if (p == NULL) {
         std::cout<<"找不到改位置";
    }else{
        p->val = da;
        std::cout<<"修改成功";
    }
};

void List::deleteAtIndex(int index) {
    int i = 0;
    ListNode *p = head;
    while (i< index) {
        i++;
        if (i== index-1) {
            p->next = p->next->next;
        }
        p = p->next;
    }
}

void List::Search(int da){
    ListNode *p = head;
    if (p == NULL) {
        std::cout<<"链表为空";
       
    }
    int posi = 0;
    while (p!= NULL && p->val != da) {
        posi ++;
        p = p->next;
    }
    
    if (p == NULL) {
        std::cout<<"找不到该位置";
    }else{
        std::cout << "the value you want to search is at position %d" << posi;
    }
   
};

void List::Delete(int da){
    ListNode *p = head, *q = head;//q用来记录前一个节点
    if (p == NULL) {
        std::cout << "Sorry, The List is Empty!" ;
               return;
    }
    while (p != NULL && p->val !=da) {
        q = p;
        p = p->next;
    }
    if (p) {
         q->next = p->next;
         std::cout << "删除成功" ;
    }else{
         std::cout << "找不到要删除的内容" ;
    }
   
    
}

ListNode * List::Insert(int da){
    if (head == NULL) {
        head = tail = new ListNode(da);
        head->next = NULL;
        tail->next = NULL;
        return head;
    }else{
        ListNode *p = new ListNode(da);
        tail->next = p;
        tail = p;
        tail->next = NULL;
       
         return p;
    }
    
}

void List::print(){
    ListNode *p = head;
    while (p != NULL) {
        std::cout << p->val << " \a";
        p = p->next;
    }

}
///合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1) cur->next = l1;
    if (l2) cur->next = l2;
    return dummy->next;
    
}
///删除链表重复列表
ListNode* deleteDuplicates(ListNode* head) {
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    head->next = deleteDuplicates(head->next);
    if(head->val == head->next->val){
        head = head->next;
    }
    return head;
}
///删除传入的节点
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
///876.传入head，返回中间节点
ListNode* middleNode(ListNode* head) {
    int i = 1;
     ListNode *node = head;
    while (node->next) {
        node = node->next;
        i++;
    }
    int j = i/2;
    node = head;
    while (j != 0) {
        node = node->next;
        j--;
    }
    return node;
}
///876.解发2 快慢指针
ListNode* middleeNode(ListNode* head) {
    ListNode *fastNode = head;
    ListNode *lowNode = head;
    while ( fastNode != NULL && fastNode->next != NULL) {
        fastNode = fastNode->next->next;
        lowNode = lowNode->next;
    }
    return lowNode;
}
///206 反转链表 1,2,3,4,5
ListNode* reverseList(ListNode* head) {
   if (head == NULL || head->next == NULL)
            return head;
            ListNode *prev = NULL; //前指针节点
            ListNode *curr = head; //当前指针节点
           //每次循环，都将当前节点指向它前面的节点，然后当前节点和前节点后移
           while (curr != NULL) {
               ListNode *nextTemp = curr->next; //临时节点，暂存当前节点的下一节点，用于后移
               curr->next = prev; //将当前节点指向它前面的节点
               prev = curr; //前指针后移
               curr = nextTemp; //当前指针后移
           }
           return prev;
    
}

int get(int index) {
//    int i = 0;
//    ListNode *node = head;
//    while (i<=index) {
//        i++;
//
//    }
    return 0;
}
