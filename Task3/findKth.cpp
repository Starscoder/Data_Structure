#include <iostream>
#include <vector>
using namespace std;
 //https://blog.csdn.net/bladeandmaster88/article/details/52438577
//用快排的思想：例如找49个元素里面第24大的元素，那么按如下步骤：
//1.进行一次快排（将大的元素放在前半段，小的元素放在后半段）, 假设得到的中轴为p
//2.判断 k -1==p - low，如果成立，直接输出a[p]，（因为前半段有k - 1个大于a[p]的元素，故a[p]为第K大的元素）
//3.如果 k -1 < p - low， 则第k大的元素在前半段，此时更新high = p - 1，继续进行步骤1
//4.如果 k -1 > p - low， 则第k大的元素在后半段，此时更新low = p + 1, 且 k = k - (p - low + 1)，继续步骤1.
//由于常规快排要得到整体有序的数组，而此方法每次可以去掉“一半”的元素，故实际的复杂度不是o(nlgn), 而是o(n)。
class Finder 
{
public:
	int partition(vector<int>&a, int low, int high)//找枢纽
	{
		int first = low;
		int	last = high;
		int key = a[first];//用字表的第一个记录作为枢轴
 
		while (first < last)
		{
			while (a[last] >= key && first < last)
				--last;
			swap(a[first], a[last]);
 
			while (a[first] <= key && first < last)
				++first;
			swap(a[first], a[last]);
		}
		return first;//返回一个枢纽
	}
 
	int findKth(vector<int>& a, int low, int high, int k)
	{
		int p = partition(a, low, high);
		if (k == p - low + 1)
			return a[p];
 
		else if (k - 1 < p - low)//则第k大的元素在前半段
			return findKth(a, low, p - 1, k);
 
		else //则第k大的元素在后半段
			return findKth(a, p + 1, high, k - p + low - 1);
	}
 
	int findKth(vector<int> a, int n, int K)
	{
		return findKth(a, 0, n - 1, K);
	}
 
};
 
//测试
int main()
{
	vector<int> v;
	vector<int>::iterator it;                 //定义一个vector迭代器
    for(int i = 10; i >= 1; i--)              //插入数据
        v.push_back(i);
 
	Finder solution;
	cout << solution.findKth(v,v.size(), 6)<<endl;
}
