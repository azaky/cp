const
  abjad='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  n=25;

var
  i,candy,k,l,temp:integer;
  input:string;
  card:array[1..25] of integer;
  stat:array[1..50] of boolean;

function f(input:string):integer;
  begin
{
    if input='A' then f:=1
    else if input='B' then f:=2
    else if input='C' then f:=3
    else if input='D' then f:=4
    else if input='E' then f:=5
    else if input='F' then f:=6
    else if input='G' then f:=7
    else if input='H' then f:=8
    else if input='I' then f:=9
    else if input='J' then f:=10
    else if input='K' then f:=11
    else if input='L' then f:=12
    else if input='M' then f:=13
    else if input='N' then f:=14
    else if input='O' then f:=15
    else if input='P' then f:=16
    else if input='Q' then f:=17
    else if input='R' then f:=18
    else if input='S' then f:=19
    else if input='T' then f:=20
    else if input='U' then f:=21
    else if input='V' then f:=22
    else if input='W' then f:=23
    else if input='X' then f:=24
    else if input='Y' then f:=25;
}
    f:=pos(input,abjad);
  end;

begin
  i:=1;
  candy:=0;
  while true do
    begin
      while stat[i] do inc(i);
      i:=((i-1) mod (2*n))+1;
      writeln(i);
      flush(output);
      readln(input);
      k:=f(input);
      if card[k]=0 then
        begin
          card[k]:=i;
          temp:=i;
          if i=2*n then i:=1 else inc(i);
          while stat[i] do inc(i);
          writeln(i);
          flush(output);
          readln(input);
          l:=f(input);
          if k=l then
            begin
              inc(candy);
              stat[temp]:=true;
              stat[i]:=true;
            end
          else if card[l]=0 then
            begin
              card[l]:=i;
              inc(i);
            end
          else
            begin
              writeln(i);
              flush(output);
              readln(input);
              writeln(card[l]);
              flush(output);
              readln(input);
              inc(candy);
              stat[i]:=true;
              stat[card[l]]:=true;
            end;
        end
      else
        begin
          writeln(card[k]);
          flush(output);
          readln(input);
          inc(candy);
          stat[i]:=true;
          stat[card[k]]:=true;
        end;
      if candy=n then exit;
    end;
end.
