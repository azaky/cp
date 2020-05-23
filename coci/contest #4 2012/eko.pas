var
  n,i:longint;
  m,la,lb,mid,temp:int64;
  a:array[0..1000005] of int64;

begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  la:=1; lb:=1000000000;
  while (la<lb) do
    begin
      mid:=(la+lb) div 2; temp:=0;
      for i:=1 to n do
        if a[i]>=mid then inc(temp,a[i]-mid);
      //writeln(la:9,lb:9,mid:9,temp:9);
      if temp<m then lb:=mid else la:=mid;
      if (temp=m) and (lb-la=1) then break;
    end;
  writeln(mid);
end.
