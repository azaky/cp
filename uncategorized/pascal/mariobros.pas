var
  t,kasus,m,r,c,i,j,startr,startc,pr,pc,br,bc:integer;
  input:string;
  find:boolean;
  field:array[0..101,0..101] of char;
  stat,flag,bomb,deto:array[0..101,0..101] of boolean;
  fr,fc:array[0..101,0..101] of integer;

procedure fill(r0,c0:integer);
  label
    finish;

  begin
    if not stat[r0,c0] then
      begin
        //writeln(r0,' ',c0,' ',field[r0,c0],' ',bomb[r0,c0],' ',deto[r0,c0]);
        stat[r0,c0]:=true;
        if find then goto finish
          else if field[r0,c0]='E' then
            begin
              find:=true;
              goto finish;
            end
          else if (field[r0,c0]='#') and bomb[r0,c0] then
            begin
              flag[r0,c0]:=true;
              stat[r0,c0]:=false;
            end
            else if field[r0,c0]='.' then
              begin
                if deto[r0,c0] then
                  begin
                    deto[r0,c0]:=false;
                    bomb[fr[r0,c0],fc[r0,c0]]:=false;
                    if field[fr[r0,c0],fc[r0,c0]]='#' then field[fr[r0,c0],fc[r0,c0]]:='.';
                    if flag[fr[r0,c0],fc[r0,c0]] then fill(fr[r0,c0],fc[r0,c0]);
                  end;
                fill(r0-1,c0);
                fill(r0+1,c0);
                fill(r0,c0-1);
                fill(r0,c0+1);
              end;
      end;
    finish:
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(field,sizeof(field),'#');
      fillchar(stat,sizeof(stat),false);
      fillchar(flag,sizeof(flag),false);
      fillchar(bomb,sizeof(bomb),false);
      fillchar(deto,sizeof(deto),false);
      readln(r,c);
      for i:=1 to r do
        begin
          readln(input);
          for j:=1 to c do
            if input[j]='S' then
              begin
                startr:=i;
                startc:=j;
                field[i,j]:='.';
              end
            else field[i,j]:=input[j];
        end;
      readln(m);
      for i:=1 to m do
        begin
          readln(pr,pc,br,bc);
          bomb[br,bc]:=true;
          deto[pr,pc]:=true;
          fr[pr,pc]:=br;
          fc[pr,pc]:=bc;
        end;
      find:=false;
      fill(startr,startc);
      if find then writeln('Yes')
        else writeln('No');
    end;
end.