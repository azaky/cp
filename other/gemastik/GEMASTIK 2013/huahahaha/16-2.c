 int main () {
int num, count = 1;
float sum = 0.0;
for (count = 0; count <= 2; count++) {
scanf("%d",&num);
sum=+num;
}
printf("Rata-rata adalah %f\n", sum/(count-1));
}
