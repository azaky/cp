const
  max=200000;

type
  num=array[1..max+1] of byte;

var
  n,e,l,i:longint;
  s:string;
  arr,hasil:num;

function sum(arr1,arr2:num; n1,n2:longint):num;
  var
    sisa,i,x:longint;

  begin
    if n1<n2 then sum:=sum(arr2,arr1,n2,n1)
      else
        begin
           sisa:=0;
           for i:=1 to n1+1 do
             begin
               x:=arr1[i]+arr2[i]+sisa;
               if x>9 then
                 begin
                   sisa:=1;
                   sum[i]:=x mod 10;
                 end
               else
                 begin
                   sisa:=0;
                   sum[i]:=x;
                 end;
             end;
        end;
  end;

function product(arr1,arr2:num; n1,n2:longint):num;
  var
    x,sisa,i1,i2,k,i:longint;

  begin
    //while arr1[n1]=0 do dec(n1);
    //while arr2[n2]=0 do dec(n2);
    for i:=1 to n1+n2 do product[i]:=0;
    for i2:=1 to n2 do
      begin
        for i1:=1 to n1 do
          begin
            x:=arr1[i1]*arr2[i2]+10*product[i1+i2]+product[i1+i2-1];
            product[i1+i2-1]:=x mod 10;
            product[i1+i2]:=(x mod 100) div 10;
            sisa:=x div 100;
            k:=i1+i2;
            while sisa>0 do
              begin
                inc(k);
                product[k]:=sisa+product[k];
                if product[k]>9 then
                  begin
                    product[k]:=product[k] mod 10;
                    sisa:=1;
                  end
                else sisa:=0;
              end;
          end;
      end;
  end;

function power(arr:num; n,e:longint):num;
  var
    temp,temp2:num;
    i:longint;

  begin
    if e=1 then power:=arr
      else
        begin
          while arr[n]=0 do dec(n);
          temp:=power(arr,n,e div 2);
          temp2:=product(temp,temp,n*(e div 2),n*(e div 2));
          if e mod 2=1 then
            power:=product(temp2,arr,n*(e-1),n)
          else power:=temp2;
        end;
  end;

var
  s1,s2:string;
  arr1,arr2:num;
  n1,n2:longint;

var
  fin,fout:text;

begin

  assign(fin,'tes.in');
  assign(fout,'power2.out');
  reset(fin);
  rewrite(fout);

  readln(fin,s);
  n:=length(s);
  readln(fin,e);
  for i:=1 to n do val(s[i],arr[n+1-i]);
  hasil:=power(arr,n,e);
  l:=n*e;
  while hasil[l]=0 do dec(l);
  for i:=l downto 1 do write(fout,hasil[i]);
  writeln(fout);

  close(fin);
  close(fout);

{
  readln(s1);
  readln(s2);
  n1:=length(s1);
  n2:=length(s2);
  for i:=1 to n1 do val(s1[i],arr1[n1+1-i]);
  for i:=1 to n2 do val(s2[i],arr2[n2+1-i]);
  hasil:=product(arr1,arr2,n1,n2);
  n:=n1+n2;
  while hasil[n]=0 do dec(n);
  for i:=n downto 1 do write(hasil[i]);
  writeln;
}
end.
