const
  nucleotide:array[1..4] of char = ('A','C','G','T');
  maxn = 50005;
  
var
  n,k,i,j,kk,base,form:longint;
  r,temp,count,add:int64;
  dna:array[0..maxn] of longint;
  dp:array[0..maxn,0..10,0..4] of int64;
  ch:char;
  
begin
  readln(n,k,r);
  for i:=1 to n do
    begin
      read(ch);
      case ch of
        'A':dna[i]:=1;
        'C':dna[i]:=2;
        'G':dna[i]:=3;
        'T':dna[i]:=4;
        'N':dna[i]:=0;
      end;
    end;
  //initialize the dp table
  for kk:=1 to k do
    for base:=1 to 4 do
      if (base=dna[n]) or (dna[n]=0) then dp[n][kk][base]:=1;
  for i:=n-1 downto 1 do
    for kk:=1 to k do
      for base:=1 to 4 do
        if (base=dna[i]) or (dna[i]=0) then
          begin
            temp:=0;
            //if the sequence is still in the same form
            for j:=base to 4 do temp:=temp+dp[i+1][kk][j];
            //otherwise
            for j:=1 to base-1 do temp:=temp+dp[i+1][kk-1][j];
            dp[i][kk][base]:=temp;
          end;
  count:=0; form:=k;
  for i:=1 to n do
    begin
      if dna[i]=0 then
        begin
          for base:=1 to 4 do
            begin
              if base<dna[i-1] then add:=dp[i][form-1][base] else add:=dp[i][form][base];
              count:=count+add;
              if count>=r then break;
            end;
          count:=count-add;
          dna[i]:=base;
        end;
      if dna[i]<dna[i-1] then dec(form);
      write(nucleotide[dna[i]]);
    end;
  writeln;
end.
