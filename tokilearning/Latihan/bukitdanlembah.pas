var
  best,a,top,bef:longint;
  downhill:boolean;

begin
  readln(top);
  if eof then
    begin
      writeln(0); halt;
    end;
  repeat
    readln(a);
  until (a<>top) or eof;
  downhill:=a<top; bef:=a; best:=0;
  while not eof do
    begin
      readln(a);
      if a=bef then continue
        else if downhill xor (a<bef) then
          begin
            if abs(bef-top)>best then best:=abs(bef-top);
            top:=bef; downhill:=not downhill;
          end;
      bef:=a;
    end;
  if abs(bef-top)>best then best:=abs(bef-top);
  writeln(best);
end.
