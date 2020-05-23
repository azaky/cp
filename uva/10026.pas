type tipe = record idx,f,t:longint; end;

var
  tc,kasus,n,i:longint;
  a:array[0..11111] of tipe;

function better(a,b:tipe):boolean;
  begin
    if (b.f*a.t < b.t*a.f) then exit(true);
    if (b.f*a.t > b.t*a.f) then exit(false);
    exit(a.idx<b.idx);
  end;

procedure sort(l,r:longint);
  var
    i,j:longint;
    mid,temp:tipe;
  
  begin
    i := l; j := r; mid := a[(l+r) div 2];
    repeat
      while better(a[i],mid) do inc(i);
      while better(mid,a[j]) do dec(j);
      if i>j then break else temp := a[i]; a[i]:=a[j]; a[j] := temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(kasus);
  for tc:=1 to kasus do
    begin
      readln(n);
      for i:=1 to n do a[i].idx := i;
      for i:=1 to n do readln(a[i].t,a[i].f);
      sort(1,n);
      for i:=1 to n-1 do write(a[i].idx,' ');writeln(a[n].idx);
      if tc<kasus then writeln;
    end;
end.
