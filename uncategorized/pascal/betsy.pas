{
ID: a_zaky01
PROG: betsy
LANG: PASCAL
}

var
  n,i,maxp:integer;
  ans:longint;
  visit:array[0..8,0..8] of boolean;

procedure walk(x,y,path:integer);
  var
    i:integer;
  
  procedure setup;
    begin
      visit[x,y]:=true;
    end;

  begin
    //write('':path); writeln('(',x,',',y,') ',path);
    if visit[x,y] then exit;
    if (x=1) and (y=n) then
      begin
        if path=maxp then inc(ans);
        exit;
      end;
    
    inc(path);
    
    if y=1 then
      begin
        if not visit[x-1,1] then exit;
        setup;
        if x=n-1 then walk(n,1,path)
          else
            begin
              walk(x,y+1,path);
              walk(x+1,y,path);
            end;
      end
    else if x=1 then
      begin
        if not visit[1,y-1] then exit;
        setup;
        walk(x,y+1,path);
        walk(x+1,y,path);
      end
    else if x=n then
      begin
        if not visit[n,y-1] then exit;
        setup;
        walk(x-1,y,path);
        walk(x,y+1,path);
      end
    else if y=n then
      begin
        if not visit[x+1,n] then exit;
        setup;
        walk(x-1,y,path);
        walk(x,y-1,path);
      end
    else
      begin
        setup;
        walk(x,y+1,path);
        walk(x,y-1,path);
        walk(x+1,y,path);
        walk(x-1,y,path);
      end;
    
    visit[x,y]:=false;
  end;

begin
  
  //assign(input,'betsy.in'); reset(input);
  //assign(output,'betsy.out'); rewrite(output);
  
  readln(n);
  
  fillchar(visit,sizeof(visit),false);
  for i:=1 to n do
    begin
      visit[i,0]:=true;
      visit[i,n+1]:=true;
      visit[0,i]:=true;
      visit[n+1,i]:=true;
    end;
  ans:=0; maxp:=sqr(n);
  walk(1,1,1);
  
  writeln(ans);
  
  //close(input);
  //close(output);
  
end.

