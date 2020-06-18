#include"h1.h"
using namespace std;
void ex1_2() {
	int n;
	cout << "拉格朗日n次插值法，请输入n:" ;
	cin>>n;
	vector<double> x, y;
	for (int i = 0; i < n; i++) {
		cout << "请输入插值节点对(x" << i << ",y" << i << "): " ;
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
	cout << "结果的多项式表示为: "<<res<<endl ;
	cout << "请输入点X以输出相应的函数近似值: ";
	double t;
	while (cin >> t) {
		cout<<res.f(t)<<endl;
		cout << "请输入点X以输出相应的函数近似值: ";
	}
	return;
}