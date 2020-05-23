var
  tc,kasus,n,i,j,max:longint;
  stat:boolean;
  h,t,lim:array[1..100] of longint;

procedure sort(l,r:longint);
  var
    i,j,p,temp:longint;

  begin
    i:=l;
    j:=r;
    p:=t[(l+r) div 2];
    repeat
      while t[i]<p do inc(i);
      while t[j]>p do dec(j);
      if i<=j then
        begin
          if i<j then
            begin
              temp:=t[i];
              t[i]:=t[j];
              t[j]:=temp;
              temp:=h[i];
              h[i]:=h[j];
              h[j]:=temp;
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(n);
      for i:=1 to n do read(t[i]);
      for i:=1 to n do read(h[i]);
      sort(1,n);
      lim[1]:=1;
      max:=1;
      for i:=2 to n do
        begin
          stat:=false;
          for j:=max downto 1 do
            if (t[lim[j]]<t[i]) and (h[lim[j]]<=h[i]) then
              begin
                lim[j]:=i;
                stat:=true;
                break;
              end;
          if not stat then
            begin
              inc(max);
              lim[max]:=i;
            end;
        end;
      writeln(max);
    end;
end.
