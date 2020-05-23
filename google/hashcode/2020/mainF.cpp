#include <bits/stdc++.h>
using namespace std;

#include "main.h"

bool sortB(const Library &a, const Library &b) {
    // a -> b -> ndays
    // cap: (ndays - a.ndays) * a.nship + (ndays - a.ndays - b.ndays) * b.nship
    // cap: -a.ndays * b.nship
    // return a.nship > b.nship;
    return a.ndays * b.nship > a.nship * b.ndays;
}

vector<Library> solve(Problem p) {
    int ndays = 0, ilib = 0;
    vector<Library> ans;
    int totalcap = 0;
    while (ilib < p.nlibs && ndays <= p.ndays) {
        if (ndays + p.libs[ilib].ndays <= p.ndays) {   
            ndays += p.libs[ilib].ndays;
            p.libs[ilib].reg = ndays;
            p.libs[ilib].capacity = (p.ndays - ndays) * p.libs[ilib].nship;
            totalcap += p.libs[ilib].capacity;
            // fprintf(stderr, "lib %d picked, capacity = %d\n", p.libs[ilib].index, p.libs[ilib].capacity);
            ans.push_back(p.libs[ilib]);
            ilib++;
        } else break;
    }
    int nans = ans.size();
    int nbooks = 0;
    fprintf(stderr, "done! nans = %d\n", nans);
    fprintf(stderr, "totalcap = %d\n", totalcap);

    // reverse indexing in ans
    map<int, int> ians;
    for (int i = 0; i < nans; ++i) {
        ians[ans[i].index] = i;
    }

    // gather all books
    map<int, vector<int> > lbooks;
    for (auto lib : ans) {
        for (auto book : lib.books) {
            lbooks[book].push_back(lib.index);
        }
    }
    fprintf(stderr, "nbooks = %d\n", lbooks.size());
    vector<int> books;
    for (auto book : lbooks) {
        books.push_back(book.first);
    }
    fprintf(stderr, "books.size() = %d\n", books.size());

    sort(books.begin(), books.end(), [&](int a, int b) {
        return p.s[a] > p.s[b];
    });

    int nchosenbooks = 0;
    for (auto book : books) {
        // fprintf(stderr, "choosing lib for book %d from %d libraries ...\n", book, lbooks[book].size());
        int chosen = -1, maxcap = 0;
        // pick one with max capacity
        for (auto lib : lbooks[book]) {
            int ilib = ians[lib];
            if (ans[ilib].capacity > maxcap) {
                chosen = ilib;
            }
        }
        if (chosen == -1) {
            // fprintf(stderr, "\tno library!\n");
            continue;
        }
        // fprintf(stderr, "chosen lib %d for book %d\n", chosen, book);
        ans[chosen].scanned.push_back(book);
        ans[chosen].capacity--;
        nchosenbooks++;
    }
    fprintf(stderr, "allocated %d books\n", nchosenbooks);
    return ans;
}

void solveF(Problem p) {
    vector<Library> best;
    int bestscore = 0;

    // a -> b -> ndays
    // cap: (ndays - a.ndays) * a.nship + (ndays - a.ndays - b.ndays) * b.nship
    // cap: ndays * (a.nship + b.nship) - a.ndays * a.nship - b.ndays * b.nship - a.ndays * b.nship
    // cap: C - a.ndays * b.nship
    // a > b:
    // -a.ndays * b.nship > -b.ndays * 
    // return a.nship > b.nship;
    sort(p.libs.begin(), p.libs.end(), [&](const Library &a, const Library &b) {
        return a.ndays * b.nship < a.nship * b.ndays;
    });

    // prefix sum of #books
    set<int> books;
    map<int, int> diff;
    int prevsize = 0;
    for (int i = 0; i < p.nlibs; ++i) {
        for (auto book : p.libs[i].books) {
            books.insert(book);
        }
        // printf("First %d libs: %d unique books\n", i+1, books.size());
        int d = books.size() - prevsize;
        prevsize = books.size();
        diff[p.libs[i].index] = d;
    }

    sort(p.libs.begin(), p.libs.end(), [&](const Library &a, const Library &b) {
        return diff[a.index] > diff[b.index];
    });

    int tries = 1000;
    while (tries--) {
        sort(p.libs.begin(), p.libs.begin() + 23, [&](const Library &a, const Library &b) {
            return rand() % 2;
        });
        vector<Library> ans = solve(p);
        int score = judge(p, ans);
        fprintf(stderr, "tries #%d: score: %d\n", 100-tries, score);
        if (score > bestscore) {
            best = ans;
            bestscore = score;
        }
    }

    fprintf(stderr, "score: %d\n", bestscore);
    printAnswer(best);
}

void solveB(Problem p) {
    vector<Library> best;
    int bestscore = 0;
    int bestseed = 1;

    // TODO: randomize sorting
    int tries = 1000;
    srand(123456);
    while (tries--) {
        int seed = rand();
        fprintf(stderr, "seed = %d\n", seed);
        srand(seed);
        random_shuffle(p.libs.begin(), p.libs.end());
        vector<Library> candidate = solve(p);
        int score = judge(p, candidate);
        fprintf(stderr, "\tSEED[%d]: %d\n", seed, score);
        if (score > bestscore) {
            bestscore = score;
            best = candidate;
            bestseed = seed;
        }
        fprintf(stderr, "\tBEST SO FAR: SEED[%d]: %d\n", bestseed, bestscore);
    }

    fprintf(stderr, "FINAL[%d]: %d\n", bestseed, judge(p, best));
    printAnswer(best);
}

int main() {
    // setFile("a_example");
    // solveB(readProblem());

    // setFile("b_read_on");
    // solveB(readProblem());

    // setFile("c_incunabula");
    // solveB(readProblem());

    // setFile("d_tough_choices");
    // solveB(readProblem());

    // setFile("e_so_many_books");
    // solveB(readProblem());

    setFile("f_libraries_of_the_world");
    solveF(readProblem());
}
