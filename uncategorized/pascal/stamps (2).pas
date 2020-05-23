{
ID: a_zaky01
PROG: stamps
LANG: PASCAL
}
 
var
  k,n,i,ans,min:longint;
  a:array[1..50] of integer;
  count:array[0..2000000] of byte;
  
begin
  assign(input,'stamps.in'); reset(input);
  assign(output,'stamps.out'); rewrite(output);
  readln(k,n);
  for i:=1 to n do read(a[i]);
  ans:=0;
  repeat
    inc(ans);
    min:=k+1;
    for i:=1 to n do
      if ans>=a[i] then
        if count[ans-a[i]]<min then min:=count[ans-a[i]];
    count[ans]:=min+1;
  until count[ans]>k;
  writeln(ans-1);
  close(input); close(output);
end.
 