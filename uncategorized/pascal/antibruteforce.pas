var
  t,kasus,n,i,imin,temp,total:longint;
  lock,best:array[0..500] of integer;
  used:array[1..500] of boolean;

function roll(a,b:integer):integer;
  var
    lock1,lock2,i,temp:integer;

  begin
    roll:=0;
    lock1:=lock[a];
    lock2:=lock[b];
    for i:=1 to 4 do
      begin
        temp:=abs((lock1 mod 10)-(lock2 mod 10));
        if temp>5 then temp:=10-temp;
        inc(roll,temp);
        lock1:=lock1 div 10;
        lock2:=lock2 div 10;
      end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      read(n);
      fillchar(used,sizeof(used),false);
      for i:=1 to n do read(lock[i]);
      lock[0]:=0;
      imin:=1;
      for i:=1 to n do
        if roll(0,i)<roll(0,imin) then imin:=i;
      total:=roll(0,imin);
      used[imin]:=true;
      for i:=1 to n do best[i]:=roll(i,imin);
      repeat
        imin:=0;
        for i:=1 to n do
          if not used[i] then
            if (imin=0) or (best[i]<best[imin]) then imin:=i;
        if imin=0 then break;
        inc(total,best[imin]);
        used[imin]:=true;
        for i:=1 to n do
          if not used[i] then
            begin
              temp:=roll(i,imin);
              if best[i]>temp then best[i]:=temp;
            end;
      until false;
      writeln(total);
    end;
end.
