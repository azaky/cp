const
  p:array[0..12] of integer=(1,2,4,8,16,32,64,128,256,512,1024,2048,4096);

type
  arr=array[1..50] of integer;
  
var
  n,i,temp,dep,ans,l,r,d:longint;
  a,best:arr;

function find(a:arr; depth:integer):boolean;
  var
    i,max:integer;
    
  begin
    if depth=1 then
      begin
        best:=a;
        exit(a[depth]=n);
      end;
    
    max:=a[depth];
    if max>n then exit(false);
    if max*p[depth]<n then exit(false);
    
    dec(depth);
    for i:=d downto depth+1 do
      begin
        a[depth]:=a[i]+max;
        if find(a,depth) then exit(true);
      end;
    exit(false);
  end;

begin
  readln(n);
  
  temp:=n;
  dep:=0;
  while temp>0 do
    begin
      if temp mod 2=1 then inc(dep,2)
        else inc(dep);
      temp:=temp div 2;
    end;
  dec(dep);
  
  ans:=dep;
  l:=1; r:=dep;
  while l<r do
    begin
      fillchar(a,sizeof(a),0);
      if d=(l+r) div 2 then break;
      d:=(l+r) div 2;
      a[d]:=1;
      if find(a,d) then
        begin
          if ans>d then ans:=d;
          r:=d;
        end
      else l:=d;
    end;
  
  writeln(ans-1);

  for i:=1 to ans-1 do write(best[i],' ');
  writeln(best[ans]);

end.

