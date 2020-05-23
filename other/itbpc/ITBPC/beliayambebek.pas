var
  i,j,t,kasus,n,m,p,k:longint;
  ok:boolean;
  max:real;
  a,b,h:array[0..201] of longint;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,m,p);
      for i:=1 to p do readln(a[i],b[i],h[i]);
      max:=-1.00;
      a[0]:=0;
      b[0]:=1;
      h[0]:=0;
      a[p+1]:=1;
      b[p+1]:=0;
      h[p+1]:=0;
      for i:=0 to p do
        for j:=i+1 to p+1 do
          if a[i]*b[j]<>a[j]*b[i] then
            if ((a[j]*h[i]-a[i]*h[j])/(a[j]*b[i]-a[i]*b[j])>=0)
            and ((b[i]*h[j]-b[j]*h[i])/(a[j]*b[i]-a[i]*b[j])>=0) then
              begin
                ok:=true;
                for k:=1 to p do
                  if h[k]*abs(a[j]*b[i]-a[i]*b[j])<abs(a[k]*(b[i]*h[j]-b[j]*h[i])+b[k]*(a[j]*h[i]-a[i]*h[j])) then
                    begin
                      ok:=false;
                      break;
                    end;
                if ok then
                  if max<(n*(b[i]*h[j]-b[j]*h[i])+m*(a[j]*h[i]-a[i]*h[j]))/(a[j]*b[i]-a[i]*b[j]) then
                    max:=(n*(b[i]*h[j]-b[j]*h[i])+m*(a[j]*h[i]-a[i]*h[j]))/(a[j]*b[i]-a[i]*b[j]);
              end;
      writeln(max:0:3);
    end;
end.
