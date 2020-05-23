{
ID: a_zaky01
PROG: climb
LANG: PASCAL
}

uses math;

type
  cow = record
    u,d:longint;
  end;

var
  n,i,answer:longint;
  a,ans:array[0..30000] of cow;
  
function less(x,y:cow):boolean;
  begin
	exit(max(x.u+y.u+y.d,x.u+x.d+y.d)<max(y.u+x.u+x.d,y.u+y.d+x.d));
  end;
  
procedure sort(l,r:longint);
  var
    i,j:longint;
	mid,temp:cow;
  
  begin
    i:=l; j:=r; mid:=a[random(r-l+1)+l];
	repeat
	  while less(a[i],mid) do inc(i);
	  while less(mid,a[j]) do dec(j);
	  if i>j then break else temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
	  inc(i); dec(j);
	until i>j;
	if l<j then sort(l,j);
	if i<r then sort(i,r);
  end;
  
Begin
	randomize;
    Assign(input, 'climb.in'); Reset(input);
    Assign(output, 'climb.out'); Rewrite(output);
	readln(n);
	for i:=1 to n do readln(a[i].u,a[i].d);
	sort(1,n);
	for i:=1 to n do ans[i].u:=ans[i-1].u+a[i].u;
	for i:=n downto 1 do ans[i].d:=ans[i+1].d+a[i].d;
	//for i:=1 to n do writeln(ans[i].u:10,ans[i].d:10);
	for i:=1 to n do answer:=max(answer,ans[i].u+ans[i].d);
	writeln(answer);
    Close(input); Close(output);
End.
