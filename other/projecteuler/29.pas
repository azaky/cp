const
  p:array[1..25] of longint =
     ( 2,  3,  5,  7, 11,
      13, 17, 19, 23, 29,
      31, 37, 41, 43, 47,
      53, 59, 61, 67, 71,
      73, 79, 83, 89, 97);

type
  arr = array[0..25] of longint;
  
var
  i,j,a,b,ans:longint;
  pf,s:array[0..10000] of arr;
  temp:arr;
  new:boolean;

function same(x,y:arr):boolean;
  var
    i:longint;
    
  begin
    for i:=1 to 25 do
      if x[i]<>y[i] then exit(false);
    exit(true);
  end;

begin
  for i:=2 to 100 do
    for j:=1 to 25 do
      if i mod p[j]=0 then
        begin
          pf[i]:=pf[i div p[j]]; inc(pf[i][j]);
        end;
  ans:=0;
  for a:=2 to 100 do
    for b:=2 to 100 do
      begin
        for i:=1 to 25 do temp[i]:=pf[a][i]*b;
        new:=true;
        for i:=1 to ans do
          if same(temp,s[i]) then new:=false;
        if new then
          begin
            inc(ans); s[ans]:=temp;
          end;
      end;
  writeln(ans);
end.
