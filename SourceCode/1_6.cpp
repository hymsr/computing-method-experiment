#include"h1.h"
using namespace std;
double f1_6(double t) {//��ʵ��ı�������,�޸ı����������޸ı�������
	return 2/(1+t*t);
}
void ex1_6() {
	double a, b;
	cout << "�Զ�ѡȡ�������η�����֣���ֱ������������a������b:";
	cin >> a >> b;
	cout << "������ţ�";
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
			cout << "���ֽ���ֵΪ" << t1 << endl;
			return;
		}
		else n=2*n;
	}
	return;
}