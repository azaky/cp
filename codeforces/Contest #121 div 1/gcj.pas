uses math;

var
  n,w,l,i,j,temp,tc,kasus:longint;
  r,idx:array[0..1111] of longint;
  ans:array[0..1111,1..2] of double;
  used:array[0..1111] of boolean;

procedure solve(w1,l1,w2,l2:longint);
  var
    ww,ll,i:longint;
  
  begin
    if (w1>=w2) or (l1>=l2) then exit;
    ww:=w2-w1; ll:=l2-l1;
    //find the largest available circle
    for i:=n downto 0 do
      if not used[i] then
        if r[i]<=min(ww,ll) then break;
    
    if i=0 then exit else used[i]:=true;
    ans[idx[i]][1] := double(w1)+double(r[i])/2;
    ans[idx[i]][2] := double(l1)+double(r[i])/2;
    solve(w1,l1+r[i],w1+r[i],l2);
    solve(w1+r[i],l1,w2,l2);
  end;

begin
readln(kasus);
for tc:=1 to kasus do begin
  readln(n,w,l);
  for i:=1 to n do read(r[i]);
  for i:=1 to n do r[i]:=2*r[i];
  for i:=1 to n do idx[i] := i;
  for i:=1 to n-1 do
    for j:=n downto 1 do
      if r[j]<r[j-1] then
        begin
          temp:=r[j]; r[j]:=r[j-1]; r[j-1]:=temp;
          temp:=idx[j]; idx[j]:=idx[j-1]; idx[j-1]:=temp;
        end;
  fillchar(used,sizeof(used),false);
  solve(0,0,w,l);
  write('Case #',tc,': ');
  for i:=1 to n do
    begin
      write(ans[i][1]:0:1,' ',ans[i][2]:0:1);
      if i<n then write(' ') else writeln;
    end;
end;
end.
