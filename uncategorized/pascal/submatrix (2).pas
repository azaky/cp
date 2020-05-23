var
  n,m,i,j,mini,minj,minc,count,i1,j1:integer;
  a:array[1..100,1..100] of integer;
  stat:array[0..9] of boolean;

begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  mini:=0;
  minj:=0;
  minc:=0;
  for i:=1 to n-m+1 do
    for j:=1 to n-m+1 do
      begin
        fillchar(stat,sizeof(stat),false);
        count:=0;
        for i1:=1 to m do
          for j1:=1 to m do
            if not stat[a[i1,j1]] then
              begin
                inc(count);
                stat[a[i1,j1]]:=true;
              end;
        if (minc=0) or (minc>count) then
          begin
            minc:=count;
            mini:=i;
            minj:=j;
          end;
      end;
  writeln(mini,' ',minj);
end.
