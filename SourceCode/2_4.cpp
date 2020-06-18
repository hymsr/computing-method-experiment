#include"h1.h"
using namespace std;
void ex2_4() {
	int n;
	cout << "LU直接分解法，请输入系数矩阵A阶数N:";
	cin >> n;
	double **a = new double*[n+1];
	double **u = new double*[n];
	double **l = new double*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n+1];
		u[i] = new double[n];
		l[i] = new double[n];
		for (int j = 0; j < n; j++) {
			l[i][j] = 0;
			u[i][j] = 0;
		}
		l[i][i] = 1;
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
	double e;
	cout << "请输入ε:";
	cin >> e;
	for (int k = 0; k < n; k++) {
		for(int j = k; j < n; j++) {
			double sum = 0;
			for (int m = 0; m <= k - 1; m++) {
				sum += l[k][m] * u[m][j];
			}
			u[k][j] = a[k][j] - sum;
			if (j == k && abs(u[k][j]) < e) {
				cout << "求解失败" << endl;
				abort();
			}
		}
		for (int i = k+1; i < n; i++) {
			double sum = 0;
			for (int m = 0; m <= k - 1; m++) {
				sum += l[i][m] * u[m][k];
			}
			l[i][k] = (a[i][k] - sum) / u[k][k];
		}
	}
	cout << "L矩阵:"<<endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << l[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "U矩阵:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << u[i][j] << ' ';
		}
		cout << endl;
	}
	double *y = new double[n];
	y[0] = a[0][n];
	for (int i = 1; i < n; i++) {
		double sum = 0;
		for (int j = 0; j <= i - 1; j++) {
			sum += l[i][j] * y[j];
		}
		y[i] = a[i][n] - sum;
	}
	for (int i = 0; i < n; i++) {
		cout << "Y" << i + 1 << "=" << y[i] << endl;
	}
	double *x = new double[n];
	x[n - 1] = y[n - 1] / u[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < n ; j++) {
			sum += u[i][j] * x[j];
		}
		x[i] = (y[i] - sum) / u[i][i];
	}
	for (int i = 0; i < n; i++) {
		cout << "X" << i + 1 << "=" << x[i] << endl;
	}
	return;
}