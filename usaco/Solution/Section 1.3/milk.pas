{
ID: a_zaky01
PROG: milk
LANG: PASCAL
}

var
  total,n,i,money:longint;
  price,milk:array[1..5000] of longint;
  fin,fout:text;

procedure sort(l,r:longint);
  var
    i,j,x,temp:longint;

  begin
    i:=l;
    j:=r;
    x:=price[(l+r) div 2];
    repeat
      while price[i]<x do inc(i);
      while price[j]>x do dec(j);
      if not(i>j) then
        begin
          temp:=price[i];
          price[i]:=price[j];
          price[j]:=temp;
          temp:=milk[i];
          milk[i]:=milk[j];
          milk[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  assign(fin,'milk.in');
  assign(fout,'milk.out');
  reset(fin);
  rewrite(fout);
  readln(fin,total,n);
  for i:=1 to n do readln(fin,price[i],milk[i]);
  sort(1,n);
  i:=1;
  money:=0;
  while total>0 do
    begin
      if total>=milk[i] then
        begin
          total:=total-milk[i];
          money:=money+(milk[i]*price[i]);
        end
      else
        begin
          money:=money+(total*price[i]);
          total:=0;
        end;
      inc(i);
    end;
  writeln(fout,money);
  close(fin);
  close(fout);
end.
