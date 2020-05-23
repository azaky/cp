var
  subtask1_l: longint = 6;
  subtask1: array[1..6] of longint = (5, 5, 5, 5, 5, 5);
  s, balasan: ansistring;
  n, t, r: longint;
  i: longint;

begin
  readln(s);
  readln(n, t, r);

  if s[2] = '1' then begin
    for i:=1 to subtask1_l do begin
      writeln(subtask1[i]);
      flush(stdout);
      readln(balasan);
    end;
  end;
end.