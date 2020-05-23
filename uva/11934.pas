var
  a,b,c,d,l,i,ans:longint;

function f(x:longint):longint;
  begin
    f := a*x*x + b*x + c;
    if f<0 then f := -f;
  end;

begin
  repeat
    readln(a,b,c,d,l);
    if (a=0) and (b=0) and (c=0) and (d=0) and (l=0) then exit;
    ans := 0;
    for i:=0 to L do
      if f(i) mod d = 0 then inc(ans);
    writeln(ans);
  until false;
end.
