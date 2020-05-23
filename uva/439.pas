const
  next:array[1..8,1..2] of longint=((1,2),(1,-2),(-1,2),(-1,-2),(2,1),(2,-1),(-2,1),(-2,-1));
  map:array['a'..'h'] of longint = (1,2,3,4,5,6,7,8);
  num:array['1'..'8'] of longint = (1,2,3,4,5,6,7,8);

var
  i1,j1,i0,j0,ik,jk,qtake,qsave,cur,a,b,c,d,dir:longint;
  s:string[5];
  wait:array[1..8,1..8] of boolean;
  temp:array[1..8,1..8] of longint;
  best:array[1..8,1..8,1..8,1..8] of longint;
  queue:array[1..1000,1..2] of longint;

begin
  for i1:=1 to 8 do
    for j1:=1 to 8 do
	  begin
		fillchar(wait,sizeof(wait),false);
		fillchar(temp,sizeof(temp),255);
		queue[1][1]:=i1; queue[1][2]:=j1; qtake:=1; qsave:=1; wait[i1,j1]:=true; temp[i1,j1]:=0;
		repeat
		  i0:=queue[qtake][1]; j0:=queue[qtake][2]; wait[i0,j0]:=false; cur:=temp[i0,j0]+1;
		  for dir:=1 to 8 do
		    begin
			  ik:=i0+next[dir][1]; jk:=j0+next[dir][2];
			  if (ik<=0) or (jk<=0) or (ik>8) or (jk>8) then continue
			    else if (temp[ik,jk]<0) or (temp[ik,jk]>cur) then temp[ik,jk]:=cur
				  else continue;
			  if wait[ik,jk] then continue else wait[ik,jk]:=true;
			  inc(qsave); queue[qsave][1]:=ik; queue[qsave][2]:=jk;
			end;
		  inc(qtake);
		until qtake>qsave;
		best[i1,j1]:=temp;
	  end;
  repeat
    readln(s); a:=map[s[1]]; b:=num[s[2]]; c:=map[s[4]]; d:=num[s[5]];
	writeln('To get from ',s[1],s[2],' to ',s[4],s[5],' takes ',best[a,b,c,d],' knight moves.');
  until eof;
end.
