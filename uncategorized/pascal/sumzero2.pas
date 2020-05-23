type
  data=array[0..2001] of longint;

var
  t,kasus,i,ia,ib,ic,jb,jc,n:longint;
  total:int64;
  a,b,c:data;

procedure qsort(var a:data);
  procedure sort(l,r:longint);
    var
      i,j,p,temp:longint;

    begin
      i:=l;
      j:=r;
      p:=a[(l+r) div 2];
      repeat
        while a[i]<p do inc(i);
        while a[j]>p do dec(j);
        if not(i>j) then
          begin
            temp:=a[i];
            a[i]:=a[j];
            a[j]:=temp;
            inc(i);
            dec(j);
          end;
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;

  begin
    sort(1,n);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      fillchar(a,sizeof(a),0);
      fillchar(b,sizeof(b),0);
      fillchar(c,sizeof(c),0);
      for i:=1 to n do read(a[i]);
      for i:=1 to n do read(b[i]);
      for i:=1 to n do read(c[i]);
      qsort(b);
      qsort(c);
      total:=0;
{
      writeln;
      for i:=1 to n-1 do write(a[i],' ');
      writeln(a[n]);
      for i:=1 to n-1 do write(b[i],' ');
      writeln(b[n]);
      for i:=1 to n-1 do write(c[i],' ');
      writeln(c[n]);
      writeln;
}
      for ia:=1 to n do
        begin
          ib:=1;
          ic:=n;
          repeat
            if a[ia]+b[ib]+c[ic]<0 then inc(ib);
            if a[ia]+b[ib]+c[ic]>0 then dec(ic);
            if a[ia]+b[ib]+c[ic]=0 then
              begin
                jb:=ib;
                jc:=ic;
                while (ib<=n) and (b[jb]=b[ib]) do inc(ib);
                while (ic>0) and (c[jc]=c[ic]) do dec(ic);
                total:=total+(ib-jb)*(jc-ic);
              end;
          until (ib>n) or (ic=0);
        end;
      writeln(total);
    end;
end.
