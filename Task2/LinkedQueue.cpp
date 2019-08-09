//
//  链式队列.cpp
//  VOJ编程
//
//  Created by Mac on 2019/8/9.
//  Copyright © 2019 Mac. All rights reserved.
//


#include <iostream>
#include <string>
#include <strstream>
#include "LinkNode.h"
#include "Queue.h"
using namespace std;

template <class T>
struct LinkNode         //链表结点类的定义
{
    T data;             //数据域
    LinkNode<T> *link;  //指针域——后继指针
    //仅初始化指针成员的构造函数
    LinkNode(LinkNode<T>* ptr = NULL){ link = ptr; }
    //初始化数据与指针成员的构造函数
    LinkNode(const T& value, LinkNode<T>* ptr = NULL){ data = value; link = ptr; }
};




template <class T>
class LinkedQueue : public Queue<T>
{
public:
    LinkedQueue();                      //构造函数
    virtual ~LinkedQueue();                //析构函数

    virtual bool getHead(T& x) const;       //读取队头元素，并将该元素的值保存至x
    virtual bool EnQueue(const T& x);       //新元素x入队
    virtual bool DeQueue(T& x);             //队头元素出队，并将该元素的值保存至x
    virtual bool IsEmpty() const;           //判断队列是否为空
    virtual bool IsFull() const;            //判断队列是否为满
    virtual void MakeEmpty();               //清空队列的内容
    virtual int getSize() const;            //计算队列中元素个数

    friend ostream& operator<<(ostream& os, const LinkedQueue<T>& q);   //输出队列中元素的重载操作<<
private:
    LinkNode<T> *front; //队头指针，即链头指针
    LinkNode<T> *rear;  //队尾指针，即链尾指针
};

//构造函数
template <class T>
LinkedQueue<T>::LinkedQueue()
: front(NULL), rear(NULL)
{
    cout << "$ 执行构造函数" << endl;
}

//析构函数
template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    cout << "$ 执行析构函数" << endl;
    MakeEmpty();
}

//读取队头元素，并将该元素的值保存至x
template <class T>
bool LinkedQueue<T>::getHead(T& x) const
{
    if (true == IsEmpty())
    {
        return false;
    }
    x = front->data;
    return true;
}

//新元素x入队
template <class T>
bool LinkedQueue<T>::EnQueue(const T& x)
{
    LinkNode<T> *newNode = new LinkNode<T>(x);
    if (NULL == newNode)
    {
        return false;
    }
    
    if (NULL == front)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->link = newNode;
        rear = rear->link;
    }
    return true;
}

//队头元素出队，并将该元素的值保存至x
template <class T>
bool LinkedQueue<T>::DeQueue(T& x)
{
    if (true == IsEmpty())
    {
        return false;
    }
    LinkNode<T> *curNode = front;
    front = front->link;
    x = curNode->data;
    delete curNode;
    return true;
}

//判断队列是否为空
template <class T>
bool LinkedQueue<T>::IsEmpty() const
{
    return (NULL == front) ? true : false;
}

//判断队列是否为满
template <class T>
bool LinkedQueue<T>::IsFull() const
{
    return false;
}

//清空队列的内容
template <class T>
void LinkedQueue<T>::MakeEmpty()
{
    LinkNode<T> *curNode = NULL;
    while (NULL != front)           //当链表不为空时，删去链表中所有结点
    {
        curNode = front;            //保存被删结点
        front = curNode->link;      //被删结点的下一个结点成为头结点
        delete curNode;             //从链表上摘下被删结点
    }
}

//计算队列中元素个数
template <class T>
int LinkedQueue<T>::getSize() const
{
    int count = 0;
    LinkNode<T> *curNode = front;
    while (NULL != curNode)
    {
        curNode = curNode->link;
        count++;
    }
    return count;
}

//输出队列中元素的重载操作<<
template <class T>
ostream& operator<<(ostream& os, const LinkedQueue<T>& q)
{
    int i = 0;
    LinkNode<T> *curNode = q.front;
    while (NULL != curNode)
    {
        os << "[" << i++ << "]" << " : " << curNode->data << endl;
        curNode = curNode->link;
    }
    return os;
}


#define EXIT 0              //退出


#define GETHEAD 1           //读取队头元素，并将该元素的值保存至x


#define ENQUEUE 2           //新元素x入队


#define DEQUEUE  3          //队头元素出队，并将该元素的值保存至x


#define ISEMPTY  4          //判断队列是否为空


#define ISFULL 5            //判断队列是否为满


#define MAKEEMPTY 6         //清空队列的内容


#define GETSIZE 7           //计算队列中元素个数


#define OPERATOR_OSTREAM 8  //输出队列元素的重载操作<<


