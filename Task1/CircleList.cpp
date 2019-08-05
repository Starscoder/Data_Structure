//
//  循环单链表.cpp
//  VOJ编程
//
//  Created by Mac on 2019/8/5.
//  Copyright © 2019 Mac. All rights reserved.
//
#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
};

class CircleList
{
private:
    Node* head;
    int length;
public:
    CircleList()
    {
        head = new Node();
        head->next = head;
        head->data = 0;
        length = 0;
    }
    ~CircleList()
    {
        delete(head);
    }
    void createCircleList(int n);  //创建单向循环链表
    void traverseNode();            //遍历链表
    void deleteNode(int n);        //删除位置为n的结点
    void insertNode(int n,int data);//在制定位置插入结点
    int getLength();               //得到链表长度
    bool isEmpty();                //判断链表是否为空
};
void CircleList::createCircleList(int n)     //创建方式大同小异，唯一的区别就是创建的最后将尾结点指向头结点
{
    if(n<0)
    {
        cout << "你输入的长度不正确 " << endl;
    }
    else
    {
        length = n;
        printf("请输入你要存储的数据:");
        Node *p,*q;
        p = head;
        while(n--)
        {
            q = new Node();
            cin >> q->data;
            p->next = q;
            q->next = head;
            p = q;
        }
    }
}
void CircleList::traverseNode()  //遍历链表
{
    Node *p;
    p = head->next;
    while(p!=head)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void CircleList::deleteNode(int n)      //删除n位置的结点
{
    if(n<0||n>length)
    {
        printf("删除的位置是错误的\n");
        return;
    }
    else
    {
        Node *p,*q;
        p = head;
        for(int i=1;i<n;i++)
            p=p->next;
        q = p->next;
        p->next = q->next;
        delete q;
        q = NULL;
    }
}

void CircleList::insertNode(int n,int data)    //在n位置插入一个结点  结点的值为data
{
    Node *q,*p = new Node();
    p->data = data;
    q = head;
    for(int i = 1;i<n;i++)
        q = q->next;
    p->next = q->next;
    q->next = p;
}


int CircleList::getLength()     //返回循环链表长度
{
    return length;
}

bool CircleList::isEmpty()      //判断是否为空
{
    return head==head->next;
}

int main()
{
    CircleList list;
    int n,data;
    cout << "请输入你要存储的数据个数:";
    cin >> n;
    list.createCircleList(n);
    list.traverseNode();
    
    cout << "请选择你要删除的结点位置:";
    cin >> n;
    list.deleteNode(n);
    list.traverseNode();
    
    cout << "请输入你要插入的下标和值:";
    cin >> n >> data;
    list.insertNode(n , data);
    list.traverseNode();
    
    return 0;
}

