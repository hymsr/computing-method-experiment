#include"h1.h"
using namespace std;
double f2_8(double x) {//�������
	return (x * x*x - 3 * x + 1);
}
void ex2_8() {
	cout << "�Էַ�������������������a��b:";
	double a, b;
	cin >> a >> b;
	cout << "�����뾫�Ȧġ��ţ�";
	double aiTa,e;
	cin >> aiTa >> e;
	cout << "������Ľ���ֵΪ:"<<endl;
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