var
  t,kasus,n,i,j,size:longint;
  temp:boolean;
  input:string;
  land:array[1..19,1..19] of char;

function check(r,c:integer):boolean;
  var
    i,j:longint;

  begin
    check:=true;
    for i:=r to r+size-1 do
      begin
        for j:=c to c+size-1 do
          if land[i,j]='#' then
            begin
              check:=false;
              break;
            end;
        if not check then break;
      end;
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(land,sizeof(land),'#');
      readln(n);
      for i:=1 to n do
        begin
          readln(input);
          for j:=1 to n do land[i,j]:=input[j];
        end;
      size:=1;
      for i:=1 to n do
        begin
          for j:=1 to n do
            begin
              repeat
                temp:=check(i,j);
                if temp then inc(size);
              until not temp;
              if j+size>n+1 then break;
            end;
          if i+size>n+1 then break;
        end;
      writeln(size-1);
    end;
end.
