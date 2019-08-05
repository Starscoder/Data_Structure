//
//  顺序表.cpp
//  VOJ编程
//
//  Created by Mac on 2018/7/17.
//  Copyright © 2018年 Mac. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <mm_malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
using namespace std;
typedef int SqType;

typedef struct {
    SqType *elem;
    int length;
    int listsize;
}SqList;

SqList createList_sq(){
    
    SqList*  list = (SqList*)malloc(sizeof(SqList));
    return *list;
}

int InitList_sq(SqList &L){
    L.elem = (SqType*)malloc(sizeof(SqType)*LIST_INIT_SIZE);
    if (!L.elem) {
        return 0;
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;
}

void DeleteList_sq(SqList &L){
    free(L.elem);
    L.length = 0;
    L.listsize = 0;
}

int InsertList_Sq(SqList &L,int index,SqType val){
    if (index > L.length) { //存储的下表超出顺序表实际的长度
        printf("插入的下标超出顺序表的实际长度");
        return 0;
    }
    if (index < 0) //下标是负数，插入到结尾
        index = L.length;
    if (L.length == L.listsize) { //顺序表的存储单元已经存满
        printf("顺序表的存储单元已满，继续分配新的存储单元。");
        SqType* newBase = (SqType*) realloc(L.elem,(L.listsize + LISTINCREMENT) * sizeof(SqType)); //继续分配存储单元
        if (!newBase) {
            printf("分配内存单元失败");
            return 0;
        }
        L.elem = newBase;
        L.listsize += LISTINCREMENT;
    }
    for (int i=index; i<L.length; i++) {
        L.elem[i] = L.elem[i-1];
    }
    L.elem[index] = val;
    L.length++;
    return 1;
}
int removeList_sq(SqList &L,SqType val){
    int index = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == val) {
            //找到匹配的val，结束循环
            index = i;
            break;
        }
    }
    if (index < 0)
        return 0;
    for (; index < L.length - 1; index++) {
        L.elem[index] = L.elem[index + 1];
    }
    L.length--;
    return 1;
}
int removeList_sq(SqList &L, int index, SqType &elem) {
    if (index >= L.length) //下标超出顺序表的长度
        return 0;
    index = index < 0 ? L.length : index; //下标负数表示删除最后一个节点
    elem = L.elem[index];
    for (int i = index; i < L.length - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.length--;
    return 1;
}
void showList_Sq(SqList &L){
    cout<<"顺序表元素为:"<<endl;
    for (int i=0; i<L.length; i++) {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}

void mergeSort(SqList &L,SqList &L2,int left,int right){
    //归并排序
    if (left>=right) {
        return;
    }
    int mid = (left+right)/2;
    mergeSort(L, L2, left, mid);
    mergeSort(L, L2, mid+1, right);
    merge(L,L2,left,mid,right);
    
}

void merge(SqList &L1,SqList &L2,const int left,const int mid,const int right){
    //将两个有序表L1.vector[left,mid]和L1.vector[mid+1,right]归并成一个有序表
    for (int k=left; k<=right; k++) {
        L2.elem[k] = L1.elem[k];
    }
    int s1 = left,s2 = mid+1,t=left;
    while (s1<=mid&&s2<=right) {
        if (L2.elem[s1]<=L2.elem[s2]) {
            L1.elem[t++] = L2.elem[s1++];
        }
        else L1.elem[t++] = L2.elem[s2++];
    }
    while (s1<=mid) {
        L1.elem[t++] = L2.elem[s1++];
    }
    while (s2<=right) {
        L1.elem[t++] = L2.elem[s2++];
    }
}
int main(){
    SqList L = createList_sq();
    InitList_sq(L);
    for (int i=0; i<105; i++) {
        InsertList_Sq(L, i, i);
    }
    removeList_sq(L, 100);
    showList_Sq(L);

    return 0;
}










