#include<iostream>
#include<string>
using namespace std;
//从pos位置开始，返回子串在主串中的位置
int BF(string M,string T,int pos)
{
	int i=pos;
	int j=0;
	int Mlen=M.length();//主串的范围[0,Slen)
	int Tlen=T.length();//子串的范围[0,Tlen)
 
	if(pos<0 && pos>Mlen)
		return -1;
 
	while(i<Mlen && j<Tlen)
	{
		if(M[i]==T[j])
		{
			++i;
			++j;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=Tlen)
		return i-Tlen;
	else 
		return -1;
}
int main()
{
	string M="abcdefabcdx";
	string T="abcdx";
	cout<<BF(M,T,1)<<endl;
	return 0;
}
