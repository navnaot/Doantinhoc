#include "Header.h"

int main() {
	NHANVIEN nv;
	Nodeptr ds;
	khoiTao(ds); // Khởi tạo danh sách nhân viên
	int luaChon;
	bool thoat = false;
	do {
		system("cls");
		cout << "*--------------------------------------------------------------------*\n";
		cout << "|                          QUAN LY NHAN SU                           |\n";
		cout << "*--------------------------------------------------------------------*\n";
		cout << "|   1.   Nhap danh sach nhan vien                                    |\n";
		cout << "|   2.   Nhap luong co ban va tinh luong nhan vien                   |\n";
		cout << "|   3.   Xuat danh sach nhan vien                                    |\n";
		cout << "|   4.   Tim kiem nhan vien                                          |\n";
		cout << "|   5.   Nhan vien nu co tuoi lon nhat va nho nhat                   |\n";
		cout << "|   6.   Nhan vien nam co tuoi lon nhat va nho nhat                  |\n";
		cout << "|   7.   Xuat file thong ke so luong nhan vien theo do tuoi          |\n";
		cout << "|   8.   Xuat file thong ke so luong nhan vien theo gioi tinh        |\n";
		cout << "|   9.   In danh sach nhan vien co chuc vu tu 2 - 5                  |\n";
		cout << "|   10.  Sap xep danh sach tang dan theo nam sinh                    |\n";
		cout << "*--------------------------------------------------------------------*\n";
		cout << "\tLua chon cua ban -> ";
		cin >> luaChon;
		fflush(stdin);
		switch (luaChon) {
		case 1: {
			system("cls");
			cout << "\nMENU/NHAP DANH SACH NHAN VIEN\n";
			nhapDanhSachNhanVien(ds);
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			cout << "\nMENU/NHAP LUONG CO BAN VA TINH LUONG NHAN VIEN\n";
			nhapLuongCoBanVaTinhLuongNhanVien(ds);
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			cout << "\nMENU/XUAT DANH SACH NHAN VIEN\n";
			xuatDanhSachNhanVien(ds);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			cout << "\nMENU/TIM KIEM NHAN VIEN\n";
			cout << "\n(?) Nhap ma nhan vien can tim: ";
			cin.ignore();
			cin.getline(nv.maNV, 10);
			Nodeptr p = timNhanVienBangMaNV(ds, nv);
			if (p == NULL)
				cout << "\n\t(!) Ma nhan vien khong ton tai\n";
			else {
				cout << "\n\tTHONG TIN NHAN VIEN CO MA " << nv.maNV << "\n";
				xuatMotNhanVien(p->data);
			}
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			Nodeptr p1, p2;
			// Kiểm tra nếu danh sách == NULL thì xuất thông báo danh sách trống. Không thì tiếp tục
			if (ds == NULL)
				cout << "\n\t(!) Danh sach nhan vien trong\n";
			else {
				cout << "\nMENU/NHAN VIEN NU CO TUOI LON NHAT VA NHO NHAT\n";
				p1 = timNhanVienNuCoSoTuoiLonNhat(ds);
				p2 = timNhanVienNuCoSoTuoiNhoNhat(ds);
				if (p1 != NULL) {
					cout << "\nThong tin nhan vien nu co tuoi lon nhat trong danh sach\n";
					xuatMotNhanVien(p1->data);
				} else
					cout << "\n\t(!) Khong tim thay nhan vien nu co tuoi lon nhat trong danh sach\n";
				if (p2 != NULL) {
					cout << "\nThong tin nhan vien nu co tuoi nho nhat trong danh sach\n";
					xuatMotNhanVien(p2->data);
				} else
					cout << "\n\t(!) Khong tim thay nhan vien nu co tuoi nho nhat trong danh sach\n";
			}
			system("pause");
			break;
		}
		case 6: {
			system("cls");
			Nodeptr p1, p2;
			// Kiểm tra nếu danh sách == NULL thì xuất thông báo danh sách trống. Không thì tiếp tục
			if (ds == NULL)
				cout << "\n\t(!) Danh sach nhan vien trong\n";
			else {
				cout << "\nMENU/NHAN VIEN NAM CO TUOI LON NHAT VA NHO NHAT\n";
				p1 = timNhanVienNamCoSoTuoiLonNhat(ds);
				p2 = timNhanVienNamCoSoTuoiNhoNhat(ds);
				if (p1 != NULL) {
					cout << "\nThong tin nhan vien nam co tuoi lon nhat trong danh sach\n";
					xuatMotNhanVien(p1->data);
				} else
					cout << "\n\t(!) Khong tim thay nhan vien nam co tuoi lon nhat trong danh sach\n";
				if (p2 != NULL) {
					cout << "\nThong tin nhan vien nam co tuoi nho nhat trong danh sach\n";
					xuatMotNhanVien(p2->data);
				} else
					cout << "\n\t(!) Khong tim thay nhan vien nam co tuoi nho nhat trong danh sach\n";
			}
			system("pause");
			break;
		}
		case 7: {
			system("cls");
			cout << "\nMENU/XUAT FILE THONG KE SO LUONG NHAN VIEN THEO DO TUOI\n";
			xuatFileKetQuaThongKeSoLuongNhanVienTheoDoTuoi(ds);
			cout << "\n\t(!) Xuat file thanh cong\n";
			system("pause");
			break;
		}
		case 8: {
			system("cls");
			cout << "\nMENU/XUAT FILE THONG KE SO LUONG NHAN VIEN THEO GIOI TINH\n";
			xuatFileKetQuaThongKeSoLuongNhanVienTheoGioiTinh(ds);
			cout << "\n\t(!) Xuat file thanh cong\n";
			system("pause");
			break;
		}
		case 9: {
			system("cls");
			cout << "\nMENU/IN DANH SACH NHAN VIEN CO CHUC VU TU 2 DEN 5\n";
			inDanhSachNhanVienCoChucVuTu_2_Den_5(ds);
			system("pause");
			break;
		}
		case 10: {
			system("cls");
			cout << "\nMENU/SAP XEP DANH SACH TANG DAN THEO NAM SINH\n";
			sapXepDanhSachTangDanTheoNamSinh(ds);
			system("pause");
			break;
		}
		case 0:
			thoat = true;
			break;
		default:
			cout << "\n\t(!) Lua chon khong hop le\n";
			system("pause");
			break;
		}
	} while (!thoat);
	giaiPhongDanhSachNhanVien(ds); // Kết thúc thì giải phóng để tiết kiệm bộ nhớ
	return 0;
}