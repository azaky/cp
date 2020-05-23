const ep = 1e-9;

var
  s:ansistring;
  n,l,r,mid,i:longint;
  p,k,temp,t:extended;

function power(a:extended; b:longint):extended;
  var
    temp:extended;
  begin
    if b=0 then exit(1);
    temp := sqr(power(a,b shr 1));
    if b and 1=1 then temp := temp * a;
    exit(temp);
  end;

begin
  repeat
    readln(n);
    readln(s);
    p := 0;
    for i:=1 to length(s) do p := 10*p + extended(ord(s[i])-ord('0'));
    t := power(10,length(s)-1);
    l := 1; r := 1000000000;
    repeat
      mid := (l+r) div 2;
      k := extended(mid);
      temp := power(k,n);
      if abs(temp-p)/t<ep then break
        else if (temp-p)/t<ep then l := mid+1
          else r := mid-1;
    until false;
    writeln(mid);
  until eof;
end.
