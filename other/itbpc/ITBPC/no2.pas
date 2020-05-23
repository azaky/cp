var
  petak:array[1..50,1..50] of integer;
  n,m,b,i,j,x1,y1,x2,y2,x,y,hasil,bb,sum,batu:longint;

begin
  readln(n,m,b);
  hasil:=0;
  bb:=0;
  for i:=1 to n do
    for j:=1 to m do
      if j<>m then read(petak[i,j]) else readln(petak[i,j]);
  for x1:=1 to n do
    for y1:=1 to m do
      for x2:=x1 to n do
        for y2:=y2 to m do
          begin
            sum:=0;
            batu:=0;
            for x:=x1 to x2 do
              for y:=y1 to y2 do
                begin
                  if petak[x,y]=9999 then inc(batu)
                    else sum:=sum+petak[x,y];
                  if batu>b then sum:=0;
                end;
            if sum>hasil then
              begin
                hasil:=sum;
                bb:=batu;
              end;
          end;
  writeln(hasil,' ',bb);
end.
