int main () {
struct {
char *nama;
int nilai;
} Mhs;
printf("Nama mahasiswa: ");
Mhs.nama = (char *) malloc (20 * sizeof(char));
gets(Mhs.nama);
printf("Nilai: ");
scanf("%d",&Mhs.nilai);
printf("%s %d",Mhs.nama,Mhs.nilai);

return 0;
}
