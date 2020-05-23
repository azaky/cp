#if TS>200
#undef TS
#define TS 200
#elif TS<50
#undef TS
#define TS 50
#else
#undef TS
#define TS 100
#endif
int table[TS];

#include <stdio.h>

int main(){
    printf("%d\n",TS);
    return 0;
}
