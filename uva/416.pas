const d:array[0..9] of string[7] = ('YYYYYYN',
                                    'NYYNNNN',
                                    'YYNYYNY',
                                    'YYYYNNY',
                                    'NYYNNYY',
                                    'YNYYNYY',
                                    'YNYYYYY',
                                    'YYYNNNN',
                                    'YYYYYYY',
                                    'YYYYNYY');

var
  n,i:longint;
  s:array[0..11] of string[7];

function match(k:longint):boolean;
  var
    i,j:longint;
    burn:array[0..9] of boolean;
  
  begin
    fillchar(burn,sizeof(burn),false);
    for i:=n downto 1 do
      for j:=1 to 7 do
        if burn[j] and (s[i][j]='Y') then exit(false)
          else if not burn[j] then
            if (d[i+k-n][j]='N') and (s[i][j]='Y') then exit(false)
              else if (d[i+k-n][j]='Y') and (s[i][j]='N') then burn[j] := true;
    exit(true);
  end;

begin
  repeat
    readln(n); if n=0 then exit;
    for i:=n downto 1 do readln(s[i]);
    for i:=n-1 to 10 do
      if i=10 then writeln('MISMATCH')
        else if match(i) then begin writeln('MATCH'); break; end;
  until false;
end.
