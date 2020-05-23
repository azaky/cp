{
ID: a_zaky01
PROG: betsy
LANG: PASCAL
}
 
const
  next:array[1..4,1..2] of integer = ((0,-1),(1,0),(0,1),(-1,0));
 
var
  n,i,goal:integer;
  ans:longint;
  pass:array[0..8,0..8] of integer;
  visit:array[0..8,0..8] of boolean;
 
procedure cal(x,y,p:integer);
  var
    i,j,temp,d,d1,d2,nx,ny,mx1,mx2,my1,my2,fx,fy,stat:integer;
    valid:boolean;
  
  begin
    if p=goal then
      begin
        if (x=1) and (y=n) then inc(ans);
        exit;
      end;
    if visit[x,y] or ((x=1) and (y=n)) then exit;
    if (x=2) and (y=n-1) and not visit[1,n-1] and not visit[2,n] then exit;
    if (y=1) and not visit[x-1,y] then exit;
    if (y=n) and not visit[x+1,y] then exit;
    if ((x=1) or (x=n)) and not visit[x,y-1] then exit;
    
    visit[x,y]:=true; temp:=pass[x,y]; pass[x,y]:=-1000;
    stat:=0;
    for i:=1 to 4 do
      begin
        nx:=x+next[i,1]; ny:=y+next[i,2];
        inc(pass[nx,ny]);
        if pass[nx,ny]=3 then inc(stat)
          else if pass[nx,ny]=4 then stat:=-1000;
      end;
    
    if (stat>=0) and (stat<=1) then
      for i:=1 to 4 do
        begin
          nx:=x+next[i,1]; ny:=y+next[i,2];
          if (stat=1) and (pass[nx,ny]<>3) then continue;
          if visit[nx,ny] then continue;
          if (i=1) or (i=3) then
            begin
              d1:=2;
              d2:=4;
            end
          else
            begin
              d1:=1;
              d2:=3;
            end;
          mx1:=nx+next[d1,1]; my1:=ny+next[d1,2];
          mx2:=nx+next[d2,1]; my2:=ny+next[d2,2];
          fx:=nx+next[i,1]; fy:=ny+next[i,2];
          if visit[fx,fy] and not visit[mx1,my1] and not visit[mx2,my2] then continue;
          if not visit[fx,fy] and not visit[mx1,my1] and visit[fx+next[d1,1],fy+next[d1,2]] then continue;
          if not visit[fx,fy] and not visit[mx2,my2] and visit[fx+next[d2,1],fy+next[d2,2]] then continue;
          cal(nx,ny,p+1);
          if pass[nx,ny]=3 then break;
        end;
    visit[x,y]:=false; pass[x,y]:=temp;
    for i:=1 to 4 do dec(pass[x+next[i,1],y+next[i,2]]);
  end;
 
begin
  
  assign(input,'betsy.in'); reset(input);
  assign(output,'betsy.out'); rewrite(output);
  
  readln(n);
  ans:=0; goal:=sqr(n);
  fillchar(visit,sizeof(visit),false);
  for i:=1 to n do
    begin
      pass[i,0]:=-1000; visit[i,0]:=true;
      pass[0,i]:=-1000; visit[0,i]:=true;
      pass[i,n+1]:=-1000; visit[i,n+1]:=true;
      pass[n+1,i]:=-1000; visit[n+1,i]:=true;
      pass[i,1]:=1;
      pass[i,n]:=1;
      pass[n,i]:=1;
      pass[1,i]:=1;
    end;
  pass[1,1]:=2; pass[n,1]:=2; pass[1,n]:=-1000; pass[n,n]:=2;
  
  cal(1,1,1);
  writeln(ans);
  
  close(input);
  close(output);
  
end.

