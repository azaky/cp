var
  max,i:longint;

function prime(n:longint):boolean;
  var
    i:longint;
  
  begin
    prime:=true;
    for i:=2 to trunc(sqrt(n)) do
      if n mod i=0 then exit(false);
  end;

begin
  max:=1;
  for i:=1 to 10001 do
    begin
      inc(max);
      while not prime(max) do inc(max);
    end;
  writeln(max);
end.

