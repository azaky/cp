var
  n:integer;

function pangkat(x:integer):integer;

  begin
    pangkat:=0;
    while x>0 do
      begin
        if x mod 2 = 0 then
          begin
            inc(pangkat);
            x:=x div 2;
          end
        else x:=0;
      end;
  end;

function f(x:integer):integer;

  begin
    if x=1 then f:=1
      else f:=f(x-1)-pangkat(x)+1;
  end;

begin
  readln(n);
  writeln(f(n));
end.