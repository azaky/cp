{
ID: a_zaky01
PROG: kimbits
LANG: PASCAL
}

uses
  math;

var
  n,l,i,j,pos1:longint;
  size,tempsize,k:int64;
  com:array[0..31,0..31] of int64;
  used:array[0..31] of boolean;
  fin,fout:text;

begin
  assign(fin,'kimbits.in');
  assign(fout,'kimbits.out');
  reset(fin);
  rewrite(fout);
  for i:=0 to 31 do
    begin
      com[i,0]:=1;
      com[0,i]:=1;
    end;
  for i:=1 to 31 do
    for j:=1 to 31 do com[i,j]:=com[i,j-1]+com[i-1,j];
  readln(fin,n,l,k);
  while true do
    begin
      size:=0;
      pos1:=-1;
      while size<k do
        begin
          tempsize:=size;
          inc(pos1);
          if pos1=0 then inc(size)
            else for i:=0 to min(l-1,pos1-1) do inc(size,com[pos1-i-1,i]);
        end;
      used[pos1]:=true;
      if pos1=0 then break
        else
          begin
            dec(l);
            dec(k,tempsize);
          end;
    end;
  for i:=n downto 1 do
    if used[i] then write(fout,'1')
      else write(fout,'0');
  writeln(fout);
  close(fin);
  close(fout);
end.
