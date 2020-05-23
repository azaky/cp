uses math;
var
  n,k,i,ans:longint;
  s:ansistring;

function ok(k:longint):boolean;
  var
    i:longint;
  
  begin
    for i:=k+1 to n do
      if s[i]<>s[i-k] then exit(false);
    exit(true);
  end;

begin
  repeat
    readln(s); if s='.' then exit;
    n := length(s);
    ans := 0;
    for k:=1 to 1001 do
      begin
        if n mod k<>0 then continue;
        if ok(k) then ans := max(ans, n div k);
        if ok(n div k) then ans := max(ans,k);
      end;
    writeln(ans);
  until false;
end.
