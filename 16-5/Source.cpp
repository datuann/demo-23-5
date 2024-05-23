#include<iostream>
using namespace std;
long xn(int n) {
	if (n == 0) return 1;
	long s = 0;
	for (int i = 1; i <= n; i++) {
		s = s + i * i * xn(n - i);

	}
	return s;
}
void findMinMax(int arr[], int left, int right, int& min, int& max) {
	if (left == right) {
		if (max < arr[left]) max = arr[left];
		if (min > arr[right]) min = arr[right];
		return;
	}
	if (right - left == 1) {
		if (arr[left] < arr[right]) {
			if (min > arr[left])min = arr[left];
			if (max < arr[right]) max = arr[right];
		}
		else {
			if (min > arr[right]) min = arr[right];
			if (max < arr[left]) max = arr[left];
		}
		return;
	}
	int mid = (left + right) / 2;
	findMinMax(arr, left, mid, min, max);
	findMinMax(arr, mid + 1, right, min, max);

	


}
void chuyen(int n, char A, char C, char B) {
	if (n == 1) {
		cout << A << "->" << C << endl;
		return;
	}
	chuyen(n - 1, A, B, C);
	cout << A << "->" << C << endl;
	chuyen(n - 1, B, C, A);

}
int main() {
	int arr[] = { 1,9,4,1,5,7,8,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int max = INT_MIN;
	int min = INT_MAX;
	findMinMax(arr, 0, n - 1, min, max);
	cout << "The minimum element is: " << min << endl;
	cout << "The maximum element is: " << max << endl;
	/*int n;
	cin >> n;
	chuyen(n, 'A', 'C', 'B');*/
	return 0;
}