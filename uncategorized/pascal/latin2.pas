{
ID: a_zaky01
PROG: latin
LANG: PASCAL
}

const
  fact:array[0..7] of int64 = (1,1,2,6,24,120,720,5040);

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

function latin(stat:st; next:cal):int64;
  var
    k:integer;
    temp:int64;
  
  begin
    with next do
      begin
        if (r=n-1) and (c=n) then exit(1);
        stat.row[r,num]:=true;
        stat.col[c,num]:=true;
        if c=n then
          begin
            c:=2;
            inc(r);
          end
        else inc(c);
      end;

    latin:=0;
    
      for k:=1 to n do
        if not stat.row[next.r,k] and not stat.col[next.c,k] then
          begin
            next.num:=k;
            temp:=latin(stat,next); latin:=latin+temp;
            if (next.r=2) and (k>next.c) then
              begin
                latin:=latin+(n-k)*temp;
                exit(latin);
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
  for i:=1 to n do
    with stat do
      begin
        row[1,i]:=true;
        row[i,i]:=true;
        col[i,i]:=true;
      end;
  with next do
    begin
      r:=2;
      c:=1;
      num:=2;
    end;
    
  ans:=latin(stat,next)*fact[n-1];
  
  writeln(ans);

  closefile:

  close(input);
  close(output);

end.

