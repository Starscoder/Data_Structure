//
//  顺序队列.cpp
//  VOJ编程
//
//  Created by Mac on 2019/8/9.
//  Copyright © 2019 Mac. All rights reserved.
//



#include <iostream>
#include <string>
#include <strstream>
#include<queue>
using namespace std;

const int defaultSize = 50;

template <class T>
class SeqQueue : public queue<T>
{
public:
    SeqQueue(int sz = defaultSize);     //构造函数
    virtual ~SeqQueue();                //析构函数

    virtual bool getHead(T& x) const;       //读取队头元素，并将该元素的值保存至x
    virtual bool EnQueue(const T& x);       //新元素x入队
    virtual bool DeQueue(T& x);             //队头元素出队，并将该元素的值保存至x
    virtual bool IsEmpty() const;           //判断队列是否为空
    virtual bool IsFull() const;            //判断队列是否为满
    virtual void MakeEmpty();               //清空队列的内容
    virtual int getSize() const;            //计算队列中元素个数
    
    friend ostream& operator<<(ostream& os, const SeqQueue<T>& q);  //输出队列元素的重载操作<<
private:
    T *elements;    //存放队列元素的队列数组
    int front;      //队头指针
    int rear;       //队尾指针
    int maxSize;    //队列最大可容纳元素个数
};

//构造函数
template <class T>
SeqQueue<T>::SeqQueue(int sz)
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
SeqQueue<T>::~SeqQueue()
{
    cout << "$ 执行析构函数" << endl;
    delete[] elements;
    elements = NULL;
}

//读取队头元素，并将该元素的值保存至x
template <class T>
bool SeqQueue<T>::getHead(T& x) const
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
bool SeqQueue<T>::EnQueue(const T& x)
{
    if (true == IsFull())
    {
        return false;
    }
    elements[rear++] = x;
    return true;
}

//队头元素出队，并将该元素的值保存至x
template <class T>
bool SeqQueue<T>::DeQueue(T& x)
{
    if (true == IsEmpty())
    {
        return false;
    }
    x = elements[front++];
    return true;
}

//判断队列是否为空
template <class T>
bool SeqQueue<T>::IsEmpty() const
{
    return (front == rear) ? true : false;
}

//判断队列是否为满
template <class T>
bool SeqQueue<T>::IsFull() const
{
    if (getSize() == maxSize)
    {
        cout << "* 队列已满，再添加元素会导致真溢出" << endl;
        return true;
    }
    if (maxSize == rear)
    {
        cout << "* 队列未满，再添加元素会导致假溢出" << endl;
        return true;
    }
    return false;
}

//清空队列的内容
template <class T>
void SeqQueue<T>::MakeEmpty()
{
    delete[] elements;
    front = rear = 0;
    elements = new T[maxSize];
}

//计算队列中元素个数
template <class T>
int SeqQueue<T>::getSize() const
{
    return rear - front;
}

//输出队列元素的重载操作<<
template <class T>
ostream& operator<<(ostream& os, const SeqQueue<T>& q)
{
    for (int i = q.front; i < q.rear; i++)
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
    cout << "------------------------------>顺序队列<------------------------------" << endl;
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

//构造顺序队列
template <class T>
SeqQueue<T>* construct_seqqueue()
{
    cout << "\n==> 创建顺序队列" << endl;
    int n_maxsize = get_maxsize<T>();
    SeqQueue<T> *seqQueue = new SeqQueue<T>(n_maxsize);
    return seqQueue;
}

//析构顺序队列
template <class T>
void destory_seqqueue(SeqQueue<T>* seqQueue)
{
    cout << "\n==> 释放顺序队列在堆中申请的空间，并将指向该空间的指针变量置为空" << endl;
    delete seqQueue;
    seqQueue = NULL;
}

//读取队头元素，并将该元素的值保存至x
template <class T>
void gethead(SeqQueue<T>* seqQueue)
{
    cout << "$ 执行读取队头元素并将该元素的值保存至x函数" << endl;
    T data;
    if (false == seqQueue->getHead(data))
    {
        cout << "* 读取队头元素失败" << endl;
        return;
    }
    cout << "* 读取队头元素成功，data = " << data << endl;
}

//新元素x入队
template <class T>
void enqueue(SeqQueue<T>* seqQueue)
{
    cout << "$ 执行新元素x入队函数" << endl;
    T data = get_data<T>();
    if (false == seqQueue->EnQueue(data))
    {
        cout << "* 入队失败" << endl;
        return;
    }
    cout << "* 入队成功，data = " << data << endl;
}

//队头元素出队，并将该元素的值保存至x
template <class T>
void dequeue(SeqQueue<T>* seqQueue)
{
    cout << "$ 执行队头元素出队并将该元素的值保存至x函数" << endl;
    T data;
    if (false == seqQueue->DeQueue(data))
    {
        cout << "* 出队失败" << endl;
        return;
    }
    cout << "* 出队成功，data = " << data << endl;
}

//判断队列是否为空
template <class T>
void isempty(SeqQueue<T>* seqQueue)
{
    cout << "$ 执行判断队列是否为空函数，IsEmpty = " << seqQueue->IsEmpty() << endl;
}

//判断队列是否为满
template <class T>
void isfull(SeqQueue<T>* seqQueue)
{
    cout << "$ 执行判断队列是否为满函数，IsFull = " << seqQueue->IsFull() << endl;
}

//清空队列的内容
template <class T>
void makeempty(SeqQueue<T>* seqQueue)
{
    cout << "$ 执行清空队列的内容函数" << endl;
    seqQueue->MakeEmpty();
}

//计算队列中元素个数
template <class T>
void getsize(SeqQueue<T>* seqQueue)
{
    cout << "$ 执行计算队列中元素个数函数，Size = " << seqQueue->getSize() << endl;
}

//输出队列元素的重载操作<<
template <class T>
void operator_ostream(SeqQueue<T>* seqQueue)
{
    cout << "$ 执行输出队列元素的重载操作<<函数" << endl;
    cout << *seqQueue;//或operator<<(cout, *seqQueue);
}

//顺序队列操作选择
template <class T>
void select_operation(SeqQueue<T>* seqQueue)
{
    if (NULL == seqQueue)
    {
        cout << "* 没有构造顺序队列，请先构造顺序队列。" << endl;
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
                gethead(seqQueue);
                break;
            }
            case ENQUEUE://新元素x入队
            {
                enqueue(seqQueue);
                break;
            }
            case DEQUEUE://队头元素出队，并将该元素的值保存至x
            {
                dequeue(seqQueue);
                break;
            }
            case ISEMPTY://判断队列是否为空
            {
                isempty(seqQueue);
                break;
            }
            case ISFULL://判断队列是否为满
            {
                isfull(seqQueue);
                break;
            }
            case MAKEEMPTY://清空队列的内容
            {
                makeempty(seqQueue);
                break;
            }
            case GETSIZE://计算队列元素个数
            {
                getsize(seqQueue);
                break;
            }
            case OPERATOR_OSTREAM://输出队列元素的重载操作<<
            {
                operator_ostream(seqQueue);
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
    SeqQueue<int> *seqQueue = construct_seqqueue<int>();
    select_operation(seqQueue);
    destory_seqqueue(seqQueue);
    system("pause");
    return 0;
}
