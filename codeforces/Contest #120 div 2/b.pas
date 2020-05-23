var
  x1,y1,r1,x2,y2,r2,dd:double;
function d(x1,y1,x2,y2:double):double;
  begin
    exit(sqrt(sqr(x1-x2)+sqr(y1-y2)));
  end;
begin
  readln(x1,y1,r1);
  readln(x2,y2,r2);
  dd := d(x1,y1,x2,y2);
  if dd>=r1+r2 then writeln((dd-r1-r2)/2:0:20)
  else if dd<=abs(r1-r2) then writeln((abs(r1-r2)-dd)/2:0:20)
  else writeln(0);
end.
