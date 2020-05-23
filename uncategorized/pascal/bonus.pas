var
  i,m,n:longint;
  k:int64;
  hasil:ansistring;
  p:array[0..31] of int64;

procedure print(n:integer; k:int64; m:integer);
  var
    s,pos:longint;

  begin
    if n=0 then hasil:=hasil+'( '
      else
        begin
          s:=trunc(ln(k+1)/ln(2));
          pos:=k+1-p[s];
          while true do
            begin
              if m=0 then break;
              if s=n then
                begin
                  hasil:=hasil+') ';
                  break;
                end;
              if m>=p[s]-pos then
                begin
                  print(s,pos,p[s]);
                  dec(m,p[s]-pos);
                  inc(s);
                  pos:=0;
                end
              else
                begin
                  print(s,pos,m);
                  break;
                end;
            end;
        end;
  end;

begin
  p[0]:=1;
  for i:=1 to 31 do p[i]:=2*p[i-1];
  while true do
    begin
      readln(n,k,m);
      if (n=0) and (k=0) and (m=0) then break;
      hasil:='';
      print(n,k,m);
      for i:=1 to length(hasil) do write(hasil[i]);
      writeln;
    end;
end.
