var
  n,t,best,i:longint;
  a:array[1..20] of longint;
  used,ans:array[1..20] of boolean;

procedure play(k,time:longint);
  begin
    if time>n then exit
	  else if k=t then
	    begin
		  if time>best then
		    begin
			  best:=time; ans:=used;
			end;
		  exit;
		end;
	inc(k); play(k,time);
	used[k]:=true; play(k,time+a[k]); used[k]:=false;
  end;

begin
  repeat
    read(n,t); for i:=1 to t do read(a[i]); readln;
	best:=0; fillchar(used,sizeof(used),false); play(0,0);
	for i:=1 to t do
	  if ans[i] then write(a[i],' ');
	writeln('sum:',best);
  until eof;
end.
