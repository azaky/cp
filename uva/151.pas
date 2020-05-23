var
  n,m,i,j,p,tp:longint;
  next:array[0..100] of longint;
  v:array[0..100] of boolean;

begin
  repeat
    readln(n); if n=0 then halt;
	for m:=1 to n do
	  begin
	    for i:=1 to n-1 do next[i]:=i+1; next[n]:=2;
		p:=1; fillchar(v,sizeof(v),false);
		for i:=2 to n do
		  begin
		    v[p]:=true;
		    for j:=1 to m do
			  begin
			    tp:=p; p:=next[tp];
			  end;
			next[tp]:=next[p];
		  end;
		if p=13 then
		  begin
		    writeln(m); break;
		  end;
	  end;
  until false;
end.
//00:10:06.556