var
  s1,s2:string;
  l1,l2,i,j,d,l:integer;
  hasil:array[1..200] of integer;

procedure sum(x:string; i:integer);
  var
    sisa,temp,k,s:integer;

  begin
    sisa:=0;
    for k:=1 to length(x) do
      begin
        val(x[length(x)+1-k],temp);
        s:=hasil[k+i]+temp+sisa;
        hasil[k+i]:=s mod 10;
        if s<10 then sisa:=0 else sisa:=1;
      end;
    while sisa=1 do
      begin
        inc(k);
        s:=hasil[k+i]+sisa;
        hasil[k+i]:=s mod 10;
        if s<10 then sisa:=0 else sisa:=1;
      end;
  end;

begin
  readln(s1);
  readln(s2);
  l1:=length(s1);
  l2:=length(s2);
  for i:=1 to l2 do
    begin
      val(s2[l2+1-i],d);
      for j:=1 to d do sum(s1,i-1);
    end;
  l:=l1+l2;
  if hasil[l]=0 then dec(l);
  for i:=l downto 1 do write(hasil[i]);
  writeln;
end.