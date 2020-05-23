var
  i,t,kasus,n:longint;
  f:array[1..10000] of ansistring;

function sum(a,b:ansistring):ansistring;
  var
    k,sisa,n1,n2,x:integer;

  begin
    if length(b)>length(a) then sum:=sum(b,a)
      else
        begin
          n1:=length(a);
          n2:=length(b);
          sisa:=0;
          k:=1;
          sum:='';
          while k<=n1 do
            begin
              x:=ord(a[n1+1-k])-48+sisa;
              if k<=n2 then x:=x+ord(b[n2+1-k])-48;
              sum:=char((x mod 10)+48)+sum;
              if x>9 then sisa:=1
                else sisa:=0;
              inc(k);
            end;
          if sisa<>0 then sum:='1'+sum;
        end;
  end;

begin
  f[1]:='2';
  f[2]:='5';
  f[3]:='13';
  for i:=4 to 10000 do f[i]:=sum(sum(sum(f[i-1],f[i-1]),f[i-2]),f[i-3]);
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      writeln(f[n]);
    end;
end.
