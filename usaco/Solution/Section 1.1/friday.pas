{
ID: a_zaky01
PROG: friday
LANG: PASCAL
}

var
  n,i,j,t,m,v:integer;
  month:array[1..12] of integer;
  w:array[0..6] of integer;
  fin,fout:text;

function leap(x:integer):boolean;
  begin
    if (x mod 4=0) then
      if (x mod 100=0) and (x mod 400<>0) then leap:=false
        else leap:=true
      else leap:=false;
  end;

begin
  assign(fin,'friday.in');
  assign(fout,'friday.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to 12 do
    case i of
      4,6,9,11:month[i]:=2;
      2:month[i]:=0;
      else month[i]:=3;
    end;
  v:=6;
  for t:=1900 to 1900+n-1 do
    for m:=1 to 12 do
      begin
        inc(w[v]);
        v:=(v+month[m]) mod 7;
        if (leap(t)) and (m=2) then v:=(v+1) mod 7;
      end;
  write(fout,w[6]);
  for i:=0 to 5 do write(fout,' ',w[i]);
  writeln(fout);
  close(fin);
  close(fout);
end.
