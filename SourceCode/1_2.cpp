#include"h1.h"
using namespace std;
void ex1_2() {
	int n;
	cout << "��������n�β�ֵ����������n:" ;
	cin>>n;
	vector<double> x, y;
	for (int i = 0; i < n; i++) {
		cout << "�������ֵ�ڵ��(x" << i << ",y" << i << "): " ;
		double xi, yi;
		cin >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
	}
	vector<polynomial> li;
	stack<polynomial> spson;
	stack<double> spmum;
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n; j++) {
			if (j != i) {
				if (!spmum.empty()) {
					double temp = spmum.top();
					spmum.pop();
					spmum.push(temp*(x[i] - x[j]));
				}
				else {
					spmum.push(x[i] - x[j]);
				}
				if (!spson.empty()) {
					polynomial temp = spson.top();
					spson.pop();
					vector<double> v{ -x[j],1 };
					spson.push(temp*polynomial(v));
				}
				else {
					vector<double> v{ -x[j],1 };
					spson.push(polynomial(v));
				}
			}
		}
		li.push_back(spson.top()*(1 / spmum.top()));
		spson.pop();
		spmum.pop();
	}
	polynomial res;
	res.x.push_back(0);
	for (int i = 0; i < n; i++) {
		res = res + li[i] * y[i];
	}
	cout << "����Ķ���ʽ��ʾΪ: "<<res<<endl ;
	cout << "�������X�������Ӧ�ĺ�������ֵ: ";
	double t;
	while (cin >> t) {
		cout<<res.f(t)<<endl;
		cout << "�������X�������Ӧ�ĺ�������ֵ: ";
	}
	return;
}