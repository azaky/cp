{
ID: a_zaky01
PROG: ttwo
LANG: PASCAL
}
 
var
  i,j,rc,cc,rf,cf,dirc,dirf:integer;
  time:longint;
  meet:boolean;
  input:string;
  field:array[0..11,0..11] of char;
  stat:array[1..10,1..10,0..3,1..10,1..10,0..3] of boolean;
  fin,fout:text;
 
begin
  assign(fin,'ttwo.in');
  assign(fout,'ttwo.out');
  reset(fin);
  rewrite(fout);
  fillchar(field,sizeof(field),'*');
  for i:=1 to 10 do
    begin
      readln(fin,input);
      for j:=1 to 10 do
        if input[j]='C' then
          begin
            rc:=i;
            cc:=j;
            field[i,j]:='.';
          end
        else if input[j]='F' then
          begin
            rf:=i;
            cf:=j;
            field[i,j]:='.';
          end
        else field[i,j]:=input[j];
    end;
  meet:=false;
  dirc:=1;
  dirf:=1;
  time:=0;
  while not stat[rc,cc,dirc,rf,cf,dirf] and not meet do
    begin
      inc(time);
      stat[rc,cc,dirc,rf,cf,dirf]:=true;
      case dirc of
          1:if field[rc-1,cc]<>'*' then dec(rc)
              else dirc:=2;
          2:if field[rc,cc+1]<>'*' then inc(cc)
              else dirc:=3;
          3:if field[rc+1,cc]<>'*' then inc(rc)
              else dirc:=0;
          0:if field[rc,cc-1]<>'*' then dec(cc)
              else dirc:=1;
        end;
      case dirf of
          1:if field[rf-1,cf]<>'*' then dec(rf)
              else dirf:=2;
          2:if field[rf,cf+1]<>'*' then inc(cf)
              else dirf:=3;
          3:if field[rf+1,cf]<>'*' then inc(rf)
              else dirf:=0;
          0:if field[rf,cf-1]<>'*' then dec(cf)
              else dirf:=1;
        end;
      if (rc=rf) and (cc=cf) then meet:=true;
    end;
  if meet then writeln(fout,time)
    else writeln(fout,0);
  close(fin);
  close(fout);
end.
