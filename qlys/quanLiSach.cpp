#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

//============khai bao dulieu=========
struct book_st
{
	char maTk[1000];
	char tenTk[1000];
	char theLoai[1000];
	char fullname[1000];
	int tongSoMuon;
};

struct user
{
	string acc;
	string pass;
};

user ad, cus, sign;

typedef book_st Sach;
void Login();
void nhapSach(Sach *sach);
void nhapDanhSach(Sach *&danhsach, int &soluong);
void xoaSach(Sach *sach, int soluong);
void suaTenSach(Sach *sach, int soluong);
void ghiFile(Sach *sach, int n);
void pressAnyKey();
void menu();
int numlines();
bool check();
bool daCo();

int main()
{
	system("color 2");
	Login();
	menu();
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
	if(sign.acc == ad.acc && sign.pass == ad.pass) return false;
	else if(sign.acc == cus.acc && sign.pass == cus.pass) return false;
	return true;
}

void menu()
{
	Sach *sach;
	int soluong, key;
	bool daNhap = daCo();
	sach = (Sach *)malloc(sizeof(Sach));
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
			nhapDanhSach(sach, soluong);
			printf("\n   Ban da nhap thanh cong!\n");
			daNhap = true;
			ghiFile(sach, soluong);
			soluong = numlines();
			pressAnyKey();
			break;
		case 2:
			if (daNhap)
			{
				printf("\n   Ban da chon cap nhat tai khoan!");
				suaTenSach(sach, soluong);
			}
			else
			{
				printf("\n   Nhap danh sach sach truoc!!!!");
			}
			pressAnyKey();
			break;
		case 3:
			if (daNhap)
			{
				printf("\n   Ban da chon xoa tai khoan!");
				xoaSach(sach, soluong);
			}
			else
			{
				printf("\n   Nhap danh sach sach truoc!!!!");
			}
			pressAnyKey();
			break;
		case 0:
			printf("\n   Ban da chon thoat chuong trinh!");
			flat = 0;
			false;
		default:
			printf("\n   Khong co chuc nang nay!");
			printf("\n   Bam phim bat ky de tiep tuc!");
			printf("\n");
			getch();
			break;
		}
	}
	if (sach == NULL)
	{
		free(sach);
	}
}

bool daCo()
{
	fstream data;
	char c;
	data.open("sach.in", ios::in);
	data.get(c);
	data.close();
	if(c == '\0') return false;
	return true;
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
void nhapSach(Sach *sach)
{
	fflush(stdin);
	printf("\n   Nhap ma tai khoan: ");
	gets(sach->maTk);
	printf("\n   Nhap ten tai khoan: ");
	gets(sach->tenTk);
	printf("\n   Nhap the loai: ");
	gets(sach->theLoai);
	printf("\n   Nhap ten day du: ");
	gets(sach->fullname);
	printf("\n   Nhap so luong sach muon: ");
	scanf("%d", &sach->tongSoMuon);
}
void nhapDanhSach(Sach *&danhsach, int &soluong)
{
	printf("\n   So luong tai khoan them: ");
	scanf("%d", &soluong);
	danhsach = (Sach *)malloc(soluong * sizeof(Sach));
	for (int i = 0; i < soluong; i++)
	{
		printf("\n   Nhap tai khoan thu %d: ", i + 1);
		nhapSach(&*(danhsach + i));
	}
	// soluong = numlines();
}

void xoaSach(Sach *sach, int soluong)
{
	char maSach[30];
	int bienKT = 0, bienLap;
	printf("\n   Xoa tai khoan...");
	printf("\n   Nhap ma tai khoan:");
	fflush(stdin);
	gets(maSach);
	Sach *fid;
	fstream of;
	of.open("sach.in", ios::in);
	for (int i = 1; i <= soluong; i++)
	{
		of >> *(fid + i) -> maTk;
	}
	for (int i = 0; i < soluong; i++)
	{
		if (strcmp((sach + i)->maTk, maSach) == 0)
		{
			for (bienLap = i; bienLap < soluong; i++)
			{
				*(sach + bienLap) = *(sach + bienLap + 1);
				soluong = soluong - 1;
			}
			printf("\n   Da xoa xong");
			bienKT++;
		}
	}
	if (bienKT == 0)
	{
		printf("\n   Ma sach khong ton tai!!!");
	}
}
void suaTenSach(Sach *sach, int soluong)
{
	int bienKT = 0;
	char maSach[30];
	printf("\n   CAP NHAT THONG TIN TAI KHOAN ");
	printf("\n   Nhap ma tai khoan can sua :");
	fflush(stdin);
	gets(maSach);
	for (int i = 0; i < soluong; i++)
	{
		if (strcmp((sach + i)->maTk, maSach) == 0)
		{
			printf("\n   Nhap ten tai khoan: ");
			gets((sach + i)->tenTk);
			printf("\n   Da sua xong ");
			bienKT++;
		}
	}
	if (bienKT == 0)
	{
		printf("\n   Ma sach khong ton tai!!!");
	}
}
void ghiFile(Sach *danhsach, int soluong)
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
	data.seekg(0,ios_base::end);
	for (int i = 0; i < soluong; i++)
	{
		data << (danhsach + i)->maTk << "_" << (danhsach + i)->tenTk << "_" << (danhsach + i)->theLoai << "_" << (danhsach + i)->fullname << "_" << (danhsach + i)->tongSoMuon << endl;
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
