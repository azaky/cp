#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>

using namespace std;

//20
//400*16
//76800

int day[]={31,28,31,30,31,30,31,31,30,31,30,31};
set<int> jam;
map<int,int> hari;

string balik(string in){
	string ret = in;
	reverse(ret.begin(),ret.end());
	return ret;
}

bool isJam(string in){
	int h,m,s;
	if (in.length()==5){
		h=in[0]-'0';m=(in[1]-'0')*10+in[2]-'0';s=(in[3]-'0')*10+in[4]-'0';
	} else if (in.length()==6){
		h=(in[0]-'0')*10+in[1]-'0';m=(in[2]-'0')*10+in[3]-'0';s=(in[4]-'0')*10+in[5]-'0';
	} else {
		return false;
	}
	return (h<24)&&(m<60)&&(s<60);
}

int cekPalin(string in, int a, int b){
	bool fl=true;
	for (int i=a,j=b;((i<j)&&(fl));i++,j--){
		fl=in[i]==in[j];
	}
	return fl;
}

int cekPalin(string in){
	bool fl=true;
	int a=0,b=(in.length()-1);
	for (int i=a,j=b;((i<j)&&(fl));i++,j--){
		fl=in[i]==in[j];
	}
	if (fl)printf("%s\n",in.c_str());
	//printf("  %s %c\n",in.c_str(),(fl?'Y':'N'));
	return fl;
}

int test(string in){
	cout<<in<<endl;
	int ret=0;
	int hum=jam.size();
	//int graa;
	if (in.length()==4){
		if (isJam(string("0")+balik(in))){
			//1-9x2;11x2;0;22
			int tp=int(in[0]-'0')+10*int(in[1]-'0')+60*(int(in[2]-'0')+10*int(in[3]-'0'));
			for (int i=1;i<=9;i++){
				jam.insert(tp+60*i);
				jam.insert(tp+60*(i+12));
			}
			jam.insert(tp+60*(11));
			jam.insert(tp+60*(11+12));
			jam.insert(tp+60*0);
			jam.insert(tp+60*22);
			ret+=22;
		}
	} else if (in.length()==5){
		if (isJam(balik(in))){
			//AM/PM
			ret+=2;
			int tp=int(in[0]-'0')+10*int(in[1]-'0')+60*(int(in[2]-'0')+10*int(in[3]-'0'));
			jam.insert(tp+60*(in[4]-'0'));
			jam.insert(tp+60*(in[4]-'0'+12));
			if (isJam(string("1")+balik(in))){
				ret++;
				jam.insert(tp+60*(in[4]-'0'+10));
			}
			if (isJam(string("2")+balik(in))){
				ret++;
				jam.insert(tp+60*(in[4]-'0'+20));
			}
		}
	} else if (in.length()==6){
		if (isJam(balik(in.substr(0,5)))){
			//AM/PM
			ret+=2;
			int tp=int(in[0]-'0')+10*int(in[1]-'0')+60*(int(in[2]-'0')+10*int(in[3]-'0'));
			int h = (in[4]-'0');
			jam.insert(tp+60*h);
			jam.insert(tp+60*(h+12));
		}
		if (isJam(balik(in))){
			ret++;
			int tp=int(in[0]-'0')+10*int(in[1]-'0')+60*(int(in[2]-'0')+10*int(in[3]-'0'));
			int h = (in[5]-'0') + (in[4]-'0')*10;
			jam.insert(tp+60*h);
			//AM/PM
			if ((0<h)&&(h<13)){
				ret++;
				jam.insert(tp+60*(h+12));
			}
		}
	} else if (in.length()>6){
		if (cekPalin(in,5,in.length()-1)){
			if (isJam(balik(in.substr(0,5)))){
				//AM/PM
				ret+=2;
				int tp=int(in[0]-'0')+10*int(in[1]-'0')+60*(int(in[2]-'0')+10*int(in[3]-'0'));
				int h = (in[4]-'0');
				jam.insert(tp+60*h);
				jam.insert(tp+60*(h+12));
			}
		}
		if (cekPalin(in,6,in.length()-1)){
			if (isJam(balik(in.substr(0,6)))){
				ret++;
				int tp=int(in[0]-'0')+10*int(in[1]-'0')+60*(int(in[2]-'0')+10*int(in[3]-'0'));
				int h = (in[5]-'0') + (in[4]-'0')*10;
				jam.insert(tp+60*h);
				//AM/PM
				if ((0<h)&&(h<13)){
					ret++;
					jam.insert(tp+60*(h+12));
				}
			}
		}
		//return ret;
	} else {
		assert(false);
		ret=0;
	}
	cout<<"=>"<<ret<<endl;
	//if ((jam.size()-hum)!=ret)printf("!!%s = %d vs %d\n",in.c_str(),ret,jam.size()-hum);
	return ret;
}

