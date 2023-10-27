#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

//============khai bao dulieu=========
struct Sach
{
	string maTk;
	string tenTk;
	string theLoai;
	string fullname;
	string tongSoMuon;
};

struct user
{
	string acc;
	string pass;
};

user ad, cus, sign;
string pq;
bool quyen[5] = {false};

void Login();
void PhanQuyen();
void nhapSach(Sach &sach);
void nhapDanhSach(vector<Sach> &danhsach);
void xoaSach(vector<Sach> &danhsach);
void suaTenSach(vector<Sach> &danhsach);
void ghiFile(vector<Sach> &danhsach, int soluong);
void pressAnyKey();
int numlines();
bool check();
bool daCo();

int main()
{
	Login();
	system("color 2");

	bool daNhap = daCo();
	PhanQuyen();

	vector<Sach> danhsach;
	int soluong, key;
	int flat = 1;
	while (flat)
	{
		system("cls");
		printf("\n 		################### QUAN LY THU VIEN SACH #################");
		printf("\n 		#=========================================================#");
		printf("\n 		###        Lop :64KTPM4   BM CNPM - DH THUY LOI         ###");
		printf("\n 		#=========================================================#");
		printf("\n 		#=========================================================#");
		printf("\n 		#                  1-Them tai khoan moi                   #");
		printf("\n 		#                                                         #");
		printf("\n 		#              2-Cap nhat thong tin tai khoan             #");
		printf("\n 		#                                                         #");
		printf("\n 		#                     3-Xoa tai khoan                     #");
		printf("\n 		#                                                         #");
		printf("\n 		#                  0-Thoat chuong trinh                   #");
		printf("\n 		#=========================================================#");
		printf("\n 		###########################################################");
		printf("\n  Nhap lua chon : ");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			printf("\n   Ban da chon them tai khoan moi!\n");
			nhapDanhSach(danhsach);
			printf("\n   Ban da nhap thanh cong!\n");
			daNhap = true;
			// ghiFile(danhsach);
			// soluong = numlines();
			pressAnyKey();
			break;
		case 2:
			if (!quyen[2])
				cout << "Ban khong duoc dung chuc nang nay";
			else
			{
				if (daNhap)
				{
					printf("\n   Ban da chon cap nhat tai khoan!");
					suaTenSach(danhsach);
				}
				else
				{
					printf("\n   Nhap danh sach sach truoc!!!!");
				}
			}
			pressAnyKey();
			break;
		case 3:
			if (!quyen[2])
				cout << "Ban khong duoc dung chuc nang nay";
			else
			{
				if (daNhap)
				{
					printf("\n   Ban da chon xoa tai khoan!");
					xoaSach(danhsach);
				}
				else
				{
					printf("\n   Nhap danh sach sach truoc!!!!");
				}
			}
			pressAnyKey();
			break;
		case 0:
			printf("\n   Ban da chon thoat chuong trinh!");
			flat = 0;
			false;
		default:
			// printf("\n   Khong co chuc nang nay!");
			// printf("\n   Bam phim bat ky de tiep tuc!");
			printf("\n");
			getch();
			break;
		}
	}
	ghiFile(danhsach, soluong);
	return 0;
}

void Login()
{
	ifstream input("admin.inp");
	input >> ad.acc >> ad.pass >> cus.acc >> cus.pass;
	do
	{
		printf("\n                                              Ten dang nhap:");
		cin >> sign.acc;
		printf("\n                                              Mat khau:");
		cin >> sign.pass;
		if (check())
			printf("\n     Moi ban nhap lai!");
	} while (check());
}

bool check()
{
	if (sign.acc == ad.acc && sign.pass == ad.pass)
	{
		pq = "admin";
		return false;
	}
	else if (sign.acc == cus.acc && sign.pass == cus.pass)
	{
		pq = "cus";
		return false;
	}
	return true;
}

bool daCo()
{
	fstream data;
	char c;
	data.open("sach.in", ios::in);
	data.get(c);
	data.close();
	if (c == '\0')
		return false;
	return true;
}

