{
ID: a_zaky01
PROG: humble
LANG: PASCAL
}

const
  max=2147483647;

var
  k,n,i,j,min:longint;
  p:array[1..100] of longint;
  h:array[0..100000] of int64;
  temp:array[1..100] of longint;

begin
  assign(input,'humble.in'); reset(input);
  assign(output,'humble.out'); rewrite(output);
  readln(k,n);
  for i:=1 to k do read(p[i]);
  h[0]:=1;
  //fillchar(temp,sizeof(temp),0);
  for i:=1 to n do
    begin
      min:=max;
      for j:=1 to k do
        if p[j]*h[temp[j]]<min then min:=p[j]*h[temp[j]];
      h[i]:=min;
      for j:=1 to k do
        if p[j]*h[temp[j]]=min then inc(temp[j]);
    end;
  writeln(h[n]);
  close(input);
  close(output);
end.
