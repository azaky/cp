{
ID: a_zaky01
PROG: sort3
LANG: PASCAL
}

var
  i,j,n,temp,sisa:integer;
  count:longint;
  data,sorted:array[1..1001] of integer;
  total:array[1..3] of integer;
  fin,fout:text;

begin
  assign(fin,'sort3.in');
  assign(fout,'sort3.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    begin
      readln(fin,temp);
      data[i]:=temp;
      inc(total[temp]);
    end;
  if total[1]<>0 then
    for i:=1 to total[1] do sorted[i]:=1;
  if total[2]<>0 then
    for i:=1 to total[2] do sorted[total[1]+i]:=2;
  if total[3]<>0 then
    for i:=1 to total[3] do sorted[total[1]+total[2]+i]:=3;
  total[3]:=total[2]+1;
  total[2]:=total[1]+1;
  total[1]:=1;
  count:=0;
  for i:=1 to n do
    if data[i]<>sorted[i] then
      begin
        j:=total[data[i]];
        while ((data[j]<>sorted[i]) or (data[j]=sorted[j])) and (sorted[j]=data[i]) do inc(j);
        if sorted[j]<>data[i] then
          begin
            for sisa:=1 to 3 do
              if (sisa<>data[i]) and (sisa<>sorted[i]) then break;
            j:=total[sisa];
            while (data[j]<>sorted[i]) or (data[j]=sorted[j]) do inc(j);
          end;
        temp:=data[i];
        data[i]:=data[j];
        data[j]:=temp;
        inc(count);
      end;
  writeln(fout,count);
  close(fin);
  close(fout);
end.
