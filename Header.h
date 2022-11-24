#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
	char maNV[50];    // mã
	char tenNV[100];  // tên
	int gioiTinh;     // giới tính     1: nam, 0: nữ
	int namSinh;      // năm sinh
	int chucVu;       // chức vụ       1: nhân viên, 2: phó phòng, 3: trưởng phòng, 4: phó giám đốc, 5: giám đốc
	int luong;        // lương
};
typedef NhanVien NHANVIEN;

struct NodeNhanVien {
	NHANVIEN data;
	NodeNhanVien* link;
};
typedef NodeNhanVien* Nodeptr;

void khoiTao(Nodeptr& list);
Nodeptr taoNode(NHANVIEN nv);
Nodeptr themCuoi(Nodeptr& list, NHANVIEN nv);
void giaiPhongDanhSachNhanVien(Nodeptr& list);
//
// Câu 1
void nhapDanhSachNhanVien(Nodeptr& list);
bool kiemTraTrungMaNhanVien(Nodeptr list, char* ma);
//
// Câu 2
void nhapLuongCoBanVaTinhLuongNhanVien(Nodeptr list);
//
// Câu 3
void xuatDanhSachNhanVien(Nodeptr list);
//
// Câu 4
Nodeptr timNhanVienBangMaNV(Nodeptr list, NHANVIEN nv);
void xuatMotNhanVien(NHANVIEN nv);
//
// Câu 5
Nodeptr timNhanVienNuDauTien(Nodeptr list);
Nodeptr timNhanVienNuCoSoTuoiLonNhat(Nodeptr list);
Nodeptr timNhanVienNuCoSoTuoiNhoNhat(Nodeptr list);
//
// Câu 6
Nodeptr timNhanVienNamDauTien(Nodeptr list);
Nodeptr timNhanVienNamCoSoTuoiLonNhat(Nodeptr list);
Nodeptr timNhanVienNamCoSoTuoiNhoNhat(Nodeptr list);
//
// Câu 7
void xuatFileKetQuaThongKeSoLuongNhanVienTheoDoTuoi(Nodeptr list);
void layThoiGianHeThong(int& nam);
//
// Câu 8
void xuatFileKetQuaThongKeSoLuongNhanVienTheoGioiTinh(Nodeptr list);
//
// Câu 9
void inDanhSachNhanVienCoChucVuTu_2_Den_5(Nodeptr list);
//
// Câu 10
void sapXepDanhSachTangDanTheoNamSinh(Nodeptr& list);