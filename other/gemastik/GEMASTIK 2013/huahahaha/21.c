 int main() {
 typedef double Suhu;
 #define c 1.0002
 #define x 1.0005
 Suhu Tp = 231.0; //suhu awal
	 Suhu Tb = 272.6; 
 int n = 10;
	 Suhu dT = (Tb - Tp) / (n-1);
	 Suhu T = Tp;
 do {
	 printf("%f\n",T);
 T+=dT * c * x;
	 } while(--n);
	 return 0;
 }