void print_description()
{
    cout << "------------------------------>链式队列<------------------------------" << endl;
    cout << "功能选项说明：" << endl;
    cout << "#0： 退出" << endl;
    cout << "#1： 读取队头元素，并将该元素的值保存至x" << endl;
    cout << "#2： 新元素x入队" << endl;
    cout << "#3： 队头元素出队，并将该元素的值保存至x" << endl;
    cout << "#4： 判断队列是否为空" << endl;
    cout << "#5： 判断队列是否为满" << endl;
    cout << "#6： 清空队列的内容" << endl;
    cout << "#7： 计算队列中元素个数" << endl;
    cout << "#8： 输出队列元素的重载操作<<" << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

//判断输入的字符串每个字符是否都是数值0~9
bool IsNumber(const string& s_num)
{
    for (size_t i = 0; i < s_num.size(); i++)
    {
        if ((s_num[i] < '0') || (s_num[i] > '9'))
        {
            return false;
        }
    }
    return true;
}

//类型转换——将string型转为模板类型T
template <class T>
T StrToTtype(const string& s_num)
{
    T n_num;
    strstream ss_num;
    ss_num << s_num;
    ss_num >> n_num;
    return n_num;
}

//输入数据值
template <class T>
T get_data()
{
    cout << "> 请输入数据值，data = ";
    string s_data;
    cin >> s_data;
    return StrToTtype<T>(s_data);
}

//构造链式队列
template <class T>
LinkedQueue<T>* construct_linkedqueue()
{
    cout << "\n==> 创建链式队列" << endl;
    LinkedQueue<T> *linkedQueue = new LinkedQueue<T>;
    return linkedQueue;
}

//析构链式队列
template <class T>
void destory_linkedqueue(LinkedQueue<T>* linkedQueue)
{
    cout << "\n==> 释放链式队列在堆中申请的空间，并将指向该空间的指针变量置为空" << endl;
    delete linkedQueue;
    linkedQueue = NULL;
}

//读取队头元素，并将该元素的值保存至x
template <class T>
void gethead(LinkedQueue<T>* linkedQueue)
{
    cout << "$ 执行读取队头元素并将该元素的值保存至x函数" << endl;
    T data;
    if (false == linkedQueue->getHead(data))
    {
        cout << "* 读取队头元素失败" << endl;
        return;
    }
    cout << "* 读取队头元素成功，data = " << data << endl;
}

//新元素x入队
template <class T>
void enqueue(LinkedQueue<T>* linkedQueue)
{
    cout << "$ 执行新元素x入队函数" << endl;
    T data = get_data<T>();
    if (false == linkedQueue->EnQueue(data))
    {
        cout << "* 入队失败" << endl;
        return;
    }
    cout << "* 入队成功，data = " << data << endl;
}

//队头元素出队，并将该元素的值保存至x
template <class T>
void dequeue(LinkedQueue<T>* linkedQueue)
{
    cout << "$ 执行队头元素出队并将该元素的值保存至x函数" << endl;
    T data;
    if (false == linkedQueue->DeQueue(data))
    {
        cout << "* 出队失败" << endl;
        return;
    }
    cout << "* 出队成功，data = " << data << endl;
}

//判断队列是否为空
template <class T>
void isempty(LinkedQueue<T>* linkedQueue)
{
    cout << "$ 执行判断队列是否为空函数，IsEmpty = " << linkedQueue->IsEmpty() << endl;
}

//判断队列是否为满
template <class T>
void isfull(LinkedQueue<T>* linkedQueue)
{
    cout << "$ 执行判断队列是否为满函数，IsFull = " << linkedQueue->IsFull() << endl;
}

//清空队列的内容
template <class T>
void makeempty(LinkedQueue<T>* linkedQueue)
{
    cout << "$ 执行清空队列的内容函数" << endl;
    linkedQueue->MakeEmpty();
}

//计算队列中元素个数
template <class T>
void getsize(LinkedQueue<T>* linkedQueue)
{
    cout << "$ 执行计算队列中元素个数函数，Size = " << linkedQueue->getSize() << endl;
}

//输出队列元素的重载操作<<
template <class T>
void operator_ostream(LinkedQueue<T>* linkedQueue)
{
    cout << "$ 执行输出队列元素的重载操作<<函数" << endl;
    cout << *linkedQueue;//或operator<<(cout, *linkedQueue);
}

//链式队列操作选择
template <class T>
void select_operation(LinkedQueue<T>* linkedQueue)
{
    if (NULL == linkedQueue)
    {
        cout << "* 没有构造链式队列，请先构造链式队列。" << endl;
        return;
    }
    
    string s_operation;
    while (s_operation != "0")
    {
        cout << "\n==> 请输入功能选项编号(按\"0\"退出程序)：";
        cin >> s_operation;
        while (false == IsNumber(s_operation))
        {
            cout << "* 输入有误，请重新输入：";
            cin >> s_operation;
        }
        int n_operation = atoi(s_operation.c_str());
        switch (n_operation)
        {
            case EXIT://退出
            {
                cout << "$ 退出程序" << endl;
                break;
            }
            case GETHEAD://读取队头元素，并将该元素的值保存至x
            {
                gethead(linkedQueue);
                break;
            }
            case ENQUEUE://新元素x入队
            {
                enqueue(linkedQueue);
                break;
            }
            case DEQUEUE://队头元素出队，并将该元素的值保存至x
            {
                dequeue(linkedQueue);
                break;
            }
            case ISEMPTY://判断队列是否为空
            {
                isempty(linkedQueue);
                break;
            }
            case ISFULL://判断队列是否为满
            {
                isfull(linkedQueue);
                break;
            }
            case MAKEEMPTY://清空队列的内容
            {
                makeempty(linkedQueue);
                break;
            }
            case GETSIZE://计算队列元素个数
            {
                getsize(linkedQueue);
                break;
            }
            case OPERATOR_OSTREAM://输出队列元素的重载操作<<
            {
                operator_ostream(linkedQueue);
                break;
            }
            default:
            {
                cout << "* 请输入正确的功能选项编号" << endl;
                break;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    print_description();
    LinkedQueue<int> *linkedQueue = construct_linkedqueue<int>();
    select_operation(linkedQueue);
    destory_linkedqueue(linkedQueue);
    system("pause");
    return 0;
}
