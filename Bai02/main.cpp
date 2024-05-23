#include"Bai02.h"
int main() {
	
	/*int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		AddNode(l1, CreateNode(sv));
	}
	for (int i = 0; i < m; i++) {
		AddNode(l2, CreateNode(sv));
	}*/
	/*
	sortList(l, sortByMSSV);
	cout << "Sort list: " << endl;
	cout << "**************" << endl;
	printListNode(l);
	*/
	//displayListNodeBy(l, printByHoTen);
	//addNodeAndSort(l, sv1, sortByGPA);
	/*cout << "Nhap diem ban muon xoa: ";
	double x;
	cin >> x;
	deleteByGPA(l, x);*/
	/*cin.ignore();
	char tmp[9];
	cin.getline(tmp, 9);
	char* mssv = new char[9];
	copyString(tmp, mssv);
	deleteByMssv(l, mssv);
	printListNode(l);*/
	//DivideListNode(l, n);
	//mergeListNode(l1, l2, l);
	while (true) {
		ListNode l;
		SinhVien sv;
		cout << "\n\n\t_________MENU___________" << endl;
		cout << "1. Khoi tao lop hoc. " << endl;
		cout << "2. Them sinh vien vao lop hoc. " << endl;
		cout << "3. Xuat danh sach sinh vien theo yeu cau: " << endl;
		cout << "4. Doc, ghi du lieu lop hoc ra file nhi phan. " << endl;
		cout << "5. Sap xep sinh vien theo yeu cau. " << endl;
		cout << "6. Duoi hoc mot so sinh vien. " << endl;
		cout << "7. Xoa lop hoc. " << endl;
		cout << "8. Them mot sinh vien vao lop hoc da duoc sap xep theo cac tieu chi cu the. " << endl;
		cout << "9. Tach 1 lop thanh 2 lop. " << endl;
		cout << "10. Gop 2 lop hoc thanh 1 lop. " << endl;
		cout << "\t_________END____________" << endl;
		int luachon;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		if (luachon == 1) {
			l.pHead = NULL;
		}
		else if (luachon == 2) {
			l.pHead = NULL;
			cout << "Nhap so luong sinh vien: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				AddNode(l, CreateNode(sv));
			}
			system("pause");
		}
		else if (luachon == 3) {
			l.pHead = NULL;
			cout << "Nhap so luong sinh vien: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				AddNode(l, CreateNode(sv));
			}
			bool check = true;
			while (check) {
				cout << "------------------" << endl;
				cout << "1. Chi xuat ten" << endl;
				cout << "2. Chi xuat ten va mssv" << endl;
				cout << "3. Xuat het thong tin " << endl;
				cout << "4. Out" << endl;
				int lc;
				cout << "Nhap lua chon de xuat thong tin" << endl;
				cin >> lc;
				if (lc == 1) {
					displayListNodeBy(l, printByHoTen);
				}
				else if (lc == 2) {
					displayListNodeBy(l, printByMssvAndHoTen);
				}
				else if (lc == 3) {
					displayListNodeBy(l, printListNode);
				}
				else if (lc == 4) check = false;
			}
			system("pause");
		}
		else if (luachon == 5) {
			l.pHead = NULL;
			cout << "Nhap so luong sinh vien: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				AddNode(l, CreateNode(sv));
			}
			bool check = true;
			while (check) {
				cout << "------------------" << endl;
				cout << "1. Sap xep theo mssv" << endl;
				cout << "2. Sap xep theo ho ten" << endl;
				cout << "3. Sap xep theo diem trung binh " << endl;
				cout << "4. Out" << endl;
				int lc;
				cout << "Nhap lua chon de sap xep" << endl;
				cin >> lc;
				if (lc == 1) {
					sortList(l, sortByMSSV);
					cout << "**************" << endl;
					cout << "List node after sort by MSSV: " << endl;
					printListNode(l);
				}
				else if (lc == 2) {
					sortList(l, sortByHoTen);
					cout << "**************" << endl;
					cout << "List node after sort by name: " << endl;
					printListNode(l);
				}
				else if (lc == 3) {
					sortList(l, sortByGPA);
					cout << "**************" << endl;
					cout << "List node after sort by gpa: " << endl;
					printListNode(l);
				}
				else if (lc == 4) check = false;
			}
			system("pause");
		}
		else if (luachon == 6) {
			l.pHead = NULL;
			cout << "Nhap so luong sinh vien: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				AddNode(l, CreateNode(sv));
			}
			bool check = true;
			while (check) {
				cout << "------------------" << endl;
				cout << "1. Duoi hoc theo MSSV" << endl;
				cout << "2. Duoi hoc theo diem trung binh" << endl;
				cout << "3. Out" << endl;
				int lc;
				cout << "Nhap lua chon de sap xep" << endl;
				cin >> lc;
	
				if (lc == 1) {
					char tmp[9];
					cin.getline(tmp, 9);
					char* mssv = new char[9];
					copyString(tmp, mssv);
					deleteByMssv(l, mssv);
				}
				else if (lc == 2) {
					double x;
					cin >> x;
					deleteByGPA(l, x);
				}
				else if (lc == 3) check = false;
			}
			system("pause");
		}
		else if (luachon == 7) {
			l.pHead = NULL;
			cout << "Nhap so luong sinh vien: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				AddNode(l, CreateNode(sv));
			}
			deleteListNode(l);
		}
		else if (luachon == 8) {
			l.pHead = NULL;
			cout << "Nhap so luong sinh vien: ";
			SinhVien sv1;
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				AddNode(l, CreateNode(sv));
			}
			bool check = true;
			while (check) {
				cout << "------------------" << endl;
				cout << "1. Sap xep theo mssv" << endl;
				cout << "2. Sap xep theo ho ten" << endl;
				cout << "3. Sap xep theo diem trung binh " << endl;
				cout << "4. Out" << endl;
				int lc;
				cout << "Nhap lua chon de sap xep" << endl;
				cin >> lc;
				if (lc == 1) {
					addNodeAndSort(l, sv1, sortByMSSV);
					cout << "**************" << endl;
					cout << "List node after add node and sort by MSSV: " << endl;
					printListNode(l);
				}
				else if (lc == 2) {
					addNodeAndSort(l, sv1, sortByHoTen);
					cout << "**************" << endl;
					cout << "List node after add node and sort by name: " << endl;
					printListNode(l);
				}
				else if (lc == 3) {
					addNodeAndSort(l, sv1, sortByGPA);
					cout << "**************" << endl;
					cout << "List node after add node and sort by gpa: " << endl;
					printListNode(l);
				}
				else if (lc == 4) check = false;
			}
			system("pause");
		}
		else if (luachon == 9) {
			l.pHead = NULL;
			cout << "Nhap so luong sinh vien: ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				AddNode(l, CreateNode(sv));
			}
			DivideListNode(l, n);
			system("pause");
			
		}
		else if (luachon == 10) {
			ListNode l1, l2;
			l1.pHead = NULL;
			l2.pHead = NULL;
			l.pHead = NULL;
			int n, m;
			cout << "Nhap so luong ListNode 1: ";
			cin >> n;
			cout << "Nhap so luong ListNode 2: ";
			cin >> m;
			cout << "Nhap thong tin ListNode 1: " << endl;
			for (int i = 0; i < n; i++) {
				AddNode(l1, CreateNode(sv));
			}
			cout << "Nhap thong tin ListNode 1: " << endl;
			for (int i = 0; i < m; i++) {
				AddNode(l2, CreateNode(sv));
			}
			mergeListNode(l1, l2, l);
			cout << "Merge list node: " << endl;
			printListNode(l);
			system("pause");
		}
	}
	}
	
