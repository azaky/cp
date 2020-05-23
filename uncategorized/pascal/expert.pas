var
  t,kasus,d,i,j,q,p,temp:longint;
  ch:char;
  maker:array[0..9999] of string;
  l,h:array[1..9999] of longint;

begin
  readln(t);
  maker[0]:='UNDETERMINED';
  for kasus:=1 to t do
    begin
      readln(d);
      for i:=1 to d do
        begin
          maker[i]:='';
          repeat
            read(ch);
            if ch=' ' then break;
            maker[i]:=maker[i]+ch;
          until false;
          readln(l[i],h[i]);
        end;
      readln(q);
      for i:=1 to q do
        begin
          readln(p);
          temp:=0;
          for j:=1 to d do
            if ((l[j]<=p) and (p<=h[j])) then
              if temp=0 then temp:=j
                else
                  begin
                    temp:=0;
                    break;
                  end;
          writeln(maker[temp]);
        end;
      if kasus<t then writeln;
    end;
end.
