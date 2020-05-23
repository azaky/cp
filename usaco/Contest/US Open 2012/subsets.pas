{
ID: a_zaky01
PROG: subsets
LANG: PASCAL
}

Var
  n,i,p,j,i1,i2,ans:longint;
  a:array[0..22] of longint;
  s,idx:array[0..1 shl 20] of longint;
  subset:array[0..1 shl 20] of boolean;

procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
  
  begin
    i:=l; j:=r; mid:=s[random(r-l+1)+l];
    repeat
      while s[i]<mid do inc(i);
      while s[j]>mid do dec(j);
      if i>j then break;
      temp:=s[i]; s[i]:=s[j]; s[j]:=temp;
      temp:=idx[i]; idx[i]:=idx[j]; idx[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

Begin
    Assign(input, 'subsets.in'); Reset(input);
    Assign(output, 'subsets.out'); Rewrite(output);
  readln(n); randomize; p:=(1 shl n)-1;
  for i:=1 to n do readln(a[i]);
  for i:=1 to p do
    for j:=1 to n do
      if i and (1 shl (j-1))>0 then s[i]:=s[i]+a[j];
  for i:=1 to p do idx[i]:=i;
  sort(1,p);
  i:=1;
  while i<=p do
    begin
      j:=i+1;
      while (j<=p) and (s[j]=s[i]) do inc(j);
      for i1:=i to j-2 do
        for i2:=i1+1 to j-1 do
          subset[idx[i1] xor idx[i2]]:=true;
      i:=j;
    end;
  ans:=0;
  for i:=1 to p do
    if subset[i] then inc(ans);
  writeln(ans);
    Close(input); Close(output);
End.
