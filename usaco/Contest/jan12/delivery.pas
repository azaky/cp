{
ID: a_zaky01
PROG: delivery
LANG: PASCAL
}

uses math;

const
  next:array[1..4,1..2] of longint = ((0,1),(0,-1),(1,0),(-1,0));
  maxn = 101;
  maxq = sqr(222);

Var
	n,i,temp,ans:longint;
	x,y:array[0..maxn] of longint;
	queue:array[0..maxq,1..2] of longint;
	dis:array[0..maxq] of longint;
	visit:array[-101..101,-101..101] of boolean;
  
function connect(a,b:longint):longint;
  var
    tx,ty,qtake,qsave,i,xx,yy,nx,ny,d,res:longint;
	reach:boolean;
  
  begin
	tx:=x[b]-x[a]; ty:=y[b]-y[a]; res:=maxlongint;
	//if (abs(tx)<101) and (abs(ty)<101) then
	  begin
	    fillchar(visit,sizeof(visit),false);
		fillchar(dis,sizeof(dis),0);
		reach:=false;
	    for i:=1 to n do
		  if (abs(x[i]-x[a])<101) and (abs(y[i]-y[a])<101) then visit[x[i]-x[a],y[i]-y[a]]:=true;
		if (abs(tx)<101) and (abs(ty)<101) then visit[tx,ty]:=false;
	    qtake:=1; qsave:=1; queue[1][1]:=0; queue[1][2]:=0; visit[0][0]:=true;
		while qtake<=qsave do
		  begin
		    xx:=queue[qtake][1]; yy:=queue[qtake][2]; d:=dis[qtake];
			if (xx=tx) and (yy=ty) then exit(d);
			for i:=1 to 4 do
			  begin
			    nx:=xx+next[i][1]; ny:=yy+next[i][2];
				if visit[nx,ny] then continue else visit[nx,ny]:=true;
				if (nx>100) or (ny>100) then
				  begin
				    reach:=true; res:=min(res,abs(tx-nx)+abs(ty-ny)+d+1);
					continue;
				  end;
				inc(qsave); queue[qsave][1]:=nx; queue[qsave][2]:=ny; dis[qsave]:=d+1;
			  end;
			inc(qtake);
		  end;
		if (abs(tx)<101) and (abs(ty)<101) then exit(-1);
	  end;
	if not reach then exit(-1) else exit(res);
  end;

Begin
    Assign(input, 'delivery.in'); Reset(input);
    Assign(output, 'delivery.out'); Rewrite(output);
	readln(n);
	if n=1 then
	  begin
	    writeln(0); halt;
	  end;
	for i:=1 to n do readln(x[i],y[i]);
	for i:=1 to n-1 do
	  begin
	    temp:=connect(i,i+1);
		if temp<0 then
		  begin
		    writeln(-1); halt;
		  end
		else ans:=ans+temp;
	  end;
	temp:=connect(1,n);
	if temp<0 then
	  begin
	    writeln(-1); halt;
	  end
	else ans:=ans+temp;
	writeln(ans);
    Close(input); Close(output);
End.
