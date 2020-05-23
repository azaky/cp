var
  t,kasus,k,i,j,n:integer;
  input,temp:string;
  hasil:array[1..4] of string;

function u(input:string):string;
  begin
    case input[length(input)] of
      '1','2':if length(input)=1 then u:=''
                else u:=u(copy(input,1,length(input)-1));
      '3','4':u:=copy(input,1,length(input)-1)+char(ord(input[length(input)])-2);
    end;
  end;

function d(input:string):string;
  begin
    case input[length(input)] of
      '3','4':if length(input)=1 then d:=''
                else d:=d(copy(input,1,length(input)-1));
      '1','2':d:=copy(input,1,length(input)-1)+char(ord(input[length(input)])+2);
    end;
  end;

function l(input:string):string;
  begin
    case input[length(input)] of
      '1','3':if length(input)=1 then l:=''
                else l:=l(copy(input,1,length(input)-1));
      '2','4':l:=copy(input,1,length(input)-1)+char(ord(input[length(input)])-1);
    end;
  end;

function r(input:string):string;
  begin
    case input[length(input)] of
      '2','4':if length(input)=1 then r:=''
            else r:=r(copy(input,1,length(input)-1));
      '1','3':r:=copy(input,1,length(input)-1)+char(ord(input[length(input)])+1);
    end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      writeln('Case #',kasus,':');
      readln(input);
      k:=0;
      temp:=u(input);
      if temp<>'' then
        begin
          inc(k);
          hasil[k]:=temp;
        end;
      temp:=l(input);
      if temp<>'' then
        begin
          inc(k);
          hasil[k]:=temp;
        end;
      temp:=d(input);
      if temp<>'' then
        begin
          inc(k);
          hasil[k]:=temp;
        end;
      temp:=r(input);
      if temp<>'' then
        begin
          inc(k);
          hasil[k]:=temp;
        end;
      for i:=k downto 2 do
        for j:=1 to i-1 do
          begin
            n:=1;
            while (n<=length(hasil[j])) and (n<=length(hasil[j+1])) do
              if hasil[j][n]=hasil[j+1][n] then inc(n)
                else
                  begin
                    if ord(hasil[j][n])>ord(hasil[j+1][n]) then
                      begin
                        temp:=hasil[j];
                        hasil[j]:=hasil[j+1];
                        hasil[j+1]:=temp;
                      end;
                    break;
                  end;
          end;
      for i:=1 to k do writeln(hasil[i]);
    end;
end.
