const
  next:array[1..4,1..2] of integer = ((1,0),(0,1),(-1,0),(0,-1));

var
  m,n,i,j,k,a,b,a1,b1,qtake,qsave:integer;
  obs:array[0..101,0..101] of boolean;
  queue:array[1..20001,1..2] of integer;
  step:array[0..101,0..101] of integer;

begin
  fillchar(obs,sizeof(obs),true);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(k); obs[i,j]:=k<0;
      end;
  readln(a,b);
  fillchar(step,sizeof(step),255);
  queue[1][1]:=a; queue[1][2]:=b; qtake:=1; qsave:=1; step[a,b]:=1;
  repeat
    a:=queue[qtake][1]; b:=queue[qtake][2];
    if (a=1) or (a=n) or (b=1) or (b=m) then
      begin
        writeln(step[a,b]);
        halt;
      end;
    for i:=1 to 4 do
      begin
        a1:=a+next[i,1]; b1:=b+next[i,2];
        if obs[a1,b1] or (step[a1,b1]>0) then continue;
        inc(qsave);
        queue[qsave][1]:=a1; queue[qsave][2]:=b1; step[a1,b1]:=step[a,b]+1;
      end;
    inc(qtake);
  until false;
end.

