var

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(flag,sizeof(flag),false);
      readln(gx,gy,n);
      for i:=1 to n do
        begin
          readln(x,y);
          flag[x,y]:=true;
        end;
      ans:=-1;
      find(0,0,0);
    end;
end.
