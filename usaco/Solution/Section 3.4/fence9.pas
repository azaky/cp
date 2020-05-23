{
ID: a_zaky01
PROG: fence9
LANG: PASCAL
}

var
  n,m,p,ans:longint;
  fin,fout:text;

function gcd(a,b:integer):integer;
  begin
    if a<b then gcd:=gcd(b,a)
      else if b=0 then gcd:=a
        else gcd:=gcd(b,a mod b);
  end;

begin
  assign(fin,'fence9.in');
  assign(fout,'fence9.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n,m,p);
  if n=0 then ans:=((p-1)*(m-1)+1-gcd(m,p)) div 2
    else ans:=((n-1)*(m-1)+1-gcd(m,n)) div 2;
  if p<n then dec(ans,((m-1)*(n-p-1)+gcd(m,n-p)-1) div 2)
    else if (p>n) and (n>0) then inc(ans,(((m-1)*(p-n-1)-gcd(m,p-n)+1) div 2)+m-1);
  writeln(fout,ans);
  close(fin);
  close(fout);
end.
