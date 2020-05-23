var
  s:array[0..5] of ansistring;
  i,j,k,x,n:longint;

begin
  //for i:=1 to 4 do readln(s[i]);
  //n:=length(s[1]);
  readln(n);
  randomize;
  for i:=1 to 4 do
    begin
      s[i]:='';
      for k:=1 to n do
        if random(2)=1 then s[i]:=s[i]+'a' else s[i]:=s[i]+'b';
    end;
  for i:=1 to 4 do writeln(s[i]);
  for i:=1 to 3 do
    for j:=i+1 to 4 do
      begin
        x:=0;
        for k:=1 to n do if s[i][k]<>s[j][k] then inc(x);
        writeln(x);
      end;
end.
