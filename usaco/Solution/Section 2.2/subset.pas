{
ID: a_zaky01
PROG: subset
LANG: PASCAL
}

var
  n,sum:integer;
  arr:array[0..39,0..390] of int64;
  fin,fout:text;

function subset(n,sum:integer):int64;
  begin
    if sum=0 then subset:=1
      else if (sum<0) or (sum>(n*(n+1)) div 2) or (n=0) then subset:=0
        else if arr[n,sum]=0 then
          begin
            arr[n,sum]:=subset(n-1,sum)+subset(n-1,sum-n);
            subset:=arr[n,sum];
          end
        else subset:=arr[n,sum];
  end;

begin
  assign(fin,'subset.in');
  assign(fout,'subset.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  sum:=(n*(n+1)) div 2;
  if sum mod 2=1 then writeln(fout,0)
    else writeln(fout,subset(n-1,sum div 2));
  close(fin);
  close(fout);
end.
