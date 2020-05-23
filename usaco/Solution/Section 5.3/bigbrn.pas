{
ID: a_zaky01
PROG: bigbrn
LANG: PASCAL
}

uses
  math;

const
  p:array[0..10] of integer = (1,2,4,8,16,32,64,128,256,512,1024);

var
  n,t,i,x,y,a,b,lim,add,mid:longint;
  poss:boolean;
  can:array[0..10,0..1001,0..1001] of boolean;

label
  closefile,found;

begin

  assign(input,'bigbrn.in');
  assign(output,'bigbrn.out');
  reset(input);
  rewrite(output);

  
  readln(n,t);
  fillchar(can,sizeof(can),false);
  fillchar(can[0],sizeof(can[0]),true);
  
  for i:=1 to t do
    begin
      readln(x,y);
      if not can[0][x,y] then dec(t);
      can[0][x,y]:=false;
    end;
  
  if sqr(n)=t then
    begin
      writeln(0);
      goto closefile;
    end;
  
  lim:=trunc(ln(n)/ln(2));
  
  for i:=1 to lim do
    begin
      poss:=false;
      for x:=1 to n-p[i]+1 do
        for y:=1 to n-p[i]+1 do
          if can[i-1][x,y] and can[i-1][x+p[i-1],y] and can[i-1][x,y+p[i-1]] and can[i-1][x+p[i-1],y+p[i-1]] then
            begin
              can[i][x,y]:=true;
              poss:=true;
            end;
      if not poss then
        begin
          lim:=i-1;
          break;
        end;
    end;
  
  a:=p[lim];
  b:=min(n,p[lim+1]);
  
  if a=b then
    begin
      writeln(a);
      goto closefile;
    end;
  
  while a<b do
    begin
      mid:=(a+b) div 2;
      add:=mid-p[lim];
      poss:=false;
      for x:=1 to n-mid+1 do
        for y:=1 to n-mid+1 do
          if can[lim][x,y] and can[lim][x+add,y] and can[lim][x,y+add] and can[lim][x+add,y+add] then
            begin
              poss:=true;
              goto found;
            end;
      found:
      if poss then a:=mid+1
        else b:=mid;
    end;
  
  add:=a-p[lim];
  for x:=1 to n-a+1 do
    for y:=1 to n-a+1 do
      if can[lim][x,y] and can[lim][x+add,y] and can[lim][x,y+add] and can[lim][x+add,y+add] then
        begin
          writeln(a);
          goto closefile;
        end;
  writeln(a-1);
  
  closefile:

  close(input);
  close(output);

end.
