var


procedure color;
  var
    i,j:integer;

  begin
    for i:=1 to 3 do
      for j:=1 to 3 do
        begin
          ff[i,j]:='f';
          rr[i,j]:='r';
          dd[i,j]:='d';
          bb[i,j]:='b';
          ll[i,j]:='l';
          uu[i,j]:='u';
        end;
  end;

procedure f;
  var

  begin


begin
  color;
  for i:=1 to 2 do
    begin
      readln(alg);
      i:=1;
      while 1<=length(alg) do
        begin
          if alg[i]='f' then
            if alg[i+1]='''' then
              begin
                f;
                f;
                f;
                f:=i+2;
              end
            else if alg[i+1]='2' then
              begin
                f;
                f;
                f:=i+2;
              end
            else
              begin
                f;
                inc(i);
              end
          else if alg[i]='r' then
            if alg[i+1]='''' then
              begin
                r;
                r;
                r;
              end
            else if alg[i+1]='2' then
              begin
                r;
                r;
              end
            else
              begin
                r;
                inc(i);
              end
          else if alg[i]='d' then
            if alg[i+1]='''' then
              begin
                d;
                d;
                d;
                i:=i+2;
              end
            else if alg[i+1]='2' then
              begin
                d;
                d;
                i:=i+1;
              end
            else
              begin
                d;
                inc(i);
              end
          else if alg[i]='b' then
            if alg[i+1]='''' then
              begin
                b;
                b;
                b;
                i:=i+2;
              end
            else if alg[i+1]='2' then
              begin
                b;
                b;
                i:=i+1;
              end
            else
              begin
                b;
                inc(i);
              end
          else if alg[i]='l' then
            if alg[i+1]='''' then
              begin
                l;
                l;
                l;
                i:=i+2;
              end
            else if alg[i+1]='2' then
              begin
                l;
                l;
                i:=i+1;
              end
            else
              begin
                l;
                inc(i);
              end
          else if alg[i]='u' then
            if alg[i+1]='''' then
              begin
                u;
                u;
                u;
                i:=i+2;
              end
            else if alg[i+1]='2' then
              begin
                u;
                u;
                i:=i+1;
              end
            else
              begin
                u;
                inc(i);
              end;
        end;
    end;
  if solve then writeln('SOLVE') else writeln('DNF');
end.