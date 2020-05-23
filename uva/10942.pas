const
  mon :array[1..12] of int64 = (31,29,31,30,31,30,31,31,30,31,30,31);

type
  date = record
    mm,yy,dd:int64;
  end;

var
  init,temp,best:date;
  tc,kasus:longint;
  cen,a,b,c:int64;

function leap(a:int64):boolean;
  begin
    exit((a mod 4=0) and not ((a mod 100=0) and (a mod 400<>0)));
  end;

procedure check(t:date);
  begin
    with t do
	  begin
	    if (mm>12) or (mm=0) then exit
	      else if (dd>mon[mm]) or (dd=0) then exit;
	    if (mm=2) and not leap(yy) and (dd=29) then exit;
		if (yy<best.yy) or ((yy=best.yy) and (mm<best.mm)) or ((yy=best.yy) and (mm=best.mm) and (dd<best.dd)) then best:=t;
	  end;
  end;

begin
  with init do
    begin
	  mm:=13; yy:=sqr(maxlongint); dd:=32;
	end;
  readln(tc);
  for kasus:=1 to tc do
    begin
	  readln(cen,a,b,c); best:=init;
	  with temp do
	    begin
		  yy:=100*cen+a; mm:=b; dd:=c;
		end;
	  check(temp);
	  with temp do
	    begin
		  yy:=100*cen+a; mm:=c; dd:=b;
		end;
	  check(temp);
	  with temp do
	    begin
		  yy:=100*cen+b; mm:=a; dd:=c;
		end;
	  check(temp);
	  with temp do
	    begin
		  yy:=100*cen+b; mm:=c; dd:=a;
		end;
	  check(temp);
	  with temp do
	    begin
		  yy:=100*cen+c; mm:=a; dd:=b;
		end;
	  check(temp);
	  with temp do
	    begin
		  yy:=100*cen+c; mm:=b; dd:=a;
		end;
	  check(temp);
	  with best do
	    if dd>31 then writeln(-1)
		  else
		    begin
		      if yy mod 100=0 then write('00 ')
			    else if yy mod 100<10 then write('0',yy mod 100,' ')
			      else write(yy mod 100,' ');
			  if mm<10 then write('0',mm,' ')
			    else write(mm,' ');
			  if dd<10 then writeln('0',dd)
			    else writeln(dd);
		    end;
	end;
end.
