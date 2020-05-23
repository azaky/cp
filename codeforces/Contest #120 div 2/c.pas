procedure error;
  begin
    writeln('Error occurred');halt;
  end;

var
  temp,s,ans:ansistring;
  n,p,i,depth:longint;
  a,have:array[0..333333] of longint;
  
begin
  readln(n); p := 0;
  readln(s); temp := '';
  for i:=1 to length(s) do
    begin
      if s[i]=' ' then
        begin
          if temp = '' then continue;
          inc(p);
          if temp = 'pair' then a[p] := 1 else a[p] := 2;
          temp := '';
        end
      else temp := temp+s[i];
    end;
  if length(temp)>0 then
    begin
      inc(p);
      if temp = 'pair' then a[p] := 1 else a[p] := 2;
    end;
  if 2*n <> p+1 then error;
  ans := '';
  for i:=1 to p do
    begin
      if a[i]=1 then
        begin
          ans := ans + 'pair<';
          if (have[depth] = 2) or ((depth=0)and(i>1)) then error;
          inc(have[depth]);
          inc(depth); have[depth] := 0;
          continue;
        end;
      //if depth = 0 then error;
      inc(have[depth]);
      if have[depth] = 1 then
        begin
          if depth=0 then ans :=ans + 'int' else ans := ans + 'int,';
          continue;
        end;
      if have[depth] = 2 then
        begin
          ans := ans + 'int';
          while have[depth] = 2 do
            begin
              ans := ans + '>'; dec(depth);
            end;
          if (have[depth] = 1) and (depth<>0) then ans := ans + ',';
          continue;
        end;
      error;
    end;
  writeln(ans);
end.
