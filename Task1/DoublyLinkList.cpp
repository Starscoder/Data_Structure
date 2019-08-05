//
//  双向链表.cpp
//  VOJ编程
//
//  Created by Mac on 2019/8/5.
//  Copyright © 2019 Mac. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* pre;
    Node* next;
    Node(int num) :value(num), pre(NULL), next(NULL) {};
    Node() {};
};
/*带头结点的双向循环链表*/
class DoublyLinkList {
public:
    void create();           //初始化
    void insertHead(Node*);  //头插法
    Node* findByValue(int);  //根据值查找节点，并返回节点的指针
    void deleteByValueOnce(int); //根据节点值删除第一个节点
    void print();
    //void reverse();
private:
    Node* head;/*头结点*/
};

void DoublyLinkList::create() {
    head = new Node(0);/*让头结点的数值域初始为0*/
    head->next = head;
    head->pre = head;
}
void DoublyLinkList::insertHead(Node* p) {
    p->next = head->next;
    head->next->pre = p;
    p->pre = head;
    head->next = p;
}
void DoublyLinkList::print() {
    for (Node* p = head->next;p!=head;p = p->next)
        cout << p->value << " ";
    cout << endl;
}
Node* DoublyLinkList::findByValue(int value) {
    for (Node *p = head->next;p!=head;p = p->next) {
        if (p->value == value)
            return p;
    }
    return NULL;
}
void DoublyLinkList::deleteByValueOnce(int value) {
    Node* deleteNode = findByValue(value);  //先查找该点是否存在
    if (!deleteNode)
        cout << "你想删除的节点不存在！" << endl;
    else {
        deleteNode->pre->next = deleteNode->next;
        deleteNode->next->pre = deleteNode->pre;
        delete deleteNode;
    }
}

int main() {
    int n,num;
    DoublyLinkList dll;
    dll.create();
    cout << "请输入节点个数：";
    cin >> n;
    while (n--) {
        cin >> num;
        dll.insertHead(new Node(num));
    }
    cout << "头插法结果：";
    dll.print();
  
}
