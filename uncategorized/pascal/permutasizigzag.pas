var
  n:integer;
  a:array[0..9] of integer;
  used:array[1..9] of boolean;

procedure zig(k:integer);
  var
    i:integer;
  
  begin
    if k>n then
      begin
        for i:=1 to n do write(a[i]);
        writeln;
        exit;
      end;
    if k<=2 then
      begin
        for i:=1 to n do
          if i<>a[k-1] then
            begin
              a[k]:=i; used[i]:=true;
              zig(k+1); used[i]:=false;
            end;
        exit;
      end;
    for i:=1 to n do
      if not used[i] and ((i-a[k-1])*(a[k-1]-a[k-2])<0) then
        begin
          a[k]:=i; used[i]:=true;
          zig(k+1); used[i]:=false;
        end;
  end;

begin
  readln(n); a[0]:=0;
  zig(1);
end.

