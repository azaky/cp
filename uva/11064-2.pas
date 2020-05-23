var
  n,t,q,k,limit,i:longint;
  p,e:array[0..111] of longint;

begin
  repeat
    readln(n);
    t := n;
    q := 2;
    k := 0;
    while t>1 do
      begin
        limit := trunc(sqrt(t));
        while (q<=limit) and (t mod q<>0) do inc(q);
        if q>limit then
          begin
            inc(k); p[k] := t; e[k] := 1;
            break;
          end;
        inc(k); p[k] := q; e[k] := 0;
        while (t mod q=0) do
          begin
            inc(e[k]); t := t div q;
          end;
      end;
    for i:=1 to k do writeln(p[i]:5,e[i]:5);
  until eof;
end.
