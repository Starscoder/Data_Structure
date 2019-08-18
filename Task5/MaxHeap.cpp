#include"iostream"
 
using namespace std;
 
template<typename T>
class MaxHeap
{
public:
	MaxHeap(int mx = 10);
	virtual~MaxHeap();
	bool IsEmpty();
	void MaxHeap::Push(const T&t);
	const T& MaxHeap::Pop();//弹出堆顶
	const T&Top()const;
	void tickleUp(int currentSize);//上浮
	void tickleDown(int index);//下沉
private:
	T*headArrey;
	int maxSize;
	int currentSize;
};

template<typename T>
MaxHeap<T>::MaxHeap(int mx = 10)//构造函数 默认参数10
{
	if (mx < 1)
	{
		throw "mx must >=1";
	}
	maxSize = mx;
	headArrey = new T[maxSize];
	currentSize = 0;
}

template<typename T>
MaxHeap<T>::~MaxHeap()//析构函数
{
	 delete[] headArrey;
 }
template<typename T>
bool MaxHeap<T>::IsEmpty()
{
	return currentSize == 0;
}

template<typename T>
void MaxHeap<T>::Push(const T&t)//插入
{
	if (currentSize == maxSize)//若插入时堆已经满了 重开一块更大内存（2倍）
	{
		T *temp =new T[2 * maxSize];
		for (int i = 0; i < this->maxSize; i++)//拷贝到新内存
		{
			temp[i] = this->headArrey[i];
		}
		delete[]this->headArrey;//析构旧内存
		this->headArrey = temp;
		this->maxSize = 2 * maxSize;//容量翻倍
		//throw "数组已经满了";
	}
	this->headArrey[currentSize] = t;//插到完全二叉树最后面
	tickleUp(currentSize);//上浮到一个比其大的父节点位置
	currentSize++;
}

template<typename T>
const T& MaxHeap<T>::Pop()//删除堆顶元素
{
	T temp = headArrey[0];
	headArrey[0] = headArrey[--currentSize];//堆顶元素先默认为树的最后节点（最小）
	tickleDown(0);//下沉 到一个比其小的儿子节点为止
	return temp;
}
template<typename T>
void MaxHeap<T>::tickleUp(int index)//上浮
{
	int parent = (index - 1) / 2;//父节点和左右孩子index关系
	T temp = headArrey[index];//保存最后面的数
	while (index > 0&& headArrey[parent]<temp)
	{
		headArrey[index] = headArrey[parent];//小于它的父节点下沉取代它位置
		index = parent;
		parent = (parent - 1) / 2;
	}
	headArrey[index] = temp;
}

template<typename T>
void MaxHeap<T>::tickleDown(int index)//下沉
{
	int largerChild;
	T top = headArrey[index];//保存待下沉的节点
	while (index < currentSize/2)//最多下沉到叶子 统计到上一层 currentSize/2
	{
		int lc = 2 * index + 1;
		int rc = lc + 1;
		if (rc < currentSize && headArrey[rc] > headArrey[lc])
			largerChild = rc;
		else
			largerChild = lc;
		if (top >= headArrey[largerChild])
			break;
		else//其大孩子节点上浮取代其位置
		{
			headArrey[index] = headArrey[largerChild];
			index = largerChild;
		}
	}
	headArrey[index] = top;
}
template<typename T>
const T& MaxHeap<T>::Top()const
{
	return headArrey[0];
}

 
int main()
{
	MaxHeap<int> Heap(5);
	int arrey[] = { 98,3,6,8,1,34,55,81,20,46 };
	for (int i = 0; i < 10; i++)
	{
		int value = arrey[i];
		Heap.Push(value);
	}
	cout << Heap.IsEmpty() << endl;
	cout << "Heap.Top" << Heap.Top() << endl;
	Heap.Pop();
	cout << "Heap.Top" << Heap.Top()<<endl;
 
	//堆排序 数据push进堆里面，然后在pop即有序
	MaxHeap<int> HeapSort;
	
	cout << "unsort data" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arrey[i]<<" ";
		HeapSort.Push(arrey[i]);
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		arrey[i] = HeapSort.Pop();
		cout << arrey[i] << " ";
	}
	cout << endl;

	return 0;
}
