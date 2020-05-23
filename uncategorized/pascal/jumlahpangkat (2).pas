var
  i,t,kasus,n:longint;
  a:array[0..20] of byte;
  
function f(a,b:longint):integer;
  var
    temp:longint;
    
  begin
    if b=1 then f:=a mod 10
      else
        begin
          temp:=f(a,b div 2);
          if b mod 2=0 then f:=(temp*temp) mod 10
            else f:=(temp*temp*a) mod 10;
        end;
  end;
  
begin
  a[0]:=0;
  for i:=1 to 20 do
    if i=1 then a[i]:=f(i,i)
      else a[i]:=(a[i-1]+f(i,i)) mod 10;
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      writeln((4*(n div 20)+a[n mod 20]) mod 10);
    end;
end.