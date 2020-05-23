var
  k,n,i,j:integer;
  input:char;
  lubang:array[0..2500] of integer;
  best:array[0..2501] of extended;

function min(a,b:extended):extended;
  begin
    if a<b then exit(a)
      else exit(b);
  end;

begin
  n:=0;
  k:=0;
  while true do
    begin
      inc(k);
      read(input);
      if input='X' then
        begin
          inc(n);
          lubang[n]:=k;
        end
      else if input<>'.' then break;
    end;
  
  best[n]:=1;
  
  for i:=n-1 downto 1 do
    begin
      best[i]:=sqrt(lubang[n]-lubang[i]+1);
      for j:=i to n-1 do
        best[i]:=min(best[i],best[j+1]+sqrt(lubang[j]-lubang[i]+1));
    end;
  
  writeln(best[1]:0:3);
end.
