#include"h1.h"
using namespace std;
void swapCol(vector<polynomial> &v, int i,int j) {
	int size = v.size();
	for (int t = 0; t < size; t++) {
		swap(v[t][i], v[t][j]);
	}
	return;
}
void ex2_3() {
	int m, n;
	cout << "列主元高斯消元法，请输入系数矩阵A行数row:";
	cin >> m;
	cout << "请输入系数矩阵A列数col:";
	cin >> n;
	vector<polynomial> v(m);
	vector<double> x, y;
	double xi;
	for (int i = 0; i < m; i++) {
		cout << "请输入系数矩阵第" << i + 1 << "行的" << n << "个元素:";
		for (int j = 0; j < n; j++) {
			cin >> xi;
			v[i].x.push_back(xi);
		}
	}
	cout << "请输入右端项b的" << m << "个元素:";
	for (int i = 0; i < m; i++) {
		cin >> xi;
		v[i].x.push_back(xi);
	}
	double e;
	cout << "请输入ε:";
	cin >> e;
	int *d = new int[m];
	for (int i = 0; i < m; i++) {
		d[i] = i;
	}
	int size = v.size();
	vector<double> res(size);
	for (int k = 0; k < size - 1; k++) {
		double t = 0;
		int indexi = 0,indexj=0;
		for (int i = k; i <= size - 1; i++) {
			for (int j = k; j <= size - 1; j++) {
				if (t < abs(v[i][j])) {
					indexi = i;
					indexj = j;
					t = abs(v[i][j]);
				}
			}
		}
		if (t < e) {
			cout << "求解失败" << endl;
			return;
		}
		else {
			if (indexi != k) {
				swap(v[k], v[indexi]);
			}
			if (indexj != k) {
				swapCol(v, indexj, k);
				swap(d[indexj], d[k]);
			}
			for (int i = k + 1; i < size; i++) {
				double t = v[i][k] / v[k][k];
				v[i][size] = v[i][size] - t * v[k][size];
				for (int j = k + 1; j < size; j++) {
					v[i][j] = v[i][j] - t * v[k][j];
				}
			}
		}
	}
	if (abs(v[size - 1][size - 1]) <= e) {
		cout << "求解失败" << endl;
		return;
	}
	else {
		res[size - 1] = v[size - 1][size] / v[size - 1][size - 1];
		for (int i = size - 2; i >= 0; i--) {
			double sum = 0;
			for (int j = i + 1; j < size; j++) {
				sum += v[i][j] * res[j];
			}
			res[i] = (v[i][size] - sum) / v[i][i];
		}
	}
	size = res.size();
	if (size == 0) return;
	else {
		for (int i = 0; i < size; i++) {
			cout << "X" << i + 1 << "=" << res[d[i]] << endl;
		}
	}
	return;
}