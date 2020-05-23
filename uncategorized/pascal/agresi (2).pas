const
  abjad='ABCDEFGHIJKLMNOPQRSTUVWXYZ';

var
  b,k,i,j,b0,k0:longint;
  total:int64;
  c:char;
  input:string;
  field:array[0..51,0..51] of char;
  stat:array[0..51,0..51] of boolean;
  p:array['A'..'Z'] of longint;
  
procedure fill(b0,k0:integer);
  begin
    if not(stat[b0,k0]) then
      begin
        stat[b0,k0]:=true;
        if pos(field[b0,k0],abjad)<>0 then total:=total+p[field[b0,k0]]
          else
            begin
              fill(b0-1,k0);
              fill(b0+1,k0);
              fill(b0,k0-1);
              fill(b0,k0+1);
            end;
      end;
  end;

begin
  readln(b,k);
  fillchar(stat,sizeof(stat),true);
  for i:=1 to b do
    begin
      readln(input);
      for j:=1 to k do
        begin
          stat[i,j]:=false;
          field[i,j]:=input[j];
          if input[j]='*' then
            begin
              b0:=i;
              k0:=j;
            end;
        end;
    end;
  for c:='A' to 'Z' do read(p[c]);
  total:=0;
  fill(b0,k0);
  writeln(total);
end.
