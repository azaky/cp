 int f (int *T, int n, int x) {
	 int i = 0;
	 while ((T[i]!=x) && (i<=n-1)) {
	 i++;	
	 } 
	 return (T[i]==x?i:-1);
	 return i;
 }

int main(){
    int T[] = {1,2,3};
    printf("%d\n",f(T,3,2));
    
    return 0;
}
