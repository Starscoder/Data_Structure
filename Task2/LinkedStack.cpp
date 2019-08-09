//
//  链式栈.cpp
//  VOJ编程
//
//  Created by Mac on 2019/8/9.
//  Copyright © 2019 Mac. All rights reserved.
//

#ifndef LINKED_STACK_H_
#define LINKED_STACK_H_
#ifndef LINK_NODE_H_
#define LINK_NODE_H_
#include <stack>
#include <iostream>
#include <string>
#include <strstream>
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


#endif /* LINK_NODE_H_ */


template <class T>
class LinkedStack : public stack<T>
{
public:
    LinkedStack();                      //构造函数
    virtual ~LinkedStack();             //析构函数

    virtual void Push(const T& x) ;     //新元素x进栈
    virtual bool Pop(T& x);             //栈顶元素出栈，并将该元素的值保存至x
    virtual bool getTop(T& x) const;    //读取栈顶元素，并将该元素的值保存至x
    virtual bool IsEmpty() const;       //判断栈是否为空
    virtual bool IsFull() const;        //判断栈是否为满
    virtual int getSize() const;        //计算栈中元素个数
    virtual void MakeEmpty();           //清空栈的内容
    friend ostream& operator<<(ostream& os, const LinkedStack<T>& s);   //输出栈中元素的重载操作<<
private:
    LinkNode<T> *top;   //栈顶指针，即链头指针
};

//构造函数
template <class T>
LinkedStack<T>::LinkedStack()
: top(NULL)
{
    cout << "$ 执行构造函数" << endl;
}

//析构函数
template <class T>
LinkedStack<T>::~LinkedStack()
{
    cout << "$ 执行析构函数" << endl;
    MakeEmpty();
}

//新元素x进栈
template <class T>
void LinkedStack<T>::Push(const T& x)
{
    LinkNode<T> *newNode = new LinkNode<T>(x);
    newNode->link = top;
    top = newNode;
}

//栈顶元素出栈，并将该元素的值保存至x
template <class T>
bool LinkedStack<T>::Pop(T& x)
{
    if (true == IsEmpty())
    {
        return false;
    }
    LinkNode<T> *curNode = top;
    top = top->link;
    x = curNode->data;
    delete curNode;
    return true;
}

//读取栈顶元素，并将该元素的值保存至x
template <class T>
bool LinkedStack<T>::getTop(T& x) const
{
    if (true == IsEmpty())
    {
        return false;
    }
    x = top->data;
    return true;
}

//判断栈是否为空
template <class T>
bool LinkedStack<T>::IsEmpty() const
{
    return (NULL == top) ? true : false;
}

//判断栈是否为满
template <class T>
bool LinkedStack<T>::IsFull() const
{
    return false;
}

//计算栈中元素个数
template <class T>
int LinkedStack<T>::getSize() const
{
    int count = 0;
    LinkNode<T> *curNode = top;
    while (NULL != curNode)
    {
        curNode = curNode->link;
        count++;
    }
    return count;
}

//清空栈的内容
template <class T>
void LinkedStack<T>::MakeEmpty()
{
    LinkNode<T> *curNode = NULL;
    while (NULL != top)             //当链表不为空时，删去链表中所有结点
    {
        curNode = top;              //保存被删结点
        top = curNode->link;        //被删结点的下一个结点成为头结点
        delete curNode;             //从链表上摘下被删结点
    }
}

//输出栈中元素的重载操作<<
template <class T>
ostream& operator<<(ostream& os, const LinkedStack<T>& s)
{
    os << "栈中元素个数 = " << s.getSize() << endl;   //输出栈中元素个数
    int i = 0;
    LinkNode<T> *curNode = s.top;
    while (NULL != curNode)
    {
        os << "[" << i++ << "]" << " : " << curNode->data << endl;
        curNode = curNode->link;
    }
    return os;
}

#define EXIT 0              //退出


#define PUSH 1              //新元素x进栈


#define POP  2              //栈顶元素出栈，并将该元素的值保存至x


#define GETTOP 3            //读取栈顶元素，并将该元素的值保存至x


#define ISEMPTY  4          //判断栈是否为空


#define ISFULL 5            //判断栈是否为满


#define GETSIZE 6           //计算栈中元素个数


#define MAKEEMPTY 7         //清空栈的内容


#define OPERATOR_OSTREAM 8  //输出栈中元素的重载操作<<

