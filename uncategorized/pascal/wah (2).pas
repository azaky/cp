type
  arr=array[0..10000] of integer;
  
var
  i,t,kasus,n,tl,tp,sl,sp,al,bl,ap,bp,sqr1,sqr2:longint;
  wl,wp,ul,up,pl,pp,init:arr;

procedure qsort(var w,u:arr);
  procedure sort(l,r:longint);
    var
      i,j,midw,midu,temp:longint;
      
    begin
      i:=l;
      j:=r;
      midw:=w[(l+r) div 2];
      midu:=u[(l+r) div 2];
      repeat
        while (w[i]<midw) or ((w[i]=midw) and (u[i]<midu)) do inc(i);
        while (w[j]>midw) or ((w[j]=midw) and (u[j]>midu)) do dec(j);
        if i<=j then
          begin
            temp:=w[i]; w[i]:=w[j]; w[j]:=temp;
            temp:=u[i]; u[i]:=u[j]; u[j]:=temp;
            inc(i); dec(j);
          end;
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;
  
  begin
    sort(1,n);
  end;

procedure proc1;
  begin
    writeln(ul[al]-1,' ',up[bp]-1,' ',sqr1);
    if al=bl then inc(bl);
    inc(al);
    if ap=bp then inc(ap);
    inc(bp);
    if bp=pp[sp+1] then
      begin
        dec(sp);
        bp:=pp[sp];
      end;
  end;

procedure proc2;
  begin
    writeln(ul[bl]-1,' ',up[ap]-1,' ',sqr2);
    if ap=bp then inc(bp);
    inc(ap);
    if al=bl then inc(al);
    inc(bl);
    if bl=pl[sl+1] then
      begin
        dec(sl);
        bl:=pl[sl];
      end;
  end;

begin
  for i:=1 to 10000 do init[i]:=i;
  readln(t);
  for kasus:=1 to t do
    begin
      readln(n);
      
      for i:=1 to n do read(wl[i]);
      for i:=1 to n do read(wp[i]);
      
      ul:=init; up:=init;
      qsort(wl,ul); qsort(wp,up);
      {
      for i:=1 to n do write(ul[i],' ');
      writeln;
      for i:=1 to n do write(wl[i],' ');
      writeln; writeln;
      
      for i:=1 to n do write(up[i],' ');
      writeln;
      for i:=1 to n do write(wp[i],' ');
      writeln; writeln;
      }
      tl:=wl[1]; tp:=wp[1];
      pl[1]:=1; pp[1]:=1;
      sl:=1; sp:=1;
      for i:=2 to n do
        begin
          if tl<>wl[i] then
            begin
              inc(sl); pl[sl]:=i;
              tl:=wl[i];
            end;
          if tp<>wp[i] then
            begin
              inc(sp); pp[sp]:=i;
              tp:=wp[i];
            end;
        end;
      pl[sl+1]:=n+1; pp[sp+1]:=n+1;
      {
      for i:=1 to sl do write(pl[i],' ');
      writeln;
      
      for i:=1 to sp do write(pp[i],' ');
      writeln; writeln;
      }
      al:=1; bl:=pl[sl];
      ap:=1; bp:=pp[sp];
      
      for i:=1 to n do
        begin
        {
          writeln;
          writeln(al,' ',bl);
          writeln(ap,' ',bp);
        }
          sqr1:=sqr(wl[al]-wp[bp]);
          sqr2:=sqr(wl[bl]-wp[ap]);
        {
          if ((sqr1=sqr2) and ((ul[al]<ul[bl]) or ((ul[al]=ul[bl]) and (up[bp]<up[ap])))) or (sqr1>sqr2) then proc1
            else proc2;
        }  
          if sqr1=sqr2 then
            begin
              if al=bl then
                if up[ap]<up[bp] then proc2
                  else proc1
              else if ul[al]<ul[bl] then proc1
                else proc2;
            end          
          else if sqr1>sqr2 then proc1
            else proc2;
        
        end;      
      writeln;
    end;
end.

