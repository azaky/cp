var
  t,kasus,total,n,i,j,k:longint;
  t1,t2:array[1..12] of longint;

procedure swap(var a,b:longint);
  var
    temp:longint;

  begin
    temp:=a;
    a:=b;
    b:=temp;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=1 to n do readln(t1[i],t2[i]);
      for i:=n downto 2 do
        begin
          k:=1;
          for j:=2 to i do
            if (t2[k]>t2[j]) or ((t2[k]=t2[j]) and (t1[k]<t1[j])) then k:=j;
          if k<>i then
            begin
              swap(t1[k],t1[i]);
              swap(t2[k],t2[i]);
            end;
        end;
      total:=0;
      for i:=n downto 1 do
        if t2[i]>total then total:=t1[i]+t2[i]
          else total:=total+t1[i];
      writeln(total);
    end;
end.
