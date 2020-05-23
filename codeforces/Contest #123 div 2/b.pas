var
  a,b,c:longint;

begin
  readln(a,b,c);
  if (c*(a-b)) mod b=0 then writeln((c*(a-b)) div b)
  else writeln(((c*(a-b)) div b)+1)
  //writeln((c*(a-b)) div b);
end.
