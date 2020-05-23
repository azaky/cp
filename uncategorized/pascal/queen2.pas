const
  max=100;

type
  st=record
         col:array[1..max] of boolean;
         diag1:array[1-max..max-1] of boolean;
         diag2:array[2..2*max] of boolean;
         num:array[1..max] of integer;
       end;

var
  i,n:integer;
  count:longint;
  stat:st;
  fin,fout:text;

procedure checker(stat:st; k:integer);
  var
    i:integer;

  procedure print;
    var
      r,c:integer;

    begin
      for r:=1 to n do
        begin
          for c:=1 to n do
            if stat.num[r]=c then write(fout,'x')
              else write(fout,'.');
          writeln(fout);
        end;
      writeln(fout);
    end;

  begin
    if k=n then
      begin
        inc(count);
        print;
      end
    else
      begin
        stat.col[stat.num[k]]:=true;
        stat.diag1[k-stat.num[k]]:=true;
        stat.diag2[k+stat.num[k]]:=true;
        inc(k);
        for i:=1 to n do
          if not(stat.col[i]) and not(stat.diag1[k-i]) and not(stat.diag2[k+i]) then
            begin
              stat.num[k]:=i;
              checker(stat,k);
            end;
      end;
  end;

begin
  assign(fin,'queen.in');
  assign(fout,'queen.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  count:=0;
  begin
    for i:=1 to n do
      begin
        stat.num[1]:=i;
        checker(stat,1);
      end;
  end;
  writeln(fout,count);
  close(fin);
  close(fout);
end.
