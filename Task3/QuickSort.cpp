#include <iostream>
using namespace std;

void Swap(int& x,int& y){
	int temp = x;
	x=y;
	y=temp;
};
int Partion(int L[],const int low,const int high){
	int pivotpos = low,pivot = L[low];
	for (int i = low + 1; i < high; ++i)
	{
		if (L[i]<pivot)
		{	
			pivotpos++;
			if (pivotpos != i)	
			{
				Swap(L[pivotpos],L[i]);
			}
		}
	}
	L[low] = L[pivotpos];
	L[pivotpos] = pivot;

	return pivotpos;
};
void QuickSort(int L[],const int left,const int right){
	if (left<right)
	{
		int pivotpos = Partion(L,left,right);
		QuickSort(L,left,pivotpos-1);
		QuickSort(L,pivotpos+1,right);
	}
};


int main(int argc, char const *argv[])
{
	int A[6]={1,3,2,4,5,9};
	QuickSort(A,0,5);
	for (int i = 0; i < 6; ++i)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}
