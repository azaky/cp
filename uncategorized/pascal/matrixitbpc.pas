var
  n:integer;

function f(n:integer):integer;
  var
    i0,n0,i,ftemp,temp:integer;

  begin
    if n=1 then f:=1
    else if n<=3 then f:=n-1
      else
        begin
          f:=n;
          for i:=2 to n-1 do
            begin
              if n mod i=0 then ftemp:=(n div i)+f(i)-1
                else
                  begin
                    ftemp:=0;
                    n0:=n;
                    i0:=i;
                    while true do
                      begin
                        inc(ftemp,n0 div i0);
                        temp:=i0;
                        i0:=n0 mod temp;
                        n0:=temp;
                        if i0=1 then
                          begin
                            inc(ftemp,f(n0));
                            break;
                          end
                        else if n0 mod i0=0 then
                          begin
                            inc(ftemp,(n0 div i0)+f(i0)-1);
                            break;
                          end;
                      end;
                  end;
              if ftemp<f then f:=ftemp;
            end;
        end;
  end;

begin
  readln(n);
  //for n:=1 to 120 do writeln('f(',n,')=',f(n));
  writeln(f(n));
end.
