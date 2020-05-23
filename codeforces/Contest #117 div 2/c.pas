var
  a,b,s:ansistring;
  n,i,ans:longint;

function sgcd(a,b:ansistring):ansistring;
  var
    la,lb,i,j:longint;
  
  begin
    if length(a)>length(b) then exit(sgcd(b,a));
    la:=length(a); lb:=length(b);
    for i:=1 to lb div la do
      for j:=1 to la do
        if a[j]<>b[j+la*(i-1)] then exit('');
    if lb mod la=0 then exit(a)
      else exit(sgcd(copy(b,1,lb mod la),a));
  end;

function check(k:longint):boolean;
  var
    i,j:longint;
  
  begin
    for i:=1 to (n div k)-1 do
      for j:=1 to k do
        if s[j]<>s[j+i*k] then exit(false);
    exit(true);
  end;

begin
  readln(a); readln(b);
  s := sgcd(a,b);
  if s='' then
    begin
      writeln(0);halt;
    end
  else n:=length(s);
  for i:=1 to trunc(sqrt(n)) do
    if n mod i=0 then
      begin
        if check(i) then inc(ans);
        if check(n div i) then inc(ans);
      end;
  writeln(ans);
end.
