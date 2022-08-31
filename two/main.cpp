#include<iostream>

using namespace std;

int founddis(int x, int y,int** val,int k,string a0,string b0)
{
	//当有一个字符串长度为0时
	if (x == 0 || y == 0)
	{
		return val[x][y];
	}
	//定义递归公式的三种情况
	int a = founddis(x - 1, y, val, k, a0, b0);
	int b = founddis(x, y - 1, val, k, a0, b0);
	int c = founddis(x - 1, y - 1, val, k, a0, b0);
	//选择其中的最小值
	val[x][y] = min(min(a + k, b + k), c + abs(a0[x-1] - b0[y-1]));
	return val[x][y];
}

int main()
{
	string a, b;
	cout << "请输入字符串A和B：" << endl;
	cin >> a >> b;
	int k;
	cout << "请输入空格与其他字符的距离：" << endl;
	cin >> k;
	//找到字符串的长度，初始化val
	int m = a.length();
	int n = b.length();
	//设置二维数组val，并进行初始化
	int** val = new int* [m + 1];
	for (int i = 0; i < m+1; i++)
	{
		val[i] = new int[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
	{
		val[i][0] = i * k;
	}
	for (int i = 0; i < n + 1; i++)
	{
		val[0][i] = i * k;
	}
	//查找扩展距离
	int dis = founddis(m, n, val, k, a, b);
	cout << "A和B的扩展距离为：" << endl;
	cout << dis << endl;
	//释放分配的二维数组val
	for (int i = 0; i < m + 1; i++)
	{
		delete[] val[i];
	}
	delete[] val;
}