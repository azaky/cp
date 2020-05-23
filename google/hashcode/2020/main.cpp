#include <bits/stdc++.h>
using namespace std;

#include "main.h"

vector<Library> solveWithLibrarySorted(Problem &p) {
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
    // fprintf(stderr, "done! nans = %d\n", nans);
    // fprintf(stderr, "totalcap = %d\n", totalcap);

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
    // fprintf(stderr, "nbooks = %d\n", lbooks.size());
    vector<int> books;
    for (auto book : lbooks) {
        books.push_back(book.first);
    }
    // fprintf(stderr, "books.size() = %d\n", books.size());

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
    // fprintf(stderr, "allocated %d books\n", nchosenbooks);
    return ans;
}

void solveA() {
    setFile("a_example");
    Problem p = readProblem();

    sort(p.libs.begin(), p.libs.end(), [&](const Library &a, const Library &b) {
        return a.nbooks > b.nbooks;
    });
    vector<Library> ans;
    for(int i=0;i<p.libs.size();i++) {
        Library lib = p.libs[i];
        lib.scanned = lib.books;
        ans.push_back(lib);
    }

    fprintf(stderr, "A: %d\n", judge(p, ans));
    printAnswer(ans);
}

void solveB() {
    setFile("b_read_on");
    Problem p = readProblem();

    sort(p.libs.begin(), p.libs.end(), [&](const Library &a, const Library &b) {
        return a.ndays < b.ndays;
    });
    int ndays = 0, ilib = 0;
    vector<Library> ans;
    while (ilib < p.nlibs && ndays <= p.ndays) {
        if (ndays + p.libs[ilib].ndays <= p.ndays) {   
            ndays += p.libs[ilib].ndays;
            p.libs[ilib].reg = ndays;
            ans.push_back(p.libs[ilib]);
            ilib++;
        } else break;
    }
    int nans = ans.size();
    // fprintf(stderr, "done! nans = %d\n", nans);
    for (int i = 0; i < nans; ++i) {
        int remainingdays = p.ndays - ans[i].reg;
        // fprintf(stderr, "scanning books in lib %d... nbook = %d, nship = %d\n", ans[i].index, ans[i].nbooks, ans[i].nship);
        for (int d = 0; d < remainingdays; ++d) {
            // register books with index [d*s .. (d+1)*s)
            if (ans[i].nbooks <= (long long) d * ans[i].nship) break;
            for (int ibook = d * ans[i].nship; ibook < (long long)((d + 1) * ans[i].nship) && ibook < ans[i].nbooks; ++ibook) {
                // fprintf(stderr, "\tadding books[%d] = %d\n", ibook, ans[i].books[ibook]);
                ans[i].scanned.push_back(ans[i].books[ibook]);
            }
        }
    }

    fprintf(stderr, "B: %d\n", judge(p, ans));
    printAnswer(ans);
}

void solveC() {
    setFile("c_incunabula");
    Problem p = readProblem();

    sort(p.libs.begin(), p.libs.end(), [&](const Library &a, const Library &b) {
        return a.ndays/a.nbooks < b.ndays/b.nbooks;
    });
    vector<Library> ans;
    for(int i=0;i<p.libs.size();i++) {
        sort(p.libs[i].books.begin(), p.libs[i].books.end(),
            [&](int &a, int &b) {
                return p.s[a] > p.s[b];
        });
        Library lib = p.libs[i];
        lib.scanned = lib.books;
        ans.push_back(lib);
    }

    fprintf(stderr, "C: %d\n", judge(p, ans));
    printAnswer(ans);
}

void solveD() {
    setFile("d_tough_choices");
    Problem p = readProblem();

    sort(p.libs.begin(), p.libs.end(), [&](const Library &a, const Library &b) {
        return a.nbooks > b.nbooks;
    });
    vector<Library> ans;
    for(int i=0;i<p.libs.size();i++) {
        Library lib = p.libs[i];
        lib.scanned = lib.books;
        ans.push_back(lib);
    }

    fprintf(stderr, "D: %d\n", judge(p, ans));
    printAnswer(ans);
}

void solveE() {
    setFile("e_so_many_books");
    Problem p = readProblem();

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

    vector<Library> ans = solveWithLibrarySorted(p);

    fprintf(stderr, "E: %d\n", judge(p, ans));
    printAnswer(ans);
}

void solveF() {
    setFile("f_libraries_of_the_world");
    Problem p = readProblem();

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

    // we try to random shuffle first 23 library until we get best possible score
    vector<Library> best;
    int bestscore = 0;
    int tries = 1000;
    while (tries--) {
        // fprintf(stderr, "tries #%d\n", 1000-tries);
        sort(p.libs.begin(), p.libs.begin() + 23, [&](const Library &a, const Library &b) {
            return rand() % 2;
        });
        vector<Library> ans = solveWithLibrarySorted(p);
        int score = judge(p, ans);
        if (score > bestscore) {
            fprintf(stderr, "F: tries #%d: score: %d\n", 1000-tries, score);
            best = ans;
            bestscore = score;
        }
    }

    fprintf(stderr, "F: %d\n", judge(p, best));
    printAnswer(best);
}

int main() {
    solveA();
    solveB();
    solveC();
    solveD();
    solveE();
    solveF();
}
