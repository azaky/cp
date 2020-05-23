{
ID: a_zaky01
PROG: latin
LANG: PASCAL
}

type
  st = record
    row,col:array[1..7,1..7] of boolean;
  end;
  cal = record
    r,c,num:integer;
  end;

var
  n,i:integer;
  ans:int64;
  stat:st;
  next:cal;

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
          if not stat.row[2][i] then break;
        if i=n then exit;
        stat.row[2][i]:=true; stat.col[n][i]:=true;
        ans:=ans+factor*latin(row,col,3,2);
        stat.row[2][i]:=false; stat.col[n][i]:=false;
        exit;
      end;
    with stat do
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
  for i:=1 to n do
    with stat do
      begin
        row[1,i]:=true;
        row[i,i]:=true;
        col[i,i]:=true;
      end;
  with next do
    begin
      r:=3;
      c:=2;
    end;
  
  generate(2,1);
  
  for i:=1 to n-1 do ans:=ans*i;
  writeln(ans);
  
  closefile:

  close(input);
  close(output);

end.

