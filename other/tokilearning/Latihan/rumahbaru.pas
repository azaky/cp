var
  n,i,xx,yy,ans:longint;
  home,up,down,left,right:array[-101..101,-101..101] of boolean;
  x,y:array[1..50] of longint;

begin
  fillchar(home,sizeof(home),false);
  fillchar(up,sizeof(up),false);
  fillchar(down,sizeof(down),false);
  fillchar(left,sizeof(left),false);
  fillchar(right,sizeof(right),false);
  readln(n);
  for i:=1 to n do read(x[i]);
  for i:=1 to n do read(y[i]);
  for i:=1 to n do home[x[i],y[i]]:=true;
  for xx:=-100 to 100 do
    for yy:=-100 to 100 do
	  if home[xx,yy-1] then down[xx,yy]:=true
	    else down[xx,yy]:=down[xx,yy-1];
  for xx:=-100 to 100 do
    for yy:=100 downto -100 do
	  if home[xx,yy+1] then up[xx,yy]:=true
	    else up[xx,yy]:=up[xx,yy+1];
  for yy:=-100 to 100 do
    for xx:=-100 to 100 do
	  if home[xx-1,yy] then left[xx,yy]:=true
	    else left[xx,yy]:=left[xx-1,yy];
  for yy:=-100 to 100 do
    for xx:=100 downto -100 do
	  if home[xx+1,yy] then right[xx,yy]:=true
	    else right[xx,yy]:=right[xx+1,yy];
  ans:=0;
  for xx:=-100 to 100 do
    for yy:=-100 to 100 do
	  if up[xx,yy] and down[xx,yy] and left[xx,yy] and right[xx,yy] then inc(ans);
  writeln(ans);
end.
