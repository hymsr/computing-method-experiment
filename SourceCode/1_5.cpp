#include"h1.h"
#include<iomanip>
using namespace std;
void ex1_5() {
	int n;
	cout << "������������Ϻ���F(x) = a + bx�����������ݵ����n:";
	cin >> n;
	vector<double> x, y;
	double sumx = 0, sumy = 0, sumxx = 0, sumxy = 0;
	for (int i = 0; i < n; i++) {
		cout << "���������ݶ�(x" << i << ",y" << i << "): ";
		double xi, yi;
		cin >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
		sumx += xi;
		sumy += yi;
		sumxx += xi * xi;
		sumxy += xi * yi;
	}
	double resA = (sumxx*sumy - sumx * sumxy) / (n*sumxx - sumx * sumx);
	double resB = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
	cout << "a=" << resA << ",b=" << resB << endl;
	return;
}