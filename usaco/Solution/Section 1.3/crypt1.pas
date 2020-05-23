{
ID: a_zaky01
PROG: crypt1
LANG: PASCAL
}

var
  i,n,int1,int2,int3,int4,int5,num1,num2,count,hasil:longint;
  a:array[1..10] of integer;
  stat:array[0..9] of boolean;
  fin,fout:text;

label
  next;

begin
  assign(fin,'crypt1.in');
  assign(fout,'crypt1.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    begin
      read(fin,a[i]);
      stat[a[i]]:=true;
    end;
  count:=0;
  for int1:=1 to n do
    for int2:=1 to n do
      for int3:=1 to n do
        for int4:=1 to n do
          for int5:=1 to n do
            begin
              if (a[int1]=0) or (a[int4]=0) or (a[int5]=0) then goto next;
              num1:=100*a[int1]+10*a[int2]+a[int3];
              num2:=10*a[int4]+a[int5];
              {check the partial product 1}
              hasil:=num1*a[int5];
              if trunc(ln(hasil)/ln(10))<>2 then goto next;
              if not(stat[hasil div 100]) then goto next;
              hasil:=hasil-100*(hasil div 100);
              if not(stat[hasil div 10]) then goto next;
              if not(stat[hasil mod 10]) then goto next;
              {check the partial product 2}
              hasil:=num1*a[int4];
              if trunc(ln(hasil)/ln(10))<>2 then goto next;
              if not(stat[hasil div 100]) then goto next;
              hasil:=hasil-100*(hasil div 100);
              if not(stat[hasil div 10]) then goto next;
              if not(stat[hasil mod 10]) then goto next;
              {check the result}
              hasil:=num1*num2;
              if trunc(ln(hasil)/ln(10))<>3 then goto next;
              if not(stat[hasil div 1000]) then goto next;
              hasil:=hasil-1000*(hasil div 1000);
              if not(stat[hasil div 100]) then goto next;
              hasil:=hasil-100*(hasil div 100);
              if not(stat[hasil div 10]) then goto next;
              if not(stat[hasil mod 10]) then goto next;
              inc(count);
              next:
            end;
  writeln(fout,count);
  close(fin);
  close(fout);
end.
