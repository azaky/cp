uses
  math;

type
  ball = record
    r,pos:extended;
	used:boolean;
  end;

var
  n,m,i,kasus:integer;
  best:extended;
  circ:array[1..8] of ball;

procedure calc(k:integer; l,r:extended);
  var
    i,j:integer;
	l0,r0:extended;
  
  begin
    if k=m then
	  begin
		if (r-l<best) then best:=r-l;
		exit;
	  end;
	for i:=1 to m do
	  begin
	    if circ[i].used then continue;
		circ[i].pos:=0;
		for j:=1 to m do
		  if circ[j].used then
		    circ[i].pos:=max(circ[i].pos,circ[j].pos+2*sqrt(circ[i].r*circ[j].r));
		l0:=min(l,circ[i].pos-circ[i].r);
		r0:=max(r,circ[i].pos+circ[i].r);
		if r0-l0<best then
		  begin
		    circ[i].used:=true;
		    calc(k+1,l0,r0);
		    circ[i].used:=false;
		  end;
	  end;
  end;

begin
  readln(n);
  for kasus:=1 to n do
    begin
      read(m);
	  for i:=1 to m do read(circ[i].r);
      best:=1e100;
      calc(0,0,0);
      writeln(best:0:3);
	end;
end.
