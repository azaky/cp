{
ID: a_zaky01
PROG: ratios
LANG: PASCAL
}

type
  arr=array[1..3] of integer;

var
  min,i,j,k,x,y,z,intx,inty,intz,tot:longint;
  ans:arr;
  a:array[1..3] of arr;
  fin,fout:text;

begin
  assign(fin,'ratios.in');
  assign(fout,'ratios.out');
  reset(fin);
  rewrite(fout);
  readln(fin,x,y,z);
  for i:=1 to 3 do
    for j:=1 to 3 do read(fin,a[i][j]);
  min:=0;
  for i:=0 to 99 do
    for j:=0 to 99 do
      for k:=0 to 99 do
        if (i<>0) or (j<>0) or (k<>0) then
          begin
            intx:=i*a[1][1]+j*a[2][1]+k*a[3][1];
            inty:=i*a[1][2]+j*a[2][2]+k*a[3][2];
            intz:=i*a[1][3]+j*a[2][3]+k*a[3][3];
            if (min=0) or (i+j+k<min) then
              if (intx*y=inty*x) and (inty*z=intz*y) and (intx mod x=0) then
                begin
                  min:=i+j+k;
                  ans[1]:=i;
                  ans[2]:=j;
                  ans[3]:=k;
                  tot:=intx div x;
                end;
          end;
  if min=0 then writeln(fout,'NONE')
    else writeln(fout,ans[1],' ',ans[2],' ',ans[3],' ',tot);
  close(fin);
  close(fout);
end.
