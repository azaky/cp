{
ID: a_zaky01
PROG: zerosum
LANG: PASCAL
}

type
  sign=array[1..9] of char;

var
  fin,fout:text;
  n,i:integer;
  count:longint;
  arr:sign;
  hasil:array[1..1000] of string;

procedure zero(k:integer; arr:sign);
  procedure generate;
    var
      i:integer;
      sum,num:longint;
      temp:char;

    begin
      sum:=0;
      temp:='+';
      i:=1;
      while i<=n do
        begin
          num:=i;
          while (arr[i]=' ') and (i<n) do
            begin
              num:=num*10;
              inc(i);
              num:=num+i;
            end;
          case temp of
              '+':sum:=sum+num;
              '-':sum:=sum-num;
            end;
          if i<=n then
            begin
              temp:=arr[i];
              inc(i);
            end;
        end;
      if sum=0 then
        begin
          inc(count);
          hasil[count]:='';
          for i:=1 to n-1 do hasil[count]:=hasil[count]+char(i+48)+arr[i];
          hasil[count]:=hasil[count]+char(n+48);
        end;
    end;

  begin
    if k=n then generate
      else
        begin
          arr[k]:=' ';
          zero(k+1,arr);
          arr[k]:='+';
          zero(k+1,arr);
          arr[k]:='-';
          zero(k+1,arr);
        end;
  end;

begin
  assign(fin,'zerosum.in');
  assign(fout,'zerosum.out');
  reset(fin);
  rewrite(fout);
  count:=0;
  readln(fin,n);
  zero(1,arr);
  for i:=1 to count do writeln(fout,hasil[i]);
  close(fin);
  close(fout);
end.
