{
ID: a_zaky01
PROG: schlnet
LANG: PASCAL
}

uses
  math;
  
type
  arr = array[0..101] of boolean;
  
var
  n,i,k,ansA,ansB,best,next:longint;
  visit,usedA,usedB,temp:arr;
  rootA,rootB:array[0..101] of integer;
  share:array[0..101] of arr;

procedure fillA(v:integer);
  var
    i:integer;
    
  begin
    if usedA[v] or visit[v] then exit;
    visit[v]:=true;
    inc(k);
    for i:=1 to n do
      if share[v,i] then fillA(i);
  end;
  
procedure fillB(v:integer);
  var
    i:integer;
    
  begin
    if usedB[v] or visit[v] then exit;
    visit[v]:=true;
    inc(k);
    for i:=1 to n do
      if share[i,v] then fillB(i);
  end;

begin

  assign(input,'schlnet.in');
  assign(output,'schlnet.out');
  reset(input);
  rewrite(output);

  readln(n);
  for i:=1 to n do
    repeat
      read(k);
      share[i,k]:=true;
    until k=0;
  
  //Subtask A
  ansA:=0;
  while true do
    begin
      best:=0;
      for i:=1 to n do
        if not usedA[i] then
          begin
            k:=0;
            fillchar(visit,sizeof(visit),false);
            fillA(i);
            if k>best then
              begin
                best:=k;
                next:=i;
                temp:=visit;
              end;
          end;
      if best=0 then break;
      inc(ansA);
      rootA[ansA]:=next;
      for i:=1 to n do
        if temp[i] or (i=next) then usedA[i]:=true;
    end;
  writeln(ansA);
  
  //Subtask B
  ansB:=0;
  while true do
    begin
      best:=0;
      for i:=1 to n do
        if not usedB[i] then
          begin
            k:=0;
            fillchar(visit,sizeof(visit),false);
            fillB(i);
            if k>best then
              begin
                best:=k;
                next:=i;
                temp:=visit;
              end;
          end;
      if best=0 then break;
      inc(ansB);
      rootB[ansB]:=next;
      for i:=1 to n do
        if temp[i] or (i=next) then usedB[i]:=true;
    end;
  
  if (ansA=1) and (ansB=1) and (rootA[ansA]=rootB[ansB]) then writeln(0)
    else writeln(max(ansA,ansB));

  close(input);
  close(output);

end.

