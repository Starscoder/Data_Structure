
//https://blog.csdn.net/kevin980123/article/details/93412945

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*本题采用动态规划求解
 *首先来分析一下思路：
 *首先创建一个二维数组保存公共子串长度，以较小串的长度+1为行数，较大串的长度+1为列数，初始值全为0
 *我们从较小串的第一个字符开始在较大串中全部查找一遍，如果有该字符则更新数组对应位置的值，直到较小字符串遍历完
 *	更新方式为[i][j] = [i-1][j-i]+1;在此过程中不断更新最大子串的长度max及起始位置start
 *最后从较小串的start位置打印长度为max的子串即可*/

void findLCS(string s1, string s2)
{
	int l1 = s1.size(), l2 = s2.size(), max = 0, start = 0;
	vector < vector<int> > lcs(l1 + 1, vector<int>(l2 + 1, 0)); //这里要+1，因为是从[0][0]到[l1][l2],初始全为0
	for (int i = 1; i <= l1; ++i) //因为要通过[i-1][j-1]来更新[i][j]，所以这里从[1][1]开始，避免越界
	{
		for (int j = 1; j <= l2; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) //如果字符相等，则更新‘到此位置的公共子串’的长度
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			if (lcs[i][j] > max) //更新最大公共子串长度及起始位置
			{
				max = lcs[i][j];
				start = i - max;
			}
		}
	}
	cout << s1.substr(start, max) << endl; 
}

int main()
{
	string s1, s2;
	while (getline(cin, s1) && getline(cin, s2))
	{
		if (s1.size() < s2.size()) //找到较短的字符串作为传入的s1
			findLCS(s1, s2);
		else
			findLCS(s2, s1);
	}
	return 0;
}

