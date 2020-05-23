var
  p,l:integer;
  count:longint;
  arrgcd,arrrec:array[0..10000,0..10000] of integer;

label
  start;

function rec(p,l:integer):integer;
  var
    d,rec1,rec2,p1,l1:integer;

  function gcd(a,b:integer):integer;
    begin
      //inc(count);
      //writeln(count);
      if arrgcd[a,b]=0 then
        if b=0 then gcd:=a
          else gcd:=gcd(b,a mod b)
      else gcd:=arrgcd[a,b];
      arrgcd[a,b]:=gcd;
    end;

  begin
    //inc(count);
    //writeln(count);
    if l>p then rec:=rec(l,p)
      else if arrrec[p,l]=0 then
        begin
          if arrgcd[p,l]=0 then d:=gcd(p,l)
            else d:=arrgcd[p,l];
          if d>1 then rec:=rec(p div d,l div d)
            else if l=1 then rec:=p
              else
                begin
                  rec:=0;
                  for p1:=1 to p div 2 do
                    begin
                      if p1<l then rec1:=rec(l,p1)
                        else rec1:=rec(p1,l);
                      if p1=p-p1 then rec2:=rec1
                        else if p-p1<l then rec2:=rec(l,p-p1)
                          else rec2:=rec(p-p1,l);
                      if (rec=0) or (rec>rec1+rec2) then
                        rec:=rec1+rec2;
                    end;
                  for l1:=1 to l div 2 do
                    begin
                      rec1:=rec(p,l1);
                      if l1=l-l1 then rec2:=rec1
                        else rec2:=rec(p,l-l1);
                      if rec>rec1+rec2 then
                        rec:=rec1+rec2;
                    end;
                end;
          arrrec[p,l]:=rec;
        end
      else rec:=arrrec[p,l];
    //arrrec[p,l]:=rec;
  end;

begin

  assign(input,'tes.in');
  assign(output,'tes.out');
  reset(input);
  rewrite(output);
  start:

  readln(p,l);
  //count:=0;
  writeln(p,' ',l,' ',rec(p,l));
  //writeln(count);
  if not(eof) then goto start;
  close(input);
  close(output);

end.
