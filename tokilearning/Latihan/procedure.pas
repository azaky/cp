var
  x:integer;

procedure TulisJawaban(x: integer);
begin
    case x of
        1..9: begin writeln('satuan'); end;
        10..99: begin writeln('puluhan'); end;
        100..999: begin writeln('ratusan'); end;
        1000..9999: begin writeln('ribuan'); end;
        10000..30000: begin writeln('puluhribuan'); end;
    end;
end;

begin
  while not eof do
    begin
      readln(x);
      TulisJawaban(x);
    end;
end.