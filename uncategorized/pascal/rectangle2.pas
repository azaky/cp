program rectangle;

const
  maxn=1000;
  maxrec=1000000;

var
  i,j,k,temp,p,l:longint;
  count,time:longint;
  gcd,rec:array[0..maxn,0..maxn] of longint;

begin
{
  assign(input,'tes.in');
  assign(output,'tes.out');
  reset(input);
  rewrite(output);
}

  //generate greatest common divisor of every pair of integers from 0..n;
  for i:=0 to maxn do
    for j:=i to maxn do
      begin
      if i=0 then
        begin
          gcd[i,j]:=j;
          gcd[j,i]:=j;
        end
      else if j mod i=0 then
        begin
          gcd[i,j]:=i;
          gcd[j,i]:=i;
        end
      else
        begin
          gcd[i,j]:=gcd[j-i,i];
          gcd[j,i]:=gcd[i,j];
        end;
      inc(count,2);
    end;
  writeln(count);
  count:=0;

  //generate function rec
  for i:=1 to maxn do
    for j:=i to maxn do
      begin
        if j mod i=0 then
          begin
            rec[i,j]:=j div i;
            rec[j,i]:=rec[i,j];
            inc(count,2);
            continue;
          end;
        if gcd[i,j]>1 then
          begin
            rec[i,j]:=rec[i div gcd[i,j],j div gcd[i,j]];
            rec[j,i]:=rec[i,j];
            inc(count,2);
            continue;
          end;
        rec[i,j]:=maxrec;
        for k:=1 to j div 2 do
          begin
            temp:=rec[i,k]+rec[i,j-k];
            if temp<rec[i,j] then rec[i,j]:=temp;
            inc(count,2);
          end;
        for k:=1 to i div 2 do
          begin
            temp:=rec[k,j]+rec[i-k,j];
            if temp<rec[i,j] then rec[i,j]:=temp;
            inc(count,2);
          end;
        rec[j,i]:=rec[i,j];
        inc(count,2);
      end;
  writeln(count);

  while not eof do
    begin
      readln(p,l);
      writeln(rec[p,l]);
    end;
{
  close(input);
  close(output);
}
end.
