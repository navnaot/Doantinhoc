#include "Header.h"

// Khởi tạo danh sách và gán bằng NULL
void khoiTao(Nodeptr& list) { list = NULL; }

// Tạo Node nhân viên
Nodeptr taoNode(NHANVIEN nv) {
	Nodeptr p;
	p = new NodeNhanVien;
	p->data = nv;
	p->link = NULL;
	return p;
}

// Thêm vào cuối danh sách
Nodeptr themCuoi(Nodeptr& list, NHANVIEN nv) {
	Nodeptr p = taoNode(nv);
	if (list == NULL)
		list = p;
	else {
		Nodeptr q = list;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
	return p;
}

// Giải phóng bộ nhớ danh sách nhân viên
void giaiPhongDanhSachNhanVien(Nodeptr& list) {
	Nodeptr p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}

// Câu 1
void nhapDanhSachNhanVien(Nodeptr& list) {
	NHANVIEN nv;
	int dem = 1;
	int n;
	do {
		cout << "\n\t(!) Nhap so luong nhan vien: ";
		cin >> n;
		// Kiểm tra nếu số lượng n nhập vào <= 0 thì bắt nhập lại
		if (n <= 0)
			cout << "\n\t(!) So luong nhan vien phai > 0. Xin hay nhap lai\n";
	} while (n <= 0);
	cin.ignore();
	// Duyệt từ 0 đến n để nhập thông tin n nhân viên
	for (int i = 0; i < n; i++) {
		system("cls");
		cout << "\n\tNHAP THONG TIN NHAN VIEN THU " << dem++ << "\n";
		do {
			cout << "\n(?) Nhap ma nhan vien (nhap -1 de dung): ";
			cin.getline(nv.maNV, 10);
			// Kiểm tra mã nhân viên đã bị trùng hay chưa, nếu trùng thì bắt nhập lại
			if (kiemTraTrungMaNhanVien(list, nv.maNV) == true)
				cout << "\n\t(!) Ma nhan vien da bi trung. Xin hay nhap lai\n";
		} while (kiemTraTrungMaNhanVien(list, nv.maNV) == true);
		//
		do {
			cout << "\n(?) Nhap ten nhan vien: ";
			cin.getline(nv.tenNV, 30);
			// Kiểm tra nếu tên nhân viên > 30 kí tự thì bắt nhập lại
			if (strlen(nv.tenNV) > 30)
				cout << "\n\t(!) Ten nhan vien chi duoc nho hon 30 ki tu. Xin hay nhap lai\n";
		} while (strlen(nv.tenNV) > 30);
		//
		do {
			cout << "\n(?) Nhap gioi tinh (1. Nam, 0. Nu): ";
			cin >> nv.gioiTinh;
			// Kiểm tra nếu giới tính != 0 hoặc giới tính != 1 thì bắt nhập lại
			if (nv.gioiTinh < 0 || nv.gioiTinh > 1)
				cout << "\n\t(!) Gioi tinh khong hop le. Xin hay nhap lai (Chon 1 hoac 0)\n";
		} while (nv.gioiTinh < 0 || nv.gioiTinh > 1);
		//
		cout << "\n(?) Nhap nam sinh: ";
		cin >> nv.namSinh;
		//
		do {
			cout << "\n(?) Nhap chuc vu (1. Nhan vien, 2. Pho phong, 3. Truong phong, 4. Pho giam doc, 5. Giam doc): ";
			cin >> nv.chucVu;
			// Kiểm tra nếu nhập chức vụ khác từ 1-5 thì bắt nhập lại
			if (nv.chucVu < 1 || nv.chucVu > 5)
				cout << "\n\t(!) Lua chon khong hop le. Xin hay nhap lai (Chon tu 1 - 5)\n";
		} while (nv.chucVu < 1 || nv.chucVu > 5);
		//
		do {
			cout << "\n(?) Nhap luong: ";
			cin >> nv.luong;
			// Kiểm tra nếu lương < 0 thì bắt nhập lại. Vì lương không thể là số âm
			if (nv.luong < 0)
				cout << "\n\t(!) Muc luong phai lon hon hoac bang 0. Xin hay nhap lai\n";
		} while (nv.luong < 0);
		//
		cin.ignore();
		// Thêm nhân viên vừa nhập vào cuối danh sách
		themCuoi(list, nv);
	}
	system("cls");
	// Khi không nhập nhân viên nữa thì xuất thông báo thành công
	cout << "\n\t(!) Nhap danh sach nhan vien thanh cong\n";
}

// Hàm kiểm tra mã nhân viên đã tồn tại hay chưa
// Nếu đã tồn tại thì trả về true, nếu chưa thì trả về false
bool kiemTraTrungMaNhanVien(Nodeptr list, char* ma) {
	while (list != NULL) {
		if (strcmp(list->data.maNV, ma) == 0)
			return true;
		list = list->link;
	}
	return false;
}

// Câu 2
void nhapLuongCoBanVaTinhLuongNhanVien(Nodeptr list) {
	int luongCoBan;
	do {
		cout << "\n(?) Nhap luong co ban: ";
		cin >> luongCoBan;
		// Kiểm tra nếu lương < 0 thì bắt nhập lại. Vì lương không thể là số âm
		if (luongCoBan < 0)
			cout << "\n\t(!) Luong co ban phai lon hon hoac bang 0. Xin hay nhap lai\n";
	} while (luongCoBan < 0);

	// Nếu danh sách == NULL thì xuất thông báo danh sách trống. Không thì tiếp tục
	if (list == NULL)
		cout << "\n\t(!) Danh sach nhan vien trong\n";
	else {
		cout << setw(10) << left << "Ma"
			<< "\t";
		cout << setw(30) << left << "Ten"
			<< "\t";
		cout << setw(15) << left << "Gioi tinh"
			<< "\t";
		cout << setw(15) << left << "Nam sinh"
			<< "\t";
		cout << setw(15) << left << "Chuc vu"
			<< "\t";
		cout << setw(30) << left << "Luong"
			<< "\t\n";
		// Duyệt từ đầu đến cuối danh sách
		while (list != NULL) {
			string gioiTinh, chucVu;
			// Kiểm tra nếu giới tính là 1 thì định dạng xuất ra sẽ là Nam, ngược lại thì là Nữ
			if (list->data.gioiTinh == 1)
				gioiTinh = "Nam";
			else
				gioiTinh = "Nu";
			//
			if (list->data.chucVu == 1) // Kiểm tra nếu chức vụ là 1 thì định dạng xuất ra sẽ là Nhan vien
				chucVu = "Nhan vien";
			else if (list->data.chucVu == 2) // 2 thì định dạng xuất ra sẽ là Pho phong
				chucVu = "Pho phong";
			else if (list->data.chucVu == 3) // 3 thì định dạng xuất ra sẽ là Truong phong
				chucVu = "Truong phong";
			else if (list->data.chucVu == 4) // 4 thì định dạng xuất ra sẽ là Pho giam doc
				chucVu = "Pho giam doc";
			else
				chucVu = "Giam doc"; // 5 thì định dạng xuất ra sẽ là Giam doc
			//
			// Công thức lương = lương cơ bản * chức vụ
			list->data.luong = luongCoBan * list->data.chucVu;
			// Tính lương rồi gán lương cho nhân viên, xuất thông tin nhân viên đó ra
			cout << setw(10) << left << list->data.maNV << "\t";
			cout << setw(30) << left << list->data.tenNV << "\t";
			cout << setw(15) << left << gioiTinh << "\t";
			cout << setw(15) << left << list->data.namSinh << "\t";
			cout << setw(15) << left << chucVu << "\t";
			cout << setw(30) << left << list->data.luong << "\t\n";
			// Sau đó trỏ tới nhân viên tiếp theo và tiếp tục lặp lại cho đến cuối danh sách
			list = list->link;
		}
	}
}

// Câu 3
void xuatDanhSachNhanVien(Nodeptr list) {
	// Nếu danh sách == NULL thì xuất thông báo danh sách trống. Không thì tiếp tục
	if (list == NULL)
		cout << "\n\t(!) Danh sach nhan vien trong\n";
	else {
		cout << setw(10) << left << "Ma"
			<< "\t";
		cout << setw(30) << left << "Ten"
			<< "\t";
		cout << setw(15) << left << "Gioi tinh"
			<< "\t";
		cout << setw(15) << left << "Nam sinh"
			<< "\t";
		cout << setw(15) << left << "Chuc vu"
			<< "\t";
		cout << setw(30) << left << "Luong"
			<< "\t\n";
		// Duyệt từ đầu đến cuối danh sách
		while (list != NULL) {
			string gioiTinh, chucVu;
			// Kiểm tra nếu giới tính là 1 thì định dạng xuất ra sẽ là Nam, ngược lại thì là Nữ
			if (list->data.gioiTinh == 1)
				gioiTinh = "Nam";
			else
				gioiTinh = "Nu";
			//
			if (list->data.chucVu == 1) // Kiểm tra nếu chức vụ là 1 thì định dạng xuất ra sẽ là Nhan vien
				chucVu = "Nhan vien";
			else if (list->data.chucVu == 2) // 2 thì định dạng xuất ra sẽ là Pho phong
				chucVu = "Pho phong";
			else if (list->data.chucVu == 3) // 3 thì định dạng xuất ra sẽ là Truong phong
				chucVu = "Truong phong";
			else if (list->data.chucVu == 4) // 4 thì định dạng xuất ra sẽ là Pho giam doc
				chucVu = "Pho giam doc";
			else
				chucVu = "Giam doc"; // 5 thì định dạng xuất ra sẽ là Giam doc
			//
			cout << setw(10) << left << list->data.maNV << "\t";
			cout << setw(30) << left << list->data.tenNV << "\t";
			cout << setw(15) << left << gioiTinh << "\t";
			cout << setw(15) << left << list->data.namSinh << "\t";
			cout << setw(15) << left << chucVu << "\t";
			cout << setw(30) << left << list->data.luong << "\t\n";
			// Sau đó trỏ tới nhân viên tiếp theo và tiếp tục lặp lại cho đến cuối danh sách
			list = list->link;
		}
	}
}

// Câu 4
Nodeptr timNhanVienBangMaNV(Nodeptr list, NHANVIEN nv) {
	Nodeptr p = list;
	while (p != NULL) {
		// Kiểm tra nếu mã nhân viên giống nhau thì trả về nhân viên đó. Nếu không giống thì trỏ tiếp để tìm
		if (strcmp(p->data.maNV, nv.maNV) == 0)
			return p;
		p = p->link;
	}
	return p;
}

// Sau khi tìm thấy nhân viên bằng mã nhân viên thì sẽ xuất thông tin nhân viên đó ra
void xuatMotNhanVien(NHANVIEN nv) {
	string gioiTinh, chucVu;
	// Kiểm tra nếu giới tính là 1 thì định dạng xuất ra sẽ là Nam, ngược lại thì là Nữ
	if (nv.gioiTinh == 1)
		gioiTinh = "Nam";
	else
		gioiTinh = "Nu";
	//
	if (nv.chucVu == 1) // Kiểm tra nếu chức vụ là 1 thì định dạng xuất ra sẽ là Nhan vien
		chucVu = "Nhan vien";
	else if (nv.chucVu == 2) // 2 thì định dạng xuất ra sẽ là Pho phong
		chucVu = "Pho phong";
	else if (nv.chucVu == 3) // 3 thì định dạng xuất ra sẽ là Truong phong
		chucVu = "Truong phong";
	else if (nv.chucVu == 4) // 4 thì định dạng xuất ra sẽ là Pho giam doc
		chucVu = "Pho giam doc";
	else
		chucVu = "Giam doc"; // 5 thì định dạng xuất ra sẽ là Giam doc
	//
	cout << setw(10) << left << "Ma"
		<< "\t";
	cout << setw(30) << left << "Ten"
		<< "\t";
	cout << setw(15) << left << "Gioi tinh"
		<< "\t";
	cout << setw(15) << left << "Nam sinh"
		<< "\t";
	cout << setw(15) << left << "Chuc vu"
		<< "\t";
	cout << setw(30) << left << "Luong"
		<< "\t\n";
	//
	cout << setw(10) << left << nv.maNV << "\t";
	cout << setw(30) << left << nv.tenNV << "\t";
	cout << setw(15) << left << gioiTinh << "\t";
	cout << setw(15) << left << nv.namSinh << "\t";
	cout << setw(15) << left << chucVu << "\t";
	cout << setw(30) << left << nv.luong << "\t\n";
}

// Câu 5
Nodeptr timNhanVienNuDauTien(Nodeptr list) {
	Nodeptr p = list;
	while (p != NULL) {
		// Kiểm tra từ đầu danh sách nếu gặp nhân viên có giới tính là nữ thì sẽ trả về nhân viên đó luôn
		if (p->data.gioiTinh == 0)
			return p;
		p = p->link;
	}
	// Nếu không có thì trả về NULL
	return NULL;
}

Nodeptr timNhanVienNuCoSoTuoiLonNhat(Nodeptr list) {
	Nodeptr nhanVienNuDauTien = timNhanVienNuDauTien(list);
	// Nếu tìm thấy nhân viên nữ đầu tiên thì tiếp tục, không thì trả về NULL
	if (nhanVienNuDauTien != NULL) {
		// Gán cho max là nhân viên nữ đầu tiên
		Nodeptr max = nhanVienNuDauTien;
		Nodeptr p = list;
		while (p != NULL) {
			// Nếu nhân viên có giới tính là nữ và năm sinh < năm sinh của nhân viên nữ đầu tiên thì gán cho max = nhân viên đó.
			// Vì số năm càng lớn thì tuổi càng nhỏ nên sẽ gán cho max = nhân viên đó
			if (p->data.gioiTinh == 0 && p->data.namSinh < max->data.namSinh)
				max = p;
			p = p->link;
		}
		// Sau khi duyệt hết danh sách thì trả về nhân viên có số tuổi lớn nhất đó
		return max;
	}
	// Nếu không tìm thấy thì trả về NULL
	return NULL;
}

Nodeptr timNhanVienNuCoSoTuoiNhoNhat(Nodeptr list) {
	Nodeptr nhanVienNuDauTien = timNhanVienNuDauTien(list);
	// Nếu tìm thấy nhân viên nữ đầu tiên thì tiếp tục, không thì trả về NULL
	if (nhanVienNuDauTien != NULL) {
		// Gán cho min là nhân viên nữ đầu tiên
		Nodeptr min = nhanVienNuDauTien;
		Nodeptr p = list;
		while (p != NULL) {
			// Nếu nhân viên có giới tính là nữ và năm sinh > năm sinh của nhân viên nữ đầu tiên thì gán cho min = nhân viên đó.
			// Vì số năm càng lớn thì tuổi càng nhỏ nên sẽ gán cho min = nhân viên đó
			if (p->data.gioiTinh == 0 && p->data.namSinh > min->data.namSinh)
				min = p;
			p = p->link;
		}
		// Sau khi duyệt hết danh sách thì trả về nhân viên có số tuổi bé nhất đó
		return min;
	}
	return NULL;
}

// Câu 6
Nodeptr timNhanVienNamDauTien(Nodeptr list) {
	Nodeptr p = list;
	while (p != NULL) {
		// Kiểm tra từ đầu danh sách nếu gặp nhân viên có giới tính là nữ thì sẽ trả về nhân viên đó luôn
		if (p->data.gioiTinh == 1)
			return p;
		p = p->link;
	}
	// Nếu không có thì trả về NULL
	return NULL;
}

Nodeptr timNhanVienNamCoSoTuoiLonNhat(Nodeptr list) {
	Nodeptr nhanVienNamDauTien = timNhanVienNamDauTien(list);
	// Nếu tìm thấy nhân viên nam đầu tiên thì tiếp tục, không thì trả về NULL
	if (nhanVienNamDauTien != NULL) {
		// Gán cho max là nhân viên nam đầu tiên
		Nodeptr max = nhanVienNamDauTien;
		Nodeptr p = list;
		while (p != NULL) {
			// Nếu nhân viên có giới tính là nam và năm sinh < năm sinh của nhân viên nam đầu tiên thì gán cho max = nhân viên đó.
			// Vì số năm càng lớn thì tuổi càng nhỏ nên sẽ gán cho max = nhân viên đó
			if (p->data.gioiTinh == 1 && p->data.namSinh < max->data.namSinh)
				max = p;
			p = p->link;
		}
		// Sau khi duyệt hết danh sách thì trả về nhân viên có số tuổi lớn nhất đó
		return max;
	}
	// Nếu không có thì trả về NULL
	return NULL;
}

Nodeptr timNhanVienNamCoSoTuoiNhoNhat(Nodeptr list) {
	Nodeptr nhanVienNamDauTien = timNhanVienNamDauTien(list);
	// Nếu tìm thấy nhân viên nam đầu tiên thì tiếp tục, không thì trả về NULL
	if (nhanVienNamDauTien != NULL) {
		// Gán cho min là nhân viên nam đầu tiên
		Nodeptr min = nhanVienNamDauTien;
		Nodeptr p = list;
		while (p != NULL) {
			// Nếu nhân viên có giới tính là nam và năm sinh > năm sinh của nhân viên nam đầu tiên thì gán cho min = nhân viên đó.
			// Vì số năm càng lớn thì tuổi càng nhỏ nên sẽ gán cho min = nhân viên đó
			if (p->data.gioiTinh == 1 && p->data.namSinh > min->data.namSinh)
				min = p;
			p = p->link;
		}
		// Sau khi duyệt hết danh sách thì trả về nhân viên có số tuổi bé nhất đó
		return min;
	}
	// Nếu không có thì trả về NULL
	return NULL;
}

// Câu 7
void xuatFileKetQuaThongKeSoLuongNhanVienTheoDoTuoi(Nodeptr list) {
	int namHienTai;
	layThoiGianHeThong(namHienTai); // lấy số năm hiện tại và gán vào biến namHienTai
	Nodeptr p = list;
	// Đặt tên file là ThongKeSoLuongNhanVienTheoDoTuoi.txt
	string fileName = "ThongKeSoLuongNhanVienTheoDoTuoi.txt";
	// Chế độ ghi file
	ofstream fileOut(fileName);
	// Khởi tạo 3 biến lưu trữ số lượng nhân viên dưới 30, từ 30 đến 40 và trên 40 tuổi
	int duoi_30 = 0, tu_30_den_40 = 0, tren_40 = 0;
	//
	// Kiểm tra từ đầu đến cuối danh sách
	while (p != NULL) {
		// Tính số tuổi = năm hiện tại - năm sinh của người đó
		int soTuoi = namHienTai - p->data.namSinh;
		// Nếu số tuổi < 30 thì tăng số lượng biến duoi_30 lên 1 đơn vị
		if (soTuoi < 30)
			duoi_30++;
		else if (soTuoi >= 30 && soTuoi <= 40) // Nếu số tuổi >= 30 và <= 40 thì tăng số lượng biến tu_30_den_40 lên 1 đơn vị
			tu_30_den_40++;
		else if (soTuoi > 40) // Nếu số tuổi > 40 thì tăng số lượng biến tren_40 lên 1 đơn vị
			tren_40++;
		// Duyệt sang Node tiếp theo
		p = p->link;
	}
	// Ghi ra file
	fileOut << "So luong nhan vien duoi 30 tuoi: " << duoi_30;
	fileOut << "\nSo luong nhan vien tu 30 den 40 tuoi: " << tu_30_den_40;
	fileOut << "\nSo luong nhan vien tren 40 tuoi: " << tren_40;
	// Đóng file
	fileOut.close();
}

// Hàm lấy thời gian hệ thống để lấy số năm hiện tại là bao nhiêu
void layThoiGianHeThong(int& nam) {
	// Thời gian hiện tại tính theo hệ thống
	time_t baygio = time(0);
	// Chuyển đổi sang cấu trúc tm struct
	tm* ltm = localtime(&baygio);
	// Ở đây chỉ cần lấy năm nên mình chỉ lấy số năm hiện tại ra để tính thôi
	nam = 1900 + ltm->tm_year;
}

// Câu 8
void xuatFileKetQuaThongKeSoLuongNhanVienTheoGioiTinh(Nodeptr list) {
	Nodeptr p = list;
	// Đặt tên file là ThongKeSoLuongNhanVienTheoGioiTinh.txt
	string fileName = "ThongKeSoLuongNhanVienTheoGioiTinh.txt";
	// Chế độ ghi file
	ofstream fileOut(fileName);
	// Khởi tạo 2 biến số lượng nhân viên nam ban đầu là 0 và số lượng nhân viên nữ ban đầu là 0
	int soLuongNam = 0, soLuongNu = 0;
	// Duyệt từ đầu đến cuối danh sách
	while (p != NULL) {
		if (p->data.gioiTinh == 1) // Nếu giới tính == 1 thì tăng số lượng nhân viên nam lên 1 đơn vị
			soLuongNam++;
		else // Nếu giới tính == 2 thì tăng số lượng nhân viên nữ lên 1 đơn vị
			soLuongNu++;
		// Duyệt sang Node tiếp theo
		p = p->link;
	}
	// Ghi file
	fileOut << "So luong nhan vien nam: " << soLuongNam;
	fileOut << "\nSo luong nhan vien nu: " << soLuongNu;
	// Đóng file
	fileOut.close();
}

// Câu 9
void inDanhSachNhanVienCoChucVuTu_2_Den_5(Nodeptr list) {
	// Nếu danh sách == NULL thì xuất thông báo danh sách trống. Không thì tiếp tục
	if (list == NULL)
		cout << "\n\t(!) Danh sach nhan vien trong\n";
	else {
		cout << setw(10) << left << "Ma"
			<< "\t";
		cout << setw(30) << left << "Ten"
			<< "\t";
		cout << setw(15) << left << "Gioi tinh"
			<< "\t";
		cout << setw(15) << left << "Nam sinh"
			<< "\t";
		cout << setw(15) << left << "Chuc vu"
			<< "\t";
		cout << setw(30) << left << "Luong"
			<< "\t\n";

		// Duyệt từ đầu đến cuối danh sách
		while (list != NULL) {
			string gioiTinh, chucVu;
			// Kiểm tra nếu giới tính là 1 thì định dạng xuất ra sẽ là Nam, ngược lại thì là Nữ
			if (list->data.gioiTinh == 1)
				gioiTinh = "Nam";
			else
				gioiTinh = "Nu";
			//
			if (list->data.chucVu == 1) // Kiểm tra nếu chức vụ là 1 thì định dạng xuất ra sẽ là Nhan vien
				chucVu = "Nhan vien";
			else if (list->data.chucVu == 2) // 2 thì định dạng xuất ra sẽ là Pho phong
				chucVu = "Pho phong";
			else if (list->data.chucVu == 3) // 3 thì định dạng xuất ra sẽ là Truong phong
				chucVu = "Truong phong";
			else if (list->data.chucVu == 4) // 4 thì định dạng xuất ra sẽ là Pho giam doc
				chucVu = "Pho giam doc";
			else
				chucVu = "Giam doc"; // 5 thì định dạng xuất ra sẽ là Giam do
			//
			// Kiểm tra nếu chức vụ > 1 thì mới xuất thông tin nhân viên đó ra
			if (list->data.chucVu > 1) {
				cout << setw(10) << left << list->data.maNV << "\t";
				cout << setw(30) << left << list->data.tenNV << "\t";
				cout << setw(15) << left << gioiTinh << "\t";
				cout << setw(15) << left << list->data.namSinh << "\t";
				cout << setw(15) << left << chucVu << "\t";
				cout << setw(30) << left << list->data.luong << "\t\n";
			}
			// Trỏ sang Node tiếp theo
			list = list->link;
		}
	}
}

// Câu 10
void sapXepDanhSachTangDanTheoNamSinh(Nodeptr& list) {
	// Duyệt 2 vòng for
	// Vòng for đầu tiên là từ đầu đến cuối danh sách
	// Vòng for thứ hai là từ phần từ phần tử thứ 2 trở đi
	// Kiểm tra nếu pTam > pTam2 thì hoán vị 2 nhân viên đó
	if (list != NULL) {
		for (Nodeptr pTam = list; pTam != NULL; pTam = pTam->link) {
			for (Nodeptr pTam2 = pTam->link; pTam2 != NULL; pTam2 = pTam2->link) {
				if (pTam->data.namSinh > pTam2->data.namSinh) {
					NHANVIEN tam = pTam->data;
					pTam->data = pTam2->data;
					pTam2->data = tam;
				}
			}
		}
		cout << "\n\t(!) Sap xep thanh cong\n";
		xuatDanhSachNhanVien(list);
	} else
		cout << "\n\t(!) Danh sach nhan vien trong\n";
}