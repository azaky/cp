#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

void header(int chance);

char* word = "KONSEP PENGEMBANGAN ILMU PENGETAHUAN";
char* hint = "salah satu mata kuliah STEI";
//int n = strlen(word), i;
int i, n;

int main(){
	int ada[256], found[256], used[256], done = false;
	int chance = 8;
	char ch;
	n = strlen(word);
	for (i=0; i<256; ++i){
		ada[i] = found[i] = used[i] = false;
		if (word[i] == ' ') found[i] = true;
	}
	for (i=0; i<n; ++i)
		if (word[i]!=' ') ada[(int)word[i]]=true;
	while (!done){
		header(chance);
		for (i=0; i<n; ++i)
			if (!found[i]) printf("* ");
			else printf("%c ",word[i]);
		puts("\n");
		for (i=(int)'A'; i<=(int)'Z'; ++i)
			if (used[i]) printf("* ");
			else printf("%c ",(char)i);
		puts("");
		printf("Tebak satu huruf: ");
		do{
			ch = getchar();
			if ('a' <= ch && ch <= 'z') ch = ch + 'A' - 'a';
			if (!('A' <= ch && ch <= 'Z')) continue;
			if (used[(int)ch]){
				printf("Huruf sudah pernah ditebak!\n");
				ch = getchar();
				printf("Tebak satu huruf: ");
				continue;
			}
			break;
		} while (true);
		used[(int)ch] = true;
		for (i=0; i<n; ++i)
			if (ch==word[i]) found[i]=true;
		if (!ada[(int)ch]) chance--;
		done = true;
		for (i=0; i<n; ++i){
			if (word[i]!=' ' && !found[i]) done = false;
		}
		if (chance==0) break;
	}
	if (done){
		header(chance);
		for (i=0; i<n; ++i)
			if (!found[i]) printf("* ");
			else printf("%c ",word[i]);
		puts("\n");
		for (i=(int)'A'; i<=(int)'Z'; ++i)
			if (used[i]) printf("* ");
			else printf("%c ",(char)i);
		puts("");
		puts("Selamat!!! Anda Menang!!!");
	}
	if (chance == 0){
		header(chance);
		for (i=0; i<n; ++i)
			if (!found[i]) printf("* ");
			else printf("%c ",word[i]);
		puts("\n");
		for (i=(int)'A'; i<=(int)'Z'; ++i)
			if (used[i]) printf("* ");
			else printf("%c ",(char)i);
		puts("");
		puts("Sayang Sekali Anda Kalah!!!\n");
		puts("Kalimat yang benar adalah:");
		for (i=0; i<n; ++i)
			printf("%c ",word[i]);
		puts("");
	}
	puts("Thanks for playing!");
	return 0;
}

void header(int chance){
	system("cls");
	puts("-------------HANGMAN-------------");
	puts("");
	printf("HINT: %s\n",hint);
	puts("");
	if (chance == 8){
		for (i=0; i<18; ++i) puts("             ");
		puts("______________\n");
		return;
	}
	if (chance == 7){
		for (i=0; i<18; ++i) puts("|             ");
		puts("|_____________\n");
		return;
	}
	puts(" ______       ");
	puts("|      |      ");
	if (chance == 6){
		for (i=0; i<16; ++i) puts("|             ");
		puts("|_____________\n");
		return;
	}
	puts("|     _|_     ");
	puts("|    /   \\    ");
	puts("|   |     |   ");
	puts("|   |     |   ");
	puts("|    \\___/    ");
	puts("|      |      ");
	if (chance == 5){
		for (i=0; i<10; ++i) puts("|             ");
		puts("|_____________\n");
		return;
	}
	if (chance == 4){
		for (i=0; i<5; ++i) puts("|      |      ");
		for (i=0; i<5; ++i) puts("|             ");
		puts("|_____________\n");
		return;
	}
	if (chance == 3){
		puts("|     -|      ");
		puts("|    / |      ");
		puts("|   /  |      ");
		puts("|      |      ");
		puts("|      |      ");
		for (i=0; i<5; ++i) puts("|             ");
		puts("|_____________\n");
		return;
	}
	puts("|     -|-     ");
	puts("|    / | \\    ");
	puts("|   /  |  \\   ");
	puts("|      |      ");
	puts("|      |      ");
	if (chance == 2){
		for (i=0; i<5; ++i) puts("|             ");
		puts("|_____________\n");
		return;
	}
	if (chance == 1){
		puts("|     /       ");
		puts("|    /        ");
		puts("|   /         ");
		puts("|             ");
		puts("|             ");
	} else {
		puts("|     / \\     ");
		puts("|    /   \\    ");
		puts("|   /     \\   ");
		puts("|             ");
		puts("|             ");
	}
	puts("|_____________\n");
	return;
}
