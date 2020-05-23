{
ID: a_zaky01
PROG: numtri
LANG: PASCAL
}

var
  i,j,n,input:integer;
  hasil:longint;
  max:array[1..1000,1..1000] of longint;
  fin,fout:text;

begin
  assign(fin,'numtri.in');
  assign(fout,'numtri.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    for j:=1 to i do
      begin
        if j=i then readln(fin,input)
          else read(fin,input);
        if i=1 then max[i,j]:=input
          else if j=i then max[i,j]:=max[i-1,j-1]+input
            else if j=1 then max[i,j]:=max[i-1,j]+input
              else if max[i-1,j-1]>max[i-1,j] then max[i,j]:=max[i-1,j-1]+input
                else max[i,j]:=max[i-1,j]+input;
      end;
  hasil:=0;
  for i:=1 to n do
    if max[n,i]>hasil then hasil:=max[n,i];
  writeln(fout,hasil);
  close(fin);
  close(fout);
end.
