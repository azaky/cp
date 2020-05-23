{
ID: a_zaky01
PROG: milk4
LANG: PASCAL
}

type
  table=array[1..100] of integer;
  
var
  p,q,i,k,depth,best,a,b:integer;
  found:boolean;
  total:array[0..100] of longint;
  pail,ans,arr:table;

label
  closefile;

procedure sort(l,r:integer);
  var
    i,j,mid,temp:integer;
    
  begin
    i:=l;
    j:=r;
    mid:=pail[(l+r) div 2];
    repeat
      while pail[i]<mid do inc(i);
      while pail[j]>mid do dec(j);
      if i<=j then
        begin
          temp:=pail[i];
          pail[i]:=pail[j];
          pail[j]:=temp;
          inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

function pour(d,p0,q0:integer):boolean;
  var
    i:integer;
    
  begin
    if d=0 then
      if q0=q then exit(true)
        else exit(false);
    
    if p-p0<d then exit(false);
    if total[p0+d]-total[p0]>q-q0 then exit(false);
    
    inc(p0);
    if pour(d,p0,q0)then exit(true);
    
    for i:=1 to (q-q0) div pail[p0] do
      if pour(d-1,p0,q0+i*pail[p0]) then exit(true);
    
    exit(false);
  end;

procedure find(d,p0,q0:integer; arr:table);
  var
    i:integer;
    better:boolean;
    
  begin
    if p-p0<d then exit;
    if total[p0+d]-total[p0]>q-q0 then exit;
    
    if found then
      begin
        better:=true;
        for i:=1 to best-d do
          if ans[i]<arr[i] then
            begin
              better:=false;
              break;
            end;
        if not better then exit;
      end;
    
    if d=0 then
      if q0=q then
        begin
          found:=true;
          ans:=arr;
          exit;
        end
      else exit;
    
    inc(p0); dec(d);
    arr[best-d]:=pail[p0];
    for i:=1 to (q-q0) div pail[p0] do find(d,p0,q0+i*pail[p0],arr);
    
    find(d+1,p0,q0,arr);
  end;

begin

  assign(input,'milk4.in');
  assign(output,'milk4.out');
  reset(input);
  rewrite(output);

  readln(q);
  readln(p);
  for i:=1 to p do readln(pail[i]);
  
  sort(1,p);
  for i:=1 to p do
    if q mod pail[i]=0 then
      begin
        writeln('1 ',pail[i]);
        goto closefile;
      end;
  
  k:=1;
  for i:=2 to p do
    if pail[i]<>pail[i-1] then
      begin
        inc(k);
        pail[k]:=pail[i];
      end;
  p:=k;
  while pail[p]>q do dec(p);
  
  total[0]:=0;
  for i:=1 to p do total[i]:=total[i-1]+pail[i];
  
  for a:=1 to p do
    if pour(a,0,0) then
      begin
        best:=a;
        break;
      end;
  
  found:=false;
  find(best,0,0,arr);
  
  write(best);
  for i:=1 to best do write(' ',ans[i]);
  writeln;
  
  closefile:

  close(input);
  close(output);

end.

