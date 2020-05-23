type
  box=array[1..80,1..80] of longint;

var
  t,kasus,i,j,n,ta,ba,la,ra,ia,ja,tb,bb,lb,rb,ib,jb:longint;
  ch:char;
  a,b:box;

function empty(a:box):boolean;
  var
    i,j:longint;
  
  begin
    empty:=true;
    for i:=1 to n do
      for j:=1 to n do
        if a[i,j]<>0 then exit(false);
  end;

function erow(a:box; k:longint):boolean;
  var
    i:longint;
  
  begin
    erow:=true;
    for i:=1 to n do
      if a[k,i]<>0 then exit(false);
  end;

function ecol(a:box; k:longint):boolean;
  var
    i:longint;
  
  begin
    ecol:=true;
    for i:=1 to n do
      if a[i,k]<>0 then exit(false);
  end;

function same:boolean;
  var
    i,j:longint;
  
  begin
    if (ia<>ib) or (ja<>jb) then exit(false);
    same:=true;
    for i:=1 to ia do
      for j:=1 to jb do
        if a[i,j]<>b[i,j] then exit(false);
  end;

procedure rotate;
  var
    temp:box;
    i,j,t:longint;
  
  begin
    fillchar(temp,sizeof(temp),0);
    for i:=1 to ia do
      for j:=1 to ja do temp[j,i]:=a[ia+1-i,j];
    a:=temp; t:=ia; ia:=ja; ja:=t;
  end;

procedure tulis;
  var
    i,j:longint;
  
  begin
    for i:=1 to n do
      begin
        for j:=1 to n do write(a[i,j]);
        write(' ');
        for j:=1 to n do write(b[i,j]);
        writeln;
      end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      
      for i:=1 to n do
        begin
          for j:=1 to n do
            begin
              read(ch); a[i,j]:=ord(ch)-ord('0');
            end;
          readln;
        end;
        
      for i:=1 to n do
        begin
          for j:=1 to n do
            begin
              read(ch); b[i,j]:=ord(ch)-ord('0');
            end;
          readln;
        end;
        
      if empty(a) and empty(b) then
        begin
          writeln('YA'); continue;
        end;
      
      if empty(a) xor empty(b) then
        begin
          writeln('TIDAK'); continue;
        end;
      
      ta:=1; la:=1; ba:=n; ra:=n;
      while erow(a,ta) do inc(ta);
      while erow(a,ba) do dec(ba);
      while ecol(a,la) do inc(la);
      while ecol(a,ra) do dec(ra);
      
      for i:=1 to ba-ta+1 do
        for j:=1 to ra-la+1 do
          a[i,j]:=a[i+ta-1,j+la-1];
      ia:=ba-ta+1; ja:=ra-la+1;
      
      tb:=1; lb:=1; bb:=n; rb:=n;
      while erow(b,tb) do inc(tb);
      while erow(b,bb) do dec(bb);
      while ecol(b,lb) do inc(lb);
      while ecol(b,rb) do dec(rb);
      
      for i:=1 to bb-tb+1 do
        for j:=1 to rb-lb+1 do
          b[i,j]:=b[i+tb-1,j+lb-1];
      ib:=bb-tb+1; jb:=rb-lb+1;
      
      if not (((ia=ib) and (ja=jb)) or ((ia=jb) and (ib=ja))) then
        begin
          writeln('TIDAK'); continue;
        end;
      
      if same then
        begin
          writeln('YA'); continue;
        end;
      //tulis;
      rotate;
      if same then
        begin
          writeln('YA'); continue;
        end;
      //tulis;
      rotate;
      if same then
        begin
          writeln('YA'); continue;
        end;
      //tulis;
      rotate;
      if same then
        begin
          writeln('YA'); continue;
        end;
      //tulis;
      writeln('TIDAK'); continue;
      
    end;
end.

