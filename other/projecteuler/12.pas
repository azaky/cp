const
  max = 20000;

var
  f:array[1..max] of longint;
  k,c,t,i:longint;

begin
  f[1]:=1;
  for k:=2 to max do
    begin
      c:=0; t:=k;
      for i:=2 to trunc(sqrt(t)) do
        if t mod i=0 then
          begin
            while t mod i=0 do
              begin
                t:=t div i; inc(c);
              end;
            break;
          end;
      if c=0 then f[k]:=2
        else f[k]:=f[t]*(c+1);
    end;
  for i:=1 to max do
    begin
      if i mod 2=0 then t:=f[i div 2]*f[i+1]
        else t:=f[i]*f[(i+1) div 2];
      if t>500 then
        begin
          writeln((int64(i)*(i+1)) div 2);
          writeln(i,' ',f[i],' ',f[(i+1) div 2]);
          break;
        end;
    end;
end.

