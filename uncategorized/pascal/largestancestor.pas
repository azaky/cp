var
  t,kasus,l,la,lb,k:integer;
  a,b,p:int64;
  level:array[0..50] of int64;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(k,a,b);
      if (a=1) or (b=1) then writeln(1)
        else
          begin
            p:=1;
            l:=0;
            level[0]:=0;
            la:=-1;
            lb:=-1;
            while (la<0) or (lb<0) do
              begin
                inc(l);
                level[l]:=level[l-1]+p;
                p:=p*k;
                if la<0 then
                  if level[l]>a then la:=l;
                if lb<0 then
                  if level[l]>b then lb:=l;
              end;
            if la>lb then
              while la>lb do
                begin
                  a:=((a-level[la]) div k)+level[la-1];
                  dec(la);
                end
            else if la<lb then
              while la<lb do
                begin
                  b:=((b-level[lb]) div k)+level[lb-1];
                  dec(lb);
                end;
            l:=la;
            while a<>b do
              begin
                a:=((a-level[l]) div k)+level[l-1];
                b:=((b-level[l]) div k)+level[l-1];
                dec(l);
              end;
            writeln(a);
          end;
    end;
end.
