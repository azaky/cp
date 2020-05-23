{
ID: a_zaky01
PROG: preface
LANG: PASCAL
}

var
  n,i,temp,k,add:integer;
  a:array[1..7] of integer;
  fin,fout:text;

begin
  assign(fin,'preface.in');
  assign(fout,'preface.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    begin
      temp:=i;
      k:=0;
      while temp>0 do
        begin
          inc(k);
          add:=temp mod 5;
          if add=4 then add:=1;
          a[2*k-1]:=a[2*k-1]+add;
          if temp mod 10>3 then
            if temp mod 10=9 then inc(a[2*k+1])
              else inc(a[2*k]);
          temp:=temp div 10;
        end;
    end;
  for i:=1 to 7 do
    if a[i]>0 then
      case i of
          1:writeln(fout,'I ',a[i]);
          2:writeln(fout,'V ',a[i]);
          3:writeln(fout,'X ',a[i]);
          4:writeln(fout,'L ',a[i]);
          5:writeln(fout,'C ',a[i]);
          6:writeln(fout,'D ',a[i]);
          7:writeln(fout,'M ',a[i]);
        end;
  close(fin);
  close(fout);
end.
