{
ID: a_zaky01
PROG: fact4
LANG: PASCAL
}

var
  n,temp,deg,i,count,ans:longint;
  fin,fout:text;

begin
  assign(fin,'fact4.in');
  assign(fout,'fact4.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  temp:=n;
  deg:=0;
  while temp>0 do
    begin
      temp:=temp div 5;
      inc(deg,temp);
    end;
  ans:=1;
  count:=0;
  for i:=1 to n do
    begin
      temp:=i;
      while temp mod 5=0 do temp:=temp div 5;
      if (count<deg) and (temp mod 2=0) then
        begin
          temp:=temp div 2;
          inc(count);
        end;
      ans:=(ans*temp) mod 10;
    end;
  writeln(fout,ans);
  close(fin);
  close(fout);
end.
