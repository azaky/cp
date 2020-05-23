var
  n,i,num,j:longint;
  a:array[0..111] of longint;
  ans:array[0..2000002] of longint;

begin
  repeat
    readln(n); if n=0 then break;
    fillchar(a,sizeof(a),0);
    for i:=1 to n do begin read(num); inc(a[num]); end;
    num := 0;
    for i:=0 to 100 do
      for j:=1 to a[i] do begin inc(num); ans[num]:=i; end;
    for i:=1 to n-1 do write(ans[i],' ');writeln(ans[n]);
  until false;
end.
