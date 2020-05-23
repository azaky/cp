var
  hasil:array[1..100] of integer;
  s1,s2:string;
  i,n:integer;

procedure sum(x,y:string);
  var
    temp:string;
    sisa,temp1,temp2,s:integer;
    stat:boolean;

  begin
    if length(x)<length(y) then
      begin
        temp:=x;
        x:=y;
        y:=temp;
      end;
    stat:=true;
    n:=1;
    sisa:=0;
    while stat do
      begin
        if n>length(x) then
          begin
            temp1:=0;
            temp2:=0;
            stat:=false;
          end
        else if n>length(y) then
          begin
            val(x[length(x)+1-n],temp1);
            temp2:=0;
          end
        else
          begin
            val(x[length(x)+1-n],temp1);
            val(y[length(y)+1-n],temp2);
          end;
        s:=temp1+temp2+sisa;
        if s<10 then
          begin
            hasil[n]:=s;
            sisa:=0;
          end
        else
          begin
            hasil[n]:=s mod 10;
            sisa:=1;
          end;
        if n>length(x) then
          if s=0 then dec(n)
            else
          else inc(n);
      end;
  end;

begin
  readln(s1);
  readln(s2);
  sum(s1,s2);
  for i:=n downto 1 do write(hasil[i]);
  writeln;
end.
