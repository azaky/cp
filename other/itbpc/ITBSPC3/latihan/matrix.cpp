#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Matrix{
	int n;
	vector<vector<long long> > M;
	void resize(int _n){
		n = _n;
		M.resize(n);
		for(int i = 0; i < n; ++i) M[i].resize(n);
	}
	void read(int _n){
		resize(_n);
		for(int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> M[i][j];
	}
	long long det(){
		int a[100], b[100];
		for (int i=0; i < n; ++i) a[i] = i;
		long long ret = 0;
		do {
			long long sgn = 1;
			for (int i=0; i < n; ++i) b[i] = a[i];
			for (int i=0; i+1 < n; ++i) for (int j=n-1; j > i; --j) if (b[j] < b[j-1]) swap(b[j],b[j-1]), sgn = -sgn;
			for (int i=0; i < n; ++i) sgn *= M[i][a[i]];
			ret += sgn;
		}
		while (next_permutation(a,a+n));
		return ret;
	}
};

Matrix Transpose(Matrix A){
	Matrix ret;
	ret.resize(A.n);
	for(int i=0; i < A.n; ++i) for (int j=0; j < A.n; ++j) ret.M[i][j] = A.M[j][i];
	return ret;
}
long long Cofactor(Matrix A, int x, int y){
	Matrix temp;
	temp.resize(A.n-1);
	for(int i=0; i < A.n-1; ++i) for (int j=0; j < A.n-1; ++j) temp.M[i][j] = A.M[i < x ? i : i+1][j < y ? j : j+1];
	return (x+y)%2 == 0 ? temp.det() : -temp.det();
}
Matrix Inverse(Matrix A){
	Matrix C;
	C.resize(A.n);
	for (int i=0; i < A.n; ++i) for (int j=0; j < A.n; ++j) C.M[i][j] = Cofactor(A,i,j);
	C = Transpose(C);
	return C;
}

int main(){
	int n;
	scanf("%d",&n);
	Matrix A;
	A.read(n);
	long long det = A.det();
	if (det == 0) puts("Matriks Jeleeeeeek!");
	else {
		Matrix B = Inverse(A);
		for (int i=0; i < n; ++i) for (int j=0; j < n; ++j) printf("%.3lf%c",(double)B.M[i][j]/(double)det,j == n-1 ? '\n' : ' ');
		cout << endl << "determinant = " << det << endl;
		for (int i=0; i < n; ++i) for (int j=0; j < n; ++j) printf("%I64d%c",B.M[i][j],j == n-1 ? '\n' : ' ');
	}
	return 0;
}
