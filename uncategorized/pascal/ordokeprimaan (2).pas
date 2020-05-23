const
  max = 1000000;
 
var
  t,kasus,n,k,i,imax:longint;
  stat:boolean;
  a,p:array[1..max] of longint;
 
procedure prime;
  var
    i,j:longint;
    temp:array[1..max] of boolean;
 
  begin
    for i:=2 to max do temp[i]:=true;
    temp[1]:=false;
    for i:=2 to trunc(sqrt(max)) do if temp[i] then
      for j:=2 to (max div i) do temp[i*j]:=false;
    j:=1;
    for i:=1 to max do if temp[i] then
      begin
        p[j]:=i;
        inc(j);
      end;
  end;
 
begin
  prime;
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=1 to n do a[i]:=i;
      k:=0;
      imax:=n;
      while true do
        begin
          i:=0;
          repeat
            inc(i);
            a[i]:=a[p[i]];
          until (a[i]>=n) or (p[i]>imax);
          imax:=i;
          if a[i]=n then
            begin
              inc(k);
              if i=1 then break;
            end
          else break;
        end;
      writeln(k);
    end;
end.