{
ID: a_zaky01
PROG: runround
LANG: PASCAL
}

var
  num:longint;
  fin,fout:text;

function check(num:longint):boolean;
  var
    n,i,count,k:integer;
    stat,temp:array[0..9] of boolean;
    arr:array[1..9] of integer;

  begin
    check:=true;
    n:=trunc(ln(num)/ln(10))+1;
    for i:=0 to 9 do temp[i]:=false;
    for i:=n downto 1 do
      begin
        stat[i]:=false;
        arr[i]:=num mod 10;
        if (temp[arr[i]]) or (arr[i]=0) then check:=false
          else temp[arr[i]]:=true;
        num:=num div 10;
      end;
    count:=0;
    if check then
      begin
        k:=1;
        while true do
          begin
            inc(count);
            k:=(k+arr[k]) mod n;
            if k=0 then k:=n;
            if stat[k] then check:=false
              else stat[k]:=true;
            if count=n then break;
          end;
      end;
  end;

begin
  assign(fin,'runround.in');
  assign(fout,'runround.out');
  reset(fin);
  rewrite(fout);
  readln(fin,num);
  while true do
    begin
      inc(num);
      if check(num) then
        begin
          writeln(fout,num);
          break;
        end;
    end;
  close(fin);
  close(fout);
end.
