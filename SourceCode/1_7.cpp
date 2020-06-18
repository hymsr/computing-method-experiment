#include"h1.h"
using namespace std;
double f1_7(double t) {//本实验的被积函数,修改本函数可以修改被积函数
	return sqrt(t);
}
void ex1_7() {
	double a, b;
	cout << "Romberg求积法求积分，请分别输入积分下限a和上限b:";
	cin >> a >> b;
	cout << "请输入ε：";
	double e;
	cin >> e;
	vector<vector<double>> t = { {(b - a)*(f1_7(a) + f1_7(b)) / 2} };
	int k = 1;
	while (1) {
		double sum = 0;
		for (int i = 1; i <= pow(2,k-1); i++) {
			sum += f1_7(a + (2 * i - 1)*(b - a) / pow(2, k));
		}
		t[0].push_back((t[0][k - 1] + ((b - a) / pow(2, k - 1))*sum) *0.5);
		for (int m = 1; m <= k; m++) {
			if (m == k) {
				t.push_back({});
			}
			t[m].push_back((pow(4, m)*t[m - 1][k - m + 1] - t[m - 1][k - m]) / (pow(4, m) - 1));
		}
		if (t[k][0] - t[k - 1][0] < e) {
			cout << "结果的近似值为：" << t[k][0] << endl;
			return;
		}
		k += 1;
	}
	return;
}