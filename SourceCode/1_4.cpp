#include"h1.h"
using namespace std;
void ex1_4() {
	int n;
	cout << "三次样条插值法，请输入插值节点数n:";
	cin >> n;
	vector<double> x, y, h;
	for (int i = 0; i < n; i++) {
		cout << "请输入插值节点对(x" << i << ",y" << i << "): ";
		double xi, yi;
		cin >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
		if (i != 0) {
			h.push_back(xi - x[i - 1]);
		}	
	}
	int kind = 0;
	while (1) {
		cout << "以下有两种边界条件：" << endl;
		cout << "1.已知两个端点的一阶导数值" << endl;
		cout << "2.已知两个端点的二阶导数值为0" << endl;
		cout << "请输入是哪种边界情况(1或2):" << endl;
		cin >> kind;
		if (kind == 1) {
			cout << "请输入端点x0和x"<<n-1<<"处的一阶导数值" << endl;
			break;
		}
		else if (kind == 2) {
			break;
		}
		else {
			cout << "输入了不正确的内容，请按照提示输入" << endl;
		}
	}
	double *m = new double[n];
	double *a = new double[n];
	double *b = new double[n];
	if (kind == 1) {
		cin >> m[0] >> m[n-1];
		a[0] = 0;	
		b[0] = 2 * m[0];
		a[n-1] = 1;
		b[n-1] = 2 * m[n-1];
	}
	else {
		m[0] = 0;
		m[n-1] = 0;
		a[0] = 1;
		b[0] = 3*(y[1]-y[0])/h[0];
		a[n-1] = 0;
		b[n-1] = 3 * (y[n-1] - y[n-2]) / h[n-2];
	}
	for (int i = 1; i < n-1; i++) {
		a[i] = h[i - 1] / (h[i - 1] + h[i]);
		b[i] = 3 * ((1 - a[i])*(y[i] - y[i - 1]) / h[i - 1] + a[i] * (y[i + 1] - y[i]) / h[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			a[i] = -a[0] / 2;
			b[i] = b[0] / 2;
		}
		else {	
			b[i] = (b[i] - (1 - a[i])*b[i - 1]) / (2 + (1 - a[i])*a[i - 1]);
			a[i] = -a[i] / (2 + (1 - a[i]) * a[i - 1]);
		}
	}
	m[n - 1] = b[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		m[i] = a[i] * m[i + 1] + b[i];
	}
	vector<polynomial> ss;
	for (int i = 0; i < n - 1; i++) {
		polynomial yy;
		polynomial p1;
		polynomial p2;
		p1.x = { -x[i],1 };
		p1 = p1 * 2 / (x[i + 1] - x[i]) + 1;
		p2.x = { -x[i+1],1 };
		p2 = p2 / (x[i] - x[i + 1]);
		yy = p1 * p2.pow(2)*y[i];
		p1.x = { -x[i+1],1 };
		p1 = p1 * 2 / (x[i] - x[i+1]) + 1;
		p2.x = { -x[i],1 };
		p2 = p2 / (x[i+1] - x[i]);
		yy = yy + p1 * p2.pow(2)*y[i+1];
		p1.x = { -x[i],1 };
		p2.x = { -x[i+1],1 };	
		p2 = p2 / (x[i] - x[i+1]);
		yy = yy + p1 * p2.pow(2)*m[i];
		p1.x = { -x[i + 1],1 };
		p2.x = { -x[i],1 };
		p2 = p2 / (x[i + 1] - x[i]);
		yy = yy + p1 * p2.pow(2)*m[i + 1];
		ss.push_back(yy);
	}
	for (int i = 0; i < n - 1; i++) {
		cout << "当x>=" << x[i] << "且x<=" << x[i + 1] << "时，插值多项式s=" << ss[i] << endl;
	}
	cout << "请输入点X以输出相应的函数近似值: ";
	double t;
	while (cin >> t) {
		int flag = 0;
		for (int i = 0; i < n-1; i++) {
			if (t >= x[i] && t <= x[i + 1]) {
				cout<<ss[i].f(t)<<endl;
				flag = 1;
				break;
			}
		}
		if(flag=0)
			cout << "输入点不不在插值范围内"<<endl;
		cout << "请输入点X以输出相应的函数近似值: ";
	}
	return;
}