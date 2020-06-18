#include"h1.h"
using namespace std;
void ex2_1() {
	int m,n;
	cout << "˳���˹��Ԫ����������ϵ������A����row:";
	cin >> m;
	cout << "������ϵ������A����col:";
	cin >> n;
	vector<polynomial> v(m);
	vector<double> x, y;
	double xi;
	for (int i = 0; i < m; i++) {
		cout << "������ϵ�������"<<i+1<<"�е�"<<n<<"��Ԫ��:";
		for (int j = 0; j < n; j++) {
			cin >> xi;
			v[i].x.push_back(xi);
		}
	}
	cout << "�������Ҷ���b��" << m << "��Ԫ��:";
	for (int i = 0; i < m; i++) {
		cin >> xi;
		v[i].x.push_back(xi);
	}
	double e;
	cout << "�������:";
	cin >> e;
	int size = v.size();
	vector<double> res(size);
	for (int k = 0; k < size - 1; k++) {
		if (abs(v[k][k]) <= e) {
			cout << "���ʧ��" << endl;
			return;
		}
		else {
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
		cout << "���ʧ��" << endl;
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