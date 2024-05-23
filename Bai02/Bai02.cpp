#include"Bai02.h"
void initNode(ListNode l) {
	l.pHead = l.pHead = NULL;
}
void copyString(char* source, char* destination) {
	int cnt = 0;
	for (int i = 0; i < strlen(source); i++) {
		destination[i] = source[i];
		cnt++;
	}
	destination[cnt] = '\0';
}
Node* CreateNode(SinhVien &sv) {
	char tmp[100];
	char tmp1[100];
	cout << "Nhap thong tin sinh vien: " << endl;
	cin.ignore();
	cout << "ID: ";
	cin.getline(tmp, 9);
	sv.MSSV = new char[strlen(tmp) + 1];
	copyString(tmp, sv.MSSV);
	cout << "Ho va ten: ";
	cin.getline(tmp1, 31);
	sv.HoTen = new char[strlen(tmp1) + 1];
	copyString(tmp1, sv.HoTen);
	cout << "GPA: "; cin >> sv.gpa;
	Node* temp = new Node();
	temp->info.MSSV = new char[strlen(sv.MSSV) + 1];
	copyString(sv.MSSV, temp->info.MSSV);
	temp->info.HoTen = new char[strlen(sv.HoTen) + 1];
	copyString(sv.HoTen, temp->info.HoTen);
	temp->info.gpa = sv.gpa;
	temp->pNext = NULL;
	return temp;

}
void AddNode(ListNode& l, Node* p) {
	if (p == NULL) return;
	if (l.pHead == NULL)l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void printListNode(ListNode l) {
	Node* temp = l.pHead;
	int i = 0;
	while (temp != NULL) {
		i++;
		cout << "--------------" << endl;
		cout << "Student " << i << ": " << endl;
		cout << "MSSV: " << temp->info.MSSV << endl;
		cout << "Ho ten: " << temp->info.HoTen << endl;
		cout << "GPA: " << temp->info.gpa << endl;
		temp = temp->pNext;
	}
	cout << endl;
}
void printNode(Node* temp) {
	cout << "MSSV: " << temp->info.MSSV << endl;
	cout << "Ho ten: " << temp->info.HoTen << endl;
	cout << "GPA: " << temp->info.gpa << endl;

}
void swap(Node *p1, Node *p2) {
	SinhVien temp = p1->info;
	p1->info = p2->info;
	p2->info = temp;

}
int compare_strings(char *s1,  char *s2) {
	for (int i = 0; i < strlen(s1) && i < strlen(s2); i++) {
		if (s1[i] > s2[i])	 return 1;
		else if (s1[i] < s2[i]) return -1;
	}
	if (strlen(s1) > strlen(s2)) return 1;
	else if (strlen(s1) < strlen(s2)) return -1;
	return 0;
}
int sortByMSSV(SinhVien& sv1, SinhVien& sv2) {
	return compare_strings(sv1.MSSV, sv2.MSSV);
}
int sortByHoTen(SinhVien& sv1, SinhVien& sv2) {
	return compare_strings(sv1.HoTen, sv2.HoTen);
}
int sortByGPA(SinhVien& sv1, SinhVien& sv2) {
	if (sv1.gpa > sv2.gpa) return 1;
	else if (sv1.gpa < sv2.gpa) return -1;
	return 0;
}
void sortList(ListNode& l, int(*comparison)(SinhVien &, SinhVien &)) {
	for (Node* temp = l.pHead; temp->pNext != NULL; temp = temp->pNext) {
		for (Node* res = temp->pNext; res != NULL; res = res->pNext) {
			if (comparison(temp->info, res->info)>0) swap(temp, res);
		}
	}
}
void printByHoTen(ListNode l) {
	Node* temp = l.pHead;
	int i = 0;
	while (temp != NULL) {
		i++;
		cout << "--------------" << endl;
		cout << "Student " << i << ": " << endl;
		cout << "Ho ten: " << temp->info.HoTen << endl;
		temp = temp->pNext;
	}
	cout << endl;
}
void printByMssvAndHoTen(ListNode l) {
	Node* temp = l.pHead;
	int i = 0;
	while (temp != NULL) {
		i++;
		cout << "--------------" << endl;
		cout << "Student " << i << ": " << endl;
		cout << "MSSV: " << temp->info.MSSV << endl;
		cout << "Ho ten: " << temp->info.HoTen << endl;
		temp = temp->pNext;
	}
	cout << endl;
}
void displayListNodeBy(ListNode& l, void(*printNode)(ListNode)) {
	printNode(l);
}
void deleteMiddle(ListNode& l, int pos) {
	Node* truoc = NULL;
	Node* sau = l.pHead;
	for (int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->pNext;
	}
	if (truoc == NULL) l.pHead = l.pHead->pNext;
	else truoc->pNext = sau->pNext;

}
void deleteByMssv(ListNode& l, char *mssv) {
	while (l.pHead != NULL && compare_strings(mssv,l.pHead->info.MSSV)==0) {
		Node* temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete[] temp->info.MSSV;
		delete[] temp->info.HoTen;
		delete temp;
	}
	Node* res = l.pHead;
	while (res->pNext != NULL) {
		if (compare_strings(mssv,res->pNext->info.MSSV) == 0) {
			Node* temp = res->pNext;
			res->pNext = temp->pNext;
			delete[] temp->info.MSSV;
			delete[] temp->info.HoTen;
			delete temp;
		}
		else res = res->pNext;
	}
}
void deleteByGPA(ListNode& l, double x) {
	while (l.pHead!=NULL &&l.pHead->info.gpa<x) {
		Node* temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete[] temp->info.MSSV;
		delete[] temp->info.HoTen;
		delete temp;
	}
	Node* res = l.pHead;
	while (res->pNext != NULL) {
		if (res->pNext->info.gpa < x) {
			Node* temp = res->pNext;
			res->pNext = temp->pNext;
			delete[] temp->info.MSSV;
			delete[] temp->info.HoTen;
			delete temp;
		}
		else res = res->pNext;
	}
	
	
	
	

}
void deleteListNode(ListNode& l) {
	Node* temp = l.pHead;
	while (temp != NULL) {
		Node* res = temp->pNext;
		delete[] temp->info.MSSV;
		delete[] temp->info.HoTen;
		delete temp;
		temp = res;
	}
}
void addNodeAndSort(ListNode& l,SinhVien &sv, int(*comparison)(SinhVien&, SinhVien&)) {
	cout << "Nhap thong tin sinh vien muon them: " << endl;
	AddNode(l, CreateNode(sv));
	for (Node* temp = l.pHead; temp->pNext != NULL; temp = temp->pNext) {
		for (Node* res = temp->pNext; res != NULL; res = res->pNext) {
			if (comparison(temp->info, res->info) > 0) swap(temp, res);
		}
	}
}
void DivideListNode(ListNode& l, int n) {
	Node* temp = l.pHead;
	int res = 0; int i = 0;
	cout << "ListNode 1: " << endl;
	while (res != n / 2) {
		i++;
		cout << "--------------" << endl;
		cout << "Student " << i << ": " << endl;
		printNode(temp);
		temp = temp->pNext;
		res++;
	}
	cout << endl;
	cout << "ListNode 2: " << endl;
	while (temp != NULL) {
		i++;
		cout << "--------------" << endl;
		cout << "Student " << i << ": " << endl;
		printNode(temp);
		temp = temp->pNext;
	}
	cout << endl;
}
void mergeListNode(ListNode& l1, ListNode& l2, ListNode &l) {
	Node* p1 = l1.pHead;
	while (p1 != NULL) {
		AddNode(l, p1);
		p1 = p1->pNext;
	}
	Node* p2 = l2.pHead;
	while (p2 != NULL) {
		AddNode(l, p2);
		p2 = p2->pNext;
	}
}