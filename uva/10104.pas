type pair = record f,s:int64; end;
function mp(a,b:int64):pair;
  begin
    mp.f := a; mp.s := b;
  end;

function gcd(a,b:int64):pair;
  var
    p:pair;
  
  begin
    if b=0 then exit(mp(1,0));
    p := gcd(b,a mod b);
    exit(mp(p.s,p.f-(a div b)*p.s));
  end;

var
  a,b:longint;
  ans:pair;

begin
  repeat
    readln(a,b); ans := gcd(a,b);
    writeln(ans.f,' ',ans.s,' ',ans.f*a+ans.s*b);
  until eof;
end.
