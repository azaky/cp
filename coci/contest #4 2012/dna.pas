var
  n,i,op:longint;
  a:array[0..1000000] of boolean;
  ch:char;
  b:boolean;

begin
  readln(n);
  op:=0;
  b:=true;
  for i:=1 to n do
    begin
      read(ch);
      a[i]:=ch='A';
    end;
  for i:=n downto 1 do
	begin
	  if (a[i]<>b) then
		begin
		  if ((i=1) or (a[i-1]=b)) then inc(op,1) else
			begin
			  b:=not b;
			  inc(op,1);
			end;
		end;
	end;
	writeln(op);
end.
