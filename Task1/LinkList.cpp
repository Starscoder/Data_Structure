//
//  单向非循环链表.cpp
//  VOJ编程
//
//  Created by Mac on 2019/8/5.
//  Copyright © 2018年 Mac. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
    Node(int num) :value(num),next(NULL) {};
    Node() {};
};
class LinkList {
public:
    void create();           //初始化
    void insertHead(Node*);  //头插法
    void insertTail(Node*);  //尾插法
    Node* findByIndex(int);  //根据索引查找节点，并返回节点的指针，注意0返回头节点
    Node* findByValue(int);  //根据值查找节点，并返回节点的指针，注意0返回头节点
    int  getLength();        //获取链表的长度
    void deleteByIndex(int); //根据索引删除节点
    void deleteByValueOnce(int); //根据节点值删除第一个节点
    void deleteByValueAll(int);//根据节点值删除所有节点
    void editByIndex(int,int);   //根据索引修改节点的值
    void print();
    void reverse();
private:
    Node* head;        //头节点指针,value用于存放链表的长度
};


void LinkList::create() {
    head = new Node();
    head->next = NULL;
    head->value = 0;
}
void LinkList::insertHead(Node* p) {
    p->next = head->next;
    head->next = p;
    head->value++;
}
void LinkList::insertTail(Node* p) {
    Node* tail = findByIndex(head->value);
    if (tail == NULL)
        insertHead(p);
    else {
        p->next = tail->next;
        tail->next = p;
    }
    head->value++;
}
Node* LinkList::findByIndex(int index){
    Node* p = head;
    int i = 0;
    if (index<0||index >getLength()) {
        cout << "索引非法！" << endl;
        return NULL;
    }
    while (p) {
        if (i == index)
            return p;
        else {
            p = p->next;
            i++;
        }
    }
    return NULL;
}
Node* LinkList::findByValue(int value) {
    Node* p = head->next;
    for (;p;p=p->next){
        if (p->value == value)
            return p;
    }
    return NULL;
}
int LinkList::getLength() {
    return head->value;
}
void LinkList::deleteByIndex(int index) {
    if (index == 0) {
        cout << "不能删除头节点！" << endl;
        return;
    }
    Node* p = findByIndex(index);
    if (!p) {
        cout << "删除失败！" << endl;
        return;
    }
    else {
        Node* q = findByIndex(index - 1);
        q->next = p->next;
        head->value--;
        delete p;
    }
}
void LinkList::deleteByValueOnce(int value) {
    Node* p = head->next;
    Node* q = head;
    bool flag = false;
    for (;p;p = p->next,q=q->next) {
        if (p->value == value) {
            q->next = p->next;
            delete p;
            flag = true;
            head->value--;
            break;
        }
    }
    if (!flag) {
        cout << "链表中不存在值为：" << value << "的节点" << endl;
    }
}
void LinkList::deleteByValueAll(int value) {
    Node* p = head->next;
    Node* q = head;
    bool flag = false;
    while(p){
        if (p->value == value) {
            q->next = p->next;
            Node* temp = p;
            p = p->next; //此处q不动，留给你们思考，不会再留言，嘻嘻
            delete temp;
            head->value--;
            flag = true;
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
    if (!flag) {
        cout << "链表中不存在值为：" << value << "的节点" << endl;
    }
}
void LinkList::editByIndex(int index,int value) {
    if (index == 0) {
        cout << "不能修改头节点！" << endl;
        return;
    }
    Node* p = findByIndex(index);
    if (!p) {
        cout << "修改失败！" << endl;
        return;
    }
    else {
        p->value = value;
    }
}
void LinkList::print() {
    for (Node* p = head->next;p;p = p->next) {
        cout << p->value << " ";
    }
    cout << endl;
}

void LinkList::reverse() {
    if (!head->next) {
        cout << "该链表无节点！" << endl;
        return;
    }
    Node* pre = head->next;    //pre指向三个中第一个
    if (!pre->next)            //若链表只有一个节点，直接返回
        return;
    Node* mid = pre->next;    //mid指向三个中中间
    pre->next = NULL;         //断开第一个节点与头节点的联系
    Node* after;             //声明三个中最后
    while (mid->next) {     //若有最后
        after = mid->next;    //让after指向三个中的最后
        mid->next = pre;      //pre与mid指向的节点连接
        pre = mid;           //pre指针后移
        mid = after;        //mid指针后移
    }
    mid->next = pre;       //因为循环体中是在有第三个中最后的节点的情况下处理，所以最后要处理一下没有最后的节点
    head->next = mid;      //头节点指向原末尾的节点
}

void printAnswer(LinkList linklist) {
    linklist.print();
    cout << "当前长度：";
    cout << linklist.getLength() << endl;
}
int main() {
    int n;
    cout << "请输入节点个数：";
    cin >> n;
    LinkList linklist;
    linklist.create();
    int num;
    while (n--) {
        cin >> num;
        linklist.insertHead(new Node(num));
    }
    cout << "头插法结果：";
    printAnswer(linklist);
    cout << "尾插一个数：";
    cin >> num;
    linklist.insertTail(new Node(num));
    cout << "尾插法结果：";
    printAnswer(linklist);
    cout << "想删除第几个：";
    cin >> num;
    linklist.deleteByIndex(num);
    cout << "删除结果：";
    printAnswer(linklist);
    cout << "反转链表：";
    linklist.reverse();
    printAnswer(linklist);
}
