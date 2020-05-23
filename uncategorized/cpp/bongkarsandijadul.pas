var
  n,i,j,k,tk,x,s,p,t:longint;
  ans,a:array[1..6] of longint;
  used:array[0..6] of longint;
  found:array[0..6] of boolean;
 
procedure minta;
  var
    i:longint;
   
  begin
    write('? ');
    for i:=1 to 6 do write(a[i]);
    writeln;
    flush(output);
    readln(k);
  end;
 
begin
  readln(n);
  //subtask 1
  if n=2 then
    begin
      for i:=0 to 9 do
        for j:=0 to 9 do
          begin
            writeln('? ',i,j);
            flush(output);
            readln(k);
            if k=2 then
              begin
                writeln('! ',i,j);
                halt;
              end;
          end;
    end;
  //other subtask
  n:=0;
  for i:=0 to 8 do
    begin
      for j:=1 to 6 do a[j]:=i;
      minta;
      for j:=n+1 to n+k do used[j]:=i;
      n:=n+k;
      if k=0 then x:=i;
      if n=6 then break;
    end;
  if x=0 then x:=i+1;
  for j:=n+1 to 6 do used[j]:=9;
  n:=6;
  used[0]:=-1;
  for i:=1 to 6 do ans[i]:=x;
  tk:=0;
  for i:=1 to 5 do
    begin
      if used[i]<>used[i-1] then p:=0;
      s:=0; t:=used[i];
      while true do
        begin
          inc(s); inc(p);
          while found[p] do inc(p);
          if s+i=7 then
            begin
              found[p]:=true;
              ans[p]:=t;
              inc(tk);
              break;
            end;
          a:=ans;
          a[p]:=t;
          minta;
          if k=tk then continue;
          inc(tk);
          ans[p]:=t; found[p]:=true;
          break;
        end;
    end;
  for i:=1 to 6 do
    if not found[i] then ans[i]:=used[6];
  write('! ');
  for i:=1 to 6 do write(ans[i]);
  writeln;
end.
