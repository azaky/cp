{
ID: a_zaky01
PROG: betsy
LANG: PASCAL
}

const
  limit = -1000;
  
var
  n,i,maxp:integer;
  ans:longint;
  visit:array[0..8,0..8] of boolean;
  pass:array[0..8,0..8] of integer;
  row,col:array[0..8] of integer;

procedure walk(x,y,path:integer);
  var
    i,stop:integer;
  
  procedure setup;
    begin
      visit[x,y]:=false;
      dec(pass[x,y+1]);
      dec(pass[x,y-1]);
      dec(pass[x+1,y]);
      dec(pass[x-1,y]);
    end;

  begin
    //write('':path); writeln('(',x,',',y,') ',path,' ',pass[x,y]);
    if visit[x,y] then exit;
    if (x=1) and (y=n) then
      begin
        if path=maxp then inc(ans);
        exit;
      end;
    
    if (y=1) and not visit[x-1,1] then exit;
    if (x=1) and not visit[1,y-1] then exit;
    if (x=n) and not visit[n,y-1] then exit;
    if (y=n) and not visit[x+1,n] then exit;
    
    visit[x,y]:=true; stop:=0;
    inc(pass[x,y+1]); if pass[x,y+1]>=3 then inc(stop);
    inc(pass[x,y-1]); if pass[x,y-1]>=3 then inc(stop);
    inc(pass[x+1,y]); if pass[x+1,y]>=3 then inc(stop);
    inc(pass[x-1,y]); if pass[x-1,y]>=3 then inc(stop);
    
    if stop>1 then
      begin
        setup;
        exit;
      end
    else if stop=1 then
      begin
        pass[x,y]:=limit; inc(path);
        if pass[x,y+1]=3 then walk(x,y+1,path);
        if pass[x,y-1]=3 then walk(x,y-1,path);
        if pass[x+1,y]=3 then walk(x+1,y,path);
        if pass[x-1,y]=3 then walk(x-1,y,path);
        setup;
      end
    else
      begin
        pass[x,y]:=limit; inc(path);
        walk(x+1,y,path);
        walk(x,y+1,path);
        walk(x-1,y,path);
        walk(x,y-1,path);
        setup;
      end;
  end;

begin
  
  //assign(input,'betsy.in'); reset(input);
  assign(output,'betsy.out'); rewrite(output);
  
  readln(n);
  
  fillchar(visit,sizeof(visit),false);
  for i:=1 to n do
    begin
      visit[i,0]:=true; pass[i,0]:=limit;
      visit[i,n+1]:=true; pass[i,n+1]:=limit;
      visit[0,i]:=true; pass[0,i]:=limit;
      visit[n+1,i]:=true; pass[n+1,i]:=limit;
      if (i=1) or (i=n) then
        begin
          pass[i,n]:=2;
          pass[i,1]:=2;
        end
      else
        begin
          pass[i,1]:=1;
          pass[i,n]:=1;
          pass[1,i]:=1;
          pass[n,i]:=1;
        end;
    end;
  
  ans:=0; maxp:=sqr(n);
  pass[1,n]:=limit;
  walk(1,1,1);
  
  writeln(ans);
  
  //close(input);
  close(output);
  
end.

