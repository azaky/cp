#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(...) fprintf(stderr, __VA_ARGS__)
// #define A first
// #define B second

char buffer[100000];

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

  for (auto &p : assignments) {
    Project &project = projectsMap[p.first];

    map<string,int> skillSet;
    for (auto &c : p.second) {
      Contributor &contributor = contributorsMap[c];
      for (auto &s : contributor.skills) {
        skillSet[s.first] = max(skillSet[s.first], s.second);
      }
    }

    int startDay = 0;
    bool fulfilled = true;
    set<int> contributorsSet;
    assert(project.skills.size() == p.second.size());
    for (int i = 0; i < project.skills.size(); ++i) {
      Contributor &contributor = contributorsMap[p.second[i]];

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

    for (auto &c : p.second) {
      Contributor &contributor = contributorsMap[c];
      lastAvailable[contributor.index] = startDay + project.D;
    }
    int lastDay = startDay + project.D;
    // lastDay == project.B -> project.R
    // lastDay == project.B+1 -> project.R-1
    int score = lastDay <= project.B ? project.S : project.S - (lastDay - project.B);
    if (score < 0) {
      score = 0;
    }
    debug("Project %s: startDay = %d: score = %d\n", p.first.c_str(), startDay, score);
    totalScore += score;

    // Learning
    for (int i = 0; i < project.skills.size(); ++i) {
      Contributor& contributor = contributorsMap[p.second[i]];
      string skill = project.skills[i].first;
      int level = project.skills[i].second;
      if (contributor.skills[skill] <= level) {
        int newSkill = contributor.skills[skill]+1;
        // Update both just to be safe.
        contributorsMap[contributor.name].skills[skill] = newSkill;
        contributors[contributor.index].skills[skill] = newSkill;
      }
    }
  }
  return totalScore;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    debug("usage: ./scorer <inputfile> <outputfile>");
    return 1;
  }

  FILE *fin = fopen(argv[1], "r");
  FILE *fout = fopen(argv[2], "r");

  int C, P;
  fscanf(fin, "%d%d", &C, &P);
  // debug("here");

  vector<Contributor> contributors(C);
  vector<Project> projects(P);

  map<string, Contributor> contributorsMap;
  map<string, Project> projectsMap;

  for (int i = 0; i < C; ++i) {
    int K;
    // debug("here");
    fscanf(fin, "%s%d", buffer, &K);
    contributors[i].name = buffer;
    contributors[i].index = i;
    // debug("contributor[%d]: %s\n", i, contributors[i].name.c_str());
    for (int j = 0; j < K; ++j) {
      int level;
      fscanf(fin, "%s%d", buffer, &level);
      contributors[i].skills[buffer] = level;
    }
    contributorsMap[contributors[i].name] = contributors[i];

    // debug("contributor[%d]: %s\n", i, contributors[i].name.c_str());
  }

  for (int i = 0; i < P; ++i) {
    fscanf(fin, "%s%d%d%d%d", buffer, &projects[i].D, &projects[i].S, &projects[i].B, &projects[i].R);
    projects[i].name = buffer;
    for (int j = 0; j < projects[i].R; ++j) {
      int level;
      fscanf(fin, "%s%d", buffer, &level);
      projects[i].skills.push_back({buffer, level});
    }
    projectsMap[projects[i].name] = projects[i];
  }

  vector<pair<string, vector<string>>> assignments;
  int M;

  fgets(buffer, sizeof(buffer), fout);
  if (sscanf(buffer, "%d", &M) != 1) {
    debug("Error: invalid number of assignments: %s\n", buffer);
    return 1;
  }

  for (int i = 0; i < M; ++i) {
    fgets(buffer, sizeof(buffer), fout);
    string projectName = buffer;
    projectName.pop_back();
    if (projectsMap.count(projectName) == 0) {
      debug("Error: project name not found: %s\n", projectName.c_str());
      return 1;
    }
    fgets(buffer, sizeof(buffer), fout);
    vector<string> contributors;
    // split buffer by space
    char *p = strtok(buffer, " ");
    while (p != NULL) {
      string c = p;
      if (c.back() == '\n') {
        c.pop_back();
      }
      contributors.push_back(c);
      p = strtok(NULL, " ");
    }
    assignments.push_back({projectName, contributors});
  }

  int score = calculateScore(contributors, projects, assignments);
  debug("Score: %d\n", score);

  return 0;
}
