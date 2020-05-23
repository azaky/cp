const
  alphabet: set of char = ['A'..'Z'];

var
  s,temp:ansistring;
  name,t:array[0..5555] of ansistring;
  i,j,n,p:longint;
  score:int64;

procedure sort(l,r:longint);
  var
    il,ir,i,mid:longint;
  
  begin
    writeln(l:5,r:5);
    if l=r then exit else mid:=(l+r) div 2;
    sort(l,mid); sort(mid+1,r);
    il:=l; ir:=mid+1;
    for i:=l to r do
      if (name[il]<=name[ir]) and (il<=mid) or (ir>r) then
        begin
          t[i]:=name[il]; inc(il);
        end
      else
        begin
          t[i]:=name[ir]; inc(ir);
        end;
    for i:=l to r do name[i]:=t[i];
  end;

begin
  assign(input,'names.txt'); reset(input);
  n:=0;
  readln(s);
  temp:=''; p:=0;
  repeat
    inc(p);
    if not (s[p] in alphabet) then
      if temp>'' then
        begin
          inc(n); name[n]:=temp; temp:='';
        end
      else
    else temp:=temp+s[p];
  until p>length(s);
  writeln('apa?');
  sort(1,n);
  writeln('apa?');
  for i:=1 to n do
    for j:=1 to length(name[i]) do score:=score+int64(i)*int64(ord(name[i][j])-ord('A')+1);
  writeln(score);
end.
