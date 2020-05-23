{
ID: a_zaky01
PROG: shuttle
LANG: PASCAL
}

type
  hole=array[-1..27] of char;

var
  n,i,len:longint;
  found:boolean;
  ans:array[1..1000] of integer;
  init,goal:hole;
  fin,fout:text;

procedure find(conf:hole; step,space:longint);
  var
    i:integer;
    temp:hole;

  begin
    if found then exit;
    if step=sqr(n+1) then
      begin
        found:=true;
        for i:=1 to step-1 do
          if (i=step-1) or (i mod 20=0) then writeln(fout,ans[i])
            else write(fout,ans[i],' ');
        exit;
      end;
    if not ((conf[space+2]='B') and (conf[space+1]='W')) then
      begin
        if space>2 then
          if (conf[space-2]='W') and (conf[space-1]='B') then
            begin
              temp:=conf;
              temp[space-2]:=' ';
              temp[space]:='W';
              ans[step]:=space-2;
              find(temp,step+1,space-2);
            end;
        if space>1 then
          if (conf[space-1]='W') then
            begin
              temp:=conf;
              temp[space-1]:=' ';
              temp[space]:='W';
              ans[step]:=space-1;
              find(temp,step+1,space-1);
            end;
      end;
    if not ((conf[space-2]='W') and (conf[space-1]='B')) then
      begin
        if space<len-1 then
          if (conf[space+2]='B') and (conf[space+1]='W') then
            begin
              temp:=conf;
              temp[space+2]:=' ';
              temp[space]:='B';
              ans[step]:=space+2;
              find(temp,step+1,space+2);
            end;
        if space<len then
          if (conf[space+1]='B') then
            begin
              temp:=conf;
              temp[space+1]:=' ';
              temp[space]:='B';
              ans[step]:=space+1;
              find(temp,step+1,space+1);
            end;
      end;
  end;

begin
  assign(fin,'shuttle.in');
  assign(fout,'shuttle.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);

  len:=2*n+1;
  for i:=1 to n do init[i]:='W';
  init[n+1]:=' ';
  for i:=n+2 to 2*n+1 do init[i]:='B';
  for i:=1 to len do goal:=init[len+1-i];

  found:=false;
  find(init,1,n+1);

  close(fin);
  close(fout);
end.
