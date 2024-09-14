#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct SinhVien {
    int MSV;
    string ten;
    string gioiTinh;
    int tuoi;
    float diemTin, diemTA, diemTriet;
    float diemTB;
    string hocLuc;

    
    void tinhDiemTB() {
        diemTB = (diemTin + diemTA + diemTriet) / 3.0;
    }

    
    void xepLoaiHocLuc() {
        if (diemTB >= 8) hocLuc = "Gioi";
        else if (diemTB >= 6.5) hocLuc = "Kha";
        else if (diemTB >= 5) hocLuc = "Trung Binh";
        else hocLuc = "Yeu";
    }
};


vector<SinhVien> danhSach;


void themSinhVien() {
    SinhVien sv;
    sv.MSV = danhSach.size() + 1; 
    cout << "Nhap ten: "; cin >> sv.ten;
    cout << "Nhap gioi tinh: "; cin >> sv.gioiTinh;
    cout << "Nhap tuoi: "; cin >> sv.tuoi;
    cout << "Nhap diem Tin: "; cin >> sv.diemTin;
    cout << "Nhap diem TA: "; cin >> sv.diemTA;
    cout << "Nhap diem Triet: "; cin >> sv.diemTriet;
    sv.tinhDiemTB();
    sv.xepLoaiHocLuc();
    danhSach.push_back(sv);
}


void capNhatSinhVien(int msv) {
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i].MSV == msv) {
            cout << "Nhap ten moi: "; cin >> danhSach[i].ten;
            cout << "Nhap gioi tinh moi: "; cin >> danhSach[i].gioiTinh;
            cout << "Nhap tuoi moi: "; cin >> danhSach[i].tuoi;
            cout << "Nhap diem Tin moi: "; cin >> danhSach[i].diemTin;
            cout << "Nhap diem TA moi: "; cin >> danhSach[i].diemTA;
            cout << "Nhap diem Triet moi: "; cin >> danhSach[i].diemTriet;
            danhSach[i].tinhDiemTB();
            danhSach[i].xepLoaiHocLuc();
            cout << "Cap nhat thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi MSV: " << msv << endl;
}


void xoaSinhVien(int msv) {
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i].MSV == msv) {
            danhSach.erase(danhSach.begin() + i);
            cout << "Da xoa sinh vien voi MSV: " << msv << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi MSV: " << msv << endl;
}


void timSinhVienTheoTen(string ten) {
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i].ten == ten) {
            cout << "Tim thay sinh vien: MSV: " << danhSach[i].MSV 
                 << ", Ten: " << danhSach[i].ten 
                 << ", DiemTB: " << danhSach[i].diemTB 
                 << ", Hoc luc: " << danhSach[i].hocLuc << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi ten: " << ten << endl;
}


bool soSanhDiemTB(SinhVien a, SinhVien b) {
    return a.diemTB > b.diemTB;
}


bool soSanhTen(SinhVien a, SinhVien b) {
    return a.ten < b.ten;
}


void sapXepTheoDiemTB() {
    sort(danhSach.begin(), danhSach.end(), soSanhDiemTB);
}


void sapXepTheoTen() {
    sort(danhSach.begin(), danhSach.end(), soSanhTen);
}


void hienThiSinhVien() {
    for (int i = 0; i < danhSach.size(); i++) {
        cout << "MSV: " << danhSach[i].MSV 
             << ", Ten: " << danhSach[i].ten 
             << ", Gioi tinh: " << danhSach[i].gioiTinh 
             << ", Tuoi: " << danhSach[i].tuoi 
             << ", DiemTB: " << danhSach[i].diemTB 
             << ", Hoc luc: " << danhSach[i].hocLuc << endl;
    }
}


void luuDanhSachSinhVien() {
    ofstream file("sinhvien.txt");
    for (int i = 0; i < danhSach.size(); i++) {
        file << danhSach[i].MSV << " " 
             << danhSach[i].ten << " " 
             << danhSach[i].gioiTinh << " " 
             << danhSach[i].tuoi << " " 
             << danhSach[i].diemTin << " " 
             << danhSach[i].diemTA << " " 
             << danhSach[i].diemTriet << " " 
             << danhSach[i].diemTB << " " 
             << danhSach[i].hocLuc << endl;
    }
    file.close();
    cout << "Da luu danh sach sinh vien vao file sinhvien.txt\n";
}


void docDanhSachSinhVien() {
    ifstream file("sinhvien.txt");
    SinhVien sv;
    while (file >> sv.MSV >> sv.ten >> sv.gioiTinh >> sv.tuoi >> sv.diemTin >> sv.diemTA >> sv.diemTriet >> sv.diemTB >> sv.hocLuc) {
        danhSach.push_back(sv);
    }
    file.close();
}


int main() {
    int chon, msv;
    string ten;
    docDanhSachSinhVien(); 

    do {
        cout << "================== MENU ==================\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Cap nhat thong tin sinh vien theo MSV\n";
        cout << "3. Xoa sinh vien theo MSV\n";
        cout << "4. Tim kiem sinh vien theo ten\n";
        cout << "5. Sap xep sinh vien theo diem trung binh\n";
        cout << "6. Sap xep sinh vien theo ten\n";
        cout << "7. Luu danh sach sinh vien vao file\n";
        cout << "8. Hien thi danh sach sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
            case 1:
                themSinhVien();
                break;
            case 2:
                cout << "Nhap MSV: "; cin >> msv;
                capNhatSinhVien(msv);
                break;
            case 3:
                cout << "Nhap MSV: "; cin >> msv;
                xoaSinhVien(msv);
                break;
            case 4:
                cout << "Nhap ten: "; cin >> ten;
                timSinhVienTheoTen(ten);
                break;
            case 5:
                sapXepTheoDiemTB();
                hienThiSinhVien();
                break;
            case 6:
                sapXepTheoTen();
                hienThiSinhVien();
                break;
            case 7:
                luuDanhSachSinhVien();
                break;
            case 8:
                hienThiSinhVien();
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (chon != 0);

    return 0;
}

