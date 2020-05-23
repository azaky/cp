{
ID: a_zaky01
PROG: latin
LANG: PASCAL
}

const
  fact:array[0..7] of int64 = (1,1,2,6,24,120,720,5040);

type
  arr = array[1..7] of integer;

var
  n,i,j,count:integer;
  ans:int64;
  row,col:array[1..8,1..8] of boolean;
  a,used:arr;
  tab:array[1..1000] of arr;
  f:array[1..1000] of integer;

label
  closefile;

function latin(r,c:integer):int64;
  var
    k:integer;
    temp:int64;
  
  begin
    if c>n then exit(latin(r+1,2));
    if r=n then exit(1);
    
    latin:=0;
    
    for k:=1 to n do
      if not row[r,k] and not col[c,k] then
        begin
          row[r,k]:=true; col[c,k]:=true;
          temp:=latin(r,c+1); latin:=latin+temp;
          row[r,k]:=false; col[c,k]:=false;
        end;
  end;

procedure generate(a:arr; pos,factor:integer);
  var
    i:integer;
  
  begin
    if pos=n then
      begin
        for i:=1 to n do
          if used[i]=0 then break;
        if i=n then exit;
        a[n]:=i;
        inc(count); tab[count]:=a; f[count]:=factor;
        exit;
      end;
    
    for i:=1 to n do
      if (used[i]=0) and (i<>pos) then
        begin
          used[i]:=1;
          a[pos]:=i;
          if i>pos then factor:=factor*(n-pos);
          generate(a,pos+1,factor);
          used[i]:=0;
          if i>pos then exit;
        end;
  end;

begin

  assign(input,'latin.in');
  assign(output,'latin.out');
  reset(input);
  rewrite(output);

  readln(n);
  ans:=0;
  
  //first we exclude cases for n=1 and 2, as my code will not work for them
  if n<=2 then
    begin
      writeln(1);
      goto closefile;
    end;
  
  count:=0;
  a[1]:=2; used[2]:=1;
  generate(a,2,1);

  writeln(count);
  for i:=1 to count do
    begin
      for j:=1 to n do write(tab[i][j]);
      writeln(' ',f[i]);
    end;

  ans:=0;
  for i:=1 to n do row[1,i]:=true;
  for i:=1 to n do row[i,i]:=true;
  
  for i:=1 to count do
    begin
      fillchar(row[2],sizeof(row[2]),false);
      fillchar(col,sizeof(col),false);
      for j:=1 to n do col[j,j]:=true;
      for j:=1 to n do
        begin
          row[2][tab[i][j]]:=true;
          col[j][tab[i][j]]:=true;
        end;
      ans:=ans+f[i]*latin(3,2);
    end;
  
  for i:=2 to n-1 do ans:=ans*i;
  writeln(ans);
  
  closefile:

  close(input);
  close(output);

end.

