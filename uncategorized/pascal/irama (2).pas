var
  c,kasus,i,j,n,m,s,ti,xi,yi:integer;
  score:longint;
  t,x,y:array[1..100] of integer;
  hilang:array[1..100] of boolean;

begin
  readln(c);
  for kasus:=1 to c do
    begin
      readln(n,m,s);
      fillchar(hilang,sizeof(hilang),false);
      score:=0;
      for i:=1 to n do readln(t[i],x[i],y[i]);
      for j:=1 to m do
        begin
          readln(ti,xi,yi);
          for i:=1 to n do
            if not(hilang[i]) and ((abs(xi-x[i])<=s) and (abs(yi-y[i])<=s)) and ((ti-t[i]>=0) and (ti-t[i]<=2)) then
              begin
                hilang[i]:=true;
                case ti-t[i] of
                    0:score:=score+300;
                    1:score:=score+100;
                    2:score:=score+50;
                  end;
              end;
        end;
      writeln(score);
    end;
end.
