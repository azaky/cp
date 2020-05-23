{
ID: a_zaky01
PROG: transform
LANG: PASCAL
}

var
  n,i,j,k:integer;
  awal,akhir,temp,temp2:array[1..10,1..10] of char;
  fin,fout:text;

label
  closefile;

function same:boolean;
  var
    i,j:integer;

  begin
    same:=true;
    for i:=1 to n do
      begin
        for j:=1 to n do
          if temp[i,j]<>akhir[i,j] then
            begin
              same:=false;
              break;
            end;
        if not same then break;
      end;
  end;

begin
  assign(fin,'transform.in');
  assign(fout,'transform.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    for j:=1 to n do
      if j<>n then read(fin,awal[i,j]) else readln(fin,awal[i,j]);
  for i:=1 to n do
    for j:=1 to n do
      if j<>n then read(fin,akhir[i,j]) else readln(fin,akhir[i,j]);
  //transform #1
  for i:=1 to n do
    for j:=1 to n do
      temp[i,j]:=awal[n+1-j,i];
  if same then
    begin
      writeln(fout,'1');
      goto closefile;
    end;
  //transform #2
  for i:=1 to n do
    for j:=1 to n do
      temp[i,j]:=awal[n+1-i,n+1-j];
  if same then
    begin
      writeln(fout,'2');
      goto closefile;
    end;
  //transform #3
  for i:=1 to n do
    for j:=1 to n do
      temp[i,j]:=awal[j,n+1-i];
  if same then
    begin
      writeln(fout,'3');
      goto closefile;
    end;
  //transform #4
  for i:=1 to n do
    for j:=1 to n do
      temp[i,j]:=awal[i,n+1-j];
  if same then
    begin
      writeln(fout,'4');
      goto closefile;
    end;
  //transform #5
  for i:=1 to n do
    for j:=1 to n do
      temp2[i,j]:=temp[i,j];
  for k:=1 to 3 do
    begin
      for i:=1 to n do
        for j:=1 to n do
          temp[i,j]:=temp2[n+1-j,i];
      for i:=1 to n do
        for j:=1 to n do
          temp2[i,j]:=temp[i,j];
      writeln(fout);
      for i:=1 to n do
        for j:=1 to n do
          if j=n then writeln(fout,temp[i,j]) else write(fout,temp[i,j]);
      if same then
        begin
          writeln(fout,'5');
          goto closefile;
        end;
    end;
  //transform #6
  for i:=1 to n do
    for j:=1 to n do
      temp[i,j]:=awal[i,j];
  if same then
    begin
      writeln(fout,'6');
      goto closefile;
    end;
  writeln(fout,'7');
  closefile:
  close(fin);
  close(fout);
end.
