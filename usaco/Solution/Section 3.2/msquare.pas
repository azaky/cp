{
ID: a_zaky01
PROG: msquare
LANG: PASCAL
}

type
  cyc0=array[1..8] of byte;
  tipe=record
         cyc:cyc0;
         step:ansistring;
         num:longint;
       end;

var
  i,qsave,qtake:longint;
  ini:tipe;
  a:cyc0;
  fact:array[0..8] of longint;
  queue:array[1..40320] of tipe;
  used:array[1..40320] of boolean;
  fin,fout:text;

function encr(z:tipe):longint;
  var
    i,j:integer;
    temp:cyc0;

  begin
    temp:=z.cyc;
    encr:=1;
    for i:=1 to 8 do
      begin
        for j:=i+1 to 8 do
          if z.cyc[j]>z.cyc[i] then dec(temp[j]);
        inc(encr,(temp[i]-1)*fact[8-i]);
      end;
  end;

procedure search(z:tipe);
  var
    i,tempr:longint;
    same:boolean;
    temp:tipe;

  begin
    same:=true;
    for i:=1 to 8 do
      if z.cyc[i]<>a[i] then
        begin
          same:=false;
          break;
        end;
    if same then
      with z do
        begin
          writeln(fout,num);
          for i:=1 to length(step) do
            if (i=length(step)) or (i mod 60=0) then writeln(fout,step[i])
              else write(fout,step[i]);
          if length(step)=0 then writeln(fout);
        end
    else
      begin
        temp.num:=z.num+1;
        //transformation A
        for i:=1 to 8 do temp.cyc[i]:=z.cyc[9-i];
        tempr:=encr(temp);
        if not used[tempr] then
          begin
            used[tempr]:=true;
            temp.step:=z.step+'A';
            inc(qsave);
            queue[qsave]:=temp;
          end;
        //transformation B
        temp.cyc[1]:=z.cyc[4];
        for i:=2 to 4 do temp.cyc[i]:=z.cyc[i-1];
        temp.cyc[8]:=z.cyc[5];
        for i:=5 to 7 do temp.cyc[i]:=z.cyc[i+1];
        tempr:=encr(temp);
        if not used[tempr] then
          begin
            used[tempr]:=true;
            temp.step:=z.step+'B';
            inc(qsave);
            queue[qsave]:=temp;
          end;
        //transformation C
        temp.cyc:=z.cyc;
        temp.cyc[2]:=z.cyc[7];
        temp.cyc[3]:=z.cyc[2];
        temp.cyc[6]:=z.cyc[3];
        temp.cyc[7]:=z.cyc[6];
        tempr:=encr(temp);
        if not used[tempr] then
          begin
            used[tempr]:=true;
            temp.step:=z.step+'C';
            inc(qsave);
            queue[qsave]:=temp;
          end;
        //call the next queue list
        inc(qtake);
        search(queue[qtake]);
      end;
  end;

begin
  assign(fin,'msquare.in');
  assign(fout,'msquare.out');
  reset(fin);
  rewrite(fout);
  fact[0]:=1;
  for i:=1 to 8 do fact[i]:=i*fact[i-1];
  for i:=1 to 8 do read(fin,a[i]);
  with ini do
    begin
      for i:=1 to 8 do cyc[i]:=i;
      num:=0;
      step:='';
    end;
  qsave:=0;
  qtake:=0;
  used[1]:=true;
  search(ini);
  close(fin);
  close(fout);
end.
