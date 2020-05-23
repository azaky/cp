const maxn = 1111111;

var
  v,w:array[0..maxn] of int64;
  n,l,i,j,now,nans:longint;
  vans,wans,temp,mmod,wnow:int64;
  line,ans:ansistring;
  s:array[0..maxn] of char;

procedure sort(l,r:longint);
  var
    i,j,p:longint;
    temp,midv,midw:int64;
  
  begin
    i := l; j := r; p := random(r-l+1)+l; midv := v[p]; midw := w[p];
    while (i <= j) do
      begin
        while (v[i] < midv) or ((v[i] = midv) and (w[i] < midw)) do inc(i);
        while (v[j] > midv) or ((v[j] = midv) and (w[j] > midw)) do dec(j);
        if (i > j) then break;
        temp := v[i]; v[i] := v[j]; v[j] := temp;
        temp := w[i]; w[i] := w[j]; w[j] := temp;
        inc(i); dec(j);
      end;
    if (l < j) then sort(l,j);
    if (i < r) then sort(i,r);
  end;

begin
  randomize; v[0] := -1;
  while not eof do
    begin
      readln(line);
      n := 0;
      i := 1;
      while (line[i] < '0') or (line[i] > '9') do inc(i);
      while ('0' <= line[i]) and (line[i] <= '9') do
        begin
          n := 10*n + ord(line[i]) - 48;
          inc(i);
        end;
      while (line[i] < 'a') or (line[i] > 'z') do inc(i);
      l := 0;
      while ('a' <= line[i]) and (line[i] <= 'z') do
        begin
          inc(l);
          s[l] := line[i];
          inc(i);
        end;
      //baca input ends here
      mmod := 1;
      for i := 1 to n-1 do mmod := mmod * int64(26);
      
      temp := 0;
      for i := 1 to n do temp := temp * int64(26) + ord(s[i]) - ord('a');
      v[1] := temp; w[1] := 1;
      for i := 2 to l-n+1 do
        begin
          temp := (temp mod mmod) * int64(26) + ord(s[i+n-1]) - ord('a');
          v[i] := temp; w[i] := i;
        end;
      sort(1,l-n+1);
      now := 0; nans := 0; wnow := maxlongint;
      for i := 1 to l-n+1 do
        begin
          if (v[i] = v[i-1]) then
            begin
              inc(now);
              if (w[i] < wnow) then wnow := w[i];
            end
          else
            begin
              now := 1;
              wnow := w[i];
            end;
          if (now > nans) or ((now = nans) and (wnow < wans)) then
            begin
              nans := now;
              vans := v[i];
              wans := wnow;
            end;
        end;
      //writeln(vans,' ',wans);
      ans := '';
      for i := 1 to n do ans := ans + s[i+wans-1];
      writeln(ans);
    end;
end.
