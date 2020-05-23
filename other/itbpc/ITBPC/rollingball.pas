type
  tipe=record
         k,sum:int64;
       end;

var
  r,c,i,j,r0,c0:longint;
  input:string;
  ini:tipe;
  a:array[0..51,0..51] of char;
  f,fl,fr:array[0..51,0..51] of tipe;

begin
  readln(r,c);
  fillchar(a,sizeof(a),'X');
  for i:=1 to r do
    begin
      readln(input);
      for j:=1 to c do
        begin
          a[i,j]:=input[j];
          if a[i,j]='B' then
            begin
              r0:=i;
              c0:=j;
              a[i,j]:='.';
            end;
        end;
    end;
  with ini do
    begin
      k:=1;
      sum:=0;
    end;
  for i:=r downto r0 do
    begin
      for j:=1 to c do
        if a[i,j]='.' then
          if a[i+1,j]='.' then
            begin
             fl[i,j].k:=f[i+1,j].k;
             fl[i,j].sum:=f[i+1,j].k+f[i+1,j].sum;
            end
          else if a[i,j-1]='X' then fl[i,j]:=ini
            else
              begin
                fl[i,j].k:=fl[i,j-1].k;
                fl[i,j].sum:=fl[i,j-1].k+fl[i,j-1].sum;
              end;
      for j:=c downto 1 do
        if a[i,j]='.' then
          if a[i+1,j]='.' then
            begin
             fr[i,j].k:=f[i+1,j].k;
             fr[i,j].sum:=f[i+1,j].k+f[i+1,j].sum;
            end
          else if a[i,j+1]='X' then fr[i,j]:=ini
            else
              begin
                fr[i,j].k:=fr[i,j+1].k;
                fr[i,j].sum:=fr[i,j+1].k+fr[i,j+1].sum;
              end;
      for j:=1 to c do
        if a[i+1,j]='.' then f[i,j]:=fl[i,j]
          else
            begin
              f[i,j].k:=fl[i,j].k+fr[i,j].k;
              f[i,j].sum:=fl[i,j].sum+fr[i,j].sum;
            end;
    end;
  writeln((f[r0,c0].sum/f[r0,c0].k):0:3);
{
  for i:=1 to r do
    begin
      for j:=1 to c do write(f[i,j].sum:5,':',f[i,j].k);
      writeln;
    end;
}
end.
