var
  n,i,j,l,p,a,b:longint;
  task,task1,task2:string;
  space:array[1..3] of longint;
  posh,posv,h:array[0..25] of longint;
  stack:array[0..25,0..25] of longint;

procedure return(a:longint);
  var
    i,t:longint;
  
  begin
	for i:=posv[a]+1 to h[posh[a]] do
	  begin
		t:=stack[posh[a],i];
		stack[t,1]:=t; posh[t]:=t; posv[t]:=1; h[t]:=1;
	  end;
	h[posh[a]]:=posv[a];
  end;

procedure move(a,b:longint);
  var
    t1,t2,t3,t,i:longint;
	
  begin
    t1:=posv[a]; t2:=h[posh[a]]; t3:=posh[a]; h[posh[a]]:=posv[a]-1;
    for i:=t1 to t2 do
	  begin
	    t:=stack[t3,i];
	    inc(h[posh[b]]);
	    posh[t]:=posh[b]; posv[t]:=h[posh[b]];
	    stack[posh[t],posv[t]]:=t;
	  end;
  end;

begin
  readln(n);
  for i:=0 to n-1 do
    begin
	  posh[i]:=i; posv[i]:=1; stack[i,1]:=i; h[i]:=1;
	end;
  repeat
    readln(task); if task = 'quit' then break;
	l:=length(task); p:=0;
	for i:=1 to l do
	  if task[i]=' ' then
	    begin
		  inc(p); space[p]:=i; if p=3 then break;
		end;
	val(copy(task,space[1]+1,space[2]-space[1]-1),a);
	val(copy(task,space[3]+1,l-space[3]),b);
	if posh[a]=posh[b] then continue;
    task1:=copy(task,1,4); task2:=copy(task,space[2]+1,4);
	if (task1='move') then
	  if (task2='onto') then
	    begin
		  return(a); return(b); move(a,b);
		end
	  else if (task2='over') then
	    begin
		  return(a); move(a,b);
		end
	  else
	else if (task1='pile') then
	  if (task2='onto') then
	    begin
		  return(b); move(a,b);
		end
      else if (task2='over') then move(a,b);
  until false;
  for i:=0 to n-1 do
    begin
	  write(i,':');
	  for j:=1 to h[i] do write(' ',stack[i,j]);
	  writeln;
	end;
end.
