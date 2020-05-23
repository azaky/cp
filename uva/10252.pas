uses math;
var
  a,b:ansistring;
  i:longint;
  xa,xb:array[#1..#255] of longint;
  ch:char;

begin
  repeat
    readln(a);readln(b);
    fillchar(xa,sizeof(xa),0);fillchar(xb,sizeof(xb),0);
    for i:=1 to length(a) do inc(xa[a[i]]);
    for i:=1 to length(b) do inc(xb[b[i]]);
    for ch:='a' to 'z' do
      for i:=1 to min(xa[ch],xb[ch]) do write(ch);
    writeln;
  until eof;
end.
