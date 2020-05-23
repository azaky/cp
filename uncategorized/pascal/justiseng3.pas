type
  step=record
         c0,r0:integer;
         direc:char;
       end;
  field=array[0..20,0..20] of char;
  stepseq=array[1..1001] of step;

var
  i,j,k,c,r,count,csolve,finc,finr,min:integer;
  input:string;
  a:field;
  seq:stepseq;
  msolve:array[1..1000] of stepseq;
  numstep:array[1..1000] of integer;
  passed:array[1..10000] of field;
  f:text;

procedure search(a:field; x:integer; seq:stepseq);
  var
    i,j,k,r1,c1,r2,c2:integer;
    tempstep:step;
    temprob:char;
    temp:field;
    stat,stat2:boolean;

  begin
    stat:=true;
    for k:=1 to count do
      begin
        stat2:=true;
        if stat2 then
          for j:=1 to c do
            if stat2 then
              for i:=1 to r do
                if passed[k][j,i]<>a[j,i] then
                  begin
                    stat2:=false;
                    break;
                  end
                else
            else break
        else break;
        if stat2 then
          begin
            stat:=false;
            break;
          end;
      end;
    if stat then
      begin
        inc(count);
        passed[count]:=a;
        if a[finc,finr]='M' then
          begin
            inc(csolve);
            msolve[csolve]:=seq;
            numstep[csolve]:=x;
            if x<min then min:=x;
          end
        else
          begin
            inc(x);
            for c1:=1 to c do
              for r1:=1 to r do
                if a[c1,r1]<>'.' then
                  begin
                    tempstep.c0:=c1;
                    tempstep.r0:=r1;
                    temprob:=a[c1,r1];
                    for k:=1 to 4 do
                      begin
                        case k of
                            1:begin
                                temp:=a;
                                temp[c1,r1]:='.';
                                stat:=true;
                                tempstep.direc:='U';
                                seq[x]:=tempstep;
                                r2:=r1-1;
                                c2:=c1;
                                while (temp[c2,r2]='.') and (r2>0) do dec(r2);
                                if r2=0 then stat:=false
                                  else temp[c2,r2+1]:=temprob;
                              end;
                            2:begin
                                temp:=a;
                                temp[c1,r1]:='.';
                                stat:=true;
                                tempstep.direc:='D';
                                seq[x]:=tempstep;
                                r2:=r1+1;
                                c2:=c1;
                                while (temp[c2,r2]='.') and (r2<=r) do inc(r2);
                                if r2>r then stat:=false
                                  else temp[c2,r2-1]:=temprob;
                              end;
                            3:begin
                                temp:=a;
                                temp[c1,r1]:='.';
                                stat:=true;
                                tempstep.direc:='R';
                                seq[x]:=tempstep;
                                r2:=r1;
                                c2:=c1+1;
                                while (temp[c2,r2]='.') and (c2<=c) do inc(c2);
                                if c2>c then stat:=false
                                  else temp[c2-1,r2]:=temprob;
                              end;
                            4:begin
                                temp:=a;
                                temp[c1,r1]:='.';
                                stat:=true;
                                tempstep.direc:='L';
                                seq[x]:=tempstep;
                                r2:=r1;
                                c2:=c1-1;
                                while (temp[c2,r2]='.') and (c2>0) do dec(c2);
                                if c2=0 then stat:=false
                                  else temp[c2+1,r2]:=temprob;
                              end;
                          end;
                        if stat then search(temp,x,seq);
                      end;
              end;
          end;
      end;
  end;

begin
  readln(c,r);
  for i:=1 to r do
    begin
      readln(input);
      for j:=1 to c do
        begin
          a[j,i]:=input[j];
          if a[j,i]='*' then
            begin
              a[j,i]:='.';
              finc:=j;
              finr:=i;
            end;
        end;
    end;
  count:=0;
  csolve:=0;
  min:=10000;
  search(a,0,seq);
{
  for k:=1 to count do
    begin
    for i:=1 to r do
      for j:=1 to c do
        if j=c then writeln(passed[k][j,i])
          else write(passed[k][j,i]);
    writeln;
    end;
}
  assign(f,'tes.out');
  rewrite(f);
  for k:=1 to count do
    begin
      for i:=1 to r do
        for j:=1 to c do
          if j=c then writeln(f,passed[k][j,i])
            else write(f,passed[k][j,i]);
      writeln(f);
    end;
  close(f);

  writeln(count,' configurations are checked');
  writeln('Result:');
  k:=0;
  if csolve=0 then writeln('No Solution')
    else for i:= 1 to csolve do
      if numstep[i]=min then
        begin
          inc(k);
          writeln('Solution #',k);
          for j:=1 to numstep[i] do writeln(msolve[i][j].c0,' ',msolve[i][j].r0,' ',msolve[i][j].direc);
          if i<csolve then writeln;
        end;
end.
