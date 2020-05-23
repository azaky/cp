var
  s:string;
  l,l2,i,j,k,d,e:integer;
  hasil,temp:array[1..20000] of integer;

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

var
  fin,fout:text;

begin
  assign(fin,'tes.in');
  assign(fout,'power.out');
  reset(fin);
  rewrite(fout);

  readln(fin,s);
  readln(fin,e);
  l:=length(s);
  for i:=1 to l do
    begin
      val(s[l+1-i],d);
      temp[i]:=d;
    end;
  for k:=1 to (e-1) do
    begin
      for i:=1 to (l*k) do hasil[i]:=0;
      for i:=1 to (l*k) do
        begin
          d:=temp[i];
          for j:=1 to d do sum(s,i-1);
        end;
      for i:=1 to (l*(k+1)) do temp[i]:=hasil[i];
    end;
  l2:=l*e;
  while hasil[l2]=0 do dec(l2);
  for i:=l2 downto 1 do write(fout,hasil[i]);
  writeln(fout);
  close(fin);
  close(fout);
end.
