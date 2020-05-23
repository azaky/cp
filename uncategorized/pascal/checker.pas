{
ID: a_zaky01
PROG: checker
LANG: PASCAL
}

type
  st=record
         col:array[1..13] of boolean;
         diag1:array[-12..12] of boolean;
         diag2:array[2..26] of boolean;
         num:array[1..13] of integer;
       end;

var
  i,n:integer;
  count,count1:longint;
  stat:st;
  fin,fout:text;

procedure checker(stat:st; k:integer);
  var
    i:integer;

  begin
    if k=n then
      begin
        inc(count);
        if (n mod 2=1) and (stat.num[n]=(n+1) div 2) then inc(count1);
        if count<=3 then
          begin
            for i:=1 to n-1 do write(stat.num[i],' ');
            writeln(stat.num[n]);
          end;
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
  //assign(fin,'checker.in');
  //assign(fout,'checker.out');
  //reset(fin);
  //rewrite(fout);
  readln(n);
  count:=0;
  count1:=0;
  if n=6 then for i:=1 to n do
    begin
      stat.num[1]:=i;
      checker(stat,1);
    end
  else
    begin
      for i:=1 to (n div 2) do
        begin
          stat.num[1]:=i;
          checker(stat,1);
        end;
      count:=2*(count+count1);
    end;
  writeln(count);
  //close(fin);
  //close(fout);
end.
