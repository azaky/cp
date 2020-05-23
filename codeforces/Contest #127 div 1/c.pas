uses math;

var
  N,i:longint;
  a,dpl,dpr,endl,endr:array[-1..111111] of int64;
  ans,x:int64;

begin
  readln(N);
  for i:=1 to N-1 do read(a[i]);
  dpl[1] := 0; endl[1] := 0;
  for i:=2 to N do
    begin
      x := a[i-1];
      if x mod 2=1 then x := x-1;
      if x = 0 then dpl[i] := 0
        else dpl[i] := dpl[i-1] + x;
      x := a[i-1];
      if x mod 2=0 then x := x-1;
      if x < 0 then endl[i] := 0
        else endl[i] := endl[i-1] + x;
      if dpl[i]>endl[i] then endl[i] := dpl[i];
    end;
  dpr[n] := 0; endr[n] := 0;
  for i:=n-1 downto 1 do
    begin
      x := a[i];
      if x mod 2=1 then x := x-1;
      if x = 0 then dpr[i] := 0
        else dpr[i] := dpr[i+1] + x;
      x := a[i];
      if x mod 2=0 then x := x-1;
      if x < 0 then endr[i] := 0
        else endr[i] := endr[i+1] + x;
      if dpr[i]>endr[i] then endr[i] := dpr[i];
    end;
  ans := 0;
  for i:=1 to n do
    begin
      x := max(dpl[i]+endr[i],dpr[i]+endl[i]);
      if x>ans then ans := x;
    end;
  writeln(ans);
end.
