var
  int1,int2,int3:longint;

begin
  readln(int1,int2,int3);
  if int2+int3=int1 then writeln(int1,'=',int2,'+',int3)
  else if int2-int3=int1 then writeln(int1,'=',int2,'-',int3)
  else if int2*int3=int1 then writeln(int1,'=',int2,'*',int3)
  else if int1+int2=int3 then writeln(int1,'+',int2,'=',int3)
  else if int1-int2=int3 then writeln(int1,'-',int2,'=',int3)
  else if int1*int2=int3 then writeln(int1,'*',int2,'=',int3)
  else if (int2 div int3=int1) and (int2 mod int3=0) then writeln(int1,'=',int2,'/',int3)
  else writeln(int1,'/',int2,'=',int3);
end.