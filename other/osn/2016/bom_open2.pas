var
  subtask1_l: longint = 6;
  subtask1: array[1..6] of longint = (5, 5, 5, 5, 5, 5);
  subtask2_l: longint = 16;
  subtask2: array[1..16] of longint = (1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);
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

  if s[3] = '2' then begin
    for i:=1 to subtask2_l do begin
      writeln(subtask2[i]);
      flush(stdout);
      readln(balasan);
    end;
  end;
end.