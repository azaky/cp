{
ID: a_zaky01
PROG: dualpal
LANG: PASCAL
}

var
  n,s,i,check,c:longint;
  fin,fout:text;

function pal(base,n:longint):boolean;
  var
    len,diff,temp,i:longint;
    result:array[1..1000] of integer;

  begin
    len:=0;
    diff:=n;
    while diff>0 do
      begin
        diff:=diff div base;
        inc(len);
      end;
    for i:=1 to len do
      begin
        temp:=n mod base;
        result[len+1-i]:=temp;
        n:=n div base;
      end;
    pal:=true;
    for i:=1 to len div 2 do
      if result[i]<>result[len+1-i] then
        begin
          pal:=false;
          break;
        end;
  end;

begin
  assign(fin,'dualpal.in');
  assign(fout,'dualpal.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n,s);
  c:=0;
  while c<n do
    begin
      inc(s);
      check:=0;
      for i:=2 to 10 do
        begin
          if pal(i,s) then inc(check);
          if check=2 then
            begin
              writeln(fout,s);
              inc(c);
              break;
            end;
        end;
    end;
  close(fin);
  close(fout);
end.
