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
      ll:=0;
      lp:=0;
      rl:=n-1;
      rp:=n-1;
      for i:=1 to n do
        begin
          if (p[rp]-l[ll])>=(l[rl]-p[lp]) then
            begin
              r:=rp;
              while (p[r-1]=p[rp]) and (r-1>=lp) do dec(r);
              if r<>rp then
                for j:=rp-1 downto r do
                  if op[rp]>op[j] then swap(op[rp],op[j]);
              l1:=ll;
              while (l[l1+1]=l[ll]) and (l1+1<=rl) do inc(l1);
              if l1<>ll then
                for j:=ll+1 to l1 do
                  if ol[ll]>ol[j] then swap(ol[ll],ol[j]);
              writeln(ol[ll],' ',op[rp],' ',(p[rp]-l[ll])*(p[rp]-l[ll]));
              inc(ll);
              dec(rp);
            end
          else
            begin
              r:=rl;
              while (l[r-1]=l[rl]) and (r-1>=ll) do dec(r);
              if r<>rl then
                for j:=rl-1 downto r do
                  if ol[rl]>ol[j] then swap(ol[rl],ol[j]);
              l1:=lp;
              while (l[l1+1]=l[lp]) and (l1+1<=rp) do inc(l1);
              if l1<>lp then
                for j:=lp+1 to l1 do
                  if op[lp]>op[j] then swap(op[lp],op[j]);
              writeln(ol[rl],' ',op[lp],' ',(l[rl]-p[lp])*(l[rl]-p[lp]));
              inc(lp);
              dec(rl);
            end;
        end;
      if t<kasus then writeln;
    end;
end.