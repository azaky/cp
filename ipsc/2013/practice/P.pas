var
  s: string;
  x: longint;

function IsInteger(s: string):boolean;
  var i : longint;
  begin
    if ((s[1] < '0') or (s[1] > '9')) and (s[1] <> '-') then exit(false);
    for i := 2 to length(s) do
      if (s[i] < '0') or (s[i] > '9') then exit(false);
    exit(true);
  end;

begin
  while (not eof) do
    begin
      readln(s);
      if (IsInteger(s)) then
        begin
          val(s,x);
          writeln(x+1);
        end
      else writeln(s);
    end;
end.
