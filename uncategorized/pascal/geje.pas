unit Baru;

interface

function NewReadln(Max: Integer): String;

implementation

function NewReadln(Max: Integer): String;
  var
    s: String;
    c: Char;

  begin
    s := '';
    repeat
      c := ReadKey;
      if (c = #8){#8 = BACKSPACE} and (s <> '') then
        begin
          Write(#8+' '+#8);
          delete(s,length(s),1);
        end;
      if (c <> #8) and (c <> #13){#13 = ENTER} and (length(s) < Max) then
        begin
          Write(c);
          s := s + c;
        end;
    until c = #13;
    NewReadln := s;
  end;

end.

