#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <cstdlib>
using namespace std;

bool has_all(const string &S) {
    for (int i=0; i<9; ++i) for (int j=0; j<i; ++j) if (S[i]==S[j]) return false;
    return true;
}

bool is_sudoku_triplet(const vector<string> &V) {
    for (int bc=0; bc<3; ++bc) {
        string block;
        for (int r=0; r<3; ++r) block += string( V[r].begin()+3*bc, V[r].begin()+3*bc+3 );
        if (!has_all(block)) return false;
    }
    return true;
}

int main() {
    vector<int> ID;
    vector<string> ordigits;
    vector<__uint128_t> digits;
    map<__uint128_t, tuple<int,int,int> > mdigits;
    int x; string y;
    while (cin >> x >> y) {
        __uint128_t d = 0;
        for (int i=0; i<9; ++i) d = (d << 9) | (1 << (y[i]-'1'));
        ID.push_back(x);
        ordigits.push_back(y);
        digits.push_back(d);
    }

    vector< __uint128_t > sudoku_triplets;
    vector< tuple<int,int,int> > sudoku_triplet_ids;
    map< __uint128_t, int > msudoku_triplets;

    int N = digits.size();
    for (int a=0; a<N; ++a) {
        if (a%100==0) cout << "a=" << a << endl;
        for (int b=0; b<a; ++b) {
            if (digits[a] & digits[b]) continue;
            for (int c=0; c<b; ++c) {
                if ((digits[a] | digits[b]) & digits[c]) continue;
                vector<string> tmp = { ordigits[a], ordigits[b], ordigits[c] };
                if (!is_sudoku_triplet(tmp)) continue;

                int t3 = sudoku_triplets.size();
                sudoku_triplets.push_back( digits[a] | digits[b] | digits[c] );
                sudoku_triplet_ids.push_back( make_tuple(a,b,c) );
                msudoku_triplets[ digits[a] | digits[b] | digits[c] ] = t3;

                for (int t2=0; t2<t3; ++t2) {
                    if (sudoku_triplets[t2] & sudoku_triplets[t3]) continue;
                    for (int t1=0; t1<t2; ++t1) {
                        if ((sudoku_triplets[t2] | sudoku_triplets[t3]) & sudoku_triplets[t1]) continue;
                        for (int t:{t1,t2,t3}) {
                            cout << ordigits[ get<0>(sudoku_triplet_ids[t]) ] << " ";
                            cout << ID      [ get<0>(sudoku_triplet_ids[t]) ] << endl;
                            cout << ordigits[ get<1>(sudoku_triplet_ids[t]) ] << " ";
                            cout << ID      [ get<1>(sudoku_triplet_ids[t]) ] << endl;
                            cout << ordigits[ get<2>(sudoku_triplet_ids[t]) ] << " ";
                            cout << ID      [ get<2>(sudoku_triplet_ids[t]) ] << endl;
                        }
                        exit(0);
                    }
                }
            }
        }
    }
}
