var
  t,kasus,i:longint;
  s0,s1:char;
  input:string;
  n,b:int64;
  a:array[-1..10000] of int64;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(input);
      s0:=input[1];
      s1:=input[3];
      val(copy(input,5,length(input)),n);
      if n=0 then writeln(s0)
        else
          begin
            a[-1]:=0;
            a[0]:=1;
            b:=0;
            i:=0;
            while b<=n do
              begin
                inc(i);
                a[i]:=a[i-1]+a[i-2];
                b:=b+a[i];
              end;
            n:=n-b+a[i];
            while (i<>1) and (i<>0) do
              begin
                if n>a[i-1] then
                  begin
                    n:=n-a[i-1];
                    i:=i-2;
                  end
                else dec(i);
              end;
            if i=0 then writeln(s0) else writeln(s1);
          end;
    end;
end.
