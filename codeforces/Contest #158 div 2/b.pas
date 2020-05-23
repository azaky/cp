var
  date: array[0..31,0..12,2013..2015] of longint;
  s: ansistring;
  a: array[0..111111] of longint;
  len, i, j, d, m, y, ansD, ansY, ansM : longint;
  dD, dM, dY : boolean;

begin
  readln(s);
  len := length(s);
  for i := 1 to len do
    if (s[i] = '-') then a[i] := -1 else a[i] := ord(s[i]) - 48;
  { dd-mm-yyyy }
  for i := 1 to len-9 do
    begin
      dD := true; dM := true; dY := true;
      d := 0;
      for j := 0 to 1 do
        begin
          if a[i+j] = -1 then dD := false;
          d := 10*d + a[i+j];
        end;
      if not dD then continue;
      if a[i+2] <>-1 then continue;
      m := 0;
      for j := 3 to 4 do
        begin
          if a[i+j] = -1 then dM := false;
          m := 10*m + a[i+j];
        end;
      if not dM then continue;
      if a[i+5] <> -1 then continue;
      y := 0;
      for j := 6 to 9 do
        begin
          if a[i+j] = -1 then dY := false;
          y := 10*y + a[i+j];
        end;
      if not dY then continue;
      if (m < 1) or (d < 1) then continue;
      if (m > 12) then continue;
      if (m = 2) and (d > 28) then continue;
      if ((m = 1) or (m = 3) or (m = 5) or (m = 7) or (m = 8) or (m = 10) or (m = 12)) and (d > 31) then continue;
      if ((m = 4) or (m = 6) or (m = 9) or (m = 11)) and (d > 30) then continue;
      if (y < 2013) or (d > 2015) then continue;
      inc(date[d][m][y]);
    end;
  ansd := 0; ansm := 0; ansy := 2013;
  for d := 1 to 31 do
    for m := 1 to 12 do
      for y := 2013 to 2015 do
        if date[d][m][y] > date[ansd][ansm][ansy] then
          begin
            ansd := d; ansm := m; ansy := y;
          end;
  if (ansd < 10) then write(0);
  write(ansd);
  write('-');
  if (ansm < 10) then write(0);
  write(ansm);
  write('-');
  writeln(ansy);
end.
