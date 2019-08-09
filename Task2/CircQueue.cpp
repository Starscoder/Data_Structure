//
//  循环队列.cpp
//  VOJ编程
//
//  Created by Mac on 2019/8/9.
//  Copyright © 2019 Mac. All rights reserved.
//

#include "Queue.h"
#include <iostream>
#include <string>
#include <strstream>
using namespace std;

const int defaultSize = 50;

template <class T>
class CircQueue : public Queue<T>
{
public:
    CircQueue(int sz = defaultSize);        //构造函数
    virtual ~CircQueue();                   //析构函数
    virtual bool getHead(T& x) const;       //读取队头元素，并将该元素的值保存至x
    virtual bool EnQueue(const T& x);       //新元素x入队
    virtual bool DeQueue(T& x);             //队头元素出队，并将该元素的值保存至x
    virtual bool IsEmpty() const;           //判断队列是否为空
    virtual bool IsFull() const;            //判断队列是否为满
    virtual void MakeEmpty();               //清空队列的内容
    virtual int getSize() const;            //计算队列中元素个数

    friend ostream& operator<<(ostream& os, const CircQueue<T>& q); //输出队列元素的重载操作<<
private:
    T *elements;    //存放队列元素的队列数组
    int front;      //队头指针
    int rear;       //队尾指针
    int maxSize;    //队列最大可容纳元素个数
};

//构造函数
template <class T>
CircQueue<T>::CircQueue(int sz)
{
    cout << "$ 执行构造函数" << endl;
    if (sz >= 0)
    {
        maxSize = sz;
        front = rear = 0;
        elements = new T[maxSize];
    }
}

//析构函数
template <class T>
CircQueue<T>::~CircQueue()
{
    cout << "$ 执行析构函数" << endl;
    delete[] elements;
    elements = NULL;
}

//读取队头元素，并将该元素的值保存至x
template <class T>
bool CircQueue<T>::getHead(T& x) const
{
    if (true == IsEmpty())
    {
        return false;
    }
    x = elements[front];
    return true;
}

