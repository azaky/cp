var
  petak:array[1..50,1..50] of integer;
  stat:boolean;
  n,m,b,i,j,x1,y1,x2,y2,x,y,hasil,bb,sum,batu:longint;

begin
  readln(n,m,b);
  hasil:=-250000;
  bb:=0;
  for i:=1 to n do
    for j:=1 to m do read(petak[i,j]);
  for x1:=1 to n do
    for y1:=1 to m do
      for x2:=x1 to n do
        for y2:=y1 to m do
          begin
            stat:=true;
            sum:=0;
            batu:=0;
            for x:=x1 to x2 do
              if stat then
                for y:=y1 to y2 do
                  if stat then
                    begin
                      if petak[x,y]=9999 then inc(batu)
                        else sum:=sum+petak[x,y];
                      if batu>b then stat:=false;
                    end;
            if stat then
              if sum>hasil then
                begin
                  hasil:=sum;
                  bb:=batu;
                end;
          end;
  writeln(hasil,' ',bb);
end.
