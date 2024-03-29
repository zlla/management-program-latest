#include<cstdio>
#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Sinhvien{
    int id;
    char ten[30];
    std::string gt;
    int tuoi;
    float dT, dL, dA;
    float dtb;
};

typedef Sinhvien SV;

int layso_int(std::string prompt){
    int x;
    std::cout<< prompt;
    std::cin>> x;
    while (cin.fail()) {
        std::cout<< "\n-- -- -- -- --\n";
        std::cout<< "* Nhap Sai * \nVui long nhap lai mot chu so !!!\n";
        std::cout<< "-- -- -- -- --";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<< endl << prompt;
        std::cin>> x;
        std::cout<< endl;
    }
    return x;
}

float layso_float(std::string prompt){
    float x;
    std::cout<< prompt;
    std::cin>> x;
    while (cin.fail()) {
        std::cout<< "\n-- -- -- -- --\n";
        std::cout<< "* Nhap Sai * \nVui long nhap lai mot chu so !!!\n";
        std::cout<< "-- -- -- -- --";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<< endl << prompt;
        std::cin>> x;
        std::cout<< endl;
    }
    return x;
}

int lay_int_trongkhoang(int max, int min, std::string prompt) {
    int socantim;
    socantim = layso_int(prompt);
    while (socantim < min || socantim > max) {
        std::cout<< "\n-- -- -- -- --\n* Nhap sai *\nVui long nhap lai so trong khoang(" << min << " - " << max << "):\n-- -- -- -- --\n";
        getchar();
        socantim = layso_int(prompt);
    }
    return socantim;
}

float lay_float_trongkhoang(int max, int min, std::string prompt) {
    float socantim;
    socantim = layso_float(prompt);
    while (socantim < min || socantim > max) {
        std::cout<< "\n-- -- -- -- --\n* Nhap sai *\nVui long nhap lai so trong khoang(" << min << " - " << max << "):\n-- -- -- -- --\n";
        getchar();
        socantim = layso_float(prompt);
    }
    return socantim;
}

void laygioitinh(SV &sv) {
    int chon;
    std::cout<< "Gioi tinh: \n";
    std::cout<< "Nam - chon so 1" << std:: endl;
    std::cout<< "Nu  - chon so 2" << std:: endl;
    std::cout<< "+----------------------------------------------------------+\n";
    std::cout<< "| Thang viet chuong trinh nay rat ki thi gioi tinh thu 3.  |\n";
    std::cout<< "| Nen khong co dau, dung nhap thu mat cong, cam_on^^       |\n";
    std::cout<< "+----------------------------------------------------------+\n";
    chon = lay_int_trongkhoang(2, 1, "Nhap lua chon cua ban: ");
    if (chon == 1) {
        sv.gt = "nam";
    }
    else if (chon == 2) {
        sv.gt = "nu";
    }
}

void tinhDTB(SV &sv){
    sv.dtb = (sv.dT + sv.dL + sv.dA) / 3;
}

void nhapttSV(SV &sv, int i){
    sv.id = i + 1;
    std::cout<< "Nhap ten: "; std::cin.getline(sv.ten, 30);
    laygioitinh(sv);
    sv.tuoi = lay_int_trongkhoang(40, 16, "Nhap tuoi: ");
    std::cout<< "Nhap diem 3 mon Toan - Ly - Anh\n";
    sv.dT = lay_float_trongkhoang(10, 1, "Toan: ");
    sv.dL = lay_float_trongkhoang(10, 1, "Ly: ");
    sv.dA = lay_float_trongkhoang(10, 1, "Anh: ");
    tinhDTB(sv);
    getchar();
};

void nhapNttSV(SV a[] ,int n){
    for(int i = 0; i < n; i++){
        std::cout<< "\nNhap sinh vien thu: " << i+1 << std::endl;
        nhapttSV(a[i], i); } }

void inttSV(SV &sv){
    std::cout<< "|" << setw(3) << sv.id << setw(3) << "|";
    std::cout<< setw(20) << sv.ten << setw(5) << "|";
    std::cout<< setw(10) << sv.gt << setw(2) << "|";
    std::cout<< setw(6) << sv.tuoi << setw(3) << "|";
    std::cout<< setw(5) << sv.dT << setw(3) << "|" << setw(5) << sv.dL << setw(3) << "|" << setw(5) << sv.dA << setw(3) << "|";
    std::cout<< setw(10) << setprecision(1)<< fixed << sv.dtb << setw(3) << "|" << std:: endl;
}

