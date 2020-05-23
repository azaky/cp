#include <bits/stdc++.h>
using namespace std;

void printvector(const vector<unsigned> &A) {
    for (unsigned i = 0; i < A.size(); ++i) {
        if (i) {
            putchar(' ');
        }
        // printf("%d", A[i]);
    }
    putchar('\n');
}

// this is just a standard pseudorandom generator
struct PRNG {
    long long seed;
    PRNG(long long seed) : seed(seed) {}

    long long _random() {
        long long M = 2147483647, A = 16807;
        long long Q = M/A, R = M%A;
        seed = A*(seed%Q) - R*(seed/Q);
        if (seed <= 0) seed += M;
        return seed;
    }

    long long randint(int lo, int hi) {
        return lo + _random() % (hi-lo);
    }
};
// valid
long long median(long long a, long long b, long long c) {
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);
    return b;
}

void modify(vector<unsigned> &A, int x, int y, bool magic) {
    if (A[x] > A[y] || magic) swap( A[x], A[y] );
}

// this is the main function
void k2_sort(vector<unsigned> &A) {
    PRNG generator(589);
    
    int N = A.size();
    int L = 1;
    while ((1<<L) < N) ++L;
    int lo = (N - (1<<L)) / 2;

    // printf("L = %d, lo = %d\n", L, lo);
   
    for (int superphase=0; superphase<2; ++superphase) {
        // printf("\tsuperphase %d\n", superphase);
        for (int phase=1; phase<=L; ++phase) {
            // printf("\t\tphase %d\n", phase);
            for (int subphase=phase; subphase>=1; --subphase) {
                // printf("\t\t\tsubphase %d\n", subphase);
                if (phase == L && subphase == L) {
                    for (int i=0; i < (1<<(L-1)); ++i) {
                        int x = lo+i, y = lo+(1<<L)-1-i;
                        if (x >= 0 && y < N) modify( A, x, y, L*superphase+phase < 2*(L-1) );
                    }
                }
                for (int block=0; block<(1<<(L-subphase)); ++block) {
                    // printf("\t\t\t\tblock %d\n", block);
                    int xlo  = median( 0, N, lo + (block << subphase) );
                    int xmed = median( 0, N, lo + (block << subphase) + (1<<(subphase-1)) );
                    int xhi  = median( 0, N, lo + (block << subphase) + (1<<subphase) );
                    // printf("\t\t\t\txlo = %d, xmed = %d, xhi = %d\n", xlo, xmed, xhi);
                    if (xlo == xmed || xmed == xhi) continue;
                    for (int comparison=0; comparison<521; ++comparison) {
                        int x = generator.randint(xlo,xmed);
                        int y = generator.randint(xmed,xhi);
                        modify( A, x, y, L*superphase+phase < 2*(L-1) );
                    }
                    // printf("\t\t\t\t");
                    printvector(A);
                }
            }
        }
    }
}

bool isSorted(vector<unsigned>& a) {
    for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

int main () {
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<unsigned> a;
    // for (int i = 0; i < 256; ++i) {
    //     a.push_back(i + 1);
    // }
    for (int i = 49; i > 0; --i) {
        a.push_back(i);
    }
    vector<unsigned> ori = a;
    k2_sort(a);
    if (!isSorted(a)) {
        puts("NOT SORTED!");
        printvector(ori);
        printvector(a);
    }

    return 0;
}