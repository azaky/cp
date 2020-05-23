type
  matrix = array[1..2,1..2] of int64;

const
  iden : matrix = ((1,0),(0,1));
  init : matrix = ((0,1),(1,1));

var MMOD:int64;

function product(a:matrix; b:matrix):matrix;
  var
    i,j,k:longint;
    ret:matrix;
  
  begin
    fillchar(ret,sizeof(ret),0);
    for i:=1 to 2 do
      for j:=1 to 2 do
        for k:=1 to 2 do
          ret[i][j] := (ret[i][j]+a[i][k]*b[k][j]) mod MMOD;
    exit(ret);
  end;

function power(a:matrix; b:int64):matrix;
  var
    ret:matrix;
  
  begin
    if (b=0) then exit(iden);
    ret := power(a,b div 2);
    ret := product(ret,ret);
    if (b mod 2 = 1) then ret := product(ret,a);
    exit(ret);
  end;

function fibo(n:int64):int64;
  begin
    exit(power(init,n)[2][1] mod MMOD);
  end;

var
  a,b,mid,cur,l,r,k,d:int64;

begin
  //MMOD := 1000000000;while true do begin readln(a); writeln(fibo(a));end;
  readln(MMOD,l,r,k);
  a := 1; b := r;
  while (a < b) do
    begin
	  mid := (a+b) div 2;
	  cur := (r div mid)-((l-1) div mid);
	  if (cur < k) then b := mid-1
		else a := mid;
	  if (b-a = 1) then
	    begin
		  cur := (r div b) -((l-1) div b);
		  if (cur < k) then b := a
			else a := b;
	    end;
    end;
  //writeln(a);
  writeln(fibo(a));
end.
