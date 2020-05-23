var
  n,i,k:longint;
  s:ansistring;
  tmp,a,b,mid:int64;
  t,pow,temp:extended;

function power(a:extended; b:int64):extended;
  var
    temp:extended;
  
  begin
    if b=0 then exit(1.0);
    temp:=power(a,b div 2);
    temp:=sqr(temp);
    if b mod 2=1 then temp:=temp*a;
    exit(temp);
  end;

begin
  repeat
    readln(n);
    readln(s);
    if length(s)<17 then
      begin
        val(s,tmp);
        pow:=tmp*1.0;
      end
    else
      begin
        val(copy(s,1,17),tmp);
        k:=length(s)-17;
        pow:=tmp*1.0;
        for i:=1 to k do pow:=pow*10.0;
      end;
    a:=1; b:=round(1e9);
    while a<b do
      begin
        mid:=(a+b) div 2; t:=mid*1.0;
        temp:=power(t,n);
        if temp=pow then break
          else if temp<pow then a:=mid+1
            else b:=mid;
      end;
    writeln(mid);
  until eof;
end.

