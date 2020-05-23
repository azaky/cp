var
  n,i,j,k,count:longint;
  s,temp:real;
  x,y:array[1..1000000] of longint;
  death:array[1..1000000] of boolean;

function d(x1,y1,x2,y2:longint):real;

  begin
    d:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
  end;

begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  for i:=1 to n do death[i]:=false;
  for i:=1 to n do
    begin
      s:=0;
      for j:=1 to n do
        if i=j then
          else
            begin
              temp:=d(x[i],y[i],x[j],y[j]);
              if (s=0) or (s>temp) then
                begin
                  s:=temp;
                  k:=j;
                end;
            end;
      death[k]:=true;
    end;
  count:=0;
  for i:=1 to n do if not(death[i]) then inc(count);
  writeln(count);
end.
