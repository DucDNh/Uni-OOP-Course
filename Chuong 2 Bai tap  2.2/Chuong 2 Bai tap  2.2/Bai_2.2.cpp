#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int gcd(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a != 0 && b != 0) {
		if (a >= b)
			a %= b;
		else
			b %= a;
	}
	if (a == 0)
		return b;
	else
		return a;
}

class phanso {
	int tu, mau;
public:
	void nhap(int t, int m) {
		tu = t;
		mau = m;
		rut_gon();
	}
	void rut_gon() {
		if (mau == 0) return;
		int ucnn = gcd(tu, mau);
		tu /= ucnn;
		mau /= ucnn;
	}
	void xuat() {
		int tem_tu = abs(tu), tem_mau = abs(mau);
		if (tu * mau < 0) cout << '-';
		if (tem_mau == 1)
			cout << tem_tu ;
		else
			cout << tem_tu << '/' << tem_mau;
	}
	phanso operator+ (phanso ps) {
		phanso tem_ps;
		tem_ps.tu = (tu * ps.mau) + (ps.tu * mau);
		tem_ps.mau = mau * ps.mau;
		tem_ps.rut_gon();
		return tem_ps;
	}
	bool operator> (const phanso& tem_ps) const {
		double gia_tri_1 = (double)tu / mau;
		double gia_tri_2 = (double)tem_ps.tu / tem_ps.mau;

		return gia_tri_1 > gia_tri_2;
	}
};

int main() {
	cout << "Nhap day cac phan so tren mot hang : " << endl;
	string dauvao;
	getline(cin, dauvao);
	stringstream ss(dauvao);
	vector<phanso> ds_phanso;
	int t, m;
	char c;
	while (ss >> t >> c >> m) {
		if (m != 0 && c == '/') {
			phanso tem_ps;
			tem_ps.nhap(t, m);
			ds_phanso.push_back(tem_ps);
		}
	}
	if (ds_phanso.empty()) {
		cout << "Khong co phan so nao duoc nhap !" << endl;
	}
	else {
		phanso max_ps = ds_phanso[0];
		for (const phanso& ps : ds_phanso) {
			if (ps > max_ps) max_ps = ps;
		}
		cout << "Phan so lon nhat trong day : ";
		max_ps.xuat();
		cout << endl;
		phanso tong_ps = ds_phanso[0];
		for (int i = 1; i < ds_phanso.size(); i++) {
			tong_ps = tong_ps + ds_phanso[i];
		}
		cout << "Tong cac phan so trong day : ";
		tong_ps.xuat();
		cout << endl;
	}
	return 0;
}