//新元素x入队
template <class T>
bool CircQueue<T>::EnQueue(const T& x)
{
    if (true == IsFull())
    {
        return false;
    }
    elements[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
}

//队头元素出队，并将该元素的值保存至x
template <class T>
bool CircQueue<T>::DeQueue(T& x)
{
    if (true == IsEmpty())
    {
        return false;
    }
    x = elements[front];
    front = (front + 1) % maxSize;
    return true;
}

//判断队列是否为空
template <class T>
bool CircQueue<T>::IsEmpty() const
{
    return (front == rear) ? true : false;
}

//判断队列是否为满
template <class T>
bool CircQueue<T>::IsFull() const
{
    return ((rear + 1) % maxSize == front) ? true : false;
}

//清空队列的内容
template <class T>
void CircQueue<T>::MakeEmpty()
{
    delete[] elements;
    front = rear = 0;
    elements = new T[maxSize];
}

//计算队列中元素个数
template <class T>
int CircQueue<T>::getSize() const
{
    return (rear - front + maxSize) % maxSize;
}

//输出队列元素的重载操作<<
template <class T>
ostream& operator<<(ostream& os, const CircQueue<T>& q)
{
    for (int i = q.front; i != q.rear; i = (i+1)%q.maxSize)
    {
        os << "[" << i << "]" << " : " << q.elements[i] << endl;
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
    cout << "------------------------------>循环队列<------------------------------" << endl;
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

//输入数组的最大长度
template <class T>
int get_maxsize()
{
    cout << "> 请输入数组的最大长度，maxsize = ";
    string s_maxsize;
    cin >> s_maxsize;
    while (false == IsNumber(s_maxsize))
    {
        cout << "* 输入有误，请重新输入：";
        cin >> s_maxsize;
    }
    return atoi(s_maxsize.c_str());
}

//构造循环队列
template <class T>
CircQueue<T>* construct_circqueue()
{
    cout << "\n==> 创建循环队列" << endl;
    int n_maxsize = get_maxsize<T>();
    CircQueue<T> *circQueue = new CircQueue<T>(n_maxsize);
    return circQueue;
}

//析构循环队列
template <class T>
void destory_circqueue(CircQueue<T>* circQueue)
{
    cout << "\n==> 释放循环队列在堆中申请的空间，并将指向该空间的指针变量置为空" << endl;
    delete circQueue;
    circQueue = NULL;
}

//读取队头元素，并将该元素的值保存至x
template <class T>
void gethead(CircQueue<T>* circQueue)
{
    cout << "$ 执行读取队头元素并将该元素的值保存至x函数" << endl;
    T data;
    if (false == circQueue->getHead(data))
    {
        cout << "* 读取队头元素失败" << endl;
        return;
    }
    cout << "* 读取队头元素成功，data = " << data << endl;
}

//新元素x入队
template <class T>
void enqueue(CircQueue<T>* circQueue)
{
    cout << "$ 执行新元素x入队函数" << endl;
    T data = get_data<T>();
    if (false == circQueue->EnQueue(data))
    {
        cout << "* 入队失败" << endl;
        return;
    }
    cout << "* 入队成功，data = " << data << endl;
}

//队头元素出队，并将该元素的值保存至x
template <class T>
void dequeue(CircQueue<T>* circQueue)
{
    cout << "$ 执行队头元素出队并将该元素的值保存至x函数" << endl;
    T data;
    if (false == circQueue->DeQueue(data))
    {
        cout << "* 出队失败" << endl;
        return;
    }
    cout << "* 出队成功，data = " << data << endl;
}

//判断队列是否为空
template <class T>
void isempty(CircQueue<T>* circQueue)
{
    cout << "$ 执行判断队列是否为空函数，IsEmpty = " << circQueue->IsEmpty() << endl;
}

//判断队列是否为满
template <class T>
void isfull(CircQueue<T>* circQueue)
{
    cout << "$ 执行判断队列是否为满函数，IsFull = " << circQueue->IsFull() << endl;
}

//清空队列的内容
template <class T>
void makeempty(CircQueue<T>* circQueue)
{
    cout << "$ 执行清空队列的内容函数" << endl;
    circQueue->MakeEmpty();
}

//计算队列中元素个数
template <class T>
void getsize(CircQueue<T>* circQueue)
{
    cout << "$ 执行计算队列中元素个数函数，Size = " << circQueue->getSize() << endl;
}

//输出队列元素的重载操作<<
template <class T>
void operator_ostream(CircQueue<T>* circQueue)
{
    cout << "$ 执行输出队列元素的重载操作<<函数" << endl;
    cout << *circQueue;//或operator<<(cout, *circQueue);
}

//循环队列操作选择
template <class T>
void select_operation(CircQueue<T>* circQueue)
{
    if (NULL == circQueue)
    {
        cout << "* 没有构造循环队列，请先构造循环队列。" << endl;
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
                gethead(circQueue);
                break;
            }
            case ENQUEUE://新元素x入队
            {
                enqueue(circQueue);
                break;
            }
            case DEQUEUE://队头元素出队，并将该元素的值保存至x
            {
                dequeue(circQueue);
                break;
            }
            case ISEMPTY://判断队列是否为空
            {
                isempty(circQueue);
                break;
            }
            case ISFULL://判断队列是否为满
            {
                isfull(circQueue);
                break;
            }
            case MAKEEMPTY://清空队列的内容
            {
                makeempty(circQueue);
                break;
            }
            case GETSIZE://计算队列元素个数
            {
                getsize(circQueue);
                break;
            }
            case OPERATOR_OSTREAM://输出队列元素的重载操作<<
            {
                operator_ostream(circQueue);
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
    CircQueue<int> *circQueue = construct_circqueue<int>();
    select_operation(circQueue);
    destory_circqueue(circQueue);
    system("pause");
    return 0;
}
