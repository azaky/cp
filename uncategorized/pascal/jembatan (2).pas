var
  k,i,min,max:integer;
  input:char;
  lubang:array[0..2500] of integer;
  arr:array[0..2500,0..2500] of single;
 
function f(l,r:integer):real;
  var
    i:integer;
    temp:real;
 
  begin
    if arr[l,r]=0 then
      begin
    f:=sqrt(lubang[r]-lubang[l]+1);
    
    if l<r then
      for i:=l to r-1 do
        if f>sqrt(lubang[i]-lubang[l]+1)+sqrt(lubang[r]-lubang[i+1]+1) then
          begin
            temp:=f(l,i)+f(i+1,r);
            if temp<f then f:=temp;
          end;
    arr[l,r]:=f;
      end
    else f:=arr[l,r];
  end;
 
begin
  while true do
    begin
      inc(k);
      read(input);
      if input='X' then
        begin
          inc(i);
          lubang[i]:=k;
        end
      else if input<>'.' then break;
    end;
  if i=0 then writeln(0.000)
    else writeln(f(1,i):0:3);
end.