{
ID: a_zaky01
PROG: milk3
LANG: PASCAL
}

var
  i,count:integer;
  max:array[1..3] of integer;
  used:array[0..20] of boolean;
  stopper:array[0..20,0..20,0..20] of boolean;
  fin,fout:text;

procedure milking(a,b,c:integer);
  var
    i,j:integer;
    milk:array[1..3] of integer;

  procedure setup;
    begin
      milk[1]:=a;
      milk[2]:=b;
      milk[3]:=c;
    end;

  procedure pour(m,n:integer);
    var
      tofill:integer;

    begin
      tofill:=max[n]-milk[n];
      if milk[m]>tofill then
        begin
          milk[n]:=max[n];
          milk[m]:=milk[m]-tofill;
        end
      else
        begin
          milk[n]:=milk[n]+milk[m];
          milk[m]:=0;
        end;
    end;

  begin
    if not(stopper[a,b,c]) then
      begin
        stopper[a,b,c]:=true;
        if a=0 then used[c]:=true;
        for i:=1 to 3 do
          for j:=1 to 3 do
            if i<>j then
              begin
                setup;
                if (milk[i]<>0) and (milk[j]<>max[j]) then
                  begin
                    pour(i,j);
                    milking(milk[1],milk[2],milk[3]);
                  end;
              end;
      end;
  end;

begin
  assign(fin,'milk3.in');
  assign(fout,'milk3.out');
  reset(fin);
  rewrite(fout);
  readln(fin,max[1],max[2],max[3]);
  milking(0,0,max[3]);
  for i:=0 to max[3]-1 do if used[i] then write(fout,i,' ');
  writeln(fout,max[3]);
  close(fin);
  close(fout);
end.
