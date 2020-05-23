var
  n, r, m, t, i : longint;
  l : array[0..1111] of longint;
  haha : text;

function s(r,m: longint):longint;
  var i : integer;
  
  begin
    for i := 1 to m do
      if ((r*i)-1) mod m = 0 then exit(i);
    exit(0);
  end;

begin
  assign(haha,'pairs.txt');
  reset(haha);
  while not eof(haha) do
    begin
      inc(n);
      readln(haha,r,m);
      writeln(r,' ',m,' -> ',s(r,m));
      l[n] := s(r,m);
    end;
  t := 0;
  for i := 1 to n do inc(t,l[i]);
  writeln(t);
end.
