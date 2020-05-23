{
ID: a_zaky01
PROG: maze1
LANG: PASCAL
}

var
  r0,c0,i,j,startr1,startr2,startc1,startc2,ans:longint;
  input:string;
  entrance1,entrance2:boolean;
  path,path1,path2:array[1..100,1..38] of longint;
  connected:array[1..100,1..38,1..100,1..38] of boolean;
  fin,fout:text;

procedure dijkstra1(r,c,k:integer);
  begin
    if (path1[r,c]=0) or (path1[r,c]>k) then
      begin
        path1[r,c]:=k;
        if c-1>0 then
          if connected[r,c,r,c-1] then dijkstra1(r,c-1,k+1);
        if c+1<=c0 then
          if connected[r,c,r,c+1] then dijkstra1(r,c+1,k+1);
        if r-1>0 then
          if connected[r,c,r-1,c] then dijkstra1(r-1,c,k+1);
        if r+1<=r0 then
          if connected[r,c,r+1,c] then dijkstra1(r+1,c,k+1);
      end;
  end;

procedure dijkstra2(r,c,k:integer);
  begin
    if (path2[r,c]=0) or (path2[r,c]>k) then
      begin
        path2[r,c]:=k;
        if c-1>0 then
          if connected[r,c,r,c-1] then dijkstra2(r,c-1,k+1);
        if c+1<=c0 then
          if connected[r,c,r,c+1] then dijkstra2(r,c+1,k+1);
        if r-1>0 then
          if connected[r,c,r-1,c] then dijkstra2(r-1,c,k+1);
        if r+1<=r0 then
          if connected[r,c,r+1,c] then dijkstra2(r+1,c,k+1);
      end;
  end;

begin
  assign(fin,'maze1.in');
  assign(fout,'maze1.out');
  reset(fin);
  rewrite(fout);
  entrance1:=false;
  entrance2:=false;
  readln(fin,c0,r0);
  for i:=0 to r0 do
    begin
      if i>0 then
        begin
          readln(fin,input);
          if input[1]=' ' then
            if not entrance1 then
              begin
                startr1:=i;
                startc1:=1;
                entrance1:=true;
              end
            else
              begin
                startr2:=i;
                startc2:=1;
                entrance2:=true;
              end;
          if input[2*c0+1]=' ' then
            if not entrance1 then
              begin
                startr1:=i;
                startc1:=c0;
                entrance1:=true;
              end
            else
              begin
                startr2:=i;
                startc2:=c0;
                entrance2:=true;
              end;
          for j:=1 to c0-1 do
            if input[2*j+1]=' ' then
              begin
                connected[i,j,i,j+1]:=true;
                connected[i,j+1,i,j]:=true;
              end;
        end;
      readln(fin,input);
      if i=0 then
        for j:=1 to c0 do
          if input[2*j]=' ' then
            if not entrance1 then
              begin
                startr1:=1;
                startc1:=j;
                entrance1:=true;
              end
            else
              begin
                startr2:=1;
                startc2:=j;
                entrance2:=true;
              end;
      if i=r0 then
        for j:=1 to c0 do
          if input[2*j]=' ' then
            if not entrance1 then
              begin
                startr1:=r0;
                startc1:=j;
                entrance1:=true;
              end
            else
              begin
                startr2:=r0;
                startc2:=j;
                entrance2:=true;
              end;
      if not(i=0) and not(i=r0) then
        for j:=1 to c0 do
          if input[2*j]=' ' then
            begin
              connected[i,j,i+1,j]:=true;
              connected[i+1,j,i,j]:=true;
            end;
    end;
  fillchar(path1,sizeof(path1),0);
  fillchar(path2,sizeof(path2),0);
  dijkstra1(startr1,startc1,1);
  dijkstra2(startr2,startc2,1);
  ans:=0;
  for i:=1 to r0 do
    for j:=1 to c0 do
      begin
        if (path1[i,j]=0) or ((path2[i,j]<>0) and (path1[i,j]>path2[i,j])) then path[i,j]:=path2[i,j]
          else path[i,j]:=path1[i,j];
        if ans<path[i,j] then ans:=path[i,j];
      end;
  writeln(fout,ans);
  close(fin);
  close(fout);
end.
