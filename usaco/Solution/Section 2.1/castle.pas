{
ID: a_zaky01
PROG: castle
LANG: PASCAL
}

type
  castle=record
           w,n,e,s,stat:array[0..51,0..51] of boolean;
           room:array[0..51,0..51] of integer ;
         end;


var
  n,m,i,j,k,max,s,input,r,c:integer;
  a:castle;
  dir:char;
  size:array[0..2500] of integer;
  fin,fout:text;

procedure check(r,c:integer);
  begin
    a.stat[r,c]:=true;
    a.room[r,c]:=k;
    inc(s);
    if not(a.w[r,c]) and not(a.stat[r,c-1]) then check(r,c-1);
    if not(a.n[r,c]) and not(a.stat[r-1,c]) then check(r-1,c);
    if not(a.e[r,c]) and not(a.stat[r,c+1]) then check(r,c+1);
    if not(a.s[r,c]) and not(a.stat[r+1,c]) then check(r+1,c);
  end;

begin
  assign(fin,'castle.in');
  assign(fout,'castle.out');
  reset(fin);
  rewrite(fout);
  readln(fin,m,n);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(fin,input);
      k:=0;
      while k<4 do
        begin
          if input mod 2=1 then
            case k of
              0:a.w[i,j]:=true;
              1:a.n[i,j]:=true;
              2:a.e[i,j]:=true;
              3:a.s[i,j]:=true;
            end;
          inc(k);
          input:=input div 2;
        end;
    end;
  k:=0;
  max:=0;
  for i:=1 to n do
    for j:=1 to m do
      if not(a.stat[i,j]) then
        begin
          s:=0;
          inc(k);
          check(i,j);
          size[k]:=s;
          if s>max then max:=s;
        end;
  writeln(fout,k);
  writeln(fout,max);
  max:=0;
  for j:=1 to m do
    begin
      for i:=n downto 2 do
        if a.n[i,j] then
          if a.room[i,j]<>a.room[i-1,j] then
            if size[a.room[i,j]]+size[a.room[i-1,j]]>max then
              begin
                max:=size[a.room[i,j]]+size[a.room[i-1,j]];
                dir:='N';
                r:=i;
                c:=j;
              end;
      if j<>m then
        for i:=n downto 1 do
          if a.e[i,j] then
            if a.room[i,j]<>a.room[i,j+1] then
              if size[a.room[i,j]]+size[a.room[i,j+1]]>max then
                begin
                  max:=size[a.room[i,j]]+size[a.room[i,j+1]];
                  dir:='E';
                  r:=i;
                  c:=j;
                end;
    end;
  writeln(fout,max);
  writeln(fout,r,' ',c,' ',dir);
  close(fin);
  close(fout);
end.
