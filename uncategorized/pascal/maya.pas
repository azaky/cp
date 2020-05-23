type
  posisi=record
           ax,ay:integer;
         end;

const
  fi='tes.in';
  fo='tes.out';

var
  x0,y0,n,x,y,t,i,j,tempx,tempy,k,k1:integer;
  dir,task,space:char;
  hilang:boolean;
  jejak:array[1..2004] of posisi;
  fin,fout:text;

procedure assigning;
  begin
    assign(fin,fi);
    assign(fout,fo);
    reset(fin);
    rewrite(fout);
  end;

procedure move(task:char);
  begin
    if task='F' then
      case dir of
        'U':y:=y+1;
        'S':y:=y-1;
        'T':x:=x+1;
        'B':x:=x-1;
      end
    else if task='R' then
      case dir of
        'U':dir:='T';
        'S':dir:='B';
        'T':dir:='S';
        'B':dir:='U';
      end
    else if task='L' then
      case dir of
        'U':dir:='B';
        'S':dir:='T';
        'T':dir:='U';
        'B':dir:='S';
      end;
  end;

begin
  assigning;
  t:=0;
  while true do
    begin
      inc(t);
      readln(fin,x0,y0,n);
      if (x0=0) and (y0=0) and (n=0) then break;
      k:=0;
      writeln(fout,'TES #',t);
      for i:=1 to n do
        begin
          read(fin,x,y);
          readln(fin,space,dir);
          hilang:=false;
          tempx:=x;
          tempy:=y;
          while true do
            begin
              read(fin,task);
              if (task='L') or (task='R') or (task='F') then
                if not(hilang) then
                  begin
                    move(task);
                    if (x>x0) or (x<0) or (y>y0) or (y<0) then
                      begin
                        hilang:=true;
                        if k>0 then
                          begin
                            for k1:=1 to k do
                              if (jejak[k1].ax=tempx) and (jejak[k1].ay=tempy) then
                                begin
                                  hilang:=false;
                                  x:=tempx;
                                  y:=tempy;
                                  break;
                                end;
                          end
                      end
                    else
                      begin
                        tempx:=x;
                        tempy:=y;
                      end;
                  end
                else
              else break;
            end;
          write(fout,tempx,' ',tempy,' ',dir);
          if hilang then writeln(fout,' HILANG')
            else writeln(fout);
          if hilang then
            begin
              inc(k);
              jejak[k].ax:=tempx;
              jejak[k].ay:=tempy;
            end;
        end;
      for j:=1 to k do
        begin
          jejak[j].ax:=0;
          jejak[j].ax:=0;
        end;
    end;
  close(fin);
  close(fout);
end.
