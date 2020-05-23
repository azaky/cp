#include <bits/stdc++.h>
using namespace std;

void setFile(string filename) {
    freopen((filename + ".txt").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

struct Library {
    int nbooks;
    int ndays;
    int nship;
    int index;
    vector<int> books;

    // set after answer calculated
    int avg;
    int reg; // when the library was finished registered
    vector<int> scanned; // scanned books
    int capacity;
};

struct Problem {
    int nbooks;
    int nlibs;
    int ndays;
    vector<int> s;
    vector<Library> libs;
};

Library readLibrary(int i) {
    Library lib;
    lib.index = i;
    scanf("%d%d%d", &lib.nbooks, &lib.ndays, &lib.nship);
    for (int i = 0; i < lib.nbooks; ++i) {
        int temp;
        scanf("%d", &temp);
        lib.books.push_back(temp);
    }
    return lib;
};

Problem readProblem() {
    Problem p;
    scanf("%d%d%d", &p.nbooks, &p.nlibs, &p.ndays);
    for (int i = 0; i < p.nbooks; ++i) {
        int temp;
        scanf("%d", &temp);
        p.s.push_back(temp);
    }
    for (int i = 0; i < p.nlibs; ++i) {
        Library lib = readLibrary(i);
        int score = 0;
        for (auto book : lib.books) {
            score += book;
        }
        lib.avg = score / lib.nbooks;
        p.libs.push_back(lib);
    }
    return p;
}


int judge(const Problem &p, vector<Library> ans) {
    int day = 0;
    int nans = ans.size();
    for (int i = 0; i < nans; ++i) {
        day += ans[i].ndays;
        if (day > p.ndays) day = p.ndays;
        ans[i].reg = day;
    }
    set<int> scanned;
    for (auto lib : ans) {
        int nbooks = 0;
        for (int d = lib.reg; d < p.ndays; ++d) {
            // scan lib.nbooks this day
            for (int i = 0; i < lib.nbooks && nbooks < lib.scanned.size(); ++i, ++nbooks) {
                scanned.insert(lib.scanned[nbooks]);
            }
        }
    }
    int score = 0;
    for (auto book : scanned) {
        score += p.s[book];
    }
    return score;
}

void printAnswer(vector<Library> ans) {
    vector<Library> filtered;
    for (auto lib : ans) {
        if (!lib.scanned.empty()) {
            filtered.push_back(lib);
        }
    }
    int nans = filtered.size();
    printf("%d\n", nans);
    for (int i = 0; i < nans; ++i) {
        printf("%d %d\n", filtered[i].index, filtered[i].scanned.size());
        for (int j = 0; j < filtered[i].scanned.size(); ++j) {
            if (j) putchar(' ');
            printf("%d", filtered[i].scanned[j]);
        }
        putchar('\n');
    }
}