void PhanQuyen()
{
	if (pq == "admin")
		for (int i = 1; i <= 5; i++, quyen[i] = true);
	else
	{
		quyen[1] = true;
	}
}

int numlines()
{
	fstream data;
	int s(0);
	char c;
	data.open("sach.in", ios::in);
	while (data)
	{
		while (data && c != '\n')
			data.get(c);
		s++;
		data.get(c);
	}
	data.close();
	return s;
}

void nhapSach(Sach &sach)
{
	cin.ignore();
	printf("\n   Nhap ma tai khoan: ");
	getline(cin, sach.maTk);
	printf("\n   Nhap ten tai khoan: ");
	getline(cin, sach.tenTk);
	printf("\n   Nhap the loai: ");
	getline(cin, sach.theLoai);
	printf("\n   Nhap ten day du: ");
	getline(cin, sach.fullname);
	printf("\n   Nhap so luong sach muon: ");
	getline(cin, sach.tongSoMuon);
}
void nhapDanhSach(vector<Sach> &danhsach)
{
	int soluong;
	printf("\n   So luong tai khoan them: ");
	scanf("%d", &soluong);
	danhsach.resize(soluong);
	for (int i = 0; i < soluong; i++)
	{
		cout << "\n   Nhap tai khoan thu " << i + 1 << ": ";
		nhapSach((danhsach[i]));
	}
	// soluong = numlines();
}

void xoaSach(vector<Sach> &danhsach)
{
	string maSach;
	int bienKT = 0, bienLap;
	printf("\n   Xoa tai khoan...");
	printf("\n   Nhap ma tai khoan:");
	cin.ignore();
	getline(cin, maSach);
	for (int i = 0; i < danhsach.size(); i++)
	{
		if (danhsach[i].maTk == maSach)
		{
			danhsach.erase(danhsach.begin() + i);
			cout << "Da xoa xong" << endl;
			bienKT++;
		}
	}
	if (bienKT == 0)
	{
		printf("\n   Ma sach khong ton tai!!!");
	}
}
void suaTenSach(vector<Sach> &danhsach)
{
	int bienKT = 0;
	string maSach;
	printf("\n   CAP NHAT THONG TIN TAI KHOAN ");
	printf("\n   Nhap ma tai khoan can sua :");
	cin.ignore();
	getline(cin, maSach);
	for (int i = 0; i < danhsach.size(); i++)
	{
		if (danhsach[i].maTk == maSach)
		{
			printf("\n   Nhap ten tai khoan: ");
			getline(cin, danhsach[i].tenTk);
			printf("\n   Nhap the loai: ");
			getline(cin, danhsach[i].theLoai);
			printf("\n   Nhap ten day du: ");
			getline(cin, danhsach[i].fullname);
			printf("\n   Nhap so luong sach muon: ");
			getline(cin, danhsach[i].tongSoMuon);
			printf("\n   Da sua xong ");
			bienKT++;
		}
	}
	if (bienKT == 0)
	{
		printf("\n   Ma tai khoan khong ton tai!!!");
	}
}

void ghiFile(vector<Sach> &danhsach, int soluong)
{
	getchar();
	fstream data;
	data.open("sach.in", ios::in | ios::out);
	if (data == NULL)
	{
		printf("\n Loi tao, mo file!");
		exit(1);
	}
	// fprintf(fOut, "%-15s|| %-10s|| %-10s|| %-10s|| %-10s\n", "Ma sach", "Ten sach", "The loai", "Nha xuat ban", "Tong so luong");
	data.seekg(0, ios_base::end);
	for (int i = 0; i < soluong; i++)
	{
		data << danhsach[i].maTk << "_" << (danhsach[i]).tenTk << "_" << danhsach[i].theLoai << "_" << danhsach[i].fullname << "_" << danhsach[i].tongSoMuon << endl;
	}
	printf("\n  Luu file thanh cong");
	data.close();
}
void pressAnyKey()
{
	printf("\n\n   Bam phim bat ky de tiep tuc...");
	getch();
	system("cls");
}