void inNttSV(SV a[], int n){
    std::cout<< "\n+-----+------------------------+-----------+--------+-------+-------+-------+------------+\n";
    std::cout<< "|" << setw(3) << "ID" << setw(3) << "|" << setw(20) << "Ho Ten     " << setw(5) << "|";
    std::cout<< setw(10) << "Gioi tinh" << setw(2) << "|" << setw(6) << " Tuoi" << setw(3) << "|";
    std::cout<< setw(5) << "Toan" << setw(3) << "|" << setw(5) << "Ly" << setw(3) << "|";
    std::cout<< setw(5) << "Anh" << setw(3) << "|" << setw(10) << "DTB  " << setw(3) << "|";
    std::cout<< "\n+-----+------------------------+-----------+--------+-------+-------+-------+------------+\n";
    for (int i = 0; i < n; i++) {
        inttSV(a[i]);
    }
    std::cout<< "+-----+------------------------+-----------+--------+-------+-------+-------+------------+\n";
}

void sapxepTheoDTBtangdan(SV a[], int n){
    SV max;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(a[i].dtb > a[j].dtb){
                max = a[i];
                a[i] = a[j];
                a[j] = max;
            }
        }
    }
}

void sapxepTheoDTBgiamdan(SV a[], int n){
    SV min;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(a[i].dtb < a[j].dtb){
                min = a[i];
                a[i] = a[j];
                a[j] = min;
            }
        }
    }
}

void sapxepTheoTen(SV a[], int n) {
    SV bien_luu_tru;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(strcmp(a[i].ten, a[j].ten) > 0) {
                bien_luu_tru = a[i];
                a[i] = a[j];
                a[j] = bien_luu_tru;
            }
        }
    }
}

void xeploai(SV &sv){
    if (sv.dtb >= 8) {
        std::cout << std::setw(10) << "Gioi" << " || ";
    }
    else if (sv.dtb >= 6.5) {
        std::cout << std::setw(10) << "Kha" << " || ";
    }
    else {
        std::cout << std::setw(10) << "Trung binh" << " || ";
    }
}

void xeploaiN(SV a[], int n){
    std::cout<< "\n++-----------------------------------------------------------------------++";
    for (int i = 0; i < n; i++) {
        std::cout<< std::endl << "|| Sinh vien: " << std::setw(25) << a[i].ten << std::setw(5) << " || id: " << a[i].id << std::setw(5) << " || xep loai: ";
        xeploai(a[i]);
    std::cout<< "\n++-----------------------------------------------------------------------++";
    }
}

void xuatFile(SV a[], int n, char Filename[]) {
    ofstream FileOut;
    FileOut.open(Filename, ios_base::out);
    FileOut << std::setw(5) << "ID" << std::setw(25) <<"Ho Ten" << std::setw(10) << "GT" << std::setw(10) << "Tuoi" << std::setw(10) << "DT" << std::setw(10) << "DL" << std::setw(10) << "DA" << std::setw(10) << "DTB" <<"\n";
    for (int i = 0; i < n; i++) {
        FileOut << std::setw(5) << a[i].id << std::setw(25) << a[i].ten << std::setw(10) << a[i].gt << std::setw(10) << a[i].tuoi << std::setw(10) << a[i].dT << std::setw(10) << a[i].dL << std::setw(10) << a[i].dA << std::setw(10) << a[i].dtb <<"\n";
    }
    FileOut.close();
}

int xoatheoID(SV a[], int n, int id, int xoa[],int biendem) {
    int found = 0;
    for (int i = 0; i < n ; i++) {
        if (a[i].id == id) {
            found = 1;
            xoa[biendem] = a[i].id;
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            std::cout<< "Da xoa sinh vien co ID: " << id;
            break;
        }
    };

    if (found==0) {
        return 0;
    }
    else {
        return 1;
    }
}

void capnhatTTSV(SV &sv) {
    int chon;
    std::cout<< "\n-- -- -- -- --\n";
    while(true) {
        std::cout<< "Thong tin ban muon cap nhat: \n";
        std::cout<< "1. Ten \n";
        std::cout<< "2. Gioi tinh \n";
        std::cout<< "3. Tuoi \n";
        std::cout<< "0. Quay lai\n\n";
        chon = layso_int("Vui long nhap lua chon cua ban (1-3): ");
        getchar();
        switch(chon) {
            case 1:
                std::cout<< "\n-- -- -- -- --\n";
                std::cout<< "Ten sinh vien luc dau: " << sv.ten;
                std::cout<< "\nNhap ten muon thay doi: ";
                std::cin.getline(sv.ten, 30);
                std::cout<< "Cap nhat TTSV thanh cong!!!";
                getchar();
                return;
            case 2:
                std::cout<< "\n-- -- -- -- --\n";
                std::cout<< "Gioi tinh SV luc dau" << sv.ten << " la: " << sv.gt << endl;
                laygioitinh(sv);
                std::cout<< "Cap nhat TTSV thanh cong!!!";
                getchar();
                return;
            case 3:
                std::cout<< "\n-- -- -- -- --\n";
                std::cout<< "Tuoi luc dau: " << sv.tuoi;
                sv.tuoi = lay_int_trongkhoang(40, 16, "\nNhap tuoi muon thay doi: ");
                std::cout<< "Cap nhat TTSV thanh cong!!!";
                getchar();
                return;
            case 0:
                std::cout<< "Ban da chon quay lai.";
                return;
            default:
                std::cout<< "\nKhong co chuc nang nay, hay thu lai!!";
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
        }
    }
}

