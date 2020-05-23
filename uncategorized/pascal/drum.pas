var
  t,kasus,n,c,p,m,i,j:longint;
  dp1,dp2,l,h:array[0..1005] of longint;
  
begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n,c,p,m);
      for i:=1 to m do readln(l[i],h[i]);
      
      fillchar(dp1,sizeof(dp1),255);
      dp1[0]:=p;
      for j:=1 to c do
        for i:=1 to m do
          if l[i]<=j then
            if (dp1[j-l[i]]>=0) and ((dp1[j]<0) or (dp1[j]>dp1[j-l[i]]+h[i])) then dp1[j]:=dp1[j-l[i]]+h[i];
      
      fillchar(dp2,sizeof(dp2),255);
      dp2[0]:=0;
      for i:=1 to n do
        for j:=1 to c do
          if (j<=i) and (dp1[j]>=0) then
            if (dp2[i-j]>=0) and ((dp2[i]<0) or (dp2[i]>dp2[i-j]+dp1[j])) then dp2[i]:=dp2[i-j]+dp1[j];
      {
      for i:=1 to c do write(dp1[i],' ');
      writeln;
      for i:=1 to n do write(dp2[i],' ');
      writeln;
      }
      writeln(dp2[n]);
      
    end;
end.
