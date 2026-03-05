#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class matran {
	int so_dong, so_cot;
	vector<vector<int>> giatri;
public :
	void nhap(int dong, int cot) {
		so_dong = dong;
		so_cot = cot;
		giatri.resize(so_dong, vector<int>(so_cot));
	}
	void nhap() {
		string chuoi;
		int max_cot = 0;
		while (true) {
			getline(cin, chuoi);
			if (chuoi.empty()) break;
			stringstream ss(chuoi);
			vector<int> dong_ht;
			int phantu;
			while (ss >> phantu) {
				dong_ht.push_back(phantu);
			}
			if (!dong_ht.empty()) {
				giatri.push_back(dong_ht);
				if (dong_ht.size() > max_cot) max_cot = dong_ht.size();
			}

		}
		so_dong = giatri.size();
		so_cot = max_cot;
		for (int i = 0; i < so_dong; i++) {
			giatri[i].resize(so_cot, 0);
		}
	}
	bool co_the_cong(const matran& mt) const{
		if (so_dong == mt.so_dong && so_cot == mt.so_cot)
			return true;
		else
			return false;
	}
	bool co_the_nhan(const matran& mt) const{
		return (so_cot == mt.so_dong);
	}
	matran operator+ (const matran& mt) const{
		matran mt_tong;
		mt_tong.nhap(so_dong, so_cot);
		for (int i = 0; i < so_dong; i++)
		for (int j = 0; j < so_cot; j++)
			mt_tong.giatri[i][j] = giatri[i][j] + mt.giatri[i][j];
		return mt_tong;
	}
	matran operator- (const matran& mt) const{
		matran mt_hieu;
		mt_hieu.nhap(so_dong, so_cot);
		for (int i = 0; i < so_dong; i++)
			for (int j = 0; j < so_cot; j++)
				mt_hieu.giatri[i][j] = giatri[i][j] - mt.giatri[i][j];
		return mt_hieu;
	}
	matran operator* (const matran& mt) const{
		matran mt_tich;
		mt_tich.nhap(so_dong, mt.so_cot);
		for (int i = 0; i < mt_tich.so_dong; i++) {
			for (int j = 0; j < mt_tich.so_cot; j++) {
				mt_tich.giatri[i][j] = 0;
				for (int k = 0; k < so_cot; k++) {
					mt_tich.giatri[i][j] += giatri[i][k] * mt.giatri[k][j];
				}
			}
		}
		return mt_tich;
	}
	void xuat() const {
		if (so_dong == 0 || so_cot == 0) {
			cout << "Ma tran rong!" << endl;
			return;
		}
		for (int i = 0; i < so_dong; i++) {
			for (int j = 0; j < so_cot; j++) {
				cout << giatri[i][j] << "\t";
			}
			cout << endl;
		}
	}
};

int main() {
	matran mt1, mt2;
	cout << "Nhap ma tran thu nhat : " << endl;
	mt1.nhap();
	cout << "Nhap ma tran thu hai : " << endl;
	mt2.nhap();
	if (mt1.co_the_cong(mt2)) {
		cout << "Tong 2 ma tran nay la :" << endl;
		matran tong = mt1 + mt2;
		tong.xuat();
		cout << "Hieu 2 ma tran nay la : " << endl;
		matran hieu = mt1 - mt2;
		hieu.xuat();
	}
	else {
		cout << "Hai ma tran nay khong the cong !" << endl;
		cout << "Hai ma tran nay khong the tru  !" << endl;
	}
	if (mt1.co_the_nhan(mt2)) {
		cout << "Tich hai ma tran nay la : " << endl;
		matran tich = mt1 * mt2;
		tich.xuat();
	}
	else {
		cout << "Hai ma tran nay khong the nhan ! " << endl;
	}
	return 0;
}