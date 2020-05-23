{
ID: a_zaky01
PROG: fence8
LANG: PASCAL
}

var
  n,r,i,j,max,a,b,depth,totalboard:longint;
  board:array[1..50] of longint;
  rail,totalrail:array[0..1023] of longint;
  fin,fout:text;

label
  closefile;

procedure swap(var a,b:longint);
  var
    temp:longint;

  begin
    temp:=a;
    a:=b;
    b:=temp;
  end;

procedure sortb(l,r:integer);
  var
    i,j,temp,mid:integer;

  begin
    i:=l;
    j:=r;
    mid:=board[(l+r) div 2];
    repeat
      while board[i]<mid do inc(i);
      while board[j]>mid do dec(j);
      if i<=j then
        begin
          swap(board[i],board[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sortb(l,j);
    if i<r then sortb(i,r);
  end;

procedure sortr(l,r:integer);
  var
    i,j,temp,mid:integer;

  begin
    i:=l;
    j:=r;
    mid:=rail[(l+r) div 2];
    repeat
      while rail[i]<mid do inc(i);
      while rail[j]>mid do dec(j);
      if i<=j then
        begin
          swap(rail[i],rail[j]);
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sortr(l,j);
    if i<r then sortr(i,r);
  end;

function cut(depth0,n0,notused0:integer):boolean;
  var
    i,notused:longint;
    temp:boolean;

  begin
    if depth0=0 then exit(true);
    cut:=false;
    for i:=n0 to n do
      if rail[depth0]<=board[i] then
        begin
          dec(board[i],rail[depth0]);
          if board[i]<rail[1] then notused:=notused0+board[i]
            else notused:=notused0;
          if totalboard-notused<totalrail[depth] then
            begin
              inc(board[i],rail[depth0]);
              continue;
            end;
          if rail[depth0]=rail[depth0-1] then temp:=cut(depth0-1,i,notused)
            else temp:=cut(depth0-1,1,notused);
          inc(board[i],rail[depth0]);
          if temp then exit(true);
        end;
  end;

begin
  assign(fin,'fence8.in');
  assign(fout,'fence8.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do readln(fin,board[i]);
  readln(fin,r);
  for i:=1 to r do readln(fin,rail[i]);
  sortb(1,n);
  sortr(1,r);
  i:=1;
  while (board[i]<rail[1]) and (i<=n) do inc(i);
  if i>n then
    begin
      writeln(fout,0);
      goto closefile;
    end;
  n:=n-i+1;
  for j:=1 to n do board[j]:=board[j+i-1];
  while rail[r]>board[n] do dec(r);
  totalboard:=0;
  totalrail[0]:=0;
  for i:=1 to n do inc(totalboard,board[i]);
  for i:=1 to r do totalrail[i]:=totalrail[i-1]+rail[i];
  while totalrail[r]>totalboard do dec(r);
  if r=0 then
    begin
      writeln(fout,0);
      goto closefile;
    end;
  max:=0;
  a:=1;
  b:=r;
  while a<=b do
    begin
      depth:=(a+b) div 2;
      if cut(depth,1,0) then
        begin
          if depth>max then max:=depth;
          a:=depth+1;
        end
      else b:=depth-1;
    end;
  writeln(fout,max);
  closefile:
  close(fin);
  close(fout);
end.
