{
ID: a_zaky01
PROG: gift1
LANG: PASCAL
}

var
  i,j,k,l,m,n,money:integer;
  inputname:string;
  name:array[1..10] of string;
  cash:array[1..10] of integer;
  fin,fout:text;

begin
  assign(fin,'gift1.in');
  assign(fout,'gift1.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do readln(fin,name[i]);
  for i:=1 to n do
    begin
      readln(fin,inputname);
      m:=1;
      while inputname<>name[m] do inc(m);
      readln(fin,money,k);
      if k<>0 then
        begin
          for j:=1 to k do
            begin
              readln(fin,inputname);
              l:=1;
              while inputname<>name[l] do inc(l);
              cash[l]:=cash[l]+(money div k);
            end;
          cash[m]:=cash[m]+(money mod k)-money;
        end;
    end;
  for i:=1 to n do writeln(fout,name[i],' ',cash[i]);
  close(fin);
  close(fout);
end.
