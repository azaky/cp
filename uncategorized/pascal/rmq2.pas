const
  maxn = 1000000;
  max2 = trunc(ln(maxn)/ln(2));

var
  n,q,i,k,a,b,ans1,ans2,lim,temp:longint;
  min,max:array[1..maxn,0..max2] of longint;
  p:array[0..max2] of longint;

begin
  assign(input,'text.txt'); reset(input);
  assign(output,'text.out'); rewrite(output);
  
  readln(n,q); writeln(n,' ',q);
  for i:=1 to n do
    begin
      read(max[i,0]);
      min[i,0]:=max[i,0];
    end;
  
  p[0]:=1; k:=0;
  
  while true do
    begin
      inc(k); p[k]:=p[k-1]*2;
      if p[k]>n then break;
      
      for i:=1 to n-p[k]+1 do
        begin
          max[i,k]:=max[i,k-1];
          if max[i+p[k-1],k-1]>max[i,k] then max[i,k]:=max[i+p[k-1],k-1];
          min[i,k]:=min[i,k-1];
          if min[i+p[k-1],k-1]<min[i,k] then min[i,k]:=min[i+p[k-1],k-1];
        end;
      
    end;
  
  for k:=1 to q do
    begin
      readln(a,b);
      if a>b then
        begin
          temp:=a;
          a:=b;
          b:=temp;
        end;
        
      lim:=trunc(ln(b-a)/ln(2));
      
      ans1:=max[a,lim];
      if max[b-p[lim]+1,lim]>ans1 then ans1:=max[b-p[lim]+1,lim];
      
      ans2:=min[a,lim];
      if min[b-p[lim]+1,lim]<ans2 then ans2:=min[b-p[lim]+1,lim];
      
      writeln(ans1,' ',ans2);
    end;
  
  close(input);
  close(output);
end.

