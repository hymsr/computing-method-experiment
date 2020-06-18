#include"h1.h"
using namespace std;
double f2_9(double x) {//松弛法迭代函数
	return (x*x*x + 1) / 3;
}
double f2_9_d(double x) {
	return x * x;
}
void ex2_9() {
	cout << "松弛法迭代求根，请输入初值x0:";
	double x;
	cin >> x ;
	cout << "请输入精度ε：";
	double e;
	cin >> e;
	double x1;
	while (1) {
		double w = 1 / (1 - f2_9_d(x));
		x1 = (1 - w)*x + w * f2_9(x);
		if (abs(x1 - x) < e) {
			cout << "解得近似值x=" << x1<<endl;
			return;
		}
		x = x1;
	}
	return;
}