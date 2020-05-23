var
  i,ans:longint;
  fact:array[0..9] of longint;

procedure find(num,sum:longint);
  var
    i:longint;
  
  begin
    if sum=num then
      begin
        writeln(num);
        if sum>9 then ans:=ans+sum;
      end;
    if num>9*fact[9] then exit;
    for i:=0 to 9 do
      find(10*num+i,sum+fact[i]);
  end;

begin
  fact[0]:=1;
  for i:=1 to 9 do fact[i]:=fact[i-1]*i;
  for i:=1 to 9 do find(i,fact[i]);
  writeln(ans);
end.
