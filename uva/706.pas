const
  digit:array[0..9,0..6] of longint
  =((1,1,1,0,1,1,1),
    (0,0,1,0,0,1,0),
    (1,0,1,1,1,0,1),
    (1,0,1,1,0,1,1),
    (0,1,1,1,0,1,0),
    (1,1,0,1,0,1,1),
    (1,1,0,1,1,1,1),
    (1,0,1,0,0,1,0),
    (1,1,1,1,1,1,1),
    (1,1,1,1,0,1,1));
    
var
  kasus,size,n,i,ss:longint;
  s:ansistring;
  a:array[0..111111] of longint;
  ch:char;

procedure line(s:longint);
  var i:longint;
  begin
    for i:=1 to s do write('-');
  end;
procedure space(s:longint);
  var i:longint;
  begin
    for i:=1 to s do write(' ');
  end;

begin
  repeat
    readln(size,n); if size=0 then halt;;
    str(n,s); n := length(s);
    for i:=1 to n do a[i] := ord(s[i])-ord('0');
    //0
    for i:=1 to n do
      begin
        write(' ');
        if digit[a[i],0]=1 then line(size) else space(size);
        write(' ');
        if i<n then write(' ');
      end;
    writeln;
    //1 and 2
    for ss:=1 to size do
      begin
        for i:=1 to n do
          begin
            if digit[a[i],1]=1 then write('|') else write(' ');
            space(size);
            if digit[a[i],2]=1 then write('|') else write(' ');
            if i<n then write(' ');
          end;
        writeln;
      end;
    //3
    for i:=1 to n do
      begin
        write(' ');
        if digit[a[i],3]=1 then line(size) else space(size);
        write(' ');
        if i<n then write(' ');
      end;
    writeln;
    //4 and 5
    for ss:=1 to size do
      begin
        for i:=1 to n do
          begin
            if digit[a[i],4]=1 then write('|') else write(' ');
            space(size);
            if digit[a[i],5]=1 then write('|') else write(' ');
            if i<n then write(' ');
          end;
        writeln;
      end;
    //6
    for i:=1 to n do
      begin
        write(' ');
        if digit[a[i],6]=1 then line(size) else space(size);
        write(' ');
        if i<n then write(' ');
      end;
    writeln;
    writeln;
  until false;
end.
