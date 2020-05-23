#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

char BASE_PATH[16];

const int PSM = 10000000;

using namespace std;

struct _probl
{
	_probl() {opt=false;}
	int id;
	float timelimit;
	int opt;
	int pset;
	int starttime;
	int endtime;
	double coef;
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

typedef vector<int> pl;

struct _prhlp
{
	_prhlp() { count=0; subms=0; problems.clear();}
	int count;
	int subms;
	vector<int> problems;
};

struct user_prob
{
	user_prob() { solved = false; tries = 0; bonus=0;}
	bool opt;
	bool solved;
	double  score;
	int userid;
	int	 tries;
	double  time;
	int  rank;
	double modifier;
	double bonus;
	double points;
	int  date;
	string  strdate;
	bool operator<(const user_prob& r) const
	{
		if (opt)
		{
			if (score==r.score)
				return date > r.date;
			return score < r.score;
		}
		else
		{
			if (time==r.time)
				return date > r.date;
			return time > r.time;
		}
	}
};

typedef vector<user_prob> ul;
typedef map<int, double> psl;
typedef map<int,user_prob>	u_p_map;

struct _uresults
{
	_uresults() { numsolved = 0;}
	int userid;
	double totalscore;
	int numsolved;
	u_p_map prob; // int - problem id
	psl psets;
	bool operator<(const _uresults& r) const
	{
		return totalscore < r.totalscore;
	}
};

struct _presults
{
	_presults() { numsolved = 0; }
	int problemid;
	int numsolved;
	double coef;
	u_p_map user; // int - user id
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
	int pset;
	bool Load(int l)
	{
		char buf[1000];
		int len;
		fscanf(input, "%d %d %d %d %d %lf %lf\n", &userid, &problemid,
			       	&timestamp, &status, &language, &score, &time );
		fgets(buf, 1000, input);
		len=strlen(buf)-1;
		while(buf[len] == '\n' || buf[len] == '\r' || buf[len] == ' ') {len--;}
		buf[len+1] = 0;
		date = buf;
		for(int t=0; t < l - 8; t++) fgets(buf, 1000, input);
		return true;
	}
};	

struct _plang
{
	int language;
	int userid;
	int score;
	int problemid;
};

subm	s;
typedef map<int, _probl> p_map;
typedef map<int, _user> u_map;
typedef map<int, _uresults> ur_map; 	// int - user id
typedef map<int, _presults> pr_map; 	// int - problem id
typedef map<int, _prhlp> pset_map;
typedef map<int, subm> s_map;
typedef priority_queue<_uresults, vector<_uresults> > r_que; 	// int - user id
p_map problems;
u_map users;
ur_map uresults;
pr_map presults;
pset_map psets;


int main()
{		
	#ifdef ONLINE_JUDGE
		input = fdopen(0, "r");
		output = fdopen(6, "w");
	#else
		input = stdin;
		output = stdout;
	#endif
	int cont_n = 0, subm_n, subm_l;
	int cont_start, cont_end, sol_limit;
	int i;
	char buf[10000];
	
//	contest data	
	fscanf(input, "%d", &cont_n);
	fscanf(input, "%d", &cont_start);
	fscanf(input, "%d", &cont_end);
	fscanf(input, "%d\n", &sol_limit);
	fgets(BASE_PATH, 1000, input);
	int len=strlen(BASE_PATH)-1;
	while(BASE_PATH[len] == '\n' || BASE_PATH[len] == '\r' || BASE_PATH[len] == ' ') {len--;}
	BASE_PATH[len+1] = 0;
		
	for(i = 0; i < cont_n-4; i++)
	{
		fgets(buf, 1000, input);
	}
//	problems data
	int pr_n, pr_l, pr_id, j;
	fscanf(input, "%d", &pr_n);
	fscanf(input, "%d\n", &pr_l);
	for(i = 0; i < pr_n; i++)
	{
		fscanf(input, "%d", &pr_id);
		while (problems.find(pr_id)!=problems.end()) pr_id+=PSM;
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

		fscanf(input, "%d\n", &problems[pr_id].opt);

		fgets(buf, 1000, input);
		len=strlen(buf)-1;
		while(buf[len] == '\n' || buf[len] == '\r' || buf[len] == ' ') {len--;}
		buf[len+1] = 0;
		problems[pr_id].pset =1;
		
		fscanf(input, "%d\n", &problems[pr_id].starttime);
		fscanf(input, "%d\n", &problems[pr_id].endtime);
		fgets(buf, 1000, input);
		if (sscanf(buf, "%lf", &problems[pr_id].coef)<1)
		{
			fprintf(output, "HTML<h3>Contest judge error.</h3><p>In the 'Edit contest' menu, please fill in the 'Info' field for each problem with a floating point numerical value.");
			return 0;
		}

		for(j = 0; j < pr_l - 9; j++)
			fgets(buf, 1000, input);

	}
	
//creating problemsets
	for(p_map::const_iterator it = problems.begin(); it != problems.end(); it++)
			psets[it->second.pset].problems.push_back(it->second.id);

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

	fgets(buf, 1000, input);
	uresults.clear();
	presults.clear();
	fscanf(input, "%d", &subm_n);
	for(i = 0; i < subm_n; i++)
	{
		s.Load(subm_l);
		if(users.find(s.userid) == users.end()) continue;
		if(problems.find(s.problemid) == problems.end()) continue;
		if (problems[s.problemid].opt==1) s.score=1/s.score;
		while (problems[s.problemid].endtime<s.timestamp) s.problemid+=PSM;
		uresults[s.userid].prob[s.problemid].tries++;
	//	presults[s.problemid].user[s.userid].tries++;
		if(s.status!=15 || (problems[s.problemid].opt && s.score==0)) continue; //void submission

		uresults[s.userid].userid = s.userid;
		presults[s.problemid].problemid = s.problemid;
		if(!uresults[s.userid].prob[s.problemid].solved || uresults[s.userid].prob[s.problemid].score<s.score)
		{
			if (!uresults[s.userid].prob[s.problemid].solved)
			{	
				presults[s.problemid].numsolved++;
				uresults[s.userid].prob[s.problemid].solved = true;
				presults[s.problemid].user[s.userid].solved = true;
			}
			uresults[s.userid].prob[s.problemid].opt = problems[s.problemid].opt;
			presults[s.problemid].user[s.userid].opt = problems[s.problemid].opt;
			uresults[s.userid].prob[s.problemid].date = s.timestamp;
			presults[s.problemid].user[s.userid].date = s.timestamp;
			uresults[s.userid].prob[s.problemid].strdate = s.date;
			presults[s.problemid].user[s.userid].strdate = s.date;
			uresults[s.userid].prob[s.problemid].score = s.score;
			presults[s.problemid].user[s.userid].score = s.score;
			uresults[s.userid].prob[s.problemid].time = s.time;
			presults[s.problemid].user[s.userid].time = s.time;
			uresults[s.userid].prob[s.problemid].userid = s.userid;
			presults[s.problemid].user[s.userid].userid = s.userid;
		}
		if (!problems[s.problemid].opt && uresults[s.userid].prob[s.problemid].time > s.time)
		{
			uresults[s.userid].prob[s.problemid].time = s.time;
			presults[s.problemid].user[s.userid].time = s.time;
		}
	}
	// assignment of coefs to problems
	for(p_map::const_iterator it = problems.begin(); it != problems.end(); it++)
	{
		if (it->second.opt) continue;
		psets[it->second.pset].count++;
		psets[it->second.pset].subms+=presults[it->second.id].numsolved;
	}
	for(int i=2; psets.find(i)!=psets.end(); i++)
	{
		psets[i].count+=psets[i-1].count;
		psets[i].subms+=psets[i-1].subms;
	}
/*
	for(p_map::const_iterator it = problems.begin(); it != problems.end(); it++)
	{
		presults[it->second.id].coef=it->second.coef;
		if (it->second.opt)  // challenge
		{
			ul v;
			for (u_p_map::const_iterator ut=presults[it->second.id].user.begin();
			ut!=presults[it->second.id].user.end(); ut++)
				v.push_back(ut->second);
			sort(v.begin(), v.end());
			int r=v.size();
			for (ul::const_iterator ut=v.begin(); ut!=v.end(); ut++)
			{	
				uresults[ut->userid].prob[it->second.id].rank=r;
				presults[it->second.id].user[ut->userid].rank=r--;
				if (presults[it->second.id].user[ut->userid].score < presults[it->second.id].user[v[v.size()-1].userid].score)
					presults[it->second.id].user[ut->userid].score /= presults[it->second.id].user[v[v.size()-1].userid].score;
				else
					presults[it->second.id].user[ut->userid].score = presults[it->second.id].user[v[v.size()-1].userid].score / presults[it->second.id].user[ut->userid].score;
			}
		}
		else //classical
		{
			ul v;
			for (u_p_map::const_iterator ut=presults[it->second.id].user.begin();
			ut!=presults[it->second.id].user.end(); ut++)
				v.push_back(ut->second);
			sort(v.begin(), v.end());
			int r=1;
			for (ul::const_iterator ut=v.end()-1; ut+1!=v.begin(); ut--)
			{	
				int cr;
				if ((ut+1)==v.end() || uresults[ut->userid].prob[it->second.id].time !=
					uresults[(ut+1)->userid].prob[it->second.id].time)
					cr= r;
				else cr = presults[it->second.id].user[(ut+1)->userid].rank;
				uresults[ut->userid].prob[it->second.id].rank=cr;
				presults[it->second.id].user[ut->userid].rank=cr;

// Note: uncomment the lines below if you wish to penalize slow submissions.
// The expression gives the "bonus" for a submission which is ranked cr \in {1,2,3,...} in terms of runtime.
//				uresults[ut->userid].prob[it->second.id].bonus= 
//				presults[it->second.id].user[ut->userid].bonus= -0.5 >? (0.11-0.01*cr);
				r++;
			}
		}
		for (u_p_map::const_iterator ut=presults[it->second.id].user.begin();
		ut!=presults[it->second.id].user.end(); ut++)
		{
			uresults[ut->second.userid].prob[it->second.id].modifier=1;
			presults[it->second.id].user[ut->second.userid].modifier=1;
		}
	}
*/
	//output ranklists

	fprintf(output, "%d\n", 1);	// number of rankings
	{
		int i=1;
		int fields = 5 + psets[i].problems.size();
		fprintf(output, "%d\n", fields);	
		fprintf(output, "Rank\nUsername\nName\n");
		for(pl::const_iterator it = psets[i].problems.begin(); it != psets[i].problems.end(); it++)
			fprintf(output, "<a href='/%s/problems/%s'>%s</a>\n", BASE_PATH, problems[*it].code.c_str(),problems[*it].code.c_str());
		fprintf(output, "Solved\nScore\n");

		// calculate total scores
		for(u_map::const_iterator it = users.begin(); it != users.end(); it++)
		{	
			uresults[it->second.id].totalscore=0;
			uresults[it->second.id].numsolved=0;
		}

		for(pl::const_iterator it = psets[i].problems.begin(); it != psets[i].problems.end(); it++)
			for (u_p_map::const_iterator ut=presults[*it].user.begin();	ut!=presults[*it].user.end(); ut++)
			{
				//uresults[ut->first].prob[*it].points=presults[*it].user[ut->first].points=presults[*it].coef*presults[*it].user[ut->first].modifier*((problems[*it].opt)?presults[*it].user[ut->first].score:1)+presults[*it].user[ut->first].bonus;
			    uresults[ut->first].prob[*it].points=presults[*it].user[ut->first].points=presults[*it].user[ut->first].score;
			    uresults[ut->first].totalscore+=uresults[ut->first].prob[*it].points;
				uresults[ut->first].numsolved++;
			}
		for(ur_map::const_iterator it = uresults.begin(); it != uresults.end(); it++)
			uresults[it->first].psets[i]=uresults[it->first].totalscore;
			

		r_que res;

		for(ur_map::const_iterator it = uresults.begin(); it != uresults.end(); it++)
			if (it->second.numsolved>0)
				res.push(it->second);			
		fprintf(output, "%d\n", res.size());
		
		_uresults it;
		int counter = 1, rnum=1;
		double prvp=0;
		while(!res.empty())
		{
			it = res.top(); res.pop();
			if (prvp!= it.totalscore) rnum=counter;
			
			fprintf(output, "%d\n<a href='/%s/users/%s'>%s</a>\n%s\n", rnum, BASE_PATH,users[it.userid].login.c_str(), users[it.userid].login.c_str(),users[it.userid].name.c_str());

			int sss=0;
			
			for(pl::const_iterator pt = psets[i].problems.begin(); pt != psets[i].problems.end(); pt++)
			{
				if (presults[*pt].user.find(it.userid)!=presults[*pt].user.end())
				{
				  if (presults[*pt].user[it.userid].points==100)
				  {
				    fprintf(output, "<font color='#00CC00'><b>%.2f</b></font>",	presults[*pt].user[it.userid].score);
				    sss++;
                  }
                  else fprintf(output,"<font color='#FF0033'><b>%.2f</b></font>", presults[*pt].user[it.userid].score);
				  
				  //fprintf(output, " (%d)", presults[*pt].user[it.userid].rank);
				  if (presults[*pt].user[it.userid].rank<10)
						fprintf(output, "&nbsp;");
				  //if (presults[*pt].user[it.userid].modifier!=1)
					//	fprintf(output, "*%.0f", presults[*pt].user[it.userid].modifier);

					fprintf(output, "\n");
				}
				else fprintf(output, "<b>-</b>\n");
			}
			
            fprintf(output, "%d\n%.2f\n",	sss, it.totalscore);
			
			counter++;
			prvp =  it.totalscore;
		}
	}
	fclose(output);
		
	return 0;
}
