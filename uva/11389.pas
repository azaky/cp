uses math;

var
  n,d,r,i,j,ans:longint;
  morning,evening:array[0..111111] of longint;

procedure qsort(var a:array of longint);
  procedure sort(l,r:longint);
    var
      i,j,mid,temp:longint;
    
    begin
      i:=l; j:=r; mid:=a[l];
      repeat
        while a[i]<mid do inc(i);
        while a[j]>mid do dec(j);
        if i>j then break;
        temp := a[i]; a[i] := a[j]; a[j] := temp;
        inc(i);dec(j);
      until false;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;
  
  begin
    sort(1,n);
  end;

begin
  repeat
    readln(n,d,r); if n = 0 then break;
    for i:=1 to n do read(morning[i]);
    for i:=1 to n do read(evening[i]);
    qsort(morning); qsort(evening);
    ans := 0;
    for i:=1 to n do ans := ans + r*max(0,morning[i]+evening[n+1-i]-d);
    writeln(ans);
  until false;
end.
