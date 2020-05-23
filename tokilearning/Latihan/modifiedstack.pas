var
  t,n,z,add,i,j,x,y:longint;
  task:string;
  ch:char;
  num,pos:array[0..1000] of longint;

begin
  readln(t);
  n:=0; z:=0; add:=0;
  for i:=1 to t do
    begin
      task:='';
      for j:=1 to 3 do
        begin
          read(ch);
          task:=task+ch;
        end;
      if task='add' then
        begin
          readln(x,y);
          inc(z); inc(n,y);
          pos[z]:=n; num[z]:=x;
          writeln(n);
        end
      else if task='del' then
        begin
          readln(x); writeln(num[z]+add);
          n:=n-x;
          if n=0 then
            begin
              z:=0;
              continue;
            end;
          for j:=1 to z do
            if (pos[j-1]<n) and (pos[j]>=n) then
              begin
                z:=j;
                pos[z]:=n;
                break;
              end;
        end
      else
        begin
          readln(x);
          if task='adx' then add:=add+x
            else add:=add-x;
        end;
    end;
end.
