const
  maxn = 1 shl 17;
  maxnode = (1 shl 18)-1;

var
  tc,kasus,n,c,i,j,p,q,task:longint;
  v:int64;
  l,r:array[0..maxn shl 2] of longint;
  temp,value,range:array[0..maxn shl 2] of int64;
  flag:array[0..maxn shl 2] of boolean;

procedure preprocess(node,ll,rr:longint);
  var
    mid:longint;
	
  begin
    l[node]:=ll; r[node]:=rr; range[node]:=int64(rr-ll+1);
	if ll=rr then exit;
	mid:=(ll+rr) div 2;
	preprocess(2*node,ll,mid);
	preprocess(2*node+1,mid+1,rr);
  end;

procedure update(node:longint; const p,q:longint; v:int64);
  var
    add:longint;
	
  begin
	if (r[node]<p) or (q<l[node]) then exit;
	//check if leaf node
	if (l[node]=r[node]) then
	   begin
	     value[node]:=value[node]+v;
		 exit;
	   end;
	if (p<=l[node]) and (r[node]<=q) then
	  begin
	    inc(temp[node],v); flag[node]:=true;
		exit;
	  end;
	//push flag if this node is flagged
	if flag[node] then
	  begin
	    flag[2*node]  :=true; inc(temp[2*node],  temp[node]);
		flag[2*node+1]:=true; inc(temp[2*node+1],temp[node]);
		flag[node]    :=false;
	  end;
	//update children
	update(2*node,  p,q,v);
	update(2*node+1,p,q,v);
	//update the value of node
	if r[node]<q then add:=r[node]+1-p
	  else if p<l[node] then add:=q+1-l[node]
	    else add:=q+1-p;
	value[node]:=value[node]+temp[node]*range[node]+int64(add)*v; temp[node]:=0;
  end;

function query(node:longint; const p,q:longint):int64;
  begin
    if (r[node]<p) or (q<l[node]) then exit(0);
	if flag[node] then
	  begin
	    inc(value[node],range[node]*temp[node]);
	    flag[2*node]  :=true; inc(temp[2*node],  temp[node]);
		flag[2*node+1]:=true; inc(temp[2*node+1],temp[node]);
		flag[node]    :=false; temp[node]:=0;
	  end;
	if (p<=l[node]) and (r[node]<=q) then exit(value[node]);
	exit(query(2*node,  p,q)+query(2*node+1,p,q));
  end;

begin
  readln(tc);
  preprocess(1,1,n);
  for kasus:=1 to tc do
    begin
	  readln(n,c);
	  fillchar(value,sizeof(value),0);
	  fillchar(temp,sizeof(temp),0);
	  fillchar(flag,sizeof(flag),false);
	  for i:=1 to c do
	    begin
		  read(task);
		  if task = 0 then
		    begin
			  readln(p,q,v);
			  update(1,p,q,v);
			  //for j:=1 to maxnode do write(value[j]:3,' ');writeln;
			  //for j:=1 to maxnode do write(temp[j]:3,' ');writeln;
			end
		  else if task = 1 then
		    begin
			  readln(p,q);
			  writeln(query(1,p,q));
			  //for j:=1 to maxnode do write(value[j]:3,' ');writeln;
			  //for j:=1 to maxnode do write(temp[j]:3,' ');writeln;
			end;
		end;
	end;
end.
