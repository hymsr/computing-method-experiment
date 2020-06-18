#include"h1.h"
using namespace std;
double f1_6(double t) {//本实验的被积函数,修改本函数可以修改被积函数
	return 2/(1+t*t);
}
void ex1_6() {
	double a, b;
	cout << "自动选取步长梯形法求积分，请分别输入积分下限a和上限b:";
	cin >> a >> b;
	cout << "请输入ε：";
	double e;
	cin >> e;
	double h = (b - a) / 2;
	double t1 = (f1_6(a) + f1_6(b))*h;
	int n = 1;
	double t0, s;
	while (1) {
		t0 = t1, s = 0;
		for (int k = 1; k <= n; k++) {
			s += f1_6(a + (2 * k - 1)*h / n);
		}
		t1 = t0 / 2 + s * h / n;
		if ((t1 - t0) < 3 * e) {
			cout << "积分近似值为" << t1 << endl;
			return;
		}
		else n=2*n;
	}
	return;
}