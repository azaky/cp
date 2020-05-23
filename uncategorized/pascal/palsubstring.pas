var
  t,kasus,len,k,max,l,r,i,temp:longint;
  s:array[0..1001] of char;
  ch:char;

label
  start,finish;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      len:=0;
      fillchar(s,sizeof(s),' ');
      repeat
        read(ch);
        if ch=' ' then break;
        inc(len);
        s[len]:=ch;
      until false;
      readln(k);
      max:=0;
      for i:=1 to len do
        begin
          {consider the palindrome with odd number of length}
          l:=i;
          r:=i;
          start:
          while ((l>0) and (r<len+1)) and (s[l]=s[r]) do
            begin
              dec(l);
              inc(r);
            end;
          if l<r then
            begin
              inc(l);
              dec(r);
            end;
          temp:=0;
          while temp<k do
            begin
              dec(l);
              inc(r);
              if (l=0) or (r>len) then
                begin
                  inc(l);
                  dec(r);
                  break;
                end;
              inc(temp);
              while ((l-1>0) and (r+1<=len)) and (s[l-1]=s[r+1]) do
                begin
                  dec(l);
                  inc(r);
                end;
            end;
          if (r-l+1)>max then max:=r-l+1;
          if abs(r-l+1) mod 2=0 then goto finish;
          {consider the palindrome with even number of length}
          if i<len then
            begin
              l:=i+1;
              r:=i;
              goto start;
            end;
          finish:
        end;
      writeln(max);
    end;
end.
