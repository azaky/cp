type
  con=array[1..4] of integer;

var
  t,kasus,n,max,mid,k,i:integer;
  c:con;
  a:array[1..12] of con;

procedure solve(n0,time:integer; c:con);
  var
    i:integer;

  begin
    if (n0=n) or (time=280) then
      if c[1]+c[2]+c[3]>max then max:=c[1]+c[2]+c[3]
        else
      else
        begin
          solve(n0+1,time,c);
          for i:=1 to 3 do
            if (time+a[n0+1,i]<=280) and (c[i]<mid) then
              begin
                inc(c[i]);
                solve(n0+1,time+a[n0+1,i],c);
                dec(c[i]);
              end;
        end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for k:=1 to 3 do
        for i:=1 to n do read(a[i][k]);
      max:=0;
      mid:=(n+1) div 2;
      solve(0,0,c);
      writeln(max);
    end;
end.
