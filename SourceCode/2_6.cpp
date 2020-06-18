#include"h1.h"
using namespace std;
void ex2_6() {
	int n;
	cout << "Seidel迭代法，请输入系数矩阵A阶数N:";
	cin >> n;
	double **a = new double*[n + 1];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n + 1];
	}
	double xi;
	for (int i = 0; i < n; i++) {
		cout << "请输入系数矩阵第" << i + 1 << "行的" << n << "个元素:";
		for (int j = 0; j < n; j++) {
			cin >> xi;
			a[i][j] = xi;
		}
	}
	cout << "请输入右端项b的" << n << "个元素:";
	for (int i = 0; i < n; i++) {
		cin >> xi;
		a[i][n] = xi;
	}
	double *y = new double[n];
	cout << "请输入初始向量Y的" << n << "个元素:";
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	double e;
	cout << "请输入ε:";
	cin >> e;
	double m;
	cout << "请输入容许最大迭代次数M:";
	cin >> m;
	int k = 1;
	double *g = new double[n];
	for (int i = 0; i < n; i++) {
		if (a[i][i] < e) {
			cout << "求解失败" << endl;
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
			cout << "迭代次数为:" << k << endl;
			cout << "解为:" << endl;
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
			cout << "求解失败" << endl;
			return;
		}
	}
	return;
}