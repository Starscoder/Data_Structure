/**
利用分治算法求一组数据的逆序对个数

https://www.cnblogs.com/td15980891505/p/5143866.html

**/


#include<iostream>
using namespace std;
#define MAX_VALUE 2147483647 
int Count_Reversations(int *A, int n);
int Merge_Reversations(int *A, int p, int r);

int Count_Reversations(int*A, int n){ //接口函数
     return Merge_Reversations(A, 0, n - 1);
}
int Merge_Reversations(int *A, int p, int r){
     if (p>=r)
          return 0;
     int i, j, k,mid,n1,n2, reversations = 0;
     mid = (p + r) >> 1;
     int next_count= Merge_Reversations(A, p, mid) + Merge_Reversations(A, mid + 1, r);
     n1 = mid - p + 1;
     n2 = r - mid;
     int *R = new int[n2 + 1];
     int *L = new int[n1 + 1];
     for (i = 0; i < n1; i++)
          L[i] = A[i + p];
     for (j = 0; j < n2; j++)
          R[j] = A[j + mid + 1];
     L[n1] = R[n2] = MAX_VALUE; //设置为最大值，当做哨兵
     i = j = 0;
     for (k = p; k <= r; k++){
          if (L[i]>R[j]){
                 reversations +=n1-i;
                 A[k] = R[j++];
     }
     else
         A[k] = L[i++];
}
    delete[]R,   L;
    return reversations +next_count;
}
int main(){
     int a[5] = { 2,3,8,6,1 };
     cout << Count_Reversations(a, 5) << endl;
     return 0;
}
