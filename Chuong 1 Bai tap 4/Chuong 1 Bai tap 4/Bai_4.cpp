#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class NhanVien {
	string ma_so, ten, phong_ban;
	long long luong, thuong, thuc_lanh;
public : 
	void nhap() {
		cout << "Nhap ma nhan vien : ";
		cin.ignore();
		getline(cin, ma_so);
		cout << "Nhap ho va ten : ";
		getline(cin, ten);
		cout << "Nhap phong ban : ";
		getline(cin, phong_ban);
		cout << "Nhap luong cua nhan vien : ";
		cin >> luong;
		cout << "Nhap thuong cua nhan vien : ";
		cin >> thuong;
		thuc_lanh = luong + thuong;
	}
	string maso() const {
		return ma_so;
	}
	string phongban() const {
		return phong_ban;
	}
	long long thuclanh() const {
		return thuc_lanh;
	}
	long long luong_co_ban() const {
		return luong;
	}
	long long muc_thuong() const {
		return thuong;
	}
	void xuat() const {
		cout << "Ma so nhan vien : " << ma_so << endl;
		cout << "Ho va Ten : " << ten << endl;
		cout << "Phong ban : " << phong_ban << endl;
		cout << "Luong thang : " << luong << endl;
		cout << "Luong thuong : " << thuong << endl;
		cout << "Thuc lanh : " << thuc_lanh << endl;
	}
};

bool cachSapXep(const NhanVien& a, const NhanVien& b) {
	if (a.phongban() == b.phongban()) {
		return a.maso() > b.maso();
	}
	else {
		return a.phongban() < b.phongban();
	}
}

class CongTy {
	vector<NhanVien> danh_sach_nv;
public :
	void them_nv(const NhanVien& nv) {
		danh_sach_nv.push_back(nv);
	}
	long long tong_thuc_lanh() {
		long long tong = 0;
		for (const NhanVien& nv : danh_sach_nv) {
			tong += nv.thuclanh();
		}
		return tong;
	}
	void danh_sach_luong_min() {
		if (danh_sach_nv.empty()) {
			cout << "Chua co nhan vien nao ca !" << endl;
			return;
		}
		long long luong_min = danh_sach_nv[0].luong_co_ban();
		for (const NhanVien& nv : danh_sach_nv) {
			long long tem_luong = nv.luong_co_ban();
			if (luong_min > tem_luong) {
				luong_min = tem_luong;
			}
		}
		for (const NhanVien& nv : danh_sach_nv) {
			if (nv.luong_co_ban() == luong_min) {
				nv.xuat();
			}
		}
	}
	void in_danh_sach_nv() {
		sort(danh_sach_nv.begin(), danh_sach_nv.end(), cachSapXep);
		cout << "-- Danh Sach Nhan Vien Cua Cong Ty -- " << endl;
		for (const NhanVien& nv : danh_sach_nv) {
			nv.xuat();
			cout << endl;
		}
	}
	int so_nv_thuong_cao() {
		int count = 0;
		for (const NhanVien& nv : danh_sach_nv) {
			if (nv.muc_thuong() >= 1200000) count++;
		}
		return count;
	}
};

int main() {
	CongTy congty;
	int thaotac = 1;
	while (thaotac != 0) {
		cout << "0. Ket thuc chuong trinh" << endl;
		cout << "1. Nhap nhan vien moi" << endl;
		cout << "2. In tong thuc lanh cua tat ca nhan vien " << endl;
		cout << "3. In nhung nhan vien co luong co ban thap nhat" << endl;
		cout << "4. So luong nhan vien thuong >= 1200000" << endl;
		cout << "5. In ra danh sach toan bo nhan vien" << endl;
		cout << "Chon thao tac : ";
		cin >> thaotac;
		cout << endl;
		switch (thaotac) {
			case 0: {
				break;
			}
			case 1: {
				NhanVien tem_nv;
				tem_nv.nhap();
				congty.them_nv(tem_nv);
				break;
			}
			case 2: {
				cout << "Tong thuc lanh cua tat ca nhan vien : " << congty.tong_thuc_lanh() << endl;
				break;
			}
			case 3: {
				cout << "Danh sach nhung nhan vien co luong co ban thap nhat : " << endl;
				congty.danh_sach_luong_min();
				break;
			}
			case 4: {
				cout << "So luong nhan vien co thuong >= 1200000 : " << congty.so_nv_thuong_cao() << endl;
				break;
			}
			case 5: {
				congty.in_danh_sach_nv();
				break;
			}
			default: {
				cout << "Thao tac khong hop le, vui long nhap lai !" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}