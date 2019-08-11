#include <iostream>
using namespace std;

void BubbleSort(int V[],int n){
	/*对数组V中的n个元素进行冒泡排序，设置flag
	如已排序完成则停止
	*/
	bool exchange ;
	for (int i = 0; i < n; ++i)
	{		
		exchange = false;
		for (int j = n-1; j >= i; j--)
		{
			if (V[j-1]>V[j])
			{
				int temp = V[j-1];
				V[j-1] = V[j];
				V[j] = temp;
				exchange = true;
			}
		}
		if (exchange == false) return ;
	}
};

int main(int argc, char const *argv[])
{
	int A[6]={1,3,2,4,5,9};
	BubbleSort(A,6);
	for (int i = 0; i < 6; ++i)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}
