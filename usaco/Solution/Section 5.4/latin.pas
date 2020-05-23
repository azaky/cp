{
ID: a_zaky01
PROG: latin
LANG: PASCAL
}

type
  arr = array[1..7] of integer;

var
  n,i,j,count,temp:integer;
  ans:int64;
  part:array[1..7] of int64;
  row,col:array[1..7,1..7] of boolean;
  a:arr;
  used:array[1..7] of boolean;
  tab:array[1..8] of arr;
  f,loop:array[1..8] of integer;

label
  closefile;

function latin(r,c:integer):int64;
  var
    k:integer;
    temp:int64;
  
  begin
    latin:=0;
    
    for k:=1 to n do
      if not row[r,k] and not col[c,k] then
        begin
          row[r,k]:=true; col[c,k]:=true;
          if c<n then temp:=latin(r,c+1)
            else if r<n-1 then temp:=latin(r+1,2)
              else temp:=1;
          latin:=latin+temp;
          row[r,k]:=false; col[c,k]:=false;
        end;
  end;

procedure generate(a:arr; pos,factor:integer);
  var
    i,temp,p:integer;
    visit:array[1..7] of boolean;
  
  begin
    if pos=n then
      begin
        for i:=1 to n do
          if not used[i] then break;
        if i=n then exit;
        a[n]:=i;
        inc(count); tab[count]:=a; f[count]:=factor; loop[count]:=0;
        
        fillchar(visit,sizeof(visit),false);
        for i:=1 to n do
          if not visit[i] then
            begin
              temp:=0; p:=i;
              while not visit[p] do
                begin
                  inc(temp);
                  visit[p]:=true;
                  p:=a[p];
                end;
              if temp>loop[count] then loop[count]:=temp;
            end;
        exit;
      end;
    
    for i:=1 to n do
      if not used[i] and (i<>pos) then
        begin
          used[i]:=true;
          a[pos]:=i;
          if i>pos then factor:=factor*(n-pos);
          generate(a,pos+1,factor);
          used[i]:=false;
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
  a[1]:=2; used[2]:=true;
  generate(a,2,1);

  ans:=0;
  for i:=1 to n do row[1,i]:=true;
  for i:=1 to n do row[i,i]:=true;
  
  fillchar(used,sizeof(used),false);
  for i:=1 to count do
    begin
      temp:=loop[i];
      if used[temp] then
        begin
          ans:=ans+f[i]*part[temp];
          continue;
        end
      else used[temp]:=true;
      fillchar(row[2],sizeof(row[2]),false);
      fillchar(col,sizeof(col),false);
      for j:=1 to n do col[j,j]:=true;
      for j:=1 to n do
        begin
          row[2][tab[i][j]]:=true;
          col[j][tab[i][j]]:=true;
        end;
      part[temp]:=latin(3,2);
      ans:=ans+f[i]*part[temp];
    end;
  
  for i:=2 to n-1 do ans:=ans*i;
  writeln(ans);
  
  closefile:

  close(input);
  close(output);

end.

