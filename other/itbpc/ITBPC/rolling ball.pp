var
  input,hmove:string;
  area:array[0..1000,0..1000] of string;
  data:array[1..1000] of integer;
  r,c,i,j,rball,cball,time,count,possibility:integer;
  move:boolean;

procedure ball(x:boolean);
  var
    temptime,tempr,tempc:integer;

  begin
    while x do
      begin
        if area[rball+1,cball]='.' then
          begin
            rball:=rball+1;
            hmove:='no';
            time:=time+1;
          end
        else if area[rball+1,cball]='X' then
          if hmove='no' then
            begin
              hmove:='left';
              temptime:=time;
              tempr:=rball;
              tempc:=cball;
              ball(true);
              time:=temptime;
              rball:=tempr;
              cball:=tempc;
              hmove:='right';
              ball(true);
              x:=false;
            end
          else if hmove='left' then
            if area[rball,cball-1]='.' then
              begin
                cball:=cball-1;
                time:=time+1;
              end
            else
              begin
                x:=false;
                inc(count);
                data[count]:=time;
              end
          else if hmove='right' then
            if area[rball,cball+1]='.' then
              begin
                cball:=cball+1;
                time:=time+1;
              end
            else
              begin
                x:=false;
                inc(count);
                data[count]:=time;
              end;
      end;
  end;

function average(a:array of integer; n:integer):real;
  var
    sum,i:integer;

  begin
    sum:=0;
    for i:=1 to n do sum:=sum + a[i];
    average:=sum/n;
  end;

begin
  readln(r,c);
  for i:=1 to r do
    begin
      readln(input);
       for j:=1 to c do if input[j]='B' then
        begin
          area[i,j]:='.';
          rball:=i;
          cball:=j;
        end
        else area[i,j]:=input[j];
    end;
  for i:=0 to r+1 do
    begin
      area[i,0]:='X';
      area[i,c+1]:='X';
    end;
  for j:=0 to c+1 do
    begin
      area[0,j]:='X';
      area[r+1,j]:='X';
    end;
  count:=0;
  time:=0;
  move:=true;
  hmove:='no';
  ball(move);
  for i:=1 to count do writeln(data[i]);
  writeln(average(data,count):1:3);
end.
