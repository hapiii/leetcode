//
//  ListNode.cpp
//  NodeList
//
//  Created by hapii on 2019/11/25.
//  Copyright © 2019 hapii. All rights reserved.
//

#include <stdio.h>
using namespace std;
#include <string>
#include <sstream>
#include <iostream>

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int val,ListNode *next){
        this->val = val;
        this->next = next;
    }
};

class MyLinkedList {
public:
    ListNode *head,*tail;
    int length;
    
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
#pragma mark =========== 获取第几个节点
    int get(int index) {
        
        int i = 0;
        ListNode *node = head;
        while (node != nullptr){
            if (i == index) {
                return node->val;
            }
            node = node->next;
            i++;
        };
        return -1;
    }
    
#pragma mark =========== 头部插入节点
    void addAtHead(int val) {
        if (head == nullptr) {
            tail = head = new ListNode(val,nullptr);
            
        }else{
            ListNode *node = new  ListNode(val,head);
            head = node;
        }
        length++;
    }
    
#pragma mark =========== 尾部追加节点
    ListNode * addAtTail(int val) {
        if (tail != nullptr) {
            if (head == tail) {
                ListNode *node = new ListNode(val,nullptr);
                head->next = node;
                tail = node;
            }else{
                ListNode *node = new ListNode(val,nullptr);
                tail->next = node;
                tail = node;
            }
            
        }else{
            tail =  head = new ListNode(val,nullptr);
        }
        length++;
        return tail;
    }
    
#pragma mark =========== 插入
    void addAtIndex(int index, int val) {
        if(index > length-1 ){
            return;
        }
        if (index <= 0){
            addAtHead(val);
            return;
        }
        
        if (index == length) {
            addAtTail(val);
            return;
        }
        
        int i = 0;
        ListNode *node= head;
        while (node->next != nullptr) {
            
            if (i == index-1) {
                ListNode *newNode = new ListNode(val,node->next);
                node->next = newNode;
                length++;
                return;
            }
            node = node->next;
            i++;
        }
    }
    
#pragma mark =========== 删除第几个节点
    void deleteAtIndex(int ind) {
        if (ind > length-1) {
            return;
        }
        
        if (ind == 0) {
            
            head = head->next;
            //delete node;
            length --;
            return;
        }
        
        int i = 0;
        ListNode *node = head;
        while (node) {
            
            if (i == ind-1) {
                //要删的是最后一个
                if (ind == length-1) {
                    delete node->next;
                    tail = node;
                    length--;
                    return;
                }else{
                    ListNode *deleNode = node->next;
                    node->next = node->next->next;
                    length--;
                    delete deleNode;
                    return;
                }
                
            }
            i++;
            node = node->next;
        }
        return;
        
    }
#pragma mark =========== 打印链表
    void printList(ListNode *node){
        
        while (node) {
            std::cout<<node->val<<"->";
            node = node->next;
        }
        std::cout<<"\n";
    }
    
#pragma mark =========== 反转链表
    ListNode* reverseList(ListNode* head) {
        
        ListNode *prev = nullptr; //前指针节点
        ListNode *curr = head; //当前指针节点
        //每次循环，都将当前节点指向它前面的节点，然后当前节点和前节点后移
        while (curr != nullptr) {
            ListNode *nextTemp = curr->next; //临时节点，暂存当前节点的下一节点，用于后移 2
            curr->next = prev; //将当前节点指向它前面的节点 1->next = null
            prev = curr; //前指针后移  1
            curr = nextTemp; //当前指针后移 2
        }
        return prev;
    };
    
#pragma mark =========== 删除列表中的某个元素
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *node = head;
        while (node) {
            if (node == head &&node->val == val) {//头部一样
                head = node->next;
                node = node->next;
            }else  if (node->next == nullptr) {//尾部一样
                if (node->val == val) {
                    node = nullptr;
                    return head;
                }
                node = node->next;
            }else{
                if (node->next->val == val) {
                    node->next = node->next->next;
                }else{
                    node = node->next;
                }
            }
        }
        return head;
    }
#pragma mark =========== 是否有环
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        ListNode* low = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            low = low->next;
            if(low == fast)
            {
                return true;
            }
        }
        return false;
    }
#pragma mark =========== 返回环形链表的环点
    ListNode *getIntersect(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return nullptr;
        ListNode* low = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            low = low->next;
            if(low == fast)
            {
                return low;
            }
        }
        return nullptr;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *intersect = getIntersect(head);
        if (intersect == nullptr) {
            return nullptr;
        }
        ListNode *ptr1 = head;
        ListNode *ptr2 = intersect;
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr2;
    }
    
