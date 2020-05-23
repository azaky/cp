{
ID: a_zaky01
PROG: cowxor
LANG: PASCAL
}

Var
	N,i,j,ansl,ansr,l,r,maxxor,node,best,val,x,cowij,num:longint;
	a:array[0..111111] of longint;
	cow:array[0..111111] of longint;
	tree:array[0..1 shl 22] of boolean;
	leaf:array[0..1 shl 21] of longint;

Begin
    Assign(input, 'cowxor.in'); Reset(input);
    Assign(output, 'cowxor.out'); Rewrite(output);
	readln(N);
	for i:=1 to n do readln(a[i]);
	for i:=1 to n do cow[i] := cow[i-1] xor a[i];
	fillchar(tree,sizeof(tree),false);
	node := 1;
	for j:=20 downto 0 do
	  begin
	    node := 2*node;
	    tree[node] := true;
	  end;
	leaf[0] := 0;
	maxxor := -1;
	for i:=1 to n do
	  begin
	    node := 1; num:=0;
	    for j:=20 downto 0 do
	      begin
	        cowij := (cow[i] and (1 shl j));
	        x := (1 shl j) - cowij;
	        if tree[2*node + (x shr j)] then
	          begin
	            node := 2*node + (x shr j);
	            num := num + x;
	          end
	        else
	          begin
	            node := 2*node + (cowij shr j);
	            num := num + cowij;
	          end;
	      end;
	    best := leaf[num];
	    val := cow[i] xor cow[best];
	    if val>maxxor then
	      begin
	        maxxor := val;
	        ansl := best+1; ansr := i;
	      end;
	    node := 1;
	    for j:=20 downto 0 do
	      begin
	        cowij := (cow[i] and (1 shl j));
	        node := 2*node + (cowij shr j);
	        tree[node] := true;
	      end;
	    leaf[cow[i]] := i;
	  end;
	writeln(maxxor,' ',ansl,' ',ansr);
    Close(input); Close(output);
End.
