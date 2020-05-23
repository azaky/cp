{
ID: a_zaky01
PROG: snail
LANG: PASCAL
}

type
  board=array[0..201,0..201] of byte;

var
  i,j,n,b,best:longint;
  ch:char;
  ans,can:board;

procedure find(r,c,dir,path:longint; can:board);
  label
    finish;
  //   direction:
  //   0=up
  //   1=right
  //   2=down
  //   3=left
  begin
    case dir of
      0: begin
           if not(can[r-1,c]=0) then goto finish;
           dec(r);
           while can[r,c]=0 do
             begin
               can[r,c]:=2;
               inc(path);
               dec(r);
             end;
           if can[r,c]=2 then goto finish;
           inc(r);
           find(r,c,1,path,can);
           find(r,c,3,path,can);
         end;
      1: begin
           if not(can[r,c+1]=0) then goto finish;
           inc(c);
           while can[r,c]=0 do
             begin
               can[r,c]:=2;
               inc(path);
               inc(c);
             end;
           if can[r,c]=2 then goto finish;
           dec(c);
           find(r,c,0,path,can);
           find(r,c,2,path,can);
         end;
      2: begin
           if not(can[r+1,c]=0) then exit;
           inc(r);
           while can[r,c]=0 do
             begin
               can[r,c]:=2;
               inc(path);
               inc(r);
             end;
           if can[r,c]=2 then goto finish;
           dec(r);
           find(r,c,1,path,can);
           find(r,c,3,path,can);
         end;
      3: begin
           if not(can[r,c-1]=0) then exit;
           dec(c);
           while can[r,c]=0 do
             begin
               can[r,c]:=2;
               inc(path);
               dec(c);
             end;
           if can[r,c]=2 then goto finish;
           inc(c);
           find(r,c,0,path,can);
           find(r,c,2,path,can);
         end;
    end;
    finish:
    if path>best then
      begin
        best:=path;
        ans:=can;
      end;
  end;


begin

  assign(input,'snail.in');
  assign(output,'snail.out');
  reset(input);
  rewrite(output);

  readln(n,b);
  //can:
  //0=empty
  //1=barrier/edge
  //2=already visited
  for i:=1 to n do
    begin
      can[0,i]:=1;
      can[n+1,i]:=1;
      can[i,0]:=1;
      can[i,n+1]:=1;
    end;
  for i:=1 to b do
    begin
      read(ch);
      readln(j);
      can[ord(ch)-ord('A')+1,j]:=1;
    end;

  can[1,1]:=2;
  best:=1;

  //   direction:
  //   0=up
  //   1=right
  //   2=down
  //   3=left
  //   find(r,c,dir,path,can);
  find(1,1,1,1,can);
  find(1,1,2,1,can);

  writeln(best);
  
  close(input);
  close(output);

end.
