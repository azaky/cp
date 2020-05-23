var
a,i:longint;
k:int64;
m:string;

function fact(x:longint):int64;
  begin
  if x=1 then fact:=1
  else fact:=x*fact(x-1);
  end;

begin
readln(a);
k:=0;
str(fact(a),m);
for i:=length(m) downto 1 do
  begin
  if m[i]='0' then k:=k+1 else break;
  end;
writeln(k);
end.
