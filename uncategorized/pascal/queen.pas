var
  n,i,j:longint;
  count:int64;
  stat,place:array[1..1000,1..1000] of boolean;
  fin,f:text;

procedure print;
  var
    i,j:longint;

  begin
    for i:=1 to n do
      for j:=1 to n do
        if j=n then if place[i,j] then writeln(f,'*') else writeln(f,'.')
          else if place[i,j] then write(f,'*') else write(f,'.');
    writeln(f);
  end;

procedure occupy(b,k:longint);
  var
    i:longint;

  procedure ul(b,k:longint);
    begin
      while (b>0) and (k>0) do
        begin
          stat[b,k]:=true;
          dec(b);
          dec(k);
        end;
    end;

  procedure ur(b,k:longint);
    begin
      while (b>0) and (k<n+1) do
        begin
          stat[b,k]:=true;
          dec(b);
          inc(k);
        end;
    end;

  procedure dl(b,k:longint);
    begin
      while (b<n+1) and (k>0) do
        begin
          stat[b,k]:=true;
          inc(b);
          dec(k);
        end;
    end;

  procedure dr(b,k:longint);
    begin
      while (b<n+1) and (k<n+1) do
        begin
          stat[b,k]:=true;
          inc(b);
          inc(k);
        end;
    end;

  begin
    for i:=1 to n do
      begin
        stat[b,i]:=true;
        stat[i,k]:=true;
      end;
    ul(b,k);
    ur(b,k);
    dl(b,k);
    dr(b,k);
  end;

procedure queen(b:longint);
  var
    i,j,int:longint;
    temp,p:array[1..1000,1..1000] of boolean;

  begin
    for i:=1 to n do
      for j:=1 to n do
        begin
          temp[i,j]:=stat[i,j];
          p[i,j]:=place[i,j];
        end;
    for int:=1 to n do
      begin
        for i:=1 to n do
          for j:=1 to n do
            begin
              stat[i,j]:=temp[i,j];
              place[i,j]:=p[i,j];
            end;
        if not(stat[b,int]) then
          begin
            place[b,int]:=true;
            if b=n then
              begin
                inc(count);
                print;
              end
            else
              begin
                occupy(b,int);
                queen(b+1);
              end;
          end;
      end;
  end;

begin
  assign(fin,'queen.in');
  reset(fin);
  readln(fin,n);
  close(fin);
  assign(f,'queen.out');
  rewrite(f);
  for i:=1 to n do
    for j:=1 to n do
      begin
        stat[i,j]:=false;
        place[i,j]:=false;
      end;
  count:=0;
  queen(1);
  writeln(f,count);
  close(f);
end.