void timkiemTheoTen(SV a[], char ten[], int n) {
    SV dsTimKiem[1000];
    char tenSV[30];
    int found = 0;
    for (int i = 0; i < n ; i++) {
        strcpy(tenSV, a[i].ten);
        if (strstr(strdup(tenSV), strdup(ten))) { //strstr la ham tim kiem
            dsTimKiem[found] = a[i];
            found++; 
        }
    }
    if (found == 0) {
        std::cout<< "\nKhong ton tai SV da nhap trong he thong\n";
    }
    else
        inNttSV(dsTimKiem, found);
}

int main() {
    int key;
    int n;
    char Filename[] = "list_data.txt";
    bool daNhap = false;
    int xoa[1000];
    int biendem = 0;
    SV a[1000];

    while(true){
        std::cout<< "+--------------------------------------+\n";
        std::cout<< "| >> CHUONG TRINH QUAN LY SINH VIEN << |\n";
        std::cout<< "+--------------------------------------+\n";
        std::cout<< "|     1.  Nhap du lieu                 |\n";
        std::cout<< "|     2.  Hien thi DS sinh vien        |\n";
        std::cout<< "|     3.  Sap xep sinh vien            |\n";
        std::cout<< "|     4.  Xep loai sinh vien           |\n";
        std::cout<< "|     5.  Cap nhat TTSV theo ID        |\n";
        std::cout<< "|     6.  Tim kiem SV theo ten         |\n";
        std::cout<< "|     7.  Them sinh vien vao ds        |\n";
        std::cout<< "|     8.  Xoa SV theo ID               |\n";
        std::cout<< "|     9.  Xuat DS sinh vien            |\n";
        std::cout<< "|     0.  Thoat chuong trinh           |\n";
        std::cout<< "+--------------------------------------+\n";
        std::cout<< "<-------------------------------------->\n";
        key = layso_int(">>>      Nhap lua chon cua ban      <<<\n");
        std::cout<< "-- -- -- -- --";
        getchar();

        switch(key){
            case 1:
                std::cout<< "\nBan da chon nhap danh sach SV: ";
                std::cout<< "\n<---------------->\n";
                n = layso_int("Nhap so luong SV: ");
                std::cout<< "<---------------->\n\n";
                getchar();
                nhapNttSV(a, n);
                std::cout<< "\nNhap du lieu thanh cong!!!";
                daNhap = true;
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 2:
                if(daNhap && n!=0){
                    std::cout<< "\nBan da chon in danh sach SV: ";
                    inNttSV(a, n);}
                else {
                    std::cout<< "\nVui long nhap danh sach SV truoc!";
                }
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 3:
                if (daNhap && n!=0) {
                    std::cout<< "\nBan da chon sap xep danh sach: \n";
                    std::cout<< "Chon kieu sap xep: \n";
                    std::cout<< "1. Sap xep theo DTB tang dan\n";
                    std::cout<< "2. Sap xep theo DTB giam dan\n";
                    std::cout<< "3. Sap xep theo Ten\n";
                    int choice = lay_int_trongkhoang(3, 1, "\nLua chon cua ban: ");
                    getchar();
                    if (choice == 1) {
                        std::cout<< "\nBan da chon sap xep danh sach SV theo DTB tang dan: ";
                        sapxepTheoDTBtangdan(a, n);
                        inNttSV(a, n);
                    }
                    else if(choice == 2) {
                        std::cout<< "\nBan da chon sap xep danh sach SV theo DTB giam dan: ";
                        sapxepTheoDTBgiamdan(a, n);
                        inNttSV(a, n);
                    }
                    else if(choice == 3) {
                        std::cout<< "\nBan da chon sap xep danh sach SV theo Ten: ";
                        sapxepTheoTen(a, n);
                        inNttSV(a, n);
                    }
                }
                else {
                    std::cout<< "\nVui long nhap danh sach SV truoc!";
                }
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 4:
                if (daNhap && n!=0) {
                    std::cout<< "\nBan da chon xep loai SV: ";
                    xeploaiN(a, n);
                }
                else {
                    std::cout<< "\nVui long nhap danh sach SV truoc!";
                }
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 5:
                if (daNhap && n!=0) {
                    int chon;
                    int maxDS, minDS;

                    std::cout<< "\nBan da chon cap nhat TTSV: \n";
                    std::cout<< "-- -- -- -- --\n";
                    for (int i = 0; i < n; i++) {
                        std::cout<< "SV: " << std::setw(20) << a[i].ten << std::setw(5) << "  ||  " << "ID: " << a[i].id << std:: endl;
                    }
                    std::cout<< "-- -- -- -- --\n";

                    minDS = maxDS = a[0].id;
                    for (int i = 1; i < n; i++) {
                        if(maxDS < a[i].id) {
                            maxDS = a[i].id;
                        }
                    }
                    for (int i = 1; i < n; i++) {
                        if(minDS > a[i].id) {
                            minDS = a[i].id;
                        }
                    }
                    
                    chon = layso_int("Nhap ID sinh vien muon chinh sua: ");
                    while (chon > maxDS || chon < minDS) {
                        std::cout<< "-- -- -- -- --\nID khong ton tai hoac co the da bi xoa\nVui long nhap lai!\n-- -- -- -- --\n";
                        getchar();
                        chon = layso_int("Nhap ID sinh vien muon chinh sua: ");
                    }
                    for (int i = 0; i < biendem; i++) {
                        while (chon > maxDS || chon < minDS || chon == xoa[i]) {
                            std::cout<< "-- -- -- -- --\nID khong ton tai hoac co the da bi xoa\nVui long nhap lai!\n-- -- -- --\n";
                            getchar();
                            chon = layso_int("Nhap ID sinh vien muon chinh sua: ");
                        }
                    }
                    getchar();

                    for (int i = 0; i < n; i++) {
                        if (a[i].id == chon) {
                            capnhatTTSV(a[i]);
                            break;
                        }
                    }
                }
                else {
                    std::cout<< "\nVui long nhap danh sach SV truoc!";
                }
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 6:
                if (daNhap && n!=0) {
                    std::cout<< "\nBan da chon tim kiem sinh vien theo ten: \n";
                    char strTen[30];
                    std::cout<< "Nhap ten de tim kiem: ";
                    cin.getline(strTen, 30);
                    timkiemTheoTen(a, strTen, n);
                }
                else {
                    std::cout<< "\nVui long nhap danh sach SV truoc!";
                }
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 7:
                if (daNhap) {
                    if (n == 0) {
                        for (int i = 0; i < biendem; i++) {
                            xoa[i] = 0;
                    }

                    }
                    std::cout<< "\nBan da chon them sinh vien: \n";
                    std::cout<< "Nhap thong tin sinh vien can them\n";
                    int maxID = a[0].id;
                    for (int i = 0; i < n; i++) {
                        if (a[i].id >  maxID) {
                            maxID = a[i].id;
                        }
                    }
                    n++;
                    nhapttSV(a[n-1], maxID);
                    std::cout<< "\nThem SV thanh cong!!!";
                }
                else {
                    std::cout<< "\nVui long nhap danh sach SV truoc!";
                }
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 8:
                if (daNhap && n!=0) {
                    int id;
                    std::cout<< "\nBan da chon xoa SV theo ID: \n";
                    for (int i = 0; i < n; i++) {
                        std::cout<< "SV: " << a[i].ten << "  --  " << "ID: " << a[i].id << std:: endl;
                    }
                    id = layso_int("Nhap ID cua SV can xoa: ");
                    getchar();
                    if (xoatheoID(a, n , id, xoa, biendem) == 0) {
                        std::cout<< "Xoa SV that bai(ID khong ton tai)!!!";
                        getchar();
                        break;
                    }
                    else {
                        biendem++;
                        n--;
                    }
                }
                else {
                    std::cout<< "\nVui long nhap danh sach SV truoc!";
                }
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 9:
                if (daNhap && n!=0) {
                    std::cout<< "\nBan da chon xuat danh sach SV ra file txt: ";
                    xuatFile(a, n, Filename);
                    std::cout<< "\nXuat DSSV thanh cong!!!";
                }
                else {
                    std::cout<< "\nVui long nhap danh sach SV truoc!";
                }
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
            case 0:
                std::cout<< "\nBan da chon thoat chuong trinh!!!";
                std::cout<< "\n❤ Cam on ban da su dung ❤";
                getchar();
                return 0;
            default:
                std::cout<< "\nKhong co chuc nang nay, hay thu lai!!";
                std::cout<< "\nBam phim bat ki de tiep tuc.\n";
                getchar();
                break;
        }
    }

    return 0;
}
