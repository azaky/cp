var
  s,i,j,ans,step,b:longint;
  line:string[10]; task:ansistring;
  a,t,this,score:array[0..2222] of longint;

begin
  for s := 0 to 1023 do
    begin
      this[s] := 0; score[s] := 0;
      for i := 1 to 10 do
        if s and (1 shl (i-1)) > 0 then
          begin
            inc(score[s]);
            this[s] := this[s] xor (1 shl (i-1));
            if i>1 then this[s] := this[s] xor (1 shl (i-2));
            if i<10 then this[s] := this[s] xor (1 shl i);
          end;
    end;
  repeat
    readln(task); if task = 'end' then break;
    for i:=1 to 10 do
      begin
        readln(line);
        a[i] := 0;
        for j:=1 to 10 do
          if line[j]='O' then a[i] := a[i] + (1 shl (j-1));
      end;
    ans := maxlongint;
    for s:=0 to 1023 do
      begin
        t := a;
        step := 0; b := s;
        for i:=1 to 10 do
          begin
            step := step + score[b];
            t[i+1] := t[i+1] xor b;
            b := t[i] xor this[b];
          end;
        if b = 0 then
          if step < ans then ans := step;
      end;
    writeln(task,' ',ans);
  until false;
end.
