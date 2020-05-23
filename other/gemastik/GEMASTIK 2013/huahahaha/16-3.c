 int main () {
int num, count = 1;
float sum = 0.0;
while (count <= 3) {
scanf("%d",&num);
sum = sum + num;
count = count + 1;
}
printf("Rata-rata adalah %f\n", sum/count);
}
