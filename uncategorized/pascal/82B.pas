var
  n,i,ans,j:longint;
  outdate:boolean;
  speed,ram,hdd,cost:array[0..100] of longint;

begin
  readln(n);
  for i:=1 to n do readln(speed[i],ram[i],hdd[i],cost[i]);
  ans:=0; cost[0]:=maxlongint;
  for i:=1 to n do
    begin
	  outdate:=false;
	  for j:=1 to n do
	    if (speed[i]<speed[j]) and (ram[i]<ram[j]) and (hdd[i]<hdd[j]) then
		  begin
		    outdate:=true; break;
		  end;
	  if outdate then continue
	    else if cost[i]<cost[ans] then ans:=i;
	end;
  writeln(ans);
end.
