var
  i,j,max,t1,t2,t3,t4:longint;
  a:array[-3..24,-3..24] of longint;

begin
  fillchar(a,sizeof(a),0);
  for i:=1 to 20 do
    for j:=1 to 20 do read(a[i,j]);
  max:=0;
  for i:=1 to 20 do
    for j:=1 to 20 do
      begin
        t1:=a[i,j]*a[i,j+1]*a[i,j+2]*a[i,j+3];
        t2:=a[i,j]*a[i+1,j]*a[i+2,j]*a[i+3,j];
        t3:=a[i,j]*a[i+1,j+1]*a[i+2,j+2]*a[i+3,j+3];
        t4:=a[i,j]*a[i-1,j+1]*a[i-2,j+2]*a[i-3,j+3];
        writeln(i,' ',j,' ',t1,' ',t2,' ',t3,' ',t4);
        if t1>max then max:=t1;
        if t2>max then max:=t2;
        if t3>max then max:=t3;
        if t4>max then max:=t4;
      end;
  writeln(max);
end.

