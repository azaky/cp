#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

char BASE_PATH[1000];

using namespace std;

struct _probl
{
	int id;
	float timelimit;
	string code;
	string name;
	bool operator<(const _probl& p) const
	{
		return id < p.id;
	}
};

struct _user
{
	int id;
	string login;
	string name;
};


struct user_prob
{
	user_prob() { solved = false; tries = 0;}
	bool solved;
	int  tries;
	int  time;
	int  date;
	int  score;
	string  strdate;
};
typedef map<int,user_prob>	u_p_map;

struct _results
{
	_results() { numsolved = 0; totaltime = 0; }
	int numsolved;
	int userid;
	int totaltime;
	u_p_map prob; // int - problem id
	bool operator<(const _results& r) const
	{
		if(numsolved == r.numsolved)
		{
			return totaltime >= r.totaltime;
		}
		return numsolved < r.numsolved;
	}
};
FILE *input;
FILE *output;

struct subm
{
	int userid;
	int problemid;
	int timestamp;
	int status;
	int language;
	double score;
	double time;
	string date;
	bool Load(int l)
	{
		char buf[1000];
		int len;
		fscanf(input, "%d %d %d %d %d %lf %lf\n", &userid, &problemid, &timestamp, &status, &language, &score, &time );
		fgets(buf, 1000, input);
		len=strlen(buf)-1;
		while(buf[len] == '\n' || buf[len] == '\r' || buf[len] == ' ') {len--;}
		buf[len+1] = 0;
		date = buf;
		for(int t = 0; t < l - 8; t++) fgets(buf, 1000, input);
		return true;
	}
};	

subm	s;
typedef map<int, _probl> p_map;
typedef map<int, _user> u_map;
typedef map<int, _results> r_map; 	// int - user id
typedef priority_queue<_results, vector<_results> > r_que; 	// int - user id
p_map problems;
u_map users;
r_map results;


