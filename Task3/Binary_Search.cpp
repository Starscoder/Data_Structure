#include <iostream>

using namespace std;
void ShellSort(int L[],const int left,const int right){
    int i,j,gap = right - left + 1;
    int  temp;
    do
    {
        gap = gap/3+1;
        for (int i = left + gap; i <= right; ++i)
        {       
            if (L[i]<L[i-gap])
            {
                temp = L[i];
                j = i - gap;
                do
                {
                    L[j+gap] = L[j];
                    j = j-gap;
                } while (j >left && temp < L[j]);
                L[j+gap] = temp;
            }
        }
    } while (gap > 1);
};
/*折半查找，递归实现*/  
int Binary_Search(int *a, int low, int high, int key)  
{  
     if(low > high) 
          return -1;
     int mid = (low + high) / 2;  
     if(a[mid] == key)  
          return mid;  
     if(a[mid] > key)  
          return Binary_Search(a, low, mid-1, key);     //有没有return都可以。  
     else  
          return Binary_Search(a, mid+1, high, key);     //有没有return都可以。  
}  


int main(int argc, char const *argv[])
{
    int L[] = {1,4,2,1,5,6,7};
    ShellSort(L,0,6);
    int pos = Binary_Search(L,0,6,4);
    cout<<"4的位置为："<<pos+1<<endl;
    return 0;
}
