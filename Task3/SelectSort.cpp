#include <iostream>
using namespace std;

void Swap(int& x,int& y){
	int temp = x;
	x=y;
	y=temp;
};
void SelectSort(int L[],const int left,const int right){
	//直接选择排序，与元素的初始排列无关
	for (int i = left; i < right; ++i)
	{
		int k = i;
		for (int j = i+1; j <= right; j++)
		{
			if (L[j]<L[k])
			{
				k=j;
			}
		}
		if (k != i)
		{
			Swap(L[i],L[k]);
		}
	}
};

int main(int argc, char const *argv[])
{
	int A[6]={1,3,2,4,5,9};
	SelectSort(A,0,5);
	for (int i = 0; i < 6; ++i)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}
