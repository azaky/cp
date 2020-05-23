type
  flash=array[1..51] of extended;

const
  inf=1e50;

var
  n,i,p,next,d:longint;
  hi,m,red,add:extended;
  k,pos:array[1..3] of longint;
  temp:array[1..3] of extended;
  h:array[1..3] of flash;

procedure sort(l,r:longint);
  var
    i,j:longint;
    mid,temp:extended;

  begin
    i:=l;
    j:=r;
    mid:=h[p][(l+r) div 2];
    repeat
      while h[p][i]<mid do inc(i);
      while h[p][j]>mid do dec(j);
      if i<=j then
        begin
          temp:=h[p][i];
          h[p][i]:=h[p][j];
          h[p][j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n);
  
  for i:=1 to n do
    begin
      readln(hi,d);
      inc(k[d]);
      h[d][k[d]]:=hi;
    end;
  readln(m);
  
  for p:=1 to 3 do sort(1,k[p]);
  
  for i:=1 to 3 do pos[i]:=1;
  red:=m;
  add:=0.0;
  
  while true do
    begin
      for i:=1 to 3 do
        if pos[i]>k[i] then temp[i]:=inf
          else temp[i]:=(red*(100-i)/100+h[i][pos[i]]);
      next:=3;
      if (temp[1]<=temp[2]) and (temp[1]<=temp[3]) and (pos[1]<=k[1]) then next:=1
        else if (temp[2]<=temp[1]) and (temp[2]<=temp[3]) and (pos[2]<=k[2]) then next:=2;
      if (pos[next]>k[next]) or (temp[next]>red) then break;
      red:=red*(100-next)/100;
      add:=add+h[next][pos[next]];
      inc(pos[next]);
    end;
  
  writeln((red+add):0:3);
  
end.

