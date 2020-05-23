const
  g = 10000;

var
  t,kasus,n,i,l0,l1,p0,p1,a,b:longint;
  l,p:array[0..g] of integer;
  statl,statp:array[0..g] of boolean;

function maxl():integer;
  var
    i,max:integer;

  begin
    max:=0;
    for i:=0 to n-1 do if not(statl[i]) then if l[i]>max then
      begin
        max:=l[i];
        maxl:=i;
      end;
  end;

function maxp():integer;
  var
    i,max:integer;

  begin
    max:=0;
    for i:=0 to n-1 do if not(statp[i]) then if p[i]>max then
      begin
        max:=p[i];
        maxp:=i;
      end;
  end;

function minl():integer;
  var
    i,min:integer;

  begin
    min:=g;
    for i:=0 to n-1 do if not(statl[i]) then if l[i]<min then
      begin
        min:=l[i];
        minl:=i;
      end;
  end;

function minp():integer;
  var
    i,min:integer;

  begin
    min:=g;
    for i:=0 to n-1 do if not(statp[i]) then if p[i]<min then
      begin
        min:=p[i];
        minp:=i;
      end;
  end;

procedure setup;
  var
    i:integer;

  begin
    for i:=0 to n-1 do statl[i]:=false;
    for i:=0 to n-1 do statp[i]:=false;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      for i:=0 to n-1 do if i=n-1 then readln(l[i]) else read(l[i]);
      for i:=0 to n-1 do if i=n-1 then readln(p[i]) else read(p[i]);
      setup;
      for i:=1 to n do
        begin
          l1:=maxl;
          l0:=minl;
          p1:=maxp;
          p0:=minp;
          a:=l[l1]-p[p0];
          b:=p[p1]-l[l0];
          if (a>b) or ((a=b) and ((l1<l0) or ((l1=l0) and (p0<p1)))) then
            begin
              writeln(l1,' ',p0,' ',a*a);
              statl[l1]:=true;
              statp[p0]:=true;
            end
          else
            begin
              writeln(l0,' ',p1,' ',b*b);
              statl[l0]:=true;
              statp[p1]:=true;
            end;
        end;
      writeln;
    end;
end.
