#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(...) fprintf(stderr, __VA_ARGS__)
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

int calculateScore(vector<Contributor> contributors, vector<Project> projects, vector<pair<string, vector<string>>> assignments) {
  int C = contributors.size();
  int P = projects.size();

  map<string, Contributor> contributorsMap;
  map<string, Project> projectsMap;
  for (int i = 0; i < P; ++i) {
    projectsMap[projects[i].name] = projects[i];
  }
  for (int i = 0; i < C; ++i) {
    contributorsMap[contributors[i].name] = contributors[i];
  }

  vector<int> lastAvailable(C);
  int totalScore = 0;

  for (auto& p : assignments) {
    Project& project = projectsMap[p.first];

    map<string, int> skillSet;
    for (auto& c : p.second) {
      Contributor& contributor = contributorsMap[c];
      for (auto& s : contributor.skills) {
        skillSet[s.first] = max(skillSet[s.first], s.second);
      }
    }

    int startDay = 0;
    bool fulfilled = true;
    set<int> contributorsSet;
    assert(project.skills.size() == p.second.size());
    for (int i = 0; i < project.skills.size(); ++i) {
      Contributor& contributor = contributorsMap[p.second[i]];

      if (contributorsSet.count(contributor.index) > 0) {
        debug("Warning: Project %s has duplicated contributors: %s\n", project.name.c_str(), contributor.name.c_str());
        fulfilled = false;
        break;
      }

      if (startDay < lastAvailable[contributor.index]) {
        startDay = lastAvailable[contributor.index];
      }

      string skill = project.skills[i].first;
      int level = project.skills[i].second;

      if (contributor.skills.find(skill) == contributor.skills.end()) {
        fulfilled = false;
        break;
      }

      // Level >= project.skill
      if (contributor.skills[skill] >= level) {
        continue;
      }

      // Level == project.skill - 1: need a mentor
      if (contributor.skills[skill] == level - 1) {
        assert(skillSet.find(skill) != skillSet.end());
        if (skillSet[skill] >= level) {
          continue;
        }
        fulfilled = false;
        break;
      }
    }
    if (!fulfilled) {
      debug("Warning: Project %s is not fulfilled.\n", p.first.c_str());
      continue;
    }

    for (auto& c : p.second) {
      Contributor& contributor = contributorsMap[c];
      lastAvailable[contributor.index] = startDay + project.D;
    }
    int lastDay = startDay + project.D;
    // lastDay == project.B -> project.R
    // lastDay == project.B+1 -> project.R-1
    int score = lastDay <= project.B ? project.S : project.S - (lastDay - project.B);
    if (score < 0) {
      score = 0;
    }
    // debug("Project %s: startDay = %d: score = %d\n", p.first.c_str(), startDay, score);
    totalScore += score;

    // Learning
    for (int i = 0; i < project.skills.size(); ++i) {
      Contributor& contributor = contributorsMap[p.second[i]];
      string skill = project.skills[i].first;
      int level = project.skills[i].second;
      if (contributor.skills[skill] <= level) {
        int newSkill = contributor.skills[skill] + 1;
        // Update both just to be safe.
        contributorsMap[contributor.name].skills[skill] = newSkill;
        contributors[contributor.index].skills[skill] = newSkill;
      }
    }
  }
  return totalScore;
}

