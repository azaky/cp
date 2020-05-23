var
  i,j,t,kasus,n,sa,sb,k:longint;
  ok:boolean;
  max:real;
  a,b,w:array[0..301] of longint;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=1 to n do read(w[i]);
      for i:=1 to n do read(a[i]);
      for i:=1 to n do read(b[i]);
      readln(sa,sb);
      max:=-1.00;
      a[0]:=0;
      b[0]:=1;
      w[0]:=0;
      a[n+1]:=1;
      b[n+1]:=0;
      w[n+1]:=0;
      for i:=0 to n do
        for j:=i+1 to n+1 do
          if a[i]*b[j]<>a[j]*b[i] then
            if ((a[j]*w[i]-a[i]*w[j])/(a[j]*b[i]-a[i]*b[j])>=0)
            and ((b[i]*w[j]-b[j]*w[i])/(a[j]*b[i]-a[i]*b[j])>=0) then
              begin
                ok:=true;
                for k:=1 to n do
                  if w[k]*abs(a[j]*b[i]-a[i]*b[j])>abs(a[k]*(b[i]*w[j]-b[j]*w[i])+b[k]*(a[j]*w[i]-a[i]*w[j])) then
                    begin
                      ok:=false;
                      break;
                    end;
                if ok then
                  if (max>(sa*(b[i]*w[j]-b[j]*w[i])+sb*(a[j]*w[i]-a[i]*w[j]))/(a[j]*b[i]-a[i]*b[j])) or (max<0) then
                    max:=(sa*(b[i]*w[j]-b[j]*w[i])+sb*(a[j]*w[i]-a[i]*w[j]))/(a[j]*b[i]-a[i]*b[j]);
              end;
      writeln(max:0:2);
    end;
end.
