{
ID: a_zaky01
PROG: prefix
LANG: PASCAL
}

const
  abjad='QWERTYUIOPASDFGHJKLZXCVBNM';

var
  i,n,max,len:longint;
  input:char;
  res:array[1..200000] of char;
  sub:array[1..200] of string;
  stat:array[0..200000] of boolean;
  fin,fout:text;

procedure prefix(k:longint);
  var
    i,j:integer;
    same:boolean;

  begin
    if not stat[k] then
      begin
        stat[k]:=true;
        if k>max then max:=k;
        for i:=1 to n do
          if len-k>=length(sub[i]) then
            begin
              same:=true;
              for j:=1 to length(sub[i]) do
                if res[k+j]<>sub[i][j] then
                  begin
                    same:=false;
                    break;
                  end;
              if same then prefix(k+length(sub[i]));
            end;
      end;
  end;

begin
  assign(fin,'prefix.in');
  assign(fout,'prefix.out');
  reset(fin);
  rewrite(fout);
  n:=1;
  sub[n]:='';
  while true do
    begin
      read(fin,input);
      if input='.' then break;
      if pos(input,abjad)<>0 then sub[n]:=sub[n]+input
        else if sub[n]<>'' then
          begin
            inc(n);
            sub[n]:='';
          end;
    end;
  dec(n);
  len:=0;
  while not eof(fin) do
    begin
      read(fin,input);
      if pos(input,abjad)<>0 then
        begin
          inc(len);
          res[len]:=input;
        end;
    end;
  max:=0;
  prefix(0);
  writeln(fout,max);
  close(fin);
  close(fout);
end.
