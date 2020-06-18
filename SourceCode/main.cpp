#include"h1.h"
using namespace std;
int main() {
	while (1) {
		cout << "1 有效数字丢失现象观察" << endl;
		cout << "2 n次插值的Lagrange形式" << endl;
		cout << "3 n次插值Newton形式" << endl;
		cout << "4 三次样条插值" << endl;
		cout << "5 单变量数据拟合（最小二乘法）" << endl;
		cout << "6 自动选取步长梯形法" << endl;
		cout << "7 Romberg求积法" << endl;
		cout << "8 顺序高斯消去法" << endl;
		cout << "9 列主元高斯消去法" << endl;
		cout << "10 全主元高斯消去法" << endl;
		cout << "11 LU直接分解法" << endl;
		cout << "12 Jacobi迭代算法" << endl;
		cout << "13 Seidel迭代算法" << endl;
		cout << "14 松弛迭代算法" << endl;
		cout << "15 对分法求根" << endl;
		cout << "16 松弛法迭代求根" << endl;
		cout << "17 牛顿法求根" << endl;
		cout << "请输入要查看的实验前的编号:" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			ex1_1();
			break;
		case 2:
			ex1_2();
			break;
		case 3:
			ex1_3();
			break;
		case 4:
			ex1_4();
			break;
		case 5:
			ex1_5();
			break;
		case 6:
			ex1_6();
			break;
		case 7:
			ex1_7();
			break;
		case 8:
			ex2_1();
			break;
		case 9:
			ex2_2();
			break;
		case 10:
			ex2_3();
			break;
		case 11:
			ex2_4();
			break;
		case 12:
			ex2_5();
			break;
		case 13:
			ex2_6();
			break;
		case 14:
			ex2_7();
			break;
		case 15:
			ex2_8();
			break;
		case 16:
			ex2_9();
			break;
		case 17:
			ex2_10();
			break;
		default:
			cout << "输入了错误的序号，请重新输入" << endl;
			break;
		}
	}
}