var
  n,k,ans:extended;

function fact(n:extended):extended;
  begin
    exit(n*ln(n)-n+ln(n*(1+4*n*(1+2*n)))/6+ln(Pi)/2);
  end;

begin
  repeat
    readln(n,k);
    ans := fact(n) - fact(k) - fact(n-k);
    writeln(trunc(ans/ln(10))+1);
  until eof;
end.
