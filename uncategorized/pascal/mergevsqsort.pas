var
  a, arr, b, arrtemp, x: array[1..1000000] of longint;
  n,i : longint;
  count:int64;
  fin,fout:text;

procedure merge(awal,akhir : longint);
var
  i,j,mid,k : longint;
begin
  if (awal = akhir) then inc(count)

  else begin
    mid := (awal + akhir) div 2;
    inc(count);

    merge(awal, mid);
    merge(mid+1, akhir);

    i := awal;
    j := mid+1;
    k := awal;
    count:=count+3;

    while (i <= mid) and (j <= akhir) do begin
      if (arr[i] < arr[j]) then begin
        arrtemp[k] := arr[i];
        i := i + 1;
        count:=count+2;
      end else begin
        arrtemp[k] := arr[j];
        j := j + 1;
        count:=count+2;
      end;
      k := k + 1;
      inc(count);
    end;

    while (i <= mid) do begin
      arrtemp[k] := arr[i];
      i := i + 1;
      k := k + 1;
      count:=count+3;
    end;

    while (j <= akhir) do begin
      arrtemp[k] := arr[j];
      j := j + 1;
      k := k + 1;
      count:=count+3;
    end;

    for i := awal to akhir do begin
      arr[i] := arrtemp[i];
      inc(count);
    end;
  end;
end;

procedure qsort(l,r:longint);
  var
    i,j,x,temp:longint;

  begin
    i:=l;
    j:=r;
    x:=a[(l+r) div 2];
    count:=count+3;
    repeat
      while a[i]<x do
        begin
          inc(i);
          inc(count);
        end;
      while a[j]>x do
        begin
          dec(j);
          inc(count);
        end;
      if not(i>j) then
        begin
          temp:=a[i];
          a[i]:=a[j];
          a[j]:=temp;
          inc(i);
          dec(j);
          count:=count+5;
        end;
    until i>j;
    if l<j then qsort(l,j);
    if i<r then qsort(i,r);
  end;

procedure bubble;
  var
    i,j,temp:longint;

  begin
    for i:=1 to n do
      for j:=i+1 to n do
        if b[j]<b[i] then
          begin
            temp:=b[i];
            b[i]:=b[j];
            b[j]:=temp;
            count:=count+3;
          end
        else inc(count);
  end;

procedure maxsort;
  var
    i,j,max,imax,temp:longint;

  begin
    for i:=n downto 1 do
      begin
        max:=0;
        inc(count);
        for j:=1 to i do
          begin
            if x[j]>max then
              begin
                max:=x[j];
                imax:=j;
                inc(count);
              end;
            inc(count);
          end;
        if imax<>i then
          begin
            temp:=x[i];
            x[i]:=x[imax];
            x[imax]:=temp;
            count:=count+2;
          end
        else inc(count);
      end;
  end;

begin
  assign(fin,'tes.in');
  assign(fout,'tes.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i := 1 to n do
    begin
      readln(fin,a[i]);
      arr[i]:=a[i];
      b[i]:=a[i];
      x[i]:=b[i];
    end;

  count:=0;
  merge(1,n);
  writeln(fout,'mergesort');
{
  for i := 1 to n do begin
    if i=n then writeln(fout,arr[i] )
      else write(fout,arr[i],' ');
  end;
}
  writeln(fout,'complexity = ',count);
  writeln(fout);

  count:=0;
  qsort(1,n);
  writeln(fout,'quicksort');
{
  for i := 1 to n do begin
    if i=n then writeln(fout,a[i] )
      else write(fout,a[i],' ');
  end;
}
  writeln(fout,'complexity = ',count);
  writeln(fout);

  count:=0;
  bubble;
  writeln(fout,'bubblesort');
{
  for i := 1 to n do begin
    if i=n then writeln(fout,b[i] )
      else write(fout,b[i],' ');
  end;
}
  writeln(fout,'complexity = ',count);
  writeln(fout);

  count:=0;
  maxsort;
  writeln(fout,'maxsort');
  writeln(fout,'complexity = ',count);

  close(fin);
  close(fout);
end.