int main() {
  int C, P;
  scanf("%d%d", &C, &P);
  // debug("here");

  vector<Contributor> contributors(C);
  vector<Project> projects(P);

  map<string, Contributor> contributorsMap;

  for (int i = 0; i < C; ++i) {
    int K;
    // debug("here");
    scanf("%s%d", buffer, &K);
    contributors[i].name = buffer;
    contributors[i].index = i;
    // debug("contributor[%d]: %s\n", i, contributors[i].name.c_str());
    for (int j = 0; j < K; ++j) {
      int level;
      scanf("%s%d", buffer, &level);
      contributors[i].skills[buffer] = level;
    }
    contributorsMap[contributors[i].name] = contributors[i];

    // debug("contributor[%d]: %s\n", i, contributors[i].name.c_str());
  }

  for (int i = 0; i < P; ++i) {
    scanf("%s%d%d%d%d", buffer, &projects[i].D, &projects[i].S, &projects[i].B, &projects[i].R);
    projects[i].name = buffer;
    for (int j = 0; j < projects[i].R; ++j) {
      int level;
      scanf("%s%d", buffer, &level);
      projects[i].skills.push_back({ buffer, level });
    }
  }

  vector<Contributor> originalContributors = contributors;
  vector<Project> originalProjects = projects;

  // debug("done reading\n");

  // TODO: ideas for sorting:
  // - based on "easiest" projects
  // - then based on S (score)
  // - then based on B (best before)
  sort(projects.begin(), projects.end(), [](Project& a, Project& b) {
    // Sort by total skill level.
    int aTotal = 0;
    for (auto& s : a.skills) {
      aTotal += s.second;
    }
    int bTotal = 0;
    for (auto& s : b.skills) {
      bTotal += s.second;
    }
    return aTotal < bTotal;
    // if (a.skills.size() != b.skills.size()) {
    //   return a.skills.size() < b.skills.size();
    // }
    // return a.S - a.D > b.S - b.D;
    // return a.B < b.B;
  });

  // Assign projects to contributors.

  // <name, <assignments>>
  vector<pair<string, vector<string>>> assignments;

  vector<int> lastAvailable(C);
  for (int i = 0; i < P; ++i) {
    // debug("project[%d]: %s\n", i, projects[i].name.c_str());

    Project& project = projects[i];

    bool possible = true;
    vector<int> cs(project.skills.size());

    map<string, int> skillSet;
    vector<bool> assigned(C, false);

    // Assign contributor from easiest skill first.
    vector<pair<int,int>> orders;
    for (int j = 0; j < project.skills.size(); ++j) {
      orders.push_back({ project.skills[j].second, j });
    }
    sort(orders.begin(), orders.end(), [](pair<int,int>& a, pair<int,int>& b) {
      return a.first < b.first;
    });

    for (auto z : orders) {
      int k = z.second;

      string skill = project.skills[k].first;
      int level = project.skills[k].second;
      
      int best = -1;
      for (int j = 0; j < C; ++j) {
        if (assigned[j]) {
          continue;
        }
        if (contributors[j].skills.find(skill) == contributors[j].skills.end()) {
          continue;
        }
        int clevel = contributors[j].skills[skill];
        if (clevel < level-1) {
          continue;
        }
        // mentorship
        if (clevel == level-1) {
          if (skillSet.find(skill) == skillSet.end()) {
            continue;
          }
          if (skillSet[skill] < level) {
            continue;
          }
        }

        // if (best == -1 ||
        //   // more specific skill set
        //   contributors[j].skills.size() < contributors[best].skills.size() ||
        //   // same skill set, smaller skill level
        //   (contributors[j].skills.size() == contributors[best].skills.size() &&
        //     clevel < contributors[best].skills[skill])) {
        //   best = j;
        // }
        // // Pick earliest available contributor.
        // if (best == -1 || lastAvailable[j] < lastAvailable[best]) {
        //   best = j;
        // }
        if (best == -1 || clevel < contributors[best].skills[skill]) {
          best = j;
        }
      }
      if (best == -1) {
        possible = false;
        break;
      }
      assigned[best] = true;
      cs[k] = best;

      for (auto& s : contributors[best].skills) {
        skillSet[s.first] = max(skillSet[s.first], s.second);
      }
    }

    if (!possible) {
      // debug("project[%d]: %s not assigned\n", i, projects[i].name.c_str());
      continue;
    }

    // debug("project[%d]: %s assigned\n", i, projects[i].name.c_str());

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

    assignments.push_back({ project.name, contributorsName });

    // Learning
    for (int i = 0; i < project.skills.size(); ++i) {
      Contributor& contributor = contributors[cs[i]];
      string skill = project.skills[i].first;
      int level = project.skills[i].second;
      if (contributor.skills[skill] <= level) {
        int newSkill = contributor.skills[skill] + 1;
        // Update both just to be safe.
        contributorsMap[contributor.name].skills[skill] = newSkill;
        contributors[contributor.index].skills[skill] = newSkill;
      }
    }
  }

  debug("done assigning\n");

  int score = calculateScore(originalContributors, originalProjects, assignments);
  debug("Score: %d\n", score);

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
