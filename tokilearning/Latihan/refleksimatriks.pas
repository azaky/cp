var
  n,i,j:longint;
  a,b,t:array[1..75,1..75] of integer;

procedure check(s:string);
  var
    i,j:integer;
    same:boolean;

  begin
    same:=true;
    for i:=1 to n do
      for j:=1 to n do
        if t[i,j]<>b[i,j] then same:=false;
    if not same then exit;
    writeln(s);
    halt;
  end;

begin
  readln(n,a[1,1]);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  readln(b[1,1],b[1,2]);
  for i:=1 to n do
    for j:=1 to n do read(b[i,j]);
  //identik
  t:=a;
  check('identik');
  //vertikal
  for i:=1 to n do
    for j:=1 to n do t[i,j]:=a[i,n+1-j];
  check('vertikal');
  //horisontal
  for i:=1 to n do
    for j:=1 to n do t[i,j]:=a[n+1-i,j];
  check('horisontal');
  //diagonal kanan bawah
  for i:=1 to n do
    for j:=1 to n do t[i,j]:=a[j,i];
  check('diagonal kanan bawah');
  //diagonal kiri bawah
  for i:=1 to n do
    for j:=1 to n do t[i,j]:=a[n+1-j,n+1-i];
  check('diagonal kiri bawah');
  writeln('tidak identik');
end.
