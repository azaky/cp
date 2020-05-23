{
ID: a_zaky01
PROG: money
LANG: PASCAL
}

var
  k,v,n,i,temp:integer;
  count:int64;
  a:array[1..25] of integer;
  arr:array[1..10000,1..25] of int64;
  stat:array[1..10000,1..25] of boolean;
  fin,fout:text;

function money(sum,k:integer):int64;
  begin
    if sum=0 then money:=1
      else if (sum<0) or (k=0) then money:=0
        else
          begin
            if not stat[sum,k] then
              begin
                stat[sum,k]:=true;
                arr[sum,k]:=money(sum,k-1)+money(sum-a[k],k);
              end;
            money:=arr[sum,k];
          end;
  end;

begin
  assign(fin,'money.in');
  assign(fout,'money.out');
  reset(fin);
  rewrite(fout);
  readln(fin,v,n);
  k:=0;
  for i:=1 to v do
    begin
      read(fin,temp);
      if temp<=n then
        begin
          inc(k);
          a[k]:=temp;
        end;
    end;
  writeln(fout,money(n,k));
  close(fin);
  close(fout);
end.
