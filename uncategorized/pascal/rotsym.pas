{
ID: a_zaky01
PROB: rotsym
LANG: PASCAL
}

var
  n,k,i,j,p,ans:longint;
  x0,y0:array[1..1000] of longint;
  x,y:array[1..1000000] of longint;

procedure sort(l,r:longint);
  var
    i,j,midx,midy,temp:longint;
    
  begin
    i:=l; j:=r;
    midx:=x[(l+r) div 2];
    midy:=y[(l+r) div 2];
    repeat
      while (x[i]<midx) or ((x[i]=midx) and (y[i]<midy)) do inc(i);
      while (x[j]>midx) or ((x[j]=midx) and (y[j]>midy)) do dec(j);
      if i<=j then
        begin
          temp:=x[i]; x[i]:=x[j]; x[j]:=temp;
          temp:=y[i]; y[i]:=y[j]; y[j]:=temp;
          inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
  
begin
  assign(input,'rotsym.in');
  assign(output,'rotsym.out');
  reset(input);
  rewrite(output);
 
  readln(n);
  for i:=1 to n do readln(x0[i],y0[i]);
  k:=0;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        inc(k);
        x[k]:=x0[i]+x0[j];
        y[k]:=y0[i]+y0[j];
      end;
  sort(1,k);
  ans:=0;
  p:=1;
  for i:=2 to k do
    if (x[i]=x[i-1]) and (y[i]=y[i-1]) then inc(p)
      else
        begin
          ans:=ans+((p*(p-1)) div 2);
          p:=1;
        end;
  writeln(ans);
  
  close(input);
  close(output);
end.

