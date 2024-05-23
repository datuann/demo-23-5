#pragma once
#ifndef _BAI02_H_
#define _BAI02_H_
#include<iostream>
#include<fstream>

using namespace std;
struct SinhVien {
	char* MSSV;
	char* HoTen;
	double gpa;
};
struct Node {
	SinhVien info;
	Node* pNext;
};
struct ListNode
{
	Node* pHead;
	Node* pTail;

};
void initNode(ListNode l);
void copyString(char* source, char* destination);
Node* CreateNode(SinhVien& sv);
void AddNode(ListNode& l, Node* p);
void printListNode(ListNode l);
int compare_strings(char* s1, char* s2);
int sortByMSSV(SinhVien& sv1, SinhVien& sv2);
int sortByHoTen(SinhVien& sv1, SinhVien& sv2);
int sortByGPA(SinhVien& sv1, SinhVien& sv2);
void sortList(ListNode& l, int(*comparison)(SinhVien&, SinhVien&));
void printNode(Node* temp);
void printByHoTen(ListNode l);
void printByMssvAndHoTen(ListNode l);
void displayListNodeBy(ListNode& l, void(*printNode)(ListNode));
void deleteMiddle(ListNode& l, int pos);
void deleteByMssv(ListNode& l, char* mssv);
void deleteByGPA(ListNode& l, double x);
void deleteListNode(ListNode& l);
void addNodeAndSort(ListNode& l, SinhVien& sv, int(*comparison)(SinhVien&, SinhVien&));
void DivideListNode(ListNode& l, int n);
void mergeListNode(ListNode& l1, ListNode& l2, ListNode& l);
#endif // !_BAI02_H_
