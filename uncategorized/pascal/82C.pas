var
  n,m,d0,c0,i,best:longint;
  a,b,c,d,r:array[1..11] of longint;

procedure cook(k,dough,t:longint);
  var
    i:longint;

  begin
    //writeln(k,' ',dough,' ',t);
    if k>m then
      begin
	    if t>best then best:=t;
		//writeln(t:k+5);
		exit;
	  end;
	cook(k+1,dough,t);
	for i:=1 to r[k] do
	  begin
	    dec(dough,c[k]);
		if dough<0 then exit
		  else inc(t,d[k]);
		//writeln(i:k);
		cook(k+1,dough,t);
	  end;
  end;

begin
  readln(n,m,c0,d0);
  for i:=1 to m do readln(a[i],b[i],c[i],d[i]);
  for i:=1 to m do r[i]:=a[i] div b[i];
  inc(m); r[m]:=n div c0; c[m]:=c0; d[m]:=d0;
  best:=0; cook(1,n,0);
  writeln(best);
end.
