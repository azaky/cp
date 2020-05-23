{
ID: a_zaky01
PROG: latin
LANG: PASCAL
}

const
  fact:array[0..7] of int64 = (1,1,2,6,24,120,720,5040);

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
          if (r=2) and (k>c) then
            begin
              latin:=latin+(n-k)*temp;
              break;
            end;
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
  
  //row[r,k] indicates that there exist k in the r-th row
  for i:=1 to n do col[i,i]:=true;
  for i:=1 to n do row[1,i]:=true;
  for i:=1 to n do row[i,i]:=true;
  
  ans:=latin(2,2)*fact[n-1];
  writeln(ans);

  closefile:

  close(input);
  close(output);

end.

