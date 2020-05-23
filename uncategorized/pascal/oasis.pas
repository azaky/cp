const
  next:array[0..3,1..2] of integer = ((0,1),(1,0),(0,-1),(-1,0));

var
  x0,y0,n,i,j,dir,x,y:integer;
  ch:char;
  int:array[1..1000] of char;

begin
  readln(x0,y0);
  n:=0;
  repeat
    read(ch);
    if not (ch in ['R','F','L','0']) then continue;
    if ch='0' then break else inc(n);
    int[n]:=ch;
  until false;
  for i:=0 to n-1 do
    begin
      x:=0; y:=0; dir:=0;
      for j:=1 to n do
        begin
          if j-1=i then dir:=(dir+1) mod 4;
          if int[j]='F' then
            begin
              x:=x+next[dir,1]; y:=y+next[dir,2];
            end
          else if int[j]='R' then dir:=(dir+1) mod 4
            else dir:=(dir+3) mod 4;
        end;
      if (x=x0) and (y=y0) then writeln(i);
    end;
end.

