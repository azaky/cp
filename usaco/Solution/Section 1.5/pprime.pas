{
ID: a_zaky01
PROG: pprime
LANG: PASCAL
}

type
  digit=array[1..5] of integer;

var
  i,d1,len:integer;
  a,b:longint;
  d:digit;
  fin,fout:text;

procedure pprime(d:digit; k:integer);
  var
    i:integer;
    num:longint;

  procedure generate;
    var
      i:integer;
      p:longint;

    begin
      num:=0;
      p:=1;
      for i:=1 to len do
        begin
          num:=num+p*d[i];
          p:=p*10;
        end;
      for i:=len-1 downto 1 do
        begin
          num:=num+p*d[i];
          p:=p*10;
        end;
    end;

  function check:boolean;
    var
      i:longint;

    begin
      check:=true;
      if (a<=num) and (num<=b) then
        begin
          for i:=3 to trunc(sqrt(num)) do
            if i mod 2=1 then
              if num mod i=0 then
                begin
                  check:=false;
                  break;
                end;
         end
       else check:=false;
    end;

  begin
    if k=len then
      begin
        generate; 
        if check then writeln(fout,num);
      end
    else
      begin
        inc(k);
        for i:=0 to 9 do
          begin
            d[k]:=i;
            pprime(d,k);
          end;
      end;
  end;

begin
  assign(fin,'pprime.in');
  assign(fout,'pprime.out');
  reset(fin);
  rewrite(fout);
  readln(fin,a,b);
  //check palindromes with length 1 and 2
  for i:=1 to 3 do
    begin
      case i of
          1:d1:=5;
          2:d1:=7;
          3:d1:=11;
        end;
      if (a<=d1) and (d1<=b) then writeln(fout,d1);
    end;
  //check palindromes with length 2*len+1
  for len:=2 to 4 do
    //if (ln(a)<(2*len+1)*ln(10)) and (ln(b)>=(2*len)*ln(10)) then
      for i:=1 to 4 do
        begin
          case i of
              1:d[1]:=1;
              2:d[1]:=3;
              3:d[1]:=7;
              4:d[1]:=9;
            end;
          pprime(d,1);
        end;
  close(fin);
  close(fout);
end.
