type
  sets=array[0..9999] of longint;

var
  t,kasus,i,j,r,l1,n,ll,lp,rl,rp:longint;
  l,p,ol,op:sets;

procedure swap(var a,b:longint);
  var
    temp:longint;

  begin
    temp:=a;
    a:=b;
    b:=temp;
  end;

procedure qsort(var a,o:sets);
  procedure sort(l,r:longint);
    var
      i,j,p:longint;

    begin
      i:=l;
      j:=r;
      p:=a[(l+r) div 2];
      repeat
        while a[i]<p do inc(i);
        while a[j]>p do dec(j);
        if not(i>j) then
          begin
            if i<j then
              begin
                swap(a[i],a[j]);
                swap(o[i],o[j]);
              end;
            inc(i);
            dec(j);
          end;
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;

  begin
    sort(0,n-1);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=0 to n-1 do read(l[i]);
      for i:=0 to n-1 do read(p[i]);
      for i:=0 to n-1 do op[i]:=i;
      for i:=0 to n-1 do ol[i]:=i;
      qsort(p,op);
      qsort(l,ol);

      if t<kasus then writeln;
    end;
end.
