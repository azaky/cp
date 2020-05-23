var
  n,m,i,count,max,int1,int2:integer;
  bebek,sepatu:array[1..1000] of integer;
  statsepatu:array[1..1000] of boolean;

procedure sortbebek(l,r:integer);
  var
    i,j,x,temp:integer;

  begin
    i:=l;
    j:=r;
    x:=bebek[(l+r) div 2];
    repeat
      while bebek[i]<x do inc(i);
      while bebek[j]>x do dec(j);
      if not(i>j) then
        begin
          temp:=bebek[i];
          bebek[i]:=bebek[j];
          bebek[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sortbebek(l,j);
    if i<r then sortbebek(i,r);
  end;

procedure sortsepatu(l,r:integer);
  var
    i,j,x,temp:integer;

  begin
    i:=l;
    j:=r;
    x:=sepatu[(l+r) div 2];
    repeat
      while sepatu[i]<x do inc(i);
      while sepatu[j]>x do dec(j);
      if not(i>j) then
        begin
          temp:=sepatu[i];
          sepatu[i]:=sepatu[j];
          sepatu[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sortsepatu(l,j);
    if i<r then sortsepatu(i,r);
  end;

procedure pakai(k:integer);
  var
    tempcount,i,j,temp:integer;
    stat:boolean;
    tempsepatu:array[1..1000] of boolean;

  begin
    if k>int2 then if count>max then max:=count else
      else if ((sepatu[m]<bebek[k]) or (sepatu[1]-1>bebek[k])) then pakai(k+1)
        else
          begin
            for i:=1 to m do tempsepatu[i]:=statsepatu[i];
            tempcount:=count;
            pakai(k+1);
            i:=1;
            while (bebek[k]<>sepatu[i]) and (bebek[k]<>sepatu[i]-1) do inc(i);
            while (bebek[k]=sepatu[i]) or (bebek[k]=sepatu[i]-1) do
              begin
                stat:=false;
                if not(tempsepatu[i]) then
                  begin
                    count:=tempcount;
                    for j:=1 to m do statsepatu[j]:=tempsepatu[j];
                    statsepatu[i]:=true;
                    stat:=true;
                    temp:=sepatu[i];
                    inc(count);
                    pakai(k+1);
                  end;
                if stat then while (sepatu[i]=temp) do inc(i)
                  else inc(i);
              end;
          end;
  end;

begin
  readln(n,m);
  for i:=1 to n do readln(bebek[i]);
  for i:=1 to m do readln(sepatu[i]);
  sortbebek(1,n);
  sortsepatu(1,m);
  count:=0;
  max:=0;
  if not((bebek[1]>sepatu[m]) or (bebek[n]<sepatu[1]-1)) then
    begin
      int1:=1;
      while (bebek[int1]<sepatu[1]-1) do inc(int1);
      int2:=n;
      while (bebek[int2]>sepatu[n]) do dec(int2);
      pakai(int1);
    end;
  writeln(max);
end.
