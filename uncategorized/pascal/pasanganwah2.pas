var
  t,kasus,n,i,j,k,max,a,lmax,pmax:integer;
  l,p:array[0..10000] of integer;
  statl,statp:array[0..10000] of boolean;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=0 to n-1 do if i=n then readln(l[i]) else read(l[i]);
      for i:=0 to n-1 do if i=n then readln(p[i]) else read(p[i]);
      for i:=0 to n-1 do
        begin
          statl[i]:=false;
          statp[i]:=false;
        end;
      for k:=1 to n do
        begin
          max:=0;
          for i:=0 to n-1 do if not(statl[i]) then
            for j:=0 to n-1 do if not(statp[j]) then
              if abs(l[i]-p[j])>max then
                begin
                  lmax:=i;
                  pmax:=j;
                  max:=abs(l[i]-p[j]);
                end;
          statl[lmax]:=true;
          statp[pmax]:=true;
          a:=l[lmax]-p[pmax];
          writeln(lmax,' ',pmax,' ',a*a);
        end;
      writeln;
    end;
end.