int main() {		
	input = fdopen(0, "r");
	output = fdopen(6, "w");
//	input = stdin;
//	output = stdout;
	int cont_n = 0, group_n = 0, group_l = 0, subm_n, subm_l;
	int cont_start, cont_end, sol_limit;
	int i;
	char buf[10000];
	
//	contest data	
	fscanf(input, "%d", &cont_n);
	fscanf(input, "%d", &cont_start);
	fscanf(input, "%d", &cont_end);
	fscanf(input, "%d\n", &sol_limit);
	fgets(BASE_PATH, 1000, input);
	int _len=strlen(BASE_PATH)-1;
	while(BASE_PATH[_len] == '\n' || BASE_PATH[_len] == '\r' || BASE_PATH[_len] == ' ') {_len--;}
	BASE_PATH[_len+1] = 0;
		
	for(i = 0; i < cont_n-4; i++)
	{
		fgets(buf, 1000, input);
	}
//	problems data
	int pr_n, pr_l, pr_id, j;
	fscanf(input, "%d", &pr_n);
	fscanf(input, "%d\n", &pr_l);
	int len;
	for(i = 0; i < pr_n; i++)
	{
		fscanf(input, "%d", &pr_id);
		problems[pr_id].id = pr_id;
		fscanf(input, "%f\n", &problems[pr_id].timelimit);
		fgets(buf, 1000, input);
		len=strlen(buf)-1;
		while(buf[len] == '\n' || buf[len] == '\r' || buf[len] == ' ') {len--;}
		buf[len+1] = 0;
		problems[pr_id].code = buf;
		fgets(buf, 1000, input);
		len=strlen(buf)-1;
		while(buf[len] == '\n' || buf[len] == '\r' || buf[len] == ' ') {len--;}
		buf[len+1] = 0;
		problems[pr_id].name = buf;
		for(j = 0; j < pr_l - 4; j++)			
			fgets(buf, 1000, input);
	}

//	users data
	int u_n, u_l, u_id;
	fscanf(input, "%d", &u_n);
	fscanf(input, "%d", &u_l);
	for(i = 0; i < u_n; i++)
	{
		fscanf(input, "%d\n", &u_id);
		users[u_id].id = u_id;
		fgets(buf, 1000, input);
		len=strlen(buf)-1;
		while(buf[len] == '\n' || buf[len] == '\r' || buf[len] == ' ') {len--;}
		buf[len+1] = 0;
		users[u_id].login = buf;
		fgets(buf, 1000, input);
		len=strlen(buf)-1;
		while(buf[len] == '\n' || buf[len] == '\r' || buf[len] == ' ') {len--;}
		buf[len+1] = 0;
		users[u_id].name = buf;
		for(j = 0; j < u_l - 3; j++)			
			fgets(buf, 1000, input);
	}

//	submissions
	int subm_s;
	fscanf(input, "%d", &subm_s);
	fscanf(input, "%d\n", &subm_l);

	subm s;	

	fprintf(output, "%d\n", subm_s);	// number of rankings
	for(j = 0; j < subm_s; j++)
	{
		fgets(buf, 1000, input);
		results.clear();
		fscanf(input, "%d", &subm_n);
		for(i = 0; i < subm_n; i++)
		{
			s.Load(subm_l);
			if(users.find(s.userid) == users.end()) continue;
			results[s.userid].userid = s.userid;
			if(!results[s.userid].prob[s.problemid].solved)
			{
			
				switch(s.status)
				{
				case 11:
				case 12:
				case 13:
				case 14:
					results[s.userid].prob[s.problemid].tries++;
					break;
					
				case 15:
					results[s.userid].numsolved++;
					results[s.userid].prob[s.problemid].solved = true;
					results[s.userid].prob[s.problemid].date = s.timestamp;
					results[s.userid].prob[s.problemid].strdate = s.date;
					results[s.userid].prob[s.problemid].time = s.timestamp - cont_start;
					results[s.userid].prob[s.problemid].score = (s.timestamp - cont_start 
							+ 60*20*results[s.userid].prob[s.problemid].tries) / 60;
					results[s.userid].totaltime += results[s.userid].prob[s.problemid].score;					
					break;
				}						
			}
		}
		int fields = 5 + problems.size();
		fprintf(output, "%d\n", fields); // number of fields in ranking		
		fprintf(output, "Rank\nUsername\nName\n");
		for(p_map::const_iterator it = problems.begin(); it != problems.end(); it++)
		{
			fprintf(output,"<a href='/%s/problems/%s'>%s</a>\n", BASE_PATH,it->second.code.c_str(),it->second.name.c_str());
		}
		fprintf(output, "Solved\nTime\n"); // names of the fields		
			
		fprintf(output, "%d\n", results.size());
		int counter = 1;

		r_que res;
		int cc=0;

		
		//sort(res.begin(), res.end());		// sort nie dzialal na vectorze to uzylem kolejki
		for(r_map::const_iterator it = results.begin(); it != results.end(); it++)
		{
			res.push(it->second);			
		}
		
		_results it;
//		for(r_map::const_iterator it = results.begin(); it != results.end(); it++)
		while(!res.empty())
		{
			it = res.top();
			res.pop();
			/*
			fprintf(output, "%d\n%s", 
					counter, 			// pos
					users[it.userid].name.c_str()); // user name
			*/
			fprintf(output, "%d\n<a href='/%s/users/%s'>%s</a>\n%s\n", counter, BASE_PATH,users[it.userid].login.c_str(), users[it.userid].login.c_str(),users[it.userid].name.c_str());

			for(p_map::const_iterator pr = problems.begin(); pr != problems.end(); pr++)
			{
				int ind = pr->first;
				
				u_p_map::const_iterator up = it.prob.find(ind);
				if(up != it.prob.end())
				{
					//fprintf(output, "%s (%d)\n", up->second.strdate.c_str(), up->second.tries);
					fprintf(output, "<font color='#00CC00'><b>%d (%d)</b></font>\n", up->second.score, up->second.tries);
					
				}
				else fprintf(output, "-\n");
			}
			
			fprintf(output, "%d\n%d\n",		
					it.numsolved,
				       	it.totaltime);
			
			counter++;
		}
	}
//	fclose(output);
		
	return 0;
}
/*
 * input format:
 *  - contest info
 *  - problems info
 *  - users info
 *  - submissions
 *
 * Contest info:
 * integer N - number of lines.
 * N lines, each with one value:
 * start	// int - timestamp
 * end		// int - timestamp
 * solution limit
 * ...
 *
 * 
 * Problems info:
 * integer N - number of problems
 * integer L - number of lines for each problem
 * N*L lines, each with one value:
 * id		// int
 * timelimit	// float
 * code		// string
 * name		// string
 * ...
 *
 * Users info:
 * integer N - number of users
 * integer L - number of lines for each user
 * N*L lines, each with one value:
 * id		// int
 * login	// string
 * name		// string
 * ...
 * 
 * Submissions:
 * integer S - number of submission series
 * integer L - number of lines for each submission
 * For each serie:
 * info		// string
 * integer N - number of submissions in current serie.
 * N*L lines, each with one value:
 * user id	// int
 * problem id	// int
 * date		// int (timestamp)
 * status	// int
 * language	// int
 * score  	// floating point
 * time   	// floating point
 * string date 	// string
 * ...
 * 
 */

