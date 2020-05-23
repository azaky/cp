{
ID: a_zaky01
PROG: delivery
LANG: PASCAL
}

Var
  
procedure swap(a:longint);
	var
	  temp:point;
	  
	begin
	  temp:=p[a]; p[a]:=p[a+1]; p[a+1]:=temp;
	end;

Begin
    Assign(input, 'delivery.in'); Reset(input);
    Assign(output, 'delivery.out'); Rewrite(output);
	readln(n);
	for i:=1 to n do readln(p[i].x,p[i].y);
	p[0].x:=0; p[0].y:=0; p[n+1].x:=1111111; p[n+1].y:=1111111;
	//creating the horizontal grids
	a:=p; for i:=0 to n+1 do idx[i]:=i;
	for i:=1 to n do
	  for j:=n+1 downto i+1 do
	    if p[j].x<p[j+1].x then swap(j);
	nh:=1; dh[nh]:=1; mh[nh]:=0;
	for i:=1 to n+1 do
	  begin
	    ax:=p[i].x; bx:=p[i-1].x;
		if ax-bx=0 then continue
		  else if ax-bx>1 then
		    if ax-bx=2 then
			  begin
		        inc(nh); dh[nh]:=1; mh[nh]:=
			  end
			else
			  begin
			    inc(nh); dh[nh]
			  end;
		case (ax-bx) of
		  0:continue;
		  1:begin
		    end;
		  2:begin
		    end;
		  else begin
		      inc(nh); dh[nh]:=
		    end;
		    
	  end;
    Close(input); Close(output);
End.