int proc(int d, int m, int y){
	int ret=0;
	//set day string
	string st_d;
	if (d<10) st_d=string("")+char(d+'0');
	else st_d=string("")+char((d/10)+'0')+char((d%10)+'0');
	string st_dd;
	if (d<10) st_dd=string("")+'0'+char(d+'0');
	else st_dd=string("")+'0';
	//set month string
	string st_m;
	if (m<10) st_m=string("")+char(m+'0');
	else st_m=string("")+char((m/10)+'0')+char((m%10)+'0');
	string st_mm;
	if (m<10) st_mm=string("")+'0'+char(m+'0');
	else st_mm=string("")+'0';
	//set year string
	string st_yy=string("")+char(((y/10)%10)+'0')+char((y%10)+'0');
	//stringstream tp;tp<<y;
	//string st_y=tp.str();
	char buf[1024];
	itoa(y, buf, 10);
	string st_y(buf);
	//cout<<"humbaba"<<st_d<<":"<<st_m<<":"<<st_y<<"\n";
	//cek all combi
	ret+=test(st_d+st_m+st_y);
	ret+=test(st_d+st_m+st_yy);
	if (d<10){
		ret+=test(st_dd+st_m+st_y);
		ret+=test(st_dd+st_m+st_yy);
		if (m<10){
			ret+=test(st_dd+st_mm+st_y);
			ret+=test(st_dd+st_mm+st_yy);
		}
	}
	if (m<10){
		ret+=test(st_d+st_mm+st_y);
		ret+=test(st_d+st_mm+st_yy);
	}
	if (d!=m){
		ret+=test(st_m+st_d+st_y);
		ret+=test(st_m+st_d+st_yy);
		if (d<10){
			ret+=test(st_m+st_dd+st_y);
			ret+=test(st_m+st_dd+st_yy);
			if (m<10){
				ret+=test(st_mm+st_dd+st_y);
				ret+=test(st_mm+st_dd+st_yy);
			}
		}
		if (m<10){
			ret+=test(st_mm+st_d+st_y);
			ret+=test(st_mm+st_d+st_yy);
		}
	}
	return ret;
}

