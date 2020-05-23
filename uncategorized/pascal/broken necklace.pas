var
  N,i,j,vleft,vright,v:integer;
  bead,colourleft,colourright:string;
  bead2:array[1..700] of string;

begin
  readln(N);
  readln(bead);
  for i:=1 to 3*N do
    begin
      if i<=N then bead2[i]:=bead[i]
        else bead2[i]:=bead2[i-N];
    end;
  v:=0;
  for i:=N to 2*N do
    begin
      for j:=i downto i+1-N do
        begin
          if bead2[j]='b' then colourleft:='b'
            else if bead2[j]='r' then colourleft:='r'
              else colourleft:='w';
        end;
      for j:=i to i-1+N do
        begin
        if bead2[j+1]='b' then
          begin
          colourright:='b';
          break;
          end
        else
        if bead2[j+1]='r' then
          begin
          colourright:='r';
          break;
          end
        else colourright:='w';
        end;
      vleft:=0;
      for j:=i downto i+1-N do
        begin
        if (bead2[j]=colourleft) or (bead2[j]='w') then inc(vleft)
          else break;
        end;
      vright:=0;
      for j:=i to i-1+N do
        begin
        if (bead2[j+1]=colourright) or (bead2[j+1]='w') then inc(vright)
          else break;
        end;
      if vleft=N then v:=N
        else if vleft+vright>v then v:=vleft+vright;
    end;
  write(v);
end.
