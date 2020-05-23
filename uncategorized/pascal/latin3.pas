{
ID: a_zaky01
PROG: latin
LANG: PASCAL
}

var
  n,i:integer;
  ans:int64;
  row,col:array[1..8,1..8] of boolean;

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

procedure generate(pos,factor:integer);
  var
    i:integer;
  
  begin
    if pos=n then
      begin
        for i:=1 to n do
          if not row[2][i] then break;
        if i=n then exit;
        row[2][i]:=true; col[n][i]:=true;
        ans:=ans+factor*latin(3,2);
        row[2][i]:=false; col[n][i]:=false;
        exit;
      end;
    
    for i:=1 to n do
      if not row[2][i] and not col[pos][i] then
        begin
          row[2][i]:=true; col[pos][i]:=true;
          if i>pos then factor:=factor*(n-pos);
          generate(pos+1,factor);
          row[2][i]:=false; col[pos][i]:=false;
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
  
  ans:=0;
  for i:=1 to n do row[1,i]:=true;
  for i:=1 to n do row[i,i]:=true;
  for i:=1 to n do col[i,i]:=true;
  
  generate(2,1);
{
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
}
  for i:=1 to n-1 do ans:=ans*i;
  writeln(ans);
  
  closefile:

  close(input);
  close(output);

end.

