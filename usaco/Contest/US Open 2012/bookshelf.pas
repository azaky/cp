{
ID: a_zaky01
PROG: bookshelf
LANG: PASCAL
}

uses math;

Var
  n,i,j,hh:longint;
  l:int64;
  h:array[0..111111] of longint;
  w,sum,best:array[0..111111] of int64;

Begin
    Assign(input, 'bookshelf.in'); Reset(input);
    Assign(output, 'bookshelf.out'); Rewrite(output);
  readln(n,l);
  for i:=1 to n do readln(h[i],w[i]);
  for i:=1 to n do sum[i]:=sum[i-1]+w[i];
  best[n+1]:=0;
  for i:=n downto 1 do
    begin
      best[i]:=h[i]+best[i+1];
      j:=i+1; hh:=h[i];
      while (j<=n) and (sum[j]-sum[i-1]<=l) do
        begin
          hh:=max(hh,h[j]);
          best[i]:=min(best[i],int64(hh)+best[j+1]);
          inc(j);
        end;
    end;
  //for i:=1 to n do write(best[i]:10);writeln;
  writeln(best[1]);
    Close(input); Close(output);
End.
