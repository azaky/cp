var
  n,i,a:longint;
  exist:array[1..100000] of boolean;

begin
  readln(n);
  for i:=1 to n-2 do
    begin
	  readln(a);exist[a]:=true;
	end;
  for i:=1 to n do
    if not exist[i] then writeln(i);
end.
