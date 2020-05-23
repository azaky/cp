var
  i,j,n,p,q,task,m:longint;
  l,r,range,turn:array[0..400000] of longint;
  flag:array[0..400000] of boolean;

procedure preprocess(node,ll,rr:longint);
  var
    mid:longint;
  
  begin
    l[node]:=ll; r[node]:=rr; range[node]:=rr-ll+1;
	if ll=rr then exit else mid:=(ll+rr) div 2;
	preprocess(2*node,ll,mid);
	preprocess(2*node+1,mid+1,rr);
  end;

procedure push(node:longint);
  begin
	if l[node]<r[node] then
	  begin
	    flag[2*node]:=not flag[2*node];
		flag[2*node+1]:=not flag[2*node+1];
	  end;
	flag[node]:=false;
  end;

//this function keeps track of the number ON, same as the query function
function update(node:longint; const p,q:longint):longint;
  var
    add:longint;

  begin
    if (q<l[node]) or (r[node]<p) then
	  begin
	    if flag[node] then
		  begin
			push(node);
		    turn[node]:=range[node]-turn[node];
		  end;
		exit(turn[node]);
	  end;
	if (p<=l[node]) and (r[node]<=q) then
	  begin
	    flag[node]:=not flag[node];
		if flag[node] then exit(range[node]-turn[node])
		  else exit(turn[node]);
	  end;
	if flag[node] then push(node);
	turn[node]:=update(2*node,p,q)+update(2*node+1,p,q);
	exit(turn[node]);
  end;

function query(node:longint; const p,q:longint):longint;
  begin
    if (q<l[node]) or (r[node]<p) then exit(0);
	if flag[node] then
	  begin
	    push(node);
		turn[node]:=range[node]-turn[node]
	  end;
	if (p<=l[node]) and (r[node]<=q) then exit(turn[node])
	  else exit(query(2*node,p,q)+query(2*node+1,p,q));
  end;

begin
  readln(n,m);
  preprocess(1,1,n);
  for i:=1 to m do
    begin
	  readln(task,p,q);
	  if task=0 then task:=update(1,p,q)
	    else writeln(query(1,p,q));
	  //writeln(p,' ',q);
	  //for j:=1 to 15 do write(turn[j]:6);writeln;
	  //for j:=1 to 15 do write(flag[j]:6);writeln;
	end;
end.
