#include"h1.h"
using namespace std;
double f2_10(double x) {//�������
	return (x * x*x - 3 * x + 1);
}
double f2_10_d(double x) {//��������ĵ���
	return (3 * x * x - 3);	
}
void ex2_10() {
	cout << "ţ�ٷ�������������ֵx0:";
	double x;
	cin >> x;
	cout << "�����뾫�Ȧţ�";
	double e;
	cin >> e;
	double x1;
	while (1) {
		double w = f2_10(x) / f2_10_d(x);
		x1 = x - w;
		if (abs(x1 - x) < e) {
			cout << "��ý���ֵx=" << x1<<endl;
			return;
		}
		x = x1;
	}
	return;
}