var
  n,i,k:integer;
  s,duit:array[1..10] of integer;

begin
  readln(n);
  for i:=1 to 10 do s[i]:=0;
  duit[1]:=1000;
  duit[2]:=500;
  duit[3]:=200;
  duit[4]:=100;
  duit[5]:=50;
  duit[6]:=20;
  duit[7]:=10;
  duit[8]:=5;
  duit[9]:=2;
  duit[10]:=1;
  k:=1;
  while n>0 do
    begin
      if n>=duit[k] then
        begin
          n:=n-duit[k];
          inc(s[k]);
        end
      else inc(k);
    end;
  for i:=1 to 10 do if s[i]>0 then writeln(duit[i],' ',s[i]);
end.