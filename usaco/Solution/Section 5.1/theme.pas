{
ID: a_zaky01
PROG: theme
LANG: PASCAL
}

uses
  math;

var
  i,j,n,ans:longint;
  note,value:array[0..5000] of longint;
  fin,fout:text;

begin
  assign(fin,'theme.in');
  assign(fout,'theme.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do read(fin,note[i]);
  ans:=0;
  for i:=n-1 downto 6 do
    for j:=1 to i-2 do
      begin
        if note[i+1]-note[i]=note[j+1]-note[j] then
          value[j]:=min((value[j+1]+1),i-j)
        else value[j]:=1;
        if value[j]>ans then ans:=value[j];
      end;
  if ans<5 then writeln(fout,0)
    else writeln(fout,ans);
  close(fin);
  close(fout);
end.
