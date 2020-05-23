{
ID: a_zaky01
PROG: cowcheck
LANG: PASCAL
}
 
const
  maxn = 1000001;
 
var
  x,y,n,m,diff,i,t,temp:longint;
  loss:array[0..maxn,1..2] of longint;
  used:array[1..maxn] of boolean;
 
begin
  //assign(input,'cowcheck.in'); reset(input);
  //assign(output,'cowcheck.out'); rewrite(output);

  loss[0,1]:=1; loss[0,2]:=1; diff:=0;
  used[1]:=true;
  x:=1;
  while true do
    begin
      inc(diff);
      while (x+diff<=maxn) and not (not used[x] and not used[x+diff]) do inc(x);
      if x+diff>maxn then break;
      loss[diff][1]:=x; loss[diff][2]:=x+diff;
      used[x]:=true; used[x+diff]:=true;
    end;
  dec(diff);
    
  readln(n,m);
  readln(t);
  for i:=1 to t do
    begin
      readln(x,y);
      if x>y then
        begin
          temp:=x; x:=y; y:=temp;
        end;
      inc(x); inc(y);
      if (loss[y-x][1]=x) and (loss[y-x][2]=y) then writeln('Farmer John')
        else writeln('Bessie');
    end;
  
  //close(input);
  //close(output);
end.
 
