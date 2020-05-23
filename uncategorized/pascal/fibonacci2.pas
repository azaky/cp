var
  input:string;
  i:integer;
  f:array[1..200] of string;

function sum(a,b:string):string;
  var
    k,sisa,n1,n2,x:integer;

  begin
    if length(b)>length(a) then sum:=sum(b,a)
      else
        begin
          n1:=length(a);
          n2:=length(b);
          sisa:=0;
          k:=1;
          sum:='';
          while k<=n1 do
            begin
              x:=ord(a[n1+1-k])-48+sisa;
              if k<=n2 then x:=x+ord(b[n2+1-k])-48;
              sum:=char((x mod 10)+48)+sum;
              if x>9 then sisa:=1
                else sisa:=0;
              inc(k);
            end;
          if sisa<>0 then sum:='1'+sum;
        end;
  end;

function less(a,b:string):boolean;
  var
    k:integer;

  begin
    if length(a)<length(b) then less:=true
      else if length(a)>length(b) then less:=false
        else
          begin
            k:=1;
            less:=false;
            while k<=length(a) do
              if ord(a[k])=ord(b[k]) then inc(k)
                else
                  begin
                    if ord(a[k])<ord(b[k]) then less:=true
                      else less:=false;
                    break;
                  end;
          end;
  end;

begin
  readln(input);
  f[1]:='0';
  f[2]:='1';
  if input='0' then writeln(1)
    else if input='1' then writeln(2)
      else
        begin
          i:=2;
          while less(f[i],input) do
            begin
              inc(i);
              f[i]:=sum(f[i-1],f[i-2]);
            end;
          if f[i]=input then writeln(i)
            else writeln(0);
        end;
end.
