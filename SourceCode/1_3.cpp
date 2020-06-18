#include"h1.h"
using namespace std;
void ex1_3() {
	int n;
	cout << "ţ��n�β�ֵ����������n:";
	cin >> n;
	vector<double> x, y;
	for (int i = 0; i < n; i++) {
		cout << "�������ֵ�ڵ��(x" << i << ",y" << i << "): ";
		double xi, yi;
		cin >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
	}
	//��ʼ�������
	double **f = new double *[n];
	for (int i = 0; i < n; i++) {
		f[i] = new double[n];
		f[i][i] = y[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; i+j < n; j++) {
			f[j][i + j] = (f[j][i + j - 1] - f[j + 1][i + j]) / (x[j] - x[i + j]);
		}
	}

	polynomial res;
	res.x.push_back(0);
	stack<polynomial> sp;
	for (int i = 0; i < n; i++) {
		polynomial temp;
		if (i != 0) {
			temp = sp.top();
			sp.pop();
			vector<double> v{ -x[i - 1],1 };
			sp.push(temp*polynomial(v));
		}
		else {
			temp.x.push_back(1);
			sp.push(temp);
		}
		res = res + sp.top()*f[0][i];
	}
	cout << "����Ķ���ʽϵ������Ϊ(x�Ĵ�����0����): " << res << endl;
	cout << "�������X�������Ӧ�ĺ�������ֵ: ";
	double t;
	while (cin >> t) {
		cout << res.f(t) << endl;
		cout << "�������X�������Ӧ�ĺ�������ֵ: ";
	}
	return;
}