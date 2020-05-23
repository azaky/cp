program gamelagiguess;

uses crt;

var
  i,j:integer;
  possibility:longint;
  poinc,poinr,bombc,bombr:array[1..5] of integer;
  field:array[1..5,1..5] of integer;
  f:text;

procedure find(c,r:integer);
  var
    i,j,temppoinc,temppoinr,tempbombc,tempbombr:integer;
    tempfield:array[1..5,1..5] of integer;

  procedure writefield(x:longint);
    var
      i,j:integer;
      stat:boolean;

    begin
      stat:=true;
      for i:=1 to 5 do
        begin
          stat:=stat and (bombc[i]=0);
          stat:=stat and (bombr[i]=0);
        end;
      if stat then
        begin
          writeln(f,'Kemungkinan ke-',x);
          writeln(f);
          for i:=1 to 5 do
            begin
              for j:=1 to 5 do if field[j,i]=0 then write(f,'x')
                else write(f,field[j,i]);
              writeln(f);
            end;
          writeln(f);
        end
      else dec(possibility);
    end;

  procedure save;
    var
      i,j:integer;

    begin
      for i:=1 to 5 do
        for j:=1 to 5 do tempfield[i,j]:=field[i,j];
      temppoinc:=poinc[c];
      temppoinr:=poinr[r];
      tempbombc:=bombc[c];
      tempbombr:=bombr[r];
    end;

  procedure check1;
    var
      i,j:integer;

    begin
      for i:=1 to 5 do
        for j:=1 to 5 do field[i,j]:=tempfield[i,j];
      poinc[c]:=temppoinc;
      poinr[r]:=temppoinr;
      bombc[c]:=tempbombc;
      bombr[r]:=tempbombr;
      if (((5-r-bombc[c])*3+1) >= poinc[c]) and
         (((5-r-bombc[c])*1+1) <= poinc[c]) and
         (((5-c-bombr[r])*3+1) >= poinr[r]) and
         (((5-c-bombr[r])*1+1) <= poinr[r]) then

        begin
          field[c,r]:=1;
          poinc[c]:=poinc[c]-1;
          poinr[r]:=poinr[r]-1;
          if c=5 then
            begin
              if r=5 then
                begin
                  inc(possibility);
                  writefield(possibility);
                end
              else find(1,(r+1));
            end
          else find((c+1),r);
        end;
    end;

  procedure check2;
    var
      i,j:integer;

    begin
      for i:=1 to 5 do
        for j:=1 to 5 do field[i,j]:=tempfield[i,j];
      poinc[c]:=temppoinc;
      poinr[r]:=temppoinr;
      bombc[c]:=tempbombc;
      bombr[r]:=tempbombr;
      if ((((5-r)-bombc[c])*3+2)>=poinc[c]) and
         ((((5-r)-bombc[c])*1+2)<=poinc[c]) and
         ((((5-c)-bombr[r])*3+2)>=poinr[r]) and
         ((((5-c)-bombr[r])*1+2)<=poinr[r]) then

        begin
          field[c,r]:=2;
          poinc[c]:=poinc[c]-2;
          poinr[r]:=poinr[r]-2;
          if c=5 then
            begin
              if r=5 then
                begin
                  inc(possibility);
                  writefield(possibility);
                end
              else find(1,(r+1));
            end
          else find((c+1),r);
        end;
    end;

  procedure check3;
    var
      i,j:integer;

    begin
      for i:=1 to 5 do
        for j:=1 to 5 do field[i,j]:=tempfield[i,j];
      poinc[c]:=temppoinc;
      poinr[r]:=temppoinr;
      bombc[c]:=tempbombc;
      bombr[r]:=tempbombr;
      if ((((5-r)-bombc[c])*3+3)>=poinc[c]) and
         ((((5-r)-bombc[c])*1+3)<=poinc[c]) and
         ((((5-c)-bombr[r])*3+3)>=poinr[r]) and
         ((((5-c)-bombr[r])*1+3)<=poinr[r]) then

        begin
          field[c,r]:=3;
          poinc[c]:=poinc[c]-3;
          poinr[r]:=poinr[r]-3;
          if c=5 then
            begin
              if r=5 then
                begin
                  inc(possibility);
                  writefield(possibility);
                end
              else find(1,(r+1));
            end
          else find((c+1),r);
        end;
    end;

  procedure check0;
    var
      i,j:integer;

    begin
      for i:=1 to 5 do
        for j:=1 to 5 do field[i,j]:=tempfield[i,j];
      poinc[c]:=temppoinc;
      poinr[r]:=temppoinr;
      bombc[c]:=tempbombc;
      bombr[r]:=tempbombr;
      if (bombc[c]>=1) and (bombr[r]>=1) then

        begin
          field[c,r]:=0;
          bombc[c]:=bombc[c]-1;
          bombr[r]:=bombr[r]-1;
          if c=5 then
            begin
              if r=5 then
                begin
                  inc(possibility);
                  writefield(possibility);
                end
              else find(1,(r+1));
            end
          else find((c+1),r);
        end;
    end;

  begin
    save;
    check1;
    check2;
    check3;
    check0;
  end;

begin
  clrscr;
  assign(f,'gamelagiguess.out');
  rewrite(f);
  for i:=1 to 5 do
    begin
      write('Kolom ',i,': (äpoin,äbom) = ');
      readln(poinc[i],bombc[i]);
    end;
  for i:=1 to 5 do
    begin
      write('Baris ',i,': (äpoin,äbom) = ');
      readln(poinr[i],bombr[i]);
    end;
  for i:=1 to 5 do
    for j:=1 to 5 do field[i,j]:=0;
  possibility:=0;
  find(1,1);
  writeln(f,'Banyak kemungkinan ada ',possibility,' kemungkinan');
  close(f);
end.
