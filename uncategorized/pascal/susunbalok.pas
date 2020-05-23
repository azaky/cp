var
  t,kasus,n,m,i,k,input:longint;
  count:array[1..1000] of integer;
  a:array[1..8000] of integer;
  arr,stat:array[0..1000,0..8000] of boolean;

function f(m,k:integer):boolean;
  begin
    if m=0 then f:=true
      else if (m<0) or (k=0) then f:=false
        else
          begin
            if not stat[m,k] then
              begin
                stat[m,k]:=true;
                arr[m,k]:=f(m,k-1) or f(m-a[k],k-1);
              end;
            f:=arr[m,k];
          end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(count,sizeof(count),0);
      fillchar(arr,sizeof(arr),false);
      fillchar(stat,sizeof(stat),false);
      readln(n,m);
      k:=0;
      for i:=1 to n do
        begin
          read(input);
          if input<=m then
            if count[input]<m div input then
              begin
                inc(k);
                a[k]:=input;
                inc(count[input]);
              end;
        end;
      if f(m,k) then writeln('YA')
        else writeln('TIDAK');
    end;
end.
