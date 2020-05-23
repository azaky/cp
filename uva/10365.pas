uses math;

var
  tc,kasus,ans,n,i,j,k:longint;

begin
  readln(kasus);
  for tc:=1 to kasus do
    begin
      readln(n); ans := maxlongint;
      for i:=1 to trunc(sqrt(n)) do
        if n mod i=0 then
          for j:=i to trunc(sqrt(n div i)) do
            begin
              if n mod (i*j)<>0 then continue else k:=n div (i*j);
              ans := min(ans,2*(i*j+j*k+k*i));
            end;
      writeln(ans);
    end;
end.
