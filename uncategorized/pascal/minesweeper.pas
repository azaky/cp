var
baris,kolom,i,j,k,l,mines:integer;
input:string;
bomb:boolean;
mine:array[0..1000,0..1000] of string;

begin
  readln(baris,kolom);
  for i:=1 to baris do
    begin
      readln(input);
      for j:=1 to kolom do mine[i,j]:=input[j];
    end;
  for i:=1 to baris do
    begin
      for j:=1 to kolom do
        begin
          bomb:=false;
          mines:=0;
          for k:=i-1 to i+1 do
            begin
              for l:=j-1 to j+1 do
                begin
                  if mine[i,j]='*' then bomb:=true
                    else if not((k=i) and (l=j)) then if mine[k,l]='*' then mines:=mines+1;
                end;
            end;
          if bomb=true then write('*')
            else write(mines);
          if j=kolom then writeln;
        end;
    end;
end.