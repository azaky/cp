var
  n,i,t,j,a,b,x,y,temp:longint;
  ch:char;
  task:string;
  l,r,num:array[0..2001] of longint;

begin
  readln(t); n:=0;
  a:=1;
  for i:=1 to t do
    begin
      task:='';
      for j:=1 to 3 do
        begin
          read(ch); task:=task+ch;
        end;
      if task='add' then
        begin
          readln(x,y);
          inc(b); num[b]:=x;
          l[b]:=n+1;
          inc(n,y); writeln(n);
          r[b]:=n;
        end
      else if task='del' then
        begin
          readln(y); writeln(num[a]);
          for j:=a to b do
            if (l[j]<=y) and (y<=r[j]) then
              begin
                a:=j;
                l[a]:=1; r[a]:=r[a]-y;
              end
            else
              begin
                dec(l[j],y);
                dec(r[j],y);
              end;
          dec(n,y);
        end
      else
        begin
          readln;
          for j:=a to (a+b) div 2 do
            begin
              temp:=l[j]; l[j]:=l[a+b-j]; l[a+b-j]:=temp;
              temp:=r[j]; r[j]:=r[a+b-j]; r[a+b-j]:=temp;
              temp:=num[j]; num[j]:=num[a+b-j]; num[a+b-j]:=temp;
            end;
          for j:=a to b do
            begin
              temp:=l[j];
              l[j]:=n+1-r[j];
              r[j]:=n+1-temp;
            end;
        end;
    end;
end.

