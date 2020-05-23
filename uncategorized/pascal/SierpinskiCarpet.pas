var
  n,i,j:longint;

function Sierpinski(x,y:longint):boolean;
  begin
    while (x>0) or (y>0) do
      begin
        if (x mod 3=1) and (y mod 3=1) then exit(false);
        x := x div 3; y := y div 3;
      end;
    exit(true);
  end;

begin
  readln(n);
  for i:=0 to n-1 do
    begin
      for j:=0 to n-1 do
        if Sierpinski(i,j) then write('x') else write('.');
      writeln;
    end;
end.
