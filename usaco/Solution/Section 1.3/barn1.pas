{
ID: a_zaky01
PROG: barn1
LANG: PASCAL
}

var
  m,s,c,i,stall:integer;
  cow,diff:array[1..200] of integer;
  fin,fout:text;

procedure sortcow(l,r:longint);
  var
    i,j,x,temp:integer;

  begin
    i:=l;
    j:=r;
    x:=cow[(l+r) div 2];
    repeat
      while cow[i]<x do inc(i);
      while cow[j]>x do dec(j);
      if not(i>j) then
        begin
          temp:=cow[i];
          cow[i]:=cow[j];
          cow[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sortcow(l,j);
    if i<r then sortcow(i,r);
  end;

procedure sortdiff(l,r:longint);
  var
    i,j,x,temp:integer;

  begin
    i:=l;
    j:=r;
    x:=diff[(l+r) div 2];
    repeat
      while diff[i]>x do inc(i);
      while diff[j]<x do dec(j);
      if not(i>j) then
        begin
          temp:=diff[i];
          diff[i]:=diff[j];
          diff[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sortdiff(l,j);
    if i<r then sortdiff(i,r);
  end;

begin
  assign(fin,'barn1.in');
  assign(fout,'barn1.out');
  reset(fin);
  rewrite(fout);
  readln(fin,m,s,c);
  for i:=1 to c do readln(fin,cow[i]);
  sortcow(1,c);
  for i:=1 to c-1 do diff[i]:=cow[i+1]-cow[i]-1;
  sortdiff(1,c-1);
  stall:=0;
  for i:=1 to m-1 do stall:=stall+diff[i];
  stall:=(cow[c]-cow[1]+1)-stall;
  writeln(fout,stall);
  close(fin);
  close(fout);
end.