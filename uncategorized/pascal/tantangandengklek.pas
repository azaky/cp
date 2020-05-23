type
  arr = array[1..8] of longint;

const
  fact:array[0..8] of longint = (1,1,2,6,24,120,720,5040,40320);
  max = 2*40320;

var
  n,i,j,k,qtake,qsave,t:longint;
  a,temp:arr;
  used:array[0..max] of boolean;
  queue:array[0..max] of arr;
  step:array[0..max] of longint;

function term(a:arr):longint;
  var
    u:array[1..8] of longint;
    i,j:longint;
  
  begin
    term:=0;
    for i:=1 to n do u[i]:=i;
    for i:=1 to n do
      begin
        inc(term,(u[a[i]]-1)*fact[n-i]);
        for j:=a[i]+1 to n do dec(u[j]);
      end;
  end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  readln(k);
  used[term(a)]:=true;
  if used[0] then
    begin
      writeln(0); halt;
    end;
  queue[1]:=a; qtake:=1; qsave:=1; step[1]:=0;
  repeat
    for i:=1 to n-k+1 do
      begin
        temp:=queue[qtake];
        for j:=i to i+k-1 do temp[j]:=queue[qtake][2*i+k-1-j];
        t:=term(temp);
        if t=0 then
          begin
            writeln(step[qtake]+1); halt;
          end
        else if used[t] then continue else used[t]:=true;
        inc(qsave); queue[qsave]:=temp; step[qsave]:=step[qtake]+1;
      end;
    inc(qtake);
  until qtake>qsave;
  writeln(-1);
end.

