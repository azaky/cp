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
  row,col:array[1..7,1..7] of boolean;

label
  closefile;

procedure find(r,c:integer);
  var
    k:integer;
    temp,temp1:int64;
    permut:boolean;
  
  begin
    c:=(c mod n)+1;
    if c=1 then
      begin
        find(r+1,1);
        exit;
      end;
    if r=n then
      begin
        inc(ans);
        exit;
      end;
    if r=1 then
      begin
        temp:=-1;
        permut:=false;
        for k:=1 to n do
          if not row[r,k] and not col[c,k] then
            begin
              if k>c then permut:=true;
              if permut and (temp>=0) then ans:=ans+temp
                else
                  begin
                    row[r,k]:=true; col[c,k]:=true;
                    temp1:=ans;
                    ans:=0;
                    find(r,c);
                    temp:=ans;
                    ans:=temp1;
                    row[r,k]:=false; col[c,k]:=false;
                  end;
            end;
      end
    else for k:=1 to n do
      if not row[r,k] and not col[c,k] then
        begin
          row[r,k]:=true; col[c,k]:=true;
          find(r,c);
          row[r,k]:=false; col[c,k]:=false;
        end;
  end;

function latin(r,c:integer):int64;
  var
    k:integer;
    temp:int64;
  
  begin
    c:=(c mod n)+1;
    if c=1 then exit(latin(r+1,1));
    if r=n then exit(1);
    
    latin:=0;
    if r>2 then
      begin
        for k:=1 to n do
          if not row[r,k] and not col[c,k] then
            begin
              row[r,k]:=true; col[c,k]:=true;
              latin:=latin+latin(r,c);
              row[r,k]:=false; col[c,k]:=false;
            end;
        exit(latin);
      end;
    
    temp:=-1;
    for k:=1 to n do
      if not row[r,k] and not col[c,k] then
        begin
          row[r,k]:=true; col[c,k]:=true;
          temp:=latin(r,c); latin:=latin+temp;
          row[r,k]:=false; col[c,k]:=false;
          if k>c then
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
  //temp:=0;
  
  //first we exclude cases for n=1 and 2, as my code will not work for them
  if n<=2 then
    begin
      writeln(1);
      goto closefile;
    end;
  
  //then we define a sequence a[i], which is the number of ways to permute 1,2,..,i
  //such that there is no k such that perm(k)=k
  
  //one will easily get the recursion for a:
  //a[n]:=(n-1)*a[n-2]+(n-1)*(n-2)*a[n-3]+...
  
  //row[r,k] indicates that there exist k in the r-th row
  for i:=1 to n do col[i,i]:=true;
  for i:=1 to n do row[1,i]:=true;
  for i:=1 to n do row[i,i]:=true;
{
  for i:=2 to n do
    begin
      row[i-1,i]:=true;
      col[2,i]:=true;
      if i>2 then row[i-1,1]:=false;
      row[i,1]:=true;
      fix[i-1,2]:=i;
      fix[i,2]:=1;
      if i=n-1 then continue;
      ans:=0;
      find(2,2);
      writeln(ans);
      temp:=temp+ans*(fact[n-2] div fact[n-i]);
    end;
  ans:=temp*fact[n-1];
}
{
  //first we assume that latin[2,2]=1
  row[2,1]:=true; col[2,1]:=true;
  find(2,2);
  temp:=ans;
  
  //then we fill latin[2,2] with the other numbers, w.l.o.g. 3
  //since it will be symmetric, then we just multiply it by (n-2);
  ans:=0;
  row[2,1]:=false; col[2,1]:=false;
  row[2,3]:=true; col[2,3]:=true;
  find(2,2);
  
  ans:=(ans*(n-2)+temp)*fact[n-1];
}
  //find(2,1);
  ans:=latin(2,1)*fact[n-1];
  writeln(ans);
  
  closefile:

  close(input);
  close(output);

end.

