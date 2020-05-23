const
  max=1000000;
 
var
  n,i,j,ans:longint;
  f,g:array[0..9] of longint;
  
begin
  readln(n);
  for i:=1 to n do
    begin
      if i=1 then
        for j:=0 to 9 do f[j]:=1
      else for j:=0 to 9 do
        case  j of
          0:f[j]:=(g[j]+g[1]) mod max;
          1:f[j]:=(g[j]+g[4]+g[2]+g[0]) mod max;
          2:f[j]:=(g[j]+g[1]+g[5]+g[3]) mod max;
          3:f[j]:=(g[j]+g[2]+g[6]) mod max;
          4:f[j]:=(g[j]+g[1]+g[5]+g[7]) mod max;
          5:f[j]:=(g[j]+g[2]+g[4]+g[6]+g[8]) mod max;
          6:f[j]:=(g[j]+g[3]+g[5]+g[9]) mod max;
          7:f[j]:=(g[j]+g[4]+g[8]) mod max;
          8:f[j]:=(g[j]+g[5]+g[7]+g[9]) mod max;
          9:f[j]:=(g[j]+g[6]+g[8]) mod max;
        end;
      for j:=0 to 9 do g[j]:=f[j];
    end;
  ans:=0;
  for i:=0 to 9 do ans:=(ans+g[i]) mod max;
  writeln(ans);
end.
