#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

int tc,np,n,ans,package[2000];
map <string,int> hash;
vector <string> orang;
string _s,ss,s[2000];
stringstream _ss (stringstream::in | stringstream::out);

void add(string _s){
	if (!hash.count(_s)){
		s[np] = _s;
		hash[_s] = np++;
	}
}

int main(){
	scanf("%d\n",&tc);
	while (tc--){
		orang.clear(); hash.clear();
		memset(package,0,sizeof(package));
		np = 0;
		
		scanf("%d\n",&n);
		for (int k=0; k<n; ++k){
			getline(cin,ss);
			_ss << ss;
			while (_ss >> _s){
				if (_s.length()==0) break;
				printf("WOY:%s\n",_s.c_str());
				add(_s); orang.push_back(_s);
			}
			for (int i=1; i<orang.size(); ++i) ++package[hash[orang[i]]];
		}
		
		ans = 0;
		for (int k=1; k<np; ++k)
			if (package[k]>package[ans]) ans = k;
		printf("%s\n",s[ans].c_str());
	}
	return 0;
}
			
