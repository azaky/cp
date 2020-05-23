{
ID: a_zaky01
PROG: frac1
LANG: PASCAL
}

var
  n,i,ix:integer;
  v:real;
  min:array[0..1000] of integer;
  fin,fout:text;

function gcd(a,b:integer):integer;
  begin
    if a<b then gcd:=gcd(b,a)
      else if b=0 then gcd:=a
        else gcd:=gcd(b,a mod b);
  end;

begin
  assign(fin,'frac1.in');
  assign(fout,'frac1.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  writeln(fout,'0/1');
  for i:=1 to n do min[i]:=1;
  ix:=0;
  while true do
    begin
      v:=1.1;
      while gcd(min[ix],ix)>1 do inc(min[ix]);
      for i:=1 to n do
        if (min[i]/i<v) and (min[i]<=i) then
          begin
            ix:=i;
            v:=min[i]/i;
          end
        else if min[i]/i=v then inc(min[i]);
      writeln(fout,min[ix],'/',ix);
      if ix=1 then break;
      inc(min[ix]);
    end;
  close(fin);
  close(fout);
end.
