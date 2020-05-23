var
teta,v0,x0,y0,g,x,y,g1:real;

begin
write('Masukkan sudut elevasi  =');
readln(teta);
write('Masukkan kecepatan awal =');
readln(v0);
write('Masukkan posisi partikel=');
readln(x0,y0);
write('Masukkan besar gravitasi=');
readln(g);
x:=v0*cos(teta);
y:=v0*sin(teta);
g1:=g/2;
writeln('Persamaan posisi partikel adalah');
write('r=(',x0:1:2,'+',x:1:2,'t)i+(',y0:1:2,'+',y:1:2,'t-',g1:1:2,'t^2)j');
end.
