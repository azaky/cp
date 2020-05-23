var
  fin,fout:string;
  ch:char;
  
begin
  readln(fin);
  readln(fout);
  
  assign(input,fin);
  assign(output,fout);
  reset(input);
  rewrite(output);
  
  while not eof do
    begin
      read(ch); write(ch);
    end;
  
  close(input);
  close(output);
  
end.
