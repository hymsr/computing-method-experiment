#include"h1.h"
using namespace std;
double f2_8(double x) {//求根函数
	return (x * x*x - 3 * x + 1);
}
void ex2_8() {
	cout << "对分法求根，请输入求根区间a和b:";
	double a, b;
	cin >> a >> b;
	cout << "请输入精度δ、ε：";
	double aiTa,e;
	cin >> aiTa >> e;
	cout << "所求根的近似值为:"<<endl;
	while (1) {
		double x = (a + b) / 2;
		if (abs(f2_8(x)) < aiTa) {
			cout << "x=" << x << endl;
			return;
		}
		if (f2_8(a)*f2_8(x) < 0) {
			b = x;
		}
		else {
			a = x;
		}
		if ((b - a) <= e) {
			cout << "x=" << (a+b)/2 << endl;
			return;
		}
	}
	return;
}