type
  point = record x,y: longint; end;

const maxn = 111111;

var
  i, n : longint;
  p:array[0..maxn] of point;
  x,y:array[0..maxn] of longint;
  xx,a:array[0..9] of longint;
  used:array[0..9] of boolean;

procedure qsort(var a : array of longint);
  procedure sort(l,r:longint);
    var
      i,j,temp,mid:longint;
    
    begin
      i := l; j := r;
      mid := a[random(r-l+1)+l];
      repeat
        while (a[i] < mid) do inc(i);
        while (a[j] > mid) do dec(j);
        if (i <= j) then
          begin
            temp := a[i]; a[i] := a[j]; a[j] := temp;
            inc(i); dec(j);
          end;
      until i > j;
      if (i < r) then sort(i,r);
      if (l < j) then sort(l,j);
    end;
  
  begin
    sort(1,n);
  end;

procedure perm(s : longint);
  var
    i, up, left, right, down : longint;
    t : array[0..9] of longint;
  
  begin
    if (s > 9) then
      begin
        up := xx[1] + xx[2] + xx[3];
        left := xx[1] + xx[4] + xx[7];
        right := xx[3] + xx[6] + xx[9];
        down := xx[7] + xx[8] + xx[9];
        if y[down] = y[down+1] then exit;
        if x[left] = x[left+1] then exit;
        if y[n-up] = y[n-up+1] then exit;
        if x[n-right] = x[n-right+1] then exit;
        //candidate answer
        //writeln('yeay');
        for i := 1 to 9 do t[i] := 0;
        for i := 1 to n do
          begin
            if (p[i].x <= x[left]) then
              begin
                if (p[i].y > y[n-up]) then inc(t[1])
                else if (p[i].y > y[down]) then inc(t[4])
                else inc(t[7]);
              end
            else if (p[i].x <= x[n-right]) then
              begin
                if (p[i].y > y[n-up]) then inc(t[2])
                else if (p[i].y > y[down]) then inc(t[5])
                else inc(t[8]);
              end
            else
              begin
                if (p[i].y > y[n-up]) then inc(t[3])
                else if (p[i].y > y[down]) then inc(t[6])
                else inc(t[9]);
              end;
          end;
        //for i := 1 to 9 do write(t[i],' '); writeln;
        //for i := 1 to 9 do write(xx[i],' '); writeln;
        
        for i := 1 to 9 do
          if xx[i] <> t[i] then exit;
        //yeay!
        writeln(x[left]+0.5:0:17,' ',x[n-right]+0.5:0:17);
        writeln(y[down]+0.5:0:17,' ',y[n-up]+0.5:0:17);
        halt;
      end
    else
      begin
        for i := 1 to 9 do
          if not used[i] then
            begin
              xx[s] := a[i];
              used[i] := true; perm(s+1); used[i] := false;
            end;
      end;
  end;

begin
randomize;
  read(n);
  for i := 1 to n do read(p[i].x,p[i].y);
  for i := 1 to 9 do read(a[i]);
  for i := 1 to n do
    begin
      x[i] := p[i].x;
      y[i] := p[i].y;
    end;
  qsort(x); qsort(y);
  perm(1);
  writeln(-1);
end.
