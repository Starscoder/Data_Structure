#include <iostream>
using namespace std;

void ShellSort(int L[],const int left,const int right){
  /*
  希尔排序，使用gap来分割数据集，对于每个gap内的子集插入排序
  */
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

int main(int argc, char const *argv[])
{
	int A[6]={1,3,2,4,5,9};
	ShellSort(A,0,5);
	for (int i = 0; i < 6; ++i)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}
