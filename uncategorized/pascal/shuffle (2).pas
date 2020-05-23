var
  m,n,k,i,j:integer;
  arr:array[1..1000] of string;
 
label
  finish;
  
begin
  readln(m,n);
  for k:=1 to n div m do
    begin
      for i:=1 to m do
        begin
          readln(arr[i]);
          if i>1 then
            for j:=1 to i-1 do
              if arr[i]=arr[j] then
                begin
                  writeln('BELI BARU');
                  writeln((k-1)*m+i);
                  goto finish;
                end;
        end;
    end;
  writeln('BENAR');
  finish:
end.
 