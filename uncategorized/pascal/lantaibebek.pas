{var
  n,i:integer;
  cara:int64;

procedure bebek(x,i:integer);

  begin
    if x=i then inc(cara)
      else
        begin
          if x+3<=i then bebek(x+3,i);
          if x+1<=i then bebek(x+1,i);
        end;
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      cara:=0;
      bebek(0,i);
      writeln(cara);
    end;
end.}

var
  n,i:longint;
  a:array[1..1000] of longint;

begin
  readln(n);
  a[1]:=1;
  a[2]:=1;
  a[3]:=2;
  if (n=1) or (n=2) or (n=3) then writeln(a[n])
    else
      begin
        for i:=4 to n do a[i]:=(a[i-1]+a[i-3]) mod 1000000;
        writeln(a[n]);
      end;
end.
