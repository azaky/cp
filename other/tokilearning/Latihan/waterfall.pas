var
  v,h,v1,h1,v2,h2,n,k,i,j,ht,vt:longint;
  ans:int64;
  batu:array[0..501,0..501] of boolean;
  fl,fr:array[0..501] of int64;
  f:array[0..501,0..501] of int64;

begin
  readln(v,h,n);
  for k:=1 to n do
    begin
      readln(v1,h1,v2,h2);
      for i:=v1 to v2 do
        for j:=h1 to h2 do
          batu[i,j]:=true;
    end;
  for vt:=v downto 0 do
    begin
      for ht:=1 to h do
        if batu[vt,ht] then fl[ht]:=-1
          else if batu[vt+1,ht] then fl[ht]:=fl[ht-1]
            else fl[ht]:=f[vt+1,ht];
      for ht:=h downto 1 do
        if batu[vt,ht] then fr[ht]:=-1
          else if batu[vt+1,ht] then fr[ht]:=fr[ht+1]
            else fr[ht]:=f[vt+1,ht];
      for ht:=1 to h do
        if batu[vt,ht] then f[vt,ht]:=-1
          else if batu[vt+1,ht] then f[vt,ht]:=fl[ht]+fr[ht]+1
            else f[vt,ht]:=f[vt+1,ht];
    end;
  ans:=0;
  for ht:=1 to h do
    if f[0,ht]>ans then ans:=f[0,ht];
  writeln(ans);
end.
