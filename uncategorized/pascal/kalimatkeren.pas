type
  matrix=array[1..4,1..4] of int64;

const                    
                         {lho keren kul parah}
  init:matrix = {lho  }((  0,   1,   1,   0   ),
                {keren} (  0,   0,   1,   1   ),
                {kul  } (  0,   0,   1,   1   ),
                {parah} (  1,   1,   1,   0   ));
  iden:matrix = ((1,0,0,0),(0,1,0,0),(0,0,1,0),(0,0,0,1));
  w:array[1..4] of string = ('lho','keren','kul','parah');
  max = 1000000007;
{
parah lho keren parah
parah lho kul parah
parah keren kul parah
parah kul kul parah
}
var
  i1,i2:integer;
  n:int64;
  ch:char;
  s1,s2:string;

function product(a,b:matrix):matrix;
  var
    i,j,k:integer;
  
  begin
    fillchar(product,sizeof(product),0);
    for i:=1 to 4 do
      for j:=1 to 4 do
        for k:=1 to 4 do
          product[i,j]:=(product[i,j]+a[i,k]*b[k,j]) mod max;
  end;

function power(a:matrix; e:int64):matrix;
  var
    temp:matrix;
  
  begin
    if e=0 then exit(iden);
    temp:=power(a,e div 2);
    temp:=product(temp,temp);
    if e mod 2=0 then exit(temp)
      else exit(product(temp,a));
  end;

function gen(i1,p:longint):longint;
  var
    i:longint;
  
  begin
    if p=n then
      if i2=i1 then exit(1)
        else exit(0);
    gen:=0;
    for i:=1 to 4 do
      if init[i1,i]=1 then gen:=gen+gen(i,p+1);
  end;

begin
  //1=lho
  //2=keren
  //3=kul
  //4=parah
  readln(n);
  s1:=''; s2:='';
  repeat
    read(ch); ch:=lowercase(ch);
    if ch in ['a'..'z'] then s1:=s1+ch
      else break;
  until ch=' ';
  repeat
    read(ch); ch:=lowercase(ch);
    if ch in ['a'..'z'] then s2:=s2+ch
      else break;
  until false;
  for i1:=1 to 4 do
    if w[i1]=s1 then break;
  for i2:=1 to 4 do
    if w[i2]=s2 then break;
  writeln(power(init,n-1)[i1,i2]);
  //writeln(gen(i1,1));
end.

