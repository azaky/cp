#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(...) printf(__VA_ARGS__)
// #define A first
// #define B second

char buffer[1000];

struct Contributor {
  int index;
  string name;
  map<string, int> skills;
};

struct Project {
  string name;
  int D, S, B, R;
  vector<pair<string, int>> skills;
};

int main() {
  int C, P;
  scanf("%d %d", &C, &P);

  vector<Contributor> contributors(C);
  vector<Project> projects(P);

  map<string, Contributor> contributorsMap;

  for (int i = 0; i < C; ++i) {
    scanf("%s", buffer);
    contributors[i].name = buffer;
    contributors[i].index = i;
    int K;
    scanf("%d", &K);
    for (int j = 0; j < K; ++j) {
      int level;
      scanf("%s%d", buffer, &level);
      contributors[i].skills[buffer] = level;
    }
    contributorsMap[contributors[i].name] = contributors[i];
  }

  for (int i = 0; i < P; ++i) {
    scanf("%s", buffer);
    projects[i].name = buffer;
    scanf("%d%d%d%d", &projects[i].D, &projects[i].S, &projects[i].B, &projects[i].R);
    for (int j = 0; j < projects[i].R; ++j) {
      int level;
      scanf("%s%d", buffer, &level);
      projects[i].skills.push_back({buffer, level});
    }
  }

  // Randomize projects.
  random_shuffle(projects.begin(), projects.end());

  // TODO: ideas for sorting:
  // - based on "easiest" projects
  // - then based on S (score)
  // - then based on B (best before)

  // Assign projects to contributors.

  // <name, <assignments>>
  vector<pair<string, vector<string>>> assignments;

  vector<int> lastAvailable(C);
  for (int i = 0; i < P; ++i) {
    Project& project = projects[i];

    bool possible = true;
    vector<int> cs(project.skills.size());

    // ASSUME THERE'S NO MENTORSHIP.
    vector<bool> assigned(C, false);
    for (int k = 0; k < project.skills.size(); ++k) {
      string skill = project.skills[i].first;
      int level = project.skills[i].second;
      // Pick contributors with more specific skill set first.
      // Then pick contributors with smaller skill level.
      int best = -1;
      for (int j = 0; j < C; ++j) {
        if (assigned[j]) {
          continue;
        }
        if (contributors[j].skills.find(skill) == contributors[j].skills.end()) {
          continue;
        }
        if (contributors[j].skills[skill] < level) {
          continue;
        }
        int clevel = contributors[j].skills[skill];
        if (best == -1 ||
          contributors[j].skills.size() < contributors[best].skills.size() ||
          (contributors[j].skills.size() == contributors[best].skills.size() &&
            clevel < contributors[best].skills[skill])) {
          best = j;
        }
      }
      if (best == -1) {
        possible = false;
        break;
      }
      assigned[best] = true;
      cs[k] = best;
    }

    if (!possible) {
      continue;
    }

    int startDay = 0;
    for (int c : cs) {
      if (lastAvailable[c] > startDay) {
        startDay = lastAvailable[c];
      }
    }
    for (int c : cs) {
      lastAvailable[c] = startDay + project.D;
    }

    vector<string> contributorsName;
    for (int c : cs) {
      contributorsName.push_back(contributors[c].name);
    }

    assignments.push_back({project.name, contributorsName});
  }

  // Print assignments.
  printf("%lu\n", assignments.size());
  for (int i = 0; i < assignments.size(); ++i) {
    printf("%s\n", assignments[i].first.c_str());
    for (int j = 0; j < assignments[i].second.size(); ++j) {
      printf("%s", assignments[i].second[j].c_str());
      if (j < assignments[i].second.size() - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}
