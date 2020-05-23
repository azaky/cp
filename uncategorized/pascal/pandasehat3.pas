var
  tc,kasus,n,i,j,k,pa,pb:longint;
  ok:boolean;
  t,w,s:array[0..301] of longint;
  p:real;

begin
  readln(tc);
  for kasus:=1 to tc do
    begin
      readln(n);
      for i:=1 to n do read(w[i]);
      for i:=1 to n do read(t[i]);
      for j:=1 to n do read(s[i]);
      readln(pa,pb);
      t[0]:=1;
      s[0]:=0;
      w[i]:=0;
      t[n+1]:=0;
      s[n+1]:=1;
      w[n+1]:=0;
      p:=-1.00;
      for i:=0 to n do
        for j:=i+1 to n+1 do
          if s[i]*t[j]<>t[i]*s[j] then
            if ((w[i]*t[j]-w[j]*t[i])/(s[i]*t[j]-t[i]*s[j])>=0) and
               ((w[j]*s[i]-w[i]*s[j])/(s[i]*t[j]-t[i]*s[j])>=0) then
              begin
                ok:=true;
                for k:=1 to n do
                  if abs(t[k]*(w[j]*s[i]-w[i]*s[j])+s[k]*(w[i]*t[j]-w[j]*t[i]))<abs(w[k]*(s[i]*t[j]-t[i]*s[j])) then
                    begin
                      ok:=false;
                      break;
                    end;
                if ok then
                  if (p<0) or (p*(s[i]*t[j]-t[i]*s[j])>(pa*(w[i]*t[j]-w[j]*t[i])+pb*(w[j]*s[i]-w[i]*s[j]))) then
                    p:=(pa*(w[i]*t[j]-w[j]*t[i])+pb*(w[j]*s[i]-w[i]*s[j]))/(s[i]*t[j]-t[i]*s[j]);
              end;
      writeln(p:0:2);
    end;
end.
