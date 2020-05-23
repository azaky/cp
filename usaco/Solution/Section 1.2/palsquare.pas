{
ID: a_zaky01
PROG: palsquare
LANG: PASCAL
}

const
  angka = '0123456789ABCDEFGHIJ';

var
  base,i:integer;
  fin,fout:text;

procedure check(n:longint);
  var
    length,diff,temp,i:longint;
    palbase:boolean;
    result:array[1..100] of char;

  procedure print;
    var
      l,i:longint;
      result2:array[1..100] of char;

    begin
      l:=0;
      diff:=n;
      while diff>0 do
        begin
          diff:=diff div base;
          inc(l);
        end;
      for i:=1 to l do
        begin
          if n mod base=0 then result2[l+1-i]:='0'
            else result2[l+1-i]:=angka[(n mod base)+1];
          n:=n div base;
        end;
      for i:=1 to l do write(fout,result2[i]);
      write(fout,' ');
      for i:=1 to length do write(fout,result[i]);
      writeln(fout);
    end;

  begin
    length:=0;
    diff:=n*n;
    while diff>0 do
      begin
        diff:=diff div base;
        inc(length);
      end;
    diff:=n*n;
    for i:=1 to length do
      begin
        if diff mod base=0 then result[length+1-i]:='0'
          else result[length+1-i]:=angka[(diff mod base)+1];
        diff:=diff div base;
      end;
    palbase:=true;
    for i:=1 to length div 2 do
      if result[i]<>result[length+1-i] then
        begin
          palbase:=false;
          break;
        end;
    if palbase then print;
  end;

begin
  assign(fin,'palsquare.in');
  assign(fout,'palsquare.out');
  reset(fin);
  rewrite(fout);
  readln(fin,base);
  for i:=1 to 300 do check(i);
  close(fin);
  close(fout);
end.
