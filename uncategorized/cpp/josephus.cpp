#include <cstdio>
using namespace std;

#define MAXN 1010
int n, k, prev[MAXN], next[MAXN], now;

int main(){
	scanf("%d%d",&n,&k);
	//membuat Linked List
	for (int i = 1; i <= n; ++i){
		prev[i] = i-1;
		next[i] = i+1;
	}
	prev[1] = n;
	next[n] = 1;
	//simulasikan permainannya
	now = 1; //now adalah pemain saat ini
	for (int hitung = 1; hitung <= (n-1)*k; ++hitung){
		//sekarang, now menyebutkan angka "hitung"
		//jika hitung kelipatan k, maka now dikeluarkan
		if (hitung % k == 0){
			//ini cara menghapus now dari Linked List
			next[prev[now]] = next[now];
			prev[next[now]] = prev[now];
		}
		//sekarang giliran next[now]
		now = next[now];
	}
	//pemenangnya adalah now
	printf("%d\n",now);
	
	return 0;
}
