{
ID: a_zaky01
PROG: nuggets
LANG: PASCAL
}

const
  max=65536;

var
  n,i,j,ans,gcd0:longint;
  a:array[1..10] of integer;
  stat:array[0..max] of boolean;
  fin,fout:text;

function gcd(a,b:longint):longint;
  begin
    if a<b then gcd:=gcd(b,a)
      else if b=0 then gcd:=a
        else gcd:=gcd(b,a mod b);
  end;

begin
  assign(fin,'nuggets.in');
  assign(fout,'nuggets.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do readln(fin,a[i]);
  gcd0:=0;
  for i:=1 to n do gcd0:=gcd(gcd0,a[i]);
  if gcd0>1 then writeln(fout,0)
    else
      begin
        ans:=0;
        stat[0]:=true;
        for i:=1 to n do
          for j:=a[i] to max do stat[j]:=stat[j] or stat[j-a[i]];
        for i:=max downto 1 do
          if not stat[i] then
            begin
              ans:=i;
              break;
            end;
        writeln(fout,ans);
      end;
  close(fin);
  close(fout);
end.
