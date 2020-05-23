const
  p:array[0..12] of integer=(1,2,4,8,16,32,64,128,256,512,1024,2048,4096);

type
  arr=array[1..50] of integer;
  
var
  n,i,temp,dep,ans:longint;
  a,best:arr;
  
procedure find(a:arr; depth:integer);
  var
    i,j,max:integer;
    used:array[1..240] of boolean;
    
  begin
    max:=a[depth];
    
    if max=n then
      begin
        if ans>depth then
          begin
            //writeln('bingo');
            ans:=depth;
            best:=a;
          end;
        exit;
      end;
    
    if max>n then exit;
    if depth>dep then exit;
    if max*p[dep-depth]<n then exit;
    inc(depth);
    
    fillchar(used,sizeof(used),false);
    for i:=1 to depth-1 do
      begin
        a[depth]:=a[i]+max;
        find(a,depth);
      end;
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
  //dec(dep);
  
  ans:=dep;
  a[1]:=1;
  find(a,1);
  
  writeln(ans-1);

  for i:=1 to ans-1 do write(best[i],' ');
  writeln(best[ans]);

end.

