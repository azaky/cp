var
  s:string;
  n,i,count,ans:longint;
  a:array[1..13] of integer;
  num:array[1..1600000] of int64;

procedure express(pos:integer; cur,next:int64; has:boolean);
  begin
    //writeln(' ':pos*2,pos,' ',cur,' ',next,' ',has);
    if pos=n then
      begin
        inc(count); num[count]:=cur+next;
        if has then
          begin
            inc(count); num[count]:=cur-next;
          end;
        exit;
      end;
    inc(pos);
    express(pos,cur,10*next+a[pos],has);
    if pos>1 then express(pos,cur+next,a[pos],true);
    if has then express(pos,cur-next,a[pos],true);
  end;

procedure sort(l,r:longint);
  var
    i,j:longint;
    mid,temp:int64;
  
  begin
    i:=l; j:=r; mid:=num[(l+r) div 2];
    repeat
      while num[i]<mid do inc(i);
      while num[j]>mid do dec(j);
      if i>j then break else temp:=num[i]; num[i]:=num[j]; num[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(s); n:=length(s);
  for i:=1 to n do a[i]:=ord(s[i])-ord('0');
  count:=0; ans:=1; express(0,0,0,false);
  //for i:=1 to count do write(num[i],' '); writeln;
  sort(1,count);
  for i:=2 to count do
    if num[i]<>num[i-1] then inc(ans);
  writeln(ans);
end.
