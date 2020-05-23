{
TASK:betsy
LANG:PASCAL
}
{$inline on}
{$D-,L-,Y-,R-,S-,Y-,Q-}
program betsy;
const
    maxn=7;
    next:array[1..4,1..2]of shortint=((-1,0),(0,1),(1,0),(0,-1));
var
    dis:array[0..maxn+1,0..maxn+1]of integer;
    remain:array[0..maxn+1,0..maxn+1]of shortint;
    n,nn,nl:shortint;
    ans:longint;
procedure assignfiles;inline;
begin
    assign(input,'betsy.in');reset(input);
    assign(output,'betsy.out');rewrite(output);
end;
procedure closefiles;inline;
begin
    close(input);
    close(output);
end;
procedure init;inline;
var
    i:integer;
    temp:integer;
begin
    readln(n);
    nn:=n*n;
    nl:=n-1;
    fillchar(dis,sizeof(dis),255);
    for i:=0 to n+1 do
        begin
            dis[0,i]:=0;
            dis[i,0]:=0;
            dis[n+1,i]:=0;
            dis[i,n+1]:=0;
        end;
    dis[1,1]:=1;
    fillchar(remain,sizeof(remain),4);
    for i:=2 to n-1 do
        begin
            remain[1,i]:=3;
            remain[n,i]:=3;
            remain[i,1]:=3;
            remain[i,n]:=3;
        end;
    remain[1,1]:=2;
    remain[1,n]:=2;
    remain[n,1]:=3;
    remain[n,n]:=2;
    dec(remain[1,2]);
    dec(remain[2,1]);
    ans:=0;
end;
procedure increse(x,y:integer);inline;
begin
    inc(remain[x+next[1,1],y+next[1,2]]);
    inc(remain[x+next[2,1],y+next[2,2]]);
    inc(remain[x+next[3,1],y+next[3,2]]);
    inc(remain[x+next[4,1],y+next[4,2]]);
end;
procedure decrese(x,y:integer);inline;
begin
    dec(remain[x+next[1,1],y+next[1,2]]);
    dec(remain[x+next[2,1],y+next[2,2]]);
    dec(remain[x+next[3,1],y+next[3,2]]);
    dec(remain[x+next[4,1],y+next[4,2]]);
end;
function check_remain(x,y,nx,ny:shortint):boolean;inline;
var
    a,b:shortint;
begin
    {for i:=1 to 4 do}
        begin
            a:=x+next[1,1];
            b:=y+next[1,2];
            if (dis[a,b]=-1)and((a<>nx)or(b<>ny))and(remain[a,b]<=1) then
                exit(true);
        end;
        begin
            a:=x+next[2,1];
            b:=y+next[2,2];
            if (dis[a,b]=-1)and((a<>nx)or(b<>ny))and(remain[a,b]<=1) then
                exit(true);
        end;
        begin
            a:=x+next[3,1];
            b:=y+next[3,2];
            if (dis[a,b]=-1)and((a<>nx)or(b<>ny))and(remain[a,b]<=1) then
                exit(true);
        end;
        begin
            a:=x+next[4,1];
            b:=y+next[4,2];
            if (dis[a,b]=-1)and((a<>nx)or(b<>ny))and(remain[a,b]<=1) then
                exit(true);
        end;
    exit(false);
end;
function check_contact(nx,ny,dir:shortint):boolean;inline;
var
    d1,d2:integer;
    fx,fy:integer;
begin
    if (dir=2)or(dir=4) then
        begin
            d1:=1;
            d2:=3;
        end
        else begin
            d1:=2;
            d2:=4;
        end;
    fx:=nx+next[dir,1];
    fy:=ny+next[dir,2];
    if (dis[fx,fy]<>-1)and(dis[nx+next[d1,1],ny+next[d1,2]]=-1)and(dis[nx+next[d2,1],ny+next[d2,2]]=-1) then exit(true);
    if (dis[fx+next[d1,1],fy+next[d1,2]]<>-1)and(dis[nx+next[d1,1],ny+next[d1,2]]=-1)and(dis[fx,fy]=-1) then exit(true);
    if (dis[fx+next[d2,1],fy+next[d2,2]]<>-1)and(dis[nx+next[d2,1],ny+next[d2,2]]=-1)and(dis[fx,fy]=-1) then exit(true);
    exit(false);
end;
procedure dfs(x,y,d:integer);inline;
var
    nx,ny,dir:shortint;

begin
    if (d>nn)and(x=n)and(y=1) then
        begin
            inc(ans);
            exit;
        end;
    if (x=nl)and(y=2)and (dis[nl,1]=-1) and (dis[n,2]=-1) then exit;
    for dir:=1 to 4 do
        begin
            nx:=x+next[dir,1];
            ny:=y+next[dir,2];
            if not((dis[nx,ny]<>-1)or((d<nn)and(nx=n)and(ny=1))) then
                begin
                    if check_remain(x,y,nx,ny) then continue;
                    if check_contact(nx,ny,dir) then continue;
                    decrese(nx,ny);
                    dis[nx,ny]:=d;
                    dfs(nx,ny,d+1);
                    dis[nx,ny]:=-1;
                    increse(nx,ny);
                end;
        end;
end;
procedure work;inline;
begin
    dfs(1,1,2);
    writeln(ans);
end;
begin
    //assignfiles;
    init;
    work;
    //closefiles;
end.