bool proc2(int d, int m, int y, int h, int mi, int s){
	bool ret=false;
	//set day string
	string st_d;
	if (d<10) st_d=string("")+char(d+'0');
	else st_d=string("")+char((d/10)+'0')+char((d%10)+'0');
	string st_dd;
	if (d<10) st_dd=string("")+'0'+char(d+'0');
	else st_dd=string("")+'0';
	//set month string
	string st_m;
	if (m<10) st_m=string("")+char(m+'0');
	else st_m=string("")+char((m/10)+'0')+char((m%10)+'0');
	string st_mm;
	if (m<10) st_mm=string("")+'0'+char(m+'0');
	else st_mm=string("")+'0';
	//set year string
	string st_yy=string("")+char(((y/10)%10)+'0')+char((y%10)+'0');
	char buf[1024];
	itoa(y, buf, 10);
	string st_y(buf);
	//set time string
	string st_mis;
	st_mis=string("")+char((mi/10)+'0')+char((mi%10)+'0')+char((s/10)+'0')+char((s%10)+'0');
	string st_h;
	if (h<10)st_h=string("")+char(h+'0')+st_mis;
	else st_h=string("")+char((h/10)+'0')+char((h%10)+'0')+st_mis;
	string st_hh;
	if (h<10)st_hh=string("")+'0'+char(h+'0')+st_mis;
	else st_hh=string("")+'0'+st_mis;
	string st_h2;int h2=(h>12?h-12:h);
	if (h>12)st_h2=string("")+(char((h2/10)+'0'))+char((h2%10)+'0')+st_mis;
	else st_h2=string("")+'0'+st_mis;
	//if (h>21)cout<<" >"<<st_h2<<endl;
	//cek all combi
	ret=ret||cekPalin(st_d+st_m+st_y+st_h);
	ret=ret||cekPalin(st_d+st_m+st_yy+st_h);
	if (d<10){
		ret=ret||cekPalin(st_dd+st_m+st_y+st_h);
		ret=ret||cekPalin(st_dd+st_m+st_yy+st_h);
		if (m<10){
			ret=ret||cekPalin(st_dd+st_mm+st_y+st_h);
			ret=ret||cekPalin(st_dd+st_mm+st_yy+st_h);
		}
	}
	if (m<10){
		ret=ret||cekPalin(st_d+st_mm+st_y+st_h);
		ret=ret||cekPalin(st_d+st_mm+st_yy+st_h);
	}
	if (d!=m){
		ret=ret||cekPalin(st_m+st_d+st_y+st_h);
		ret=ret||cekPalin(st_m+st_d+st_yy+st_h);
		if (d<10){
			ret=ret||cekPalin(st_m+st_dd+st_y+st_h);
			ret=ret||cekPalin(st_m+st_dd+st_yy+st_h);
			if (m<10){
				ret=ret||cekPalin(st_mm+st_dd+st_y+st_h);
				ret=ret||cekPalin(st_mm+st_dd+st_yy+st_h);
			}
		}
		if (m<10){
			ret=ret||cekPalin(st_mm+st_d+st_y+st_h);
			ret=ret||cekPalin(st_mm+st_d+st_yy+st_h);
		}
	}
	return ret;
}

int main(){
	int t,y,hsl,hsl2;
	// scanf("%d",&t);
	t = 1;
	for (int test=0;test<t;test++){
		// scanf("%d",&y);
		hsl=0;hsl2=0;
		int tmp;
		int m=9,d=23;
		scanf("%d%d%d", &d, &m, &y);
		d--; m--;
		//for (int m=0;m<1;m++){
		//for (int m=2;m<2;m++){
		hari.clear();
		int humbaba=0;
		// for (int m=0;m<12;m++){
			// for (int d=0;d<day[m];d++){
			//for (int d=1;d<1;d++){
			//for (int d=0;d<day[m];d++){
				jam.clear();
				tmp=proc(d+1,m+1,y);
				//if (tmp!=jam.size())printf("!%d:%d:%d = %d vs %d\n",d+1,m+1,y,tmp,jam.size());
				hsl2+=tmp;
				hsl+=jam.size();
				// hari[humbaba+d]=jam.size();
			// }
			// humbaba+=day[m];
		// }
		// if (y%4==0){
		// 	if (y%100==0){
		// 		if (y%400==0){
		// 			jam.clear();
		// 			tmp=proc(29,2,y);
		// 			if (tmp!=jam.size())printf("!%d:%d:%d = %d vs %d\n",29,2,y,tmp,jam.size());
		// 			hsl2+=tmp;
		// 			hsl+=jam.size();
		// 		}
		// 	} else {
		// 		jam.clear();
		// 		tmp=proc(29,2,y);
		// 		if (tmp!=jam.size())printf("!%d:%d:%d = %d vs %d\n",29,2,y,tmp,jam.size());
		// 		hsl2+=tmp;
		// 		hsl+=jam.size();
		// 	}
		// }
		printf("test\n");
		int hsl3=0;
		// humbaba=0;
		// for (int m=0;m<1;m++){
		// 	for (int d=0;d<1;d++){
		// 		int graa=0;
		// 		for (int h=0;h<24;h++){
		// 			for (int mi=0;mi<60;mi++){
		// 				for (int s=0;s<60;s++){
		// 					graa+=(proc2(d+1,m+1,y,h,mi,s)?1:0);
		// 				}
		// 			}
		// 		}
		// 		hsl3+=graa;
		// 		printf("day = %d:%d:%d\n",d+1,m+1,y);
		// 		printf("  !%d vs %d\n",graa,hari[humbaba+d]);
		// 	}
		// 	humbaba+=day[m];
		// }
		printf("[%d] %d vs %d\n",hsl3,hsl2,hsl);
	}
}