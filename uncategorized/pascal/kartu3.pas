var
  t,i,j,k:integer;
  a,b:boolean;
  input:string;
  card:array[1..3,1..3] of char;

begin
  readln(t);
  for k:=1 to t do
    begin
      for i:=1 to 3 do
        begin
          readln(input);
          for j:=1 to 3 do card[i,j]:=input[2*j];
        end;
      a:=false;
      b:=false;
      for i:=1 to 3 do
        begin
          if (card[i,1]=card[i,2]) and (card[i,2]=card[i,3]) then
            if card[i,1]='A' then a:=true
              else if card[i,1]='B' then b:=true;
          if (card[1,i]=card[2,i]) and (card[2,i]=card[3,i]) then
            if card[1,i]='A' then a:=true
              else if card[1,i]='B' then b:=true;
        end;
      if (card[1,1]=card[2,2]) and (card[2,2]=card[3,3]) then
        if card[1,1]='A' then a:=true
          else if card[1,1]='B' then b:=true;
      if (card[3,1]=card[2,2]) and (card[1,3]=card[3,1]) then
        if card[3,1]='A' then a:=true
          else if card[3,1]='B' then b:=true;
      if a=b then writeln('S')
        else if a then writeln('A')
          else writeln('B');
    end;
end.