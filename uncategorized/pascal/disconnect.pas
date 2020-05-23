var
  t,kasus,n,e,r,q,p,d,k,v1,v2,size,i:longint;
  ans:int64;
  a,b,ep1,ep2:array[1..200005] of longint;
  z:array[1..400005] of longint;
  deg:array[1..50005] of longint;
  des:array[1..200005] of boolean;
  s,visit:array[1..50005] of boolean;
  

procedure ffill(v:longint);
  var
    i:longint;
    
  begin
    if visit[v] then exit;
    if s[v] then inc(size);
    visit[v]:=true;
    for i:=deg[v]+1 to deg[v+1] do
      if not visit[z[i]] then ffill(z[i]);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(des,sizeof(des),false);
      fillchar(s,sizeof(s),false);
      fillchar(visit,sizeof(visit),false);
      fillchar(deg,sizeof(deg),0);
      
      readln(n,e,q,r);
      
      for i:=1 to e do readln(a[i],b[i]);
      
      for i:=1 to q do
        begin
          read(p); s[p]:=true;
        end;
      //readln;
      
      //for i:=1 to e do writeln(des[i]);
      for i:=1 to r do
        begin
          read(d); des[d]:=true;
        end;
      //for i:=1 to e do writeln(des[i]);
      //readln;
      
      k:=0;
      for i:=1 to e do
        if not des[i] then
          begin
            inc(k);
            a[k]:=a[i]; b[k]:=b[i];
          end;
      e:=k;
      
      for i:=1 to e do
        begin
          inc(deg[a[i]]); inc(deg[b[i]]);
          ep1[i]:=a[i]; ep2[i]:=b[i];
        end;
      
      for i:=2 to n+1 do deg[i]:=deg[i]+deg[i-1];
      for i:=1 to e do
        begin
          v1:=ep1[i]; v2:=ep2[i];
          z[deg[v1]]:=v2; z[deg[v2]]:=v1;
          dec(deg[v1]); dec(deg[v2]);
        end;
      {
      for i:=1 to n do
        begin
          writeln('vertex #',i);
          for k:=deg[i]+1 to deg[i+1] do writeln(z[k]);
          writeln;
        end;
      }
      ans:=0;
      for i:=1 to n do
        if not visit[i] then
          begin
            size:=0;
            ffill(i);
            ans:=ans+size*(q-size);
          end;
      
      ans:=ans div 2;
      writeln(ans);
      
    end;
end.

