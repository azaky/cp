var
  max,pos,n,i,j,p,num:longint;
  a:array[1..10001] of longint;

begin
  readln(n);
  pos:=(n+2) div 2;
  max:=0;
  for i:=1 to n do
    begin
      readln(num);
      p:=1;
      while (a[p]>num) and (p<=pos) do inc(p);
      if p<=pos then
        begin
          if max<pos then inc(max);
          if p<max then
            for j:=max downto p+1 do a[j]:=a[j-1];
          a[p]:=num;
        end;
{
      writeln('p=',p);
      writeln('max=',max);
      for j:=1 to pos do writeln('posisi ',j,'=',a[j]);
}
    end;

  if n mod 2=0 then writeln((a[pos]+a[pos-1])/2:0:1)
    else writeln(a[pos]);
end.
