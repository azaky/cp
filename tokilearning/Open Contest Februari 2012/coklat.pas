var
  n,ans,l,r,l1,r1,l2,r2:int64;

begin
  readln(n);
  
  if n<1000 then
    begin
      ans:=0;
      while n>=0 do
        begin
          ans:=ans+(n div 2)+1;
          n:=n - 3;
        end;
      writeln(ans);halt;
    end;
  
  r:=n; l:=n-3*(n div 3); ans:=(r-l) div 3+1;
  if (r-l) mod 2=1 then
    begin
      l1:=l div 2; r1:=(r-3) div 2;
      l2:=(l+3) div 2; r2:=r div 2;
    end
  else
    begin
      l1:=l div 2; r1:=r div 2;
      l2:=(l+3) div 2; r2:=(r-3) div 2;
    end;
  //writeln(l:4,r:4);
  //7writeln(l1:5,r1:5,l2:5,r2:5);
  ans:=ans+(l1+r1)*((r1-l1) div 3+1) div 2+(l2+r2)*((r2-l2) div 3+1) div 2;
  writeln(ans);
end.
