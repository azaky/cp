 int main () {
int num, count = 0;
float sum = 0.0;
while (count <= 2) {
scanf("%d",&num);
sum = sum + num;
count = count + 1;
}
printf("Rata-rata adalah %f\n", sum/count);
}
