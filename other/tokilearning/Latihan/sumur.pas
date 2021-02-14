var
  r,c,a,v,i,n,curv,temv:longint;
  count,h,area:array[0..1000001] of longint;

begin
  readln(r,c,v);
  for i:=1 to r*c do
    begin
	  read(a); inc(count[a]);
	end;
  n:=0;
  for i:=0 to 1000000 do
    begin
	  if count[i]=0 then continue;
	  inc(n); h[n]:=i; area[n]:=count[i]+area[n-1];
	end;
  curv:=0;
  for i:=1 to n-1 do
    begin
	  temv:=curv+(h[i+1]-h[i])*area[i];
	  //writeln(h[i],' ',area[i],' ',temv);
	  if temv<v then
	    begin
		  curv:=temv; continue;
		end;
	  writeln((h[i]+(v-curv)/area[i]):0:3); halt;
	end;
  writeln((h[n]+(v-curv)/area[n]):0:3);
end.
