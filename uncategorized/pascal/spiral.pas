var
  input:string;
  arr:array[-20..20,-20..20] of char;
  dir,x,y,minx,miny,maxx,maxy,i,j:integer;

begin
  readln(input);
  fillchar(arr,sizeof(arr),'^');
  if length(input)>2 then
    begin
      //dir=1(right); 2(down); 3(left); 0(up);
      dir:=2;
      x:=1;
      y:=0;
      minx:=0;
      maxx:=1;
      miny:=0;
      maxy:=0;
      i:=2;
      if input[1]=' ' then arr[0,0]:='_'
        else arr[0,0]:=input[1];
      if input[2]=' ' then arr[1,0]:='_'
        else arr[1,0]:=input[2];
      while i<length(input) do
        begin
          case dir of
            2: while (arr[x-1,y]<>'^') and (i<length(input)) do
                 begin
                   dec(y);
                   inc(i);
                   if input[i]=' ' then arr[x,y]:='_'
                     else arr[x,y]:=input[i];
                 end;
            3: while (arr[x,y+1]<>'^') and (i<length(input)) do
                 begin
                   dec(x);
                   inc(i);
                   if input[i]=' ' then arr[x,y]:='_'
                     else arr[x,y]:=input[i];
                 end;
            0: while (arr[x+1,y]<>'^') and (i<length(input)) do
                 begin
                   inc(y);
                   inc(i);
                   if input[i]=' ' then arr[x,y]:='_'
                     else arr[x,y]:=input[i];
                 end;
            1: while (arr[x,y-1]<>'^') and (i<length(input)) do
                 begin
                   inc(x);
                   inc(i);
                   if input[i]=' ' then arr[x,y]:='_'
                     else arr[x,y]:=input[i];
                 end;
          end;
          dir:=(dir+1) mod 4;
          if minx>x then minx:=x;
          if miny>y then miny:=y;
          if maxx<x then maxx:=x;
          if maxy<y then maxy:=y;
        end;
      for i:=maxy downto miny do
        begin
          for j:=minx to maxx do
            if arr[j,i]='^' then write('_')
              else write(arr[j,i]);
          writeln;
        end;
    end
  else if length(input)>0 then
    begin
      for i:=1 to length(input) do
        if input[i]=' ' then write('_')
          else write(input[i]);
      writeln;
    end;
end.
