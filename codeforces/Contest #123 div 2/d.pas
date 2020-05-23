var
  n,i,nn,ans:longint;
  b,k:array[0..111111] of int64;

procedure sort(l,r:longint);
  var
    i,j,p:longint;
    temp,km,bm:int64;
  
  begin
    //writeln(l,' ',r);
    i := l; j := r; p := random(r-l+1)+l; km := k[p]; bm := b[p];
    repeat
      while ((b[i]*km>bm*k[i]) and (k[i]*km>0)) or ((b[i]*km<bm*k[i]) and (k[i]*km<0)) do inc(i);
      while ((b[j]*km>bm*k[j]) and (k[j]*km<0)) or ((b[j]*km<bm*k[j]) and (k[j]*km>0)) do dec(j);
      if i>j then break;
      temp := k[i]; k[i]:=k[j]; k[j]:=temp;
      temp := b[i]; b[i]:=b[j]; b[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n);
  for i:=1 to n do readln(k[i],b[i]);
  nn := 0;
  for i:=1 to n do
    if k[i]<>0 then
      begin
        inc(nn); k[nn]:=k[i]; b[nn]:=b[i];
      end;
  n := nn;
  randomize; sort(1,n);
  //writeln('sorted!');
  ans := 0; k[0] := 1; b[0] := maxlongint;
  for i:=1 to n do
    begin
      if b[i-1]*k[i]<>b[i]*k[i-1] then inc(ans);
    end;
  writeln(ans);
end.
