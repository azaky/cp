{
ID: a_zaky01
PROG: beads
LAnG: PASCAL
}

var
  n,i,j,l,r,tleft,tright,t:integer;
  cleft,cright:char;
  bead:array[1..1050] of char;
  fin,fout:text;

begin
  assign(fin,'beads.in');
  assign(fout,'beads.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to 3*n do
    if i<=n then read(fin,bead[i])
      else bead[i]:=bead[i-n];
  t:=0;
  for i:=n to 2*n do
    begin
      cleft:='w';
      cright:='w';
      l:=i;
      r:=i+1;
      tleft:=0;
      tright:=0;
      while (bead[l]='w') and (l>=i+1-n) do dec(l);
      cleft:=bead[l];
      while (bead[r]='w') and (r<=i-1+n) do inc(r);
      cright:=bead[r];
      for j:=i downto i+1-n do
        if (bead[j]=cleft) or (bead[j]='w') then inc(tleft)
          else break;
      for j:=i to i-1+n do
        if (bead[j+1]=cright) or (bead[j+1]='w') then inc(tright)
          else break;
      if tleft+tright>=n then t:=n
        else if tleft+tright>t then t:=tleft+tright;
    end;
  writeln(fout,t);
  close(fin);
  close(fout);
end.
