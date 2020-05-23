const
  inf = 1e18;
  eps = 1e-9;

var
  n,i:longint;
  last,area:extended;
  x,s,l,r:array[0..111111] of extended;

function same(a,b:extended):boolean;
  begin
    exit(abs(a-b)<eps);
  end;

function less(a,b:extended):boolean;
  begin
    if same(a,b) then exit(false) else exit(a<b);
  end;

procedure swap(var a,b:extended);
  var
    temp:extended;
  
  begin
    temp:=a; a:=b; b:=temp;
  end;

procedure sort(ll,rr:longint);
  var
    p,i,j:longint;
    midl,midr:extended;
  
  begin
    i:=ll; j:=rr; p:=random(rr-ll+1)+ll; midl:=l[p]; midr:=r[p];
    repeat
      while less(l[i],midl) or (same(l[i],midl) and less(midr,r[i])) do inc(i);
      while less(midl,l[j]) or (same(l[j],midl) and less(r[j],midr)) do dec(j);
      if i>j then break;
      //swap(s[i],s[j]); swap(x[i],x[j]);
      swap(l[i],l[j]); swap(r[i],r[j]);
      inc(i); dec(j);
    until i>j;
    if ll<j then sort(ll,j);
    if i<rr then sort(i,rr);
  end;

begin
  randomize;
  readln(n);
  for i:=1 to n do
    begin
      readln(x[i],s[i]);
      l[i]:=x[i]-s[i]/sqrt(2);
      r[i]:=x[i]+s[i]/sqrt(2);
    end;
  sort(1,n);
  last:=-inf; area:=0;
  for i:=1 to n do
    begin
      //writeln(s[i]:0:2,' ',x[i]:0:2,' ',l[i]:0:2,' ',r[i]:0:2);
      if less(r[i],last) then continue;
      area:=area+(r[i]-l[i])*(r[i]-l[i])/4;
      if less(l[i],last) then area:=area-(last-l[i])*(last-l[i])/4;
      last:=r[i];
      //writeln(last:0:2,' ',area:0:2);
    end;
  writeln(area:0:1);
end.
