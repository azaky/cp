uses math;

var
  n,i,t,longest,best,ans,count:longint;
  winter,come:array[0..111111] of boolean;
  len:array[0..111111] of longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(t); winter[i]:=t<0;
    end;
  for i:=n downto 1 do
    if winter[i] then len[i]:=len[i+1]+1
      else len[i]:=0;
  for i:=1 to n do
    if winter[i] then len[i]:=max(len[i],len[i-1]);
  //for i:=1 to n do write(len[i]:3);writeln;
  for i:=2 to n do
    if winter[i] and not winter[i-1] then
      for t:=i-1 downto i-2*len[i] do
        if t=0 then break else come[t]:=true;
  for i:=1 to n do if come[i] then inc(ans);
  //for i:=1 to n do if come[i] then write(1) else write(0);writeln;
  longest:=-1; best:=0;
  for i:=1 to n do longest:=max(longest,len[i]);
  for i:=2 to n do
    if winter[i] and not winter[i-1] and (len[i]=longest) then
      begin
        count:=0;
        for t:=i-2*len[i]-1 downto i-3*len[i] do
          if t=0 then break else if not come[t] then inc(count);
        best:=max(best,count);
      end;
  writeln(best+ans);
end.
