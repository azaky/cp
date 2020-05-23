{
ID: a_zaky01
PROG: hidden
LANG: PASCAL
}

var
  n,ans,i,c,p:longint;
  ch,least:char;
  init,best,temp,cur:ansistring;
  pos:array[1..100000] of longint;

begin
  
  assign(input,'hidden.in'); reset(input);
  assign(output,'hidden.out'); rewrite(output);
  
  readln(n);
  init:=''; least:='z';
  for i:=1 to n do
    repeat
      read(ch);
      if ch in ['a'..'z'] then
        begin
          init:=init+ch;
          if ch<least then least:=ch;
          break;
        end;
    until false;
  init:=init+init;
  ans:=0; p:=1;
  while p<n do
    begin
      i:=1;
      while (i<=n) and (init[ans+i]=init[p+i]) do inc(i);
      if i>n then break;
      if init[ans+i]>init[p+i] then ans:=p
        else p:=p+i-1;
      inc(p);
    end;
  writeln(ans);
  
  close(input);
  close(output);
  
end.

