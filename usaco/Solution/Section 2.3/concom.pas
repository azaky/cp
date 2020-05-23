{
ID: a_zaky01
PROG: concom
LANG: PASCAL
}

var
  i,j,k,n,p:integer;
  sum,temp,count:longint;
  x:array[1..100,1..100] of integer;
  own:array[1..100,1..100] of boolean;
  stat:array[1..100] of boolean;
  fin,fout:text;

begin
  assign(fin,'concom.in');
  assign(fout,'concom.out');
  reset(fin);
  rewrite(fout);
  count:=0;
  readln(fin,n);
  for k:=1 to n do
    begin
      readln(fin,i,j,p);
      stat[i]:=true;
      stat[j]:=true;
      x[i,j]:=p;
      if p>50 then
        begin
          own[i,j]:=true;
          inc(count);
        end;
    end;
  repeat
    temp:=count;
    for i:=1 to 100 do
      if stat[i] then
        for j:=1 to 100 do
          if stat[j] and not(i=j) and not(own[i,j]) then
            begin
              sum:=x[i,j];
              for k:=1 to 100 do
                if stat[k] and (own[i,k]) then sum:=sum+x[k,j];
              if sum>50 then
                begin
                  own[i,j]:=true;
                  inc(count);
                end;
            end;
  until temp=count;
  for i:=1 to 100 do
    for j:=1 to 100 do
      if (i<>j) and own[i,j] then writeln(fout,i,' ',j);
  close(fin);
  close(fout);
end.
