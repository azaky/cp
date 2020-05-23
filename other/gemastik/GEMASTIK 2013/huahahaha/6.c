 int incr(int i);
 int decr(int j);
 int N = 10;
 void UbahNilai(int *T, int (*f)(int));
 int main () {
 int *T;
	 T = (int *) malloc (N * sizeof(int));
	 int i; int seed = 1;
	 for (i=0;i<N;i++) {
	 *(T+i) = seed++;
	 }
 UbahNilai(&T);
 for (i=0;i<N;i++) {
 printf("%d ", *(T+i));
 }
 free(T);
	 return 0;
 }
 int incr(int i) { return i+1; }
 int decr(int j) { return j-1; }
 void UbahNilai(int *T, int (*f)(int)) {
 int i;
 for (i=0;i<N;i++) {
 *(T+i) = f(T[i]);
 }
 }
