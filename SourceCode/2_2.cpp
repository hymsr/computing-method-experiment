#include"h1.h"
using namespace std;
void ex2_2() {
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
	int size = v.size();
	vector<double> res(size);
	for (int k = 0; k < size - 1; k++) {
		double t = 0;
		int index = 0;
		for (int i = k; i <= size - 1; i++) {
			if (t < abs(v[i][k])) {
				index = i;
				t = abs(v[i][k]);
			}
		}
		if (t < e) {
			cout << "求解失败" << endl;
			return;
		}
		else {
			if (index != k) {
				swap(v[k], v[index]);
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
			cout << "X" << i + 1 << "=" << res[i] << endl;
		}
	}
	return;
}