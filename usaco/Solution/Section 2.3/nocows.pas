{
ID: a_zaky01
PROG: nocows
LANG: PASCAL
}

const
  max=9901;

var
  n,k,i,j:integer;
  p:array[1..100] of integer;
  arr:array[1..200,1..100] of longint;
  stat:array[1..200,1..100] of boolean;
  fin,fout:text;

function tree(n,k:integer):integer;
  var
    i,j,sum,temp:longint;

  begin
    if n=p[k] then tree:=1
    else if (n<2*k-1) or (n>p[k]) then tree:=0
      else
        begin
          if not stat[n,k] then
            begin
              stat[n,k]:=true;
              i:=1;
              while not((i>=2*k-3) and (i<=p[k-1])) and (i<n) do i:=i+2;
              if i<n then
                while ((i>=2*k-3) and (i<=p[k-1])) and (i<n) do
                  begin
                    sum:=0;
                    j:=1;
                    while not((n-i-1>=2*j-1) and (n-i-1<=p[j])) and (j<k-1) do inc(j);
                    if j<k-1 then
                      while ((n-i-1>=2*j-1) and (n-i-1<=p[j])) and (j<k-1) do
                        begin
                          sum:=(sum+tree(n-i-1,j)) mod max;
                          inc(j);
                        end;
                    temp:=tree(i,k-1);
                    arr[n,k]:=(arr[n,k]+2*temp*sum+temp*tree(n-i-1,k-1)) mod max;
                  end;
            end;
          tree:=arr[n,k];
        end;
    stat[n,k]:=true;
  end;

begin
  assign(fin,'nocows.in');
  assign(fout,'nocows.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n,k);
  p[1]:=1;
  for i:=2 to 8 do p[i]:=2*p[i-1]+1;
  if k>8 then
    for i:=9 to k do p[i]:=p[i-1];
  if n mod 2=1 then writeln(fout,tree(n,k))
    else writeln(fout,0);
  close(fin);
  close(fout);
end.
