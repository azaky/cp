var
  i,m,n:longint;
  k:int64;
  p:array[0..32] of int64;

procedure solve(n:integer; k:int64; m:longint);
  var
    sa,sb,s:integer;
    posa,posb:int64;
    
  begin
    if m=0 then exit;
    
    if n=1 then
      begin
        if k=0 then
          if m=1 then write('(')
          else if m=2 then write('()')
          else
        else if k=1 then
          if m=1 then write(')');
        exit;
      end;
      
    if k=0 then
      begin
        write('(');
        solve(n,k+1,m-1);
        exit;
      end;
    if k+m=p[n] then
      begin
        solve(n,k,m-1);
        write(')');
        exit;
      end;
    
    sa:=trunc(ln(k+1)/ln(2));
    sb:=trunc(ln(k+m+1)/ln(2));
    posa:=k+1-p[sa];
    posb:=k+m+1-p[sb];
    if sa=sb then
      begin
        solve(sa,posa,posb-posa);
        exit;
      end;
    solve(sa,posa,p[sa]-posa);
    for s:=sa+1 to sb-1 do solve(s,0,p[s]);
    solve(sb,0,posb);
  end;

begin
  p[0]:=1;
  for i:=1 to 32 do p[i]:=2*p[i-1];
  while true do
    begin
      readln(n,k,m);
      if (n=0) and (k=0) and (m=0) then halt;
      solve(n,k,m);
      writeln;
    end;
end.
