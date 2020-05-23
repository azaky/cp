{
ID: a_zaky01
PROG: spin
LANG: PASCAL
}

var
  i,j,t,ans,deg:integer;
  pass,passi:boolean;
  speed,n:array[1..5] of integer;
  start,size:array[1..5,1..5] of integer;
  fin,fout:text;

begin
  assign(fin,'spin.in');
  assign(fout,'spin.out');
  reset(fin);
  rewrite(fout);
  for i:=1 to 5 do
    begin
      read(fin,speed[i],n[i]);
      for j:=1 to n[i] do read(fin,start[i][j],size[i][j]);
    end;
  ans:=-1;
  for t:=0 to 359 do
    begin
      for deg:=0 to 359 do
        begin
          pass:=true;
          for i:=1 to 5 do
            begin
              passi:=false;
              for j:=1 to n[i] do
                if start[i][j]+size[i][j]>=360 then
                  if (deg>=start[i][j]) or (deg<=start[i][j]+size[i][j]-360) then passi:=true
                    else
                  else if (deg>=start[i][j]) and (deg<=start[i][j]+size[i][j]) then passi:=true;
              if not passi then
                begin
                  pass:=false;
                  break;
                end;
            end;
          if pass then
            begin
              ans:=t;
              break;
            end;
        end;
      if ans>=0 then break;
      for i:=1 to 5 do
        for j:=1 to n[i] do
          start[i][j]:=(start[i][j]+speed[i]) mod 360;
    end;
  if ans<0 then writeln(fout,'none')
    else writeln(fout,ans);
  close(fin);
  close(fout);
end.
