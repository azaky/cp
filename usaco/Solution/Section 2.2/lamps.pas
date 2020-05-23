{
ID: a_zaky01
PROG: lamps
LANG: PASCAL
}

type
  lamps=array[1..100] of boolean;

var
  n,c,count,kon,koff,i,i1,i2,i3,i4,j:integer;
  lampon,lampoff:array[1..100] of integer;
  lamp:lamps;
  hasil:array[1..16] of lamps;
  fin,fout:text;

function check(lamp:lamps):boolean;
  var
    i:integer;

  begin
    check:=true;
    if kon>0 then
      for i:=1 to kon do
        if not lamp[lampon[i]] then
          begin
            check:=false;
            break;
          end;
    if koff>0 then
      for i:=1 to koff do
        if lamp[lampoff[i]] then
          begin
            check:=false;
            break;
          end;
  end;

procedure sort(count:integer);
  var
    i,j,k:integer;
    g:boolean;
    temp:lamps;

  begin
    for i:=count downto 1 do
      for j:=1 to i-1 do
        begin
          g:=true;
          k:=1;
          while k<=count do
            begin
              if (hasil[j][k]) and not(hasil[j+1][k]) then break
                else if not(hasil[j][k]) and (hasil[j+1][k]) then
                  begin
                    g:=false;
                    break;
                  end
                else inc(k);
            end;
          if g then
            begin
              temp:=hasil[j];
              hasil[j]:=hasil[j+1];
              hasil[j+1]:=temp;
            end;
        end;
  end;

begin
  assign(fin,'lamps.in');
  assign(fout,'lamps.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  readln(fin,c);
  kon:=0;
  koff:=0;
  while true do
    begin
      read(fin,i);
      if i=-1 then break;
      inc(kon);
      lampon[kon]:=i;
    end;
  while true do
    begin
      read(fin,i);
      if i=-1 then break;
      inc(koff);
      lampoff[koff]:=i;
    end;
  count:=0;
  for i1:=0 to 1 do
    for i2:=0 to 1 do
      for i3:=0 to 1 do
        for i4:=0 to 1 do
          if (i1+i2+i3+i4<=c) and ((c-(i1+i2+i3+i4)) mod 2=0) then
            begin
              if i1=1 then
                for i:=1 to n do lamp[i]:=false
                  else for i:=1 to n do lamp[i]:=true;
              if i2=1 then
                for i:=1 to (n+1) div 2 do lamp[2*i-1]:=not lamp[2*i-1];
              if i3=1 then
                for i:=1 to n div 2 do lamp[2*i]:=not lamp[2*i];
              if i4=1 then
                for i:=1 to (n+2) div 3 do lamp[3*i-2]:=not lamp[3*i-2];
              if check(lamp) then
                begin
                  inc(count);
                  hasil[count]:=lamp;
                end;
            end;
  if count=0 then writeln(fout,'IMPOSSIBLE')
    else
      begin
        sort(count);
        for i:=1 to count do
          begin
            for j:=1 to n do
              if hasil[i][j] then write(fout,1)
                else write(fout,0);
            writeln(fout);
          end;
      end;
  close(fin);
  close(fout);
end.
