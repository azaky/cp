{
ID: a_zaky01
PROG: shopping
LANG: PASCAL
}

var
  fin,fout:text;
  s,b,i,j:integer;
  p,c,k,int:array[1..5] of integer;
  temp2:array[0..5] of integer;
  code,item:array[1..99,0..5] of integer;
  temp:array[0..999] of byte;
  n,poff:array[1..99] of integer;
  allow:array[1..99] of boolean;
  best:array[0..5,0..5,0..5,0..5,0..5] of longint;

procedure check(m:integer);
  var
    i,j:integer;
    used:boolean;
    temp:array[1..5] of integer;

  begin
    if m>b then
      begin
        best[int[1],int[2],int[3],int[4],int[5]]:=0;
        for i:=1 to b do inc(best[int[1],int[2],int[3],int[4],int[5]],int[i]*p[i]);
        for i:=1 to s do
          if allow[i] then
            begin
              used:=true;
              for j:=1 to 5 do
                if item[i][j]>int[j] then
                  begin
                    used:=false;
                    break;
                  end
                else temp[j]:=int[j]-item[i][j];
              if used then
                if best[int[1],int[2],int[3],int[4],int[5]]>poff[i]+best[temp[1],temp[2],temp[3],temp[4],temp[5]] then
                  best[int[1],int[2],int[3],int[4],int[5]]:=poff[i]+best[temp[1],temp[2],temp[3],temp[4],temp[5]]
            end;
      end
    else for i:=0 to k[m] do
      begin
        int[m]:=i;
        check(m+1);
      end;
  end;

begin
  assign(fin,'shopping.in');
  assign(fout,'shopping.out');
  reset(fin);
  rewrite(fout);
  readln(fin,s);
  for i:=1 to s do
    begin
      read(fin,n[i]);
      for j:=1 to n[i] do read(fin,code[i][j],item[i][j]);
      readln(fin,poff[i]);
    end;
  readln(fin,b);
  for i:=1 to b do
    begin
      readln(fin,c[i],k[i],p[i]);
      temp[c[i]]:=i;
    end;
  for i:=1 to s do
    begin
      fillchar(temp2,sizeof(temp2),0);
      for j:=1 to n[i] do temp2[temp[code[i][j]]]:=item[i][j];
      fillchar(item[i],sizeof(item[i]),0);
      for j:=0 to b do item[i][j]:=temp2[j];
      if temp2[0]>0 then allow[i]:=false
        else allow[i]:=true;
    end;
  check(1);
  writeln(fout,best[k[1],k[2],k[3],k[4],k[5]]);
  close(fin);
  close(fout);
end.
