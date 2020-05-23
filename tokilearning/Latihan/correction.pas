var
  k,i,j,n,ans:longint;
  c1,c2:char;
  len,d:array[0..5000] of longint;
  dict:array[1..5000] of ansistring;
  diff:array['a'..'z','a'..'z'] of longint;
  s:ansistring;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a)
      else exit(b);
  end;

begin
  readln(k);
  for i:=1 to k do
    begin
      readln(dict[i]);
      len[i]:=length(dict[i]);
    end;
  readln(s); n:=length(s);
  for c1:='a' to 'z' do
    for c2:='a' to 'z' do
      diff[c1,c2]:=min(abs(ord(c1)-ord(c2)),26-abs(ord(c1)-ord(c2)));
  d[0]:=maxlongint;
  for i:=1 to n do
    begin
      ans:=0;
      for j:=1 to k do
        begin
          if len[j]<i then continue;
          d[j]:=d[j]+diff[s[i],dict[j][i]];
          if d[j]<d[ans] then ans:=j;
        end;
      writeln(copy(dict[ans],1,i));
    end;
end.
