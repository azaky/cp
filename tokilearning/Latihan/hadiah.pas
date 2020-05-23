var
  a,c,d,pat,st,i,k:longint;
  a0,a1,b,b0:int64;
  small:boolean;
  rem:array[0..9999999] of boolean;
  
function pmod(a,b,n:int64):int64;
  var
    mid:int64;
    
  begin
    if b=0 then exit(1);
    mid:=pmod(a,b div 2,n);
    mid:=(mid*mid) mod n;
    if b mod 2=0 then pmod:=mid
      else pmod:=(mid*a) mod n;
  end;

begin
  readln(a,b,c,d);
  a:=a mod d;
  
  //first consider a case that b^c is quite small - less than 1000000000
  
  b0:=1;
  small:=true;
  for i:=1 to c do
    begin
      b0:=b0*b;
      if b0>1000000000 then
        begin
          small:=false;
          break;
        end;
    end;
  if small then
    begin
      writeln(pmod(a,b0,d)+1);
      halt;
    end;
    
  
  //in this case, b^c is a very big number. We will find pattern for the power of a in modulo n
  rem[1]:=true;
  a0:=1;
  k:=0;
  
  while true do
    begin
      inc(k);
      a0:=(a0*a) mod d;
      if rem[a0] then break
        else rem[a0]:=true;
    end;
    
  a1:=1;
  for i:=1 to k do
    begin
      a1:=(a1*a) mod d;
      if a0=a1 then
        begin
          if i=k then
            begin
              pat:=k;
              st:=0;
            end
          else
            begin
              pat:=k-i;
              st:=i-1;
            end;
          break;
        end;
    end;
  
  b0:=pmod(b,c,pat);
  while b0<=st do b0:=b0+pat;
  
  writeln(pmod(a,b0,d)+1);
  
end.