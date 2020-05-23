{
ID: a_zaky01
PROG: humble
LANG: PASCAL
}
 
var
  k,n,i,deg,sum,count,temp:longint;
  p:array[1..100] of longint;
  h:array[1..1000000] of int64;
 
procedure fill(deg:integer);
  procedure add(num,d,m:longint);
    var
      i:longint;
     
    begin
      if d=deg then
        begin
          inc(count);
          h[count]:=num;
        end
      else for i:=m to k do add(num*p[i],d+1,i);
    end;
  
  begin
    add(1,0,1);
  end;
 
procedure sort(l,r:longint);
  var
    i,j,mid,temp:longint;
    
  begin
    i:=l;
    j:=r;
    mid:=h[(l+r) div 2];
    repeat
      while h[i]<mid do inc(i);
      while h[j]>mid do dec(j);
      if i<=j then
        begin
          if i<j then
            begin
              temp:=h[i];
              h[i]:=h[j];
              h[j]:=temp;
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
 
begin
  assign(input,'humble.in'); reset(input);
  assign(output,'humble.out'); rewrite(output);
  readln(k,n);
  for i:=1 to k do read(p[i]);
  count:=0;
  i:=0;
  repeat
    inc(i);
    fill(i);
  until count>=2*n;
  sort(1,count);
  writeln(h[n]);
  close(input); close(output);
end.
