var
  n,k:integer;
  hasil,x,y,sisa:int64;

function pangkat(a,k:integer):int64;
  var
    temp:int64;

  begin
    if k=1 then pangkat:=a
      else
        begin
          temp:=pangkat(a,k div 2);
          if k mod 2=0 then pangkat:=temp*temp
            else pangkat:=temp*temp*a;
        end;
  end;

begin
  readln(n);
  hasil:=pangkat(2,n);
  case (n mod 3) of
      0:k:=1;
      1:k:=2;
      2:k:=4;
    end;
  y:=1;
  while true do
    begin
      while (y*y-k) mod 7<>0 do y:=y+2;
      sisa:=(hasil-y*y) div 7;
      x:=trunc(sqrt(sisa));
      if x*x=sisa then break;
      y:=y+2;
    end;
  writeln(x,' ',y);
end.
