uses math;

var
  kasus,tc,n,i,time,size,na:longint;
  a:array[-1..111111] of longint;
  ans:array[-1..11111,0..2] of longint;

procedure sort(l,r:longint);
  var
    temp,i,j,mid:longint;
  begin
    i:=l; j:=r; mid:=a[(l+r) div 2];
    repeat
      while a[i]<mid do inc(i);
      while a[j]>mid do dec(j);
      if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
      inc(i);dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure send(x,y:longint);
  begin
    inc(na); ans[na][1] := x; ans[na][2] := y;
    time := time + max(a[x],a[y]);
  end;

begin
a[-1] := -1000;
  read(kasus);
  for tc:=1 to kasus do
    begin
      read(n);
      for i:=1 to n do read(a[i]);
      if n=1 then
        begin
          writeln(a[1]);
          writeln(a[1]);
          if tc<kasus then writeln;
          continue;
        end;
      if n=0 then
        begin
          writeln(0);
          if tc<kasus then writeln;
          continue;
        end;
      sort(1,n);
      size := n; time := 0; na := 0;
      while size>3 do
        begin
          //sending a[size] and a[size-1]
          if a[size-1]+a[1] < 2*a[2] then
            begin
              send(1,size);send(1,-1);send(1,size-1);send(1,-1);
              size := size-2;
            end
          else
            begin
              send(1,2);send(1,-1);send(size-1,size);send(2,-1);
              size := size-2;
            end;
        end;
      if size=2 then
        begin
          send(1,2);
        end
      else
        begin
          send(1,3);send(1,-1);send(1,2);
        end;
      writeln(time);
      for i:=1 to na do
        begin
          if ans[i][2]<0 then writeln(a[ans[i][1]]) else writeln(a[ans[i][1]],' ',a[ans[i][2]]);
        end;
      if tc<kasus then writeln;
    end;
end.
