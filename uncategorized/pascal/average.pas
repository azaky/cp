type
  tabel= array[1..10000] of longint;

var
  n,i,input:longint;
  a:tabel;
  result:real;

procedure swap(var num1,num2:longint);
  var
    temp:longint;

  begin
    temp:=num1;
    num1:=num2;
    num2:=temp;
  end;

procedure bubblesort(var a:tabel; n:longint);
  var
    i,j:longint;

  begin
    for i:=1 to n-1 do
      begin
        for j:=i+1 to n do if a[i]>a[j] then swap(a[i],a[j]);
      end;
  end;

procedure average(var a:tabel; n:longint);
  var
    sum,i:longint;
    avg:real;

  begin
    sum:=0;
    for i:=1 to n do sum:=sum+a[i];
    avg:=sum/n;
    writeln(avg:1:2);
  end;

procedure modus(var a:tabel; n:longint);
  var
    i,j,v,value,max,result:longint;

  begin
    max:=0;
    for i:=2 to n do
      begin
        value:=a[i];
        v:=0;
        for j:=1 to n do
          begin
            if a[j]=a[i] then inc(v);
          end;
        if v>max then
          begin
            max:=v;
            result:=a[i];
          end;
      end;
    writeln(result);
  end;

procedure median(var a:tabel; n:longint);
  var
    result:real;

  begin
    bubblesort(a,n);
    if n mod 2 = 0 then result:=a[n div 2]/2+a[1+n div 2]/2
      else result:=a[1+n div 2];
    write(result:1:2);
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(input);
      a[i]:=input;
    end;
  //average(a,n);
  //modus(a,n);
  median(a,n);
end.
