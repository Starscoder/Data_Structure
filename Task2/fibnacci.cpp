#include <iostream>
using namespace std;

int fib(int i){
	if (i<2)
	{
		return i==0?0:1;
	}
	return fib(i-1)+fib(i-2);
}
int main(int argc, char const *argv[])
{
	cout<<fib(6);

	return 0;
}
