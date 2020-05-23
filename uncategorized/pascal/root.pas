var
  n,k,i:longint;
  j,temp:real;

function pangkat(n:real; k:integer):real;
  var
    temp:real;

  begin
    if k=1 then pangkat:=n
      else
        begin
          temp:=pangkat(n,k div 2);
          if k mod 2=0 then pangkat:=temp*temp
            else pangkat:=temp*temp*n;
        end;
  end;

begin
  readln(n,k);
  if n=0 then writeln('0.000')
    else
      begin
        i:=1;
        while pangkat(i,k)<n do inc(i);
        j:=i;
        if pangkat(i,k)=n then writeln(j:1:3)
          else
            begin
              temp:=abs(pangkat(j,k)-n);
              while abs(pangkat((j-0.001),k)-n)<temp do
                begin
                  j:=j-0.001;
                  temp:=abs(pangkat(j,k)-n)
                end;
              writeln(j:1:3);
            end;
      end;
end.