#endif /* LINKED_STACK_H_ */
void print_description()
{
    cout << "------------------------------>链式栈<------------------------------" << endl;
    cout << "功能选项说明：" << endl;
    cout << "#0： 退出" << endl;
    cout << "#1： 新元素x进栈" << endl;
    cout << "#2： 栈顶元素出栈，并将该元素的值保存至x" << endl;
    cout << "#3： 读取栈顶元素，并将该元素的值保存至x" << endl;
    cout << "#4： 判断栈是否为空" << endl;
    cout << "#5： 判断栈是否为满" << endl;
    cout << "#6： 计算栈中元素个数" << endl;
    cout << "#7： 清空栈的内容" << endl;
    cout << "#8： 输出栈中元素的重载操作<<" << endl;
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

//构造链式栈
template <class T>
LinkedStack<T>* construct_linkedstack()
{
    cout << "\n==> 创建链式栈" << endl;
    LinkedStack<T> *linkedStack = new LinkedStack<T>;
    return linkedStack;
}

//析构链式栈
template <class T>
void destory_linkedstack(LinkedStack<T>* linkedStack)
{
    cout << "\n==> 释放链式栈在堆中申请的空间，并将指向该空间的指针变量置为空" << endl;
    delete linkedStack;
    linkedStack = NULL;
}

//新元素x进栈
template <class T>
void push(LinkedStack<T>* linkedStack)
{
    cout << "$ 执行新元素x进栈函数" << endl;
    T data = get_data<T>();
    linkedStack->Push(data);
    cout << "* 进栈成功，data = " << data << endl;
}

//栈顶元素出栈，并将该元素的值保存至x
template <class T>
void pop(LinkedStack<T>* linkedStack)
{
    cout << "$ 执行栈顶元素出栈并将该元素的值保存至x函数" << endl;
    T data;
    if (false == linkedStack->Pop(data))
    {
        cout << "* 出栈失败" << endl;
        return;
    }
    cout << "* 出栈成功，data = " << data << endl;
}

//读取栈顶元素，并将该元素的值保存至x
template <class T>
void gettop(LinkedStack<T>* linkedStack)
{
    cout << "$ 执行读取栈顶元素并将该元素的值保存至x函数" << endl;
    T data;
    if (false == linkedStack->getTop(data))
    {
        cout << "* 读取栈顶元素失败" << endl;
        return;
    }
    cout << "* 读取栈顶元素成功，data = " << data << endl;
}

//判断栈是否为空
template <class T>
void isempty(LinkedStack<T>* linkedStack)
{
    cout << "$ 执行判断栈是否为空函数，IsEmpty = " << linkedStack->IsEmpty() << endl;
}

//判断栈是否为满
template <class T>
void isfull(LinkedStack<T>* linkedStack)
{
    cout << "$ 执行判断栈是否为满函数，IsFull = " << linkedStack->IsFull() << endl;
}

//计算栈中元素个数
template <class T>
void getsize(LinkedStack<T>* linkedStack)
{
    cout << "$ 执行计算栈中元素个数函数，Size = " << linkedStack->getSize() << endl;
}

//清空栈的内容
template <class T>
void makeempty(LinkedStack<T>* linkedStack)
{
    cout << "$ 执行清空栈的内容函数" << endl;
    linkedStack->MakeEmpty();
}

//输出栈中元素的重载操作<<
template <class T>
void operator_ostream(LinkedStack<T>* linkedStack)
{
    cout << "$ 执行输出栈中元素的重载操作<<函数" << endl;
    cout << *linkedStack;//或operator<<(cout, *linkedStack);
}

//链式栈操作选择
template <class T>
void select_operation(LinkedStack<T>* linkedStack)
{
    if (NULL == linkedStack)
    {
        cout << "* 没有构造链式栈，请先构造链式栈。" << endl;
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
            case PUSH://新元素x进栈
            {
                push(linkedStack);
                break;
            }
            case POP://栈顶元素出栈，并将该元素的值保存至x
            {
                pop(linkedStack);
                break;
            }
            case GETTOP://读取栈顶元素，并将该元素的值保存至x
            {
                gettop(linkedStack);
                break;
            }
            case ISEMPTY://判断栈是否为空
            {
                isempty(linkedStack);
                break;
            }
            case ISFULL://判断栈是否为满
            {
                isfull(linkedStack);
                break;
            }
            case GETSIZE://计算栈中元素个数
            {
                getsize(linkedStack);
                break;
            }
            case MAKEEMPTY://清空栈的内容
            {
                makeempty(linkedStack);
                break;
            }
            case OPERATOR_OSTREAM://输出栈中元素的重载操作<<
            {
                operator_ostream(linkedStack);
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

int main()
{
    print_description();
    LinkedStack<int> *linkedStack = construct_linkedstack<int>();
    select_operation(linkedStack);
    destory_linkedstack(linkedStack);
    system("pause");
    return 0;
}

