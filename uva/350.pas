var
  a,b,m,l,i,c,kasus:longint;
  v:array[-1..11111] of longint;

begin
  repeat
    readln(a,b,m,l); inc(kasus);
    if (a=0) and (b=0) and (m=0) and (l=0) then exit;
    for i:=0 to m do v[i] := -1;
    v[l] := 0; c := 0;
    while true do
      begin
        l := (a*l+b) mod m; inc(c);
        if v[l]>=0 then begin writeln('Case ',kasus,': ',c-v[l]); break; end;
        v[l] := c;
      end;
    until false;
end.
