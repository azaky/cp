var
  n,m,d,f,i,j,p1,p2:longint;
  s1,s2:string; ch:char;
  name:array[0..1000] of string;
  last:array[0..1000,0..1000] of longint;
  friend:array[0..1000,0..1000] of boolean;

function add(s:string):longint;
  var
    i:longint;
  
  begin
    for i:=1 to m do
      if s=name[i] then exit(i);
    inc(m); name[m]:=s; exit(m);
  end;

begin
  readln(n,d);
  fillchar(last,sizeof(last),255);
  fillchar(friend,sizeof(friend),false);
  for i:=1 to n do
    begin
      s1:=''; s2:='';
      repeat
        read(ch);
        if ch=' ' then break else s1:=s1+ch;
      until false;
      repeat
        read(ch);
        if ch=' ' then break else s2:=s2+ch;
      until false;
      p1:=add(s1); p2:=add(s2);
      readln(last[p1,p2]);
      if last[p2,p1]>=0 then
        if (last[p1,p2]-last[p2,p1]<=d) and (last[p2,p1]<last[p1,p2]) then
          begin
            if not friend[p1,p2] then inc(f);
            friend[p1,p2]:=true; friend[p2,p1]:=true;
          end;
    end;
  writeln(f);
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if friend[i,j] then writeln(name[i],' ',name[j]);
end.
