#include"h1.h"
using namespace std;
double f2_10(double x) {//求根函数
	return (x * x*x - 3 * x + 1);
}
double f2_10_d(double x) {//求根函数的导数
	return (3 * x * x - 3);	
}
void ex2_10() {
	cout << "牛顿法求根，请输入初值x0:";
	double x;
	cin >> x;
	cout << "请输入精度ε：";
	double e;
	cin >> e;
	double x1;
	while (1) {
		double w = f2_10(x) / f2_10_d(x);
		x1 = x - w;
		if (abs(x1 - x) < e) {
			cout << "解得近似值x=" << x1<<endl;
			return;
		}
		x = x1;
	}
	return;
}