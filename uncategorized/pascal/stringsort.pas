var
  n,i,j,p:longint;
  character:string;
  data:array[1..10000] of string;

procedure swap(var str1,str2:string);
  var
    temp:string;

  begin
    temp:=str1;
    str1:=str2;
    str2:=temp;
  end;

begin
  readln(n);
  character:=' .,?!"-()@/:_;+&%*=<>[]{}\~^`#|0123456789AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz';
  for i:=1 to n do readln(data[i]);
  for i:=n downto 2 do
    for j:=1 to i-1 do
      begin
        p:=1;
        while p>0 do
          begin
            if (p>length(data[j])) and (p>length(data[j+1])) then p:=0
              else if (p>length(data[j])) and (p<=length(data[j+1])) then p:=0
                else if (p<=length(data[j])) and (p>length(data[j+1])) then
                  begin
                    swap(data[j],data[j+1]);
                    p:=0;
                  end
                else if pos(data[j][p],character)=pos(data[j+1][p],character) then inc(p)
                  else if pos(data[j][p],character)>pos(data[j+1][p],character) then
                    begin
                      swap(data[j],data[j+1]);
                      p:=0;
                    end
                  else p:=0;
          end;
      end;
  for i:=1 to n do writeln(data[i]);
end.
