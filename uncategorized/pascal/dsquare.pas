var
  n,i,x,ans,root,k,temp:longint;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x);
      ans:=0;
      for k:=trunc(sqrt(x)) downto 0 do
        begin
          temp:=x-k*k;
          root:=trunc(sqrt(temp));
          if root*root=temp then inc(ans);
        end;
      writeln((ans+1) div 2);
    end;
end.
