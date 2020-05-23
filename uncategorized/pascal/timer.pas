uses
  crt,Dos,classes,sysutils;

var
  i,j,a,b:longint;
  h,m,s,ms,h2,m2,s2,ms2:word;

begin
  gettime(h,m,s,ms);
    for j:=1 to 2000d000 do
  gettime(h2,m2,s2,ms2);
  writeln(((h2-h)*360000+(m2-m)*6000+(s2-s)*100+(ms2-ms))/100:0:2);
end.

