var
  i,j:longint;
  ans,num:int64;
  a:array[-1000..1000,-1000..1000] of int64;

procedure add(x,y:longint);
  begin
    inc(num); a[x][y]:=num;
  end;
  
begin
  add(0,0);
  for i:=2 to 501 do
    begin
      for j:=i-2 downto 1-i do add(i-1,j);
      for j:=i-2 downto 1-i do add(j,1-i);
      for j:=2-i to i-1 do add(1-i,j);
      for j:=2-i to i-1 do add(j,i-1);
    end;
  for i:=1 to 500 do ans:=ans+a[i,i]+a[i,-i]+a[-i,i]+a[-i,-i];
  writeln(ans+1);
end.
