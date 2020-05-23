const
  angka='123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ';
 
var
  n,k,i,a:longint;
  
procedure base(n,a:longint);
  var
    i,k:integer;
    arr:array[1..64] of byte;
    
  begin
    k:=0;
    while n>0 do
      begin
        inc(k);
        arr[k]:=n mod a;
        n:=n div a;
      end;
    for i:=k downto 1 do
      if arr[i]=0 then write(0)
        else write(angka[arr[i]]);
    writeln;
  end;
  
begin
  readln(n);
  readln(k);
  for i:=1 to k do
    begin
      readln(a);
      base(n,a);
    end;
end.