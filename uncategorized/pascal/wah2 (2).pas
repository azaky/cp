type
  arr=array[0..10000] of integer;
  
var
  i,k,t,kasus,n,sqr1,sqr2:longint;
  size,a,b:array[1..2] of longint;
  wah,u,pos:array[1..2] of arr;
  init:arr;

procedure qsort(var w,u:arr);
  procedure sort(l,r:longint);
    var
      i,j,midw,midu,temp:longint;
      
    begin
      i:=l;
      j:=r;
      midw:=w[(l+r) div 2];
      midu:=u[(l+r) div 2];
      repeat
        while (w[i]<midw) or ((w[i]=midw) and (u[i]<midu)) do inc(i);
        while (w[j]>midw) or ((w[j]=midw) and (u[j]>midu)) do dec(j);
        if i<=j then
          begin
            temp:=w[i]; w[i]:=w[j]; w[j]:=temp;
            temp:=u[i]; u[i]:=u[j]; u[j]:=temp;
            inc(i); dec(j);
          end;
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;
  
  begin
    sort(1,n);
  end;

procedure proc1;
  begin
    writeln(u[1][a[1]]-1,' ',u[2][b[2]]-1,' ',sqr1);
    if a[1]=b[1] then inc(b[1]);
    inc(a[1]);
    if a[1]=pos[1][size[1]] then a[1]:=b[1];
    if a[2]=b[2] then inc(a[2]);
    inc(b[2]);
    if b[2]=pos[2][size[2]+1] then
      begin
        dec(size[2]);
        b[2]:=pos[2][size[2]];
        if b[2]<a[2] then b[2]:=a[2];
      end;
  end;

procedure proc2;
  begin
    writeln(u[1][b[1]]-1,' ',u[2][a[2]]-1,' ',sqr2);
    if a[2]=b[2] then inc(b[2]);
    inc(a[2]);
    if a[2]=pos[2][size[2]] then a[2]:=b[2];
    if a[1]=b[1] then inc(a[1]);
    inc(b[1]);
    if b[1]=pos[1][size[1]+1] then
      begin
        dec(size[1]);
        b[1]:=pos[1][size[1]];
        if b[1]<a[1] then b[1]:=a[1];
      end;
  end;

begin

  for i:=1 to 10000 do init[i]:=i;
  readln(t);
  for kasus:=1 to t do
    begin
    
      readln(n);
      
      for k:=1 to 2 do
        begin
        
          for i:=1 to n do read(wah[k][i]);
          
          u[k]:=init;
          qsort(wah[k],u[k]);
          
          pos[k][1]:=1;
          size[k]:=1;
          for i:=2 to n do
            if wah[k][i]<>wah[k][i-1] then
              begin
                inc(size[k]);
                pos[k][size[k]]:=i;
              end;
          pos[k][size[k]+1]:=n+1;
          
          a[k]:=1; b[k]:=pos[k][size[k]];
          {
          for i:=1 to n do write(wah[k][i],' ');
          writeln;
          for i:=1 to n do write(u[k][i],' ');
          writeln; writeln;
          }
        end;
      
      for i:=1 to n do
        begin
          //writeln(a[1],' ',b[1],'---',a[2],' ',b[2]);
        
          sqr1:=sqr(wah[1][a[1]]-wah[2][b[2]]);
          sqr2:=sqr(wah[1][b[1]]-wah[2][a[2]]);
          
          if ((sqr1=sqr2) and ((u[1][a[1]]<u[1][b[1]]) or ((u[1][a[1]]=u[1][b[1]]) and (u[2][b[2]]<u[2][a[2]])))) or (sqr1>sqr2) then proc1
            else proc2;
            
        end;
        
      writeln;
      
    end;

end.

