const
  maxn = 1000005;

var
  n,top,i,j:longint;
  h,ans:int64;
  stack,num,com:array[0..maxn] of int64;

begin
  readln(n);
  top:=1; read(stack[top]); num[top]:=1; ans:=0; stack[0]:=maxlongint;
  for i:=1 to n do com[i+1]:=com[i]+int64(i);
  for i:=2 to n do
    begin
	  read(h); inc(top);
	  while stack[top-1]<h do
	    begin
		  dec(top);
		  if top=1 then ans:=ans+num[top]+com[num[top]]
		    else ans:=ans+2*num[top]+com[num[top]];
		end;
	  if stack[top-1]=h then
	    begin
		  dec(top);
		  inc(num[top]);
		end
	  else
	    begin
		  stack[top]:=h;
		  num[top]:=1;
		end;
	end;
  for i:=2 to top do ans:=ans+num[i];
  for i:=1 to top do ans:=ans+com[num[i]];
  writeln(ans);
end.
