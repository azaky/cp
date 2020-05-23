var
  n,l,r,i,input:longint;

begin
  readln(n);
  l:=0;
  r:=0;
  for i:=1 to n do
    begin
      readln(input);
      if i mod 2=0 then
        if input>l then r:=input
          else
            begin
              r:=l;
              l:=input;
            end
      else if input>r then
        begin
          l:=r;
          r:=0;
        end
      else if input<l then r:=0
        else
          begin
            l:=input;
            r:=0;
          end;
    end;
  if n mod 2=0 then writeln((l+r)/2:0:1)
    else writeln(l);
end.
