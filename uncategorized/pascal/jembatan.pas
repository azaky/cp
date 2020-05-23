var
  k,i:integer;
  input:char;
  lubang:array[0..2500] of integer;

function f(l,r:integer):extended;
  var
    i:integer;
    temp,f2:extended;

  begin
    f:=sqrt(lubang[r]-lubang[l]+1);
    f2:=f;
    if l<r then
      for i:=l to r-1 do
        if f2>sqrt(lubang[i]-lubang[l]+1)+sqrt(lubang[r]-lubang[i+1]+1) then
          begin
            temp:=f(l,i)+f(i+1,r);
            if temp<f then f:=temp;
          end;
  end;

begin
  i:=0;
  k:=0;
  while not eof do
    begin
      inc(k);
      read(input);
      if input='X' then
        begin
          inc(i);
          lubang[i]:=k;
        end;
    end;
  if i=0 then writeln('0.000')
    else writeln(f(1,i):0:3);
end.
