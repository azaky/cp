var
  r,g,b,ansr,ansb,ansg:integer;

begin
  readln(r,g,b);
  ansr:=3*((r+1) div 2)+27;
  ansg:=3*((g+1) div 2)+28;
  ansb:=3*((b+1) div 2)+29;
  if (ansr>=ansg) and (ansr>=ansb) then writeln(ansr)
    else if ansg>=ansb then writeln(ansg)
      else writeln(ansb);
end.
