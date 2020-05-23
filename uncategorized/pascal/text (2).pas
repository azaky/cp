const
  max=45;
 
var
  t,kasus,pos:integer;
  n:int64;
  s1,s2,space:char;
  f,sum:array[0..max] of int64;
  
procedure fill;
  var
    i:integer;
    
  begin
    f[1]:=1;
    f[2]:=1;
    for i:=3 to max do f[i]:=f[i-1]+f[i-2];
    sum[0]:=0;
    for i:=1 to max do sum[i]:=sum[i-1]+f[i];
  end;
 
begin
  fill;
  readln(t);
  for kasus:=1 to t do
    begin
      read(s1,space,s2);
      readln(n);
      if n=0 then writeln(s1)
        else
          begin
            inc(n);
            pos:=1;
            while sum[pos]<n do inc(pos);
            n:=n-sum[pos-1];
            while true do
              begin
                if (n=1) and ((pos=1) or (pos=2)) then break;
                if n<=f[pos-1] then pos:=pos-1
                  else
                    begin
                      n:=n-f[pos-1];
                      pos:=pos-2;
                    end;
              end;
            if pos=1 then writeln(s1)
              else writeln(s2);
          end;
    end;
end.
