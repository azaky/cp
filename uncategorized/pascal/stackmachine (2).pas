var
  t,kasus,k,len,i:integer;
  temp:char;
  input:string;
  hasil:array[1..100] of char;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      readln(input);
      k:=1;
      len:=0;
      while k<=length(input) do
        begin
          if input[k]='^' then
            for i:=1 to (len div 2) do
              begin
                temp:=hasil[i];
                hasil[i]:=hasil[len+1-i];
                hasil[len+1-i]:=temp;
              end
          else if input[k]<>'+' then
            begin
              inc(len);
              hasil[len]:=input[k];
            end;
          inc(k);
        end;
      for i:=1 to len do write(hasil[i]);
      writeln;
    end;
end.
