#include <iostream>
using namespace std;

struct balo {
	int A = 0, B = 0;
};
balo a[100];
int L[100][100];

int Solve(int n, int w, balo a[], int L[][100]){
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (j < a[i].A) {
				L[i][j] = L[i - 1][j];
			}
			else {
				L[i][j] = max(L[i - 1][j], L[i - 1][j - a[i].A] + a[i].B);
			}
		}
	}
	return L[n][w];
}

int main() {
	int n, W;
	cout << "Nhap so do vat: ";
	cin >> n;
	cout << "Nhap khoi luong toi da: ";
	cin >> W;
	cout << "Nhap trong luong va gia tri cua moi mon hang: \n";
	for (int i = 0; i < n; i++) {
		cin >> a[i].A >> a[i].B;
	}
	cout << "================================================" << endl;
	
	cout << "\nGia tri toi da trong balo: " << Solve(n, W, a, L) << endl;
	system("pause");
	return 0;
}