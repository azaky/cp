type matrix = array[1..2,1..2] of int64;
const init:matrix = ((0,1),(1,1));
const iden:matrix = ((1,0),(0,1));
const mmod:int64  = 1000000007;

function pr(a,b:matrix):matrix;
  var
    ret: matrix;
    i,j,k: longint;
  
  begin
    fillchar(ret,sizeof(ret),0);
    for i:=1 to 2 do
      for j:=1 to 2 do
        for k:=1 to 2 do ret[i][j] := (ret[i][j] + a[i][k]*b[k][j]) mod (mmod-1);
    exit(ret);
  end;

function po(a:matrix; b:int64):matrix;
  var
    ret:matrix;
  
  begin
    if (b=0) then exit(iden);
    ret := po(a,b div 2);
    ret := pr(ret,ret);
    if (b and 1>0) then ret := pr(ret,a);
    exit(ret);
  end;

function pm(a,b:int64):int64;
  var
    ret:int64;
  
  begin
    if (b=0) then exit(1);
    ret := pm(a,b div 2);
    ret := (ret*ret) mod mmod;
    if (b and 1>0) then ret := (ret*a) mod mmod;
    exit(ret);
  end;

var
  tc,kasus:longint;
  n:int64;
  now:matrix;

begin
  readln(tc);
  for kasus := 1 to tc do
    begin
      readln(n);
      if (n=0) then
        begin
          writeln(1);
          continue;
        end;
      now := po(init,n);
      writeln(pm(2,now[2][1]));
    end;
end.