#pragma mark =========== 奇偶链表
    ListNode* oddEvenList(ListNode* head) {
        if ( head == nullptr) {
            return nullptr;
        }
        //123456
        ListNode *oddNode = head;//奇数链表
        ListNode *evenNode = head->next;//偶数链表
        ListNode *evenHead = evenNode;//连链表头
        while (evenNode != nullptr && evenNode->next != nullptr) {
            oddNode->next = evenNode->next;
            evenNode->next = oddNode->next;
            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }
        oddNode->next = evenHead;
        return head;
    }
#pragma mark =========== 回文链表
    bool isPalindrome(ListNode* head) {
        ///快慢指针查找中点
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next!= nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ///反转后半段链表
        ListNode *prev = nullptr; //前指针节点
        ListNode *curr = slow; //当前指针节点
        //每次循环，都将当前节点指向它前面的节点，然后当前节点和前节点后移
        while (curr != nullptr) {
            ListNode *nextTemp = curr->next; //临时节点，暂存当前节点的下一节点，用于后移 2
            curr->next = prev; //将当前节点指向它前面的节点 1->next = null
            prev = curr; //前指针后移  1
            curr = nextTemp; //当前指针后移 2
        }
        while (prev!= nullptr) {
            if (prev->val != head->val) {
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
#pragma mark =========== 相交链表
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        while (nodeA != nullptr &nodeB != nullptr && nodeA != nodeB) {
            nodeA = nodeA == nullptr? headB:nodeA->next;
            nodeB = nodeB == nullptr? headA:nodeB->next;;
        }
        return nodeA;
    }
#pragma mark =========== 删除倒数第N个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *dummy = new ListNode(0,head);
        ListNode *indexNode = dummy;
        ListNode *temp = dummy;
        
        for (int i = 1; i<=n+1; i++) {
            indexNode = indexNode->next;
        }
        
        while (indexNode!= nullptr) {
            indexNode = indexNode->next;
            temp = temp->next;
        }
        temp->next = temp->next == nullptr? nullptr:temp->next->next;
        return dummy->next;
    }
#pragma mark =========== 旋转链表
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode *old_tail = head;
        int n;
        for (n = 0; old_tail->next != nullptr; n++) {
            old_tail = old_tail->next;
        }
        old_tail->next = head;
        ListNode *new_tail = head;
        for (int i = 0; i< n-k%n -1; i++) {
            new_tail = new_tail->next;
        }
        ListNode *end = new_tail->next;
        new_tail->next = nullptr;
        return end;
    }
#pragma mark =========== 两数相加
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tempNode = new ListNode(-1,nullptr);
        ListNode *node = tempNode;
        tempNode->next = node;
        int addNum = 0;
        while (l1!= nullptr || l2 != nullptr || addNum != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = x+y+addNum;
           
            node->next = new ListNode(sum%10,nullptr);
             addNum = sum/10;
            node = node->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        printList(tempNode->next);
        return tempNode->next;
    }
    
#pragma mark =========== 链表排序
    ListNode* sortList(ListNode* head) {
        return head == nullptr?head:mergeSort(head);
    }
private: ListNode * mergeSort(ListNode *head){
    
    std::cout<<"mergeSort head"<<head->val<<"\n";
    if (head == nullptr||head->next == nullptr) {
        return head;
    }
    
    //1.快慢指针找中点
    ListNode *slow = head,*fast = head->next->next,*l,*r;
    while (fast!= nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //2.递归调用mergeSort
    
    r = mergeSort(slow->next);
    std::cout<<"r 内容"<<r->val<<"\n";
    slow->next = nullptr;
    l = mergeSort(head);//7->
    std::cout<<"l 内容"<<l->val<<"\n";
    //3.合并两个链表
    return mergeList(l,r);//7,8->
}

#pragma mark =========== 合并两个有序链表
private:ListNode *mergeList(ListNode *l,ListNode *r){
    std::cout<<"合并的两个列表"<<l->val<<r->val<<"\n";
    ListNode *tempHead = new ListNode(-1,nullptr);
    ListNode *p = tempHead;
    while (l != nullptr &&r != nullptr) {
        if (l->val <r->val) {
            p->next = l;
            l = l->next;
        }else{
            p->next = r;
            r = r->next;
        }
        p = p->next;
    }
    p->next = l ==nullptr?r:l;
    return tempHead->next;
}
    
};
