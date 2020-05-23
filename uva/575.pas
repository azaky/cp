var
  i,n:longint;
  s:ansistring;
  num:int64;
  skew:array[0..32] of int64;

begin
  skew[0]:=1; for i:=1 to 32 do skew[i]:=2*skew[i-1]+1;
  while true do
    begin
	  readln(s); if s='0' then break; n:=length(s); num:=0;
	  for i:=1 to n do num:=num+int64(pos(s[n+1-i],'012')-1)*skew[i-1];
	  writeln(num);
	end;
end.
//00:05:44.352