const
  two:array[0..8] of integer = (1,2,4,8,16,32,64,128,256);
  st = '0123';
  add:array[1..4,1..2] of integer = ((0,0),(0,1),(1,0),(1,1));

var
  s:string;
  n,r,c,p,k,i,j,r0,c0,p0:integer;
  code:array[1..1 shl 14] of string;
  a:array[0..256,0..256] of integer;

begin
  readln(s); n:=0;
  while s<>'END' do
    begin
	  inc(n); delete(s,1,1); code[n]:=s; readln(s);
	end;
  readln(r,c);
  p:=0; while (two[p]<r) or (two[p]<c) do inc(p);
  for k:=1 to n do
    begin
	  r0:=1; c0:=1; p0:=p;
	  for i:=1 to length(code[k]) do
	    begin
		  dec(p0);
		  r0:=r0+two[p0]*add[pos(code[k][i],st),1];
		  c0:=c0+two[p0]*add[pos(code[k][i],st),2];
		end;
	  //writeln(code[k],' ',
	  for i:=1 to two[p0] do
	    for j:=1 to two[p0] do
		  a[r0+i-1,c0+j-1]:=1;
	end;
  for i:=1 to r do
    for j:=1 to c do
	  if j=c then writeln(a[i,j])
	    else write(a[i,j],' ');
end.
