var
  s,s1,s2:ansistring;
  n,m,i,j,a,b:longint;

label
  answer;

begin
  readln(s); s1:=copy(s,1,pos(' ',s)-1); s2:=copy(s,pos(' ',s)+1,length(s)-pos(' ',s)); n:=length(s1); m:=length(s2);
  for i:=1 to n do
    for j:=1 to m do
      if s1[i]=s2[j] then goto answer;
  answer:
  a:=i; b:=j;
  for i:=1 to m do
    begin
      for j:=1 to n do
        if i=b then write(s1[j])
          else if j=a then write(s2[i])
            else write('.');
      writeln;
    end;
end.
