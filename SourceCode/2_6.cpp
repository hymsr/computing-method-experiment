#include"h1.h"
using namespace std;
void ex2_6() {
	int n;
	cout << "Seidel��������������ϵ������A����N:";
	cin >> n;
	double **a = new double*[n + 1];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n + 1];
	}
	double xi;
	for (int i = 0; i < n; i++) {
		cout << "������ϵ�������" << i + 1 << "�е�" << n << "��Ԫ��:";
		for (int j = 0; j < n; j++) {
			cin >> xi;
			a[i][j] = xi;
		}
	}
	cout << "�������Ҷ���b��" << n << "��Ԫ��:";
	for (int i = 0; i < n; i++) {
		cin >> xi;
		a[i][n] = xi;
	}
	double *y = new double[n];
	cout << "�������ʼ����Y��" << n << "��Ԫ��:";
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	double e;
	cout << "�������:";
	cin >> e;
	double m;
	cout << "��������������������M:";
	cin >> m;
	int k = 1;
	double *g = new double[n];
	for (int i = 0; i < n; i++) {
		if (a[i][i] < e) {
			cout << "���ʧ��" << endl;
			abort();
		}
		double t = a[i][i];
		for (int j = 0; j < n; j++) {
			a[i][j] = -a[i][j] / t;
		}
		a[i][i] = 0;
		g[i] = a[i][n] / t;
	}
	double *x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = y[i];
	}
	while (1) {
		for (int i = 0; i < n; i++) {
			double sum = 0;
			for (int j = 0; j < n; j++) {
				if (i != j) sum += a[i][j] * x[j];
			}
			x[i] = g[i] + sum;
		}
		if (distance(x, y, n) < e) {
			cout << "��������Ϊ:" << k << endl;
			cout << "��Ϊ:" << endl;
			for (int i = 0; i < n; i++) {
				cout << "X" << i + 1 << "=" << x[i] << endl;
			}
			return;
		}
		if (k < m) {
			k++;
			for (int i = 0; i < n; i++) {
				y[i] = x[i];
			}
			continue;
		}
		else {
			cout << "���ʧ��" << endl;
			return;
		}
	}
	return;
}