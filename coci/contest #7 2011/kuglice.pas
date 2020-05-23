var
  n,i,q,task,v:longint;
  outv:array[1..300000] of longint;
  visit:array[1..300000] of boolean;
  
begin
  readln(n);
  for i:=1 to n do read(outv[i]);
  readln(q);
  for i:=1 to q do
    begin
      readln(task,v);
      if task=2 then
        begin
          outv[v]:=0;
          continue;
        end;
      fillchar(visit,sizeof(visit),false);
      while true do
        begin
          if visit[v] then
            begin
              writeln('CIKLUS');
              break;
            end;
          if outv[v]=0 then
            begin
              writeln(v);
              break;
            end;
          visit[v]:=true;
          v:=outv[v];
        end;
    end;
end.
