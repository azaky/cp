uses math;

var
  tc,kasus,n,d,p,i,ans:longint;
  s:ansistring;
  t:array[-1..1111] of boolean;
  a:array[-1..1111] of longint;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(n,d);
      readln(s);
      p := 1; i := 0;
      while p<=length(s) do
        begin
          while (s[p]<>'B') and (s[p]<>'S') do inc(p);
          inc(i);
          t[i] := s[p]='S'; inc(p,2); a[i] := 0;
          repeat
            a[i] := 10*a[i] + ord(s[p]) - ord('0');
            inc(p);
          until not (s[p] in ['0'..'9']);
          if i = n then break;
        end;
      t[n+1] := false; a[n+1] := d;
      t[0] := false; a[0] := 0;
      ans := 0;
      for i:=1 to n do
        begin
          ans := max(ans,a[i]-a[i-1]);
          ans := max(ans,a[i+1]-a[i]);
          if t[i] then ans := max(ans,a[i+1]-a[i-1]);
        end;
      writeln('Case ',kasus,': ',ans);
    end;
end.
