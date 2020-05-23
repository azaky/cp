type
  arr = array[-1..25,-1..25] of integer;

var
  m,n,i,j,area:integer;
  ans:longint;
  a:arr;

function runtuh(a:arr; b,k:integer):arr;
  var
    i,j,k0,t:integer;
  
  procedure fill1(b,k:integer);
    begin
      if (b<0) or (k<0) or (b>=m) or (k>=n) then exit;
      if a[b,k]<>t then exit;
      a[b,k]:=0;
      fill1(b+1,k);
      fill1(b,k+1);
      fill1(b-1,k);
      fill1(b,k-1);
    end;
  
  begin
    t:=a[b,k]; fill1(b,k);
    runtuh:=a;
    for i:=m-1 downto 0 do
      for j:=0 to n-1 do
        if runtuh[i,j]=0 then
          begin
            for k0:=i-1 downto -1 do
              if k0<0 then break
                else if runtuh[k0,j]<>0 then break;
            if k0<0 then continue;
            runtuh[i,j]:=runtuh[k0,j]; runtuh[k0,j]:=0;
          end;
  end;

procedure play(a:arr; score:longint; depth:integer);
  var
    i,j:integer;
    visit:array[-1..25,-1..25] of boolean;
  
  procedure fill(b,k:integer);
    begin
      if (b<0) or (k<0) or (b>=m) or (k>=n) or visit[b,k] then exit
        else visit[b,k]:=true;
      inc(area);
      if a[b,k]=a[b+1,k] then fill(b+1,k);
      if a[b,k]=a[b,k+1] then fill(b,k+1);
      if a[b,k]=a[b-1,k] then fill(b-1,k);
      if a[b,k]=a[b,k-1] then fill(b,k-1);
    end;
  
  begin
    if score>ans then ans:=score;
    if depth=2 then exit;
    fillchar(visit,sizeof(visit),false);
    for i:=0 to m-1 do
      for j:=0 to n-1 do
        begin
          if (a[i,j]=0) or visit[i,j] then continue;
          area:=0; fill(i,j);
          if area>1 then play(runtuh(a,i,j),score+area*(area-1),depth+1);
        end;
  end;

begin
  readln(m,n);
  fillchar(a,sizeof(a),255);
  for i:=0 to m-1 do
    for j:=0 to n-1 do read(a[i,j]);
  play(a,0,0);
  writeln(ans);
end.

