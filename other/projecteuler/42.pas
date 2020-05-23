var
  s,temp:ansistring;
  p,ans:longint;

function tri(s:ansistring):boolean;
  var
    v,i:longint;
    x:extended;
    
  begin
    v:=0;
    for i:=1 to length(s) do v:=v+ord(s[i])-ord('A')+1;
    x:=(sqrt(1+8*v)-1)/2;
    exit(x-trunc(x)<1e-9);
  end;

begin
  assign(input,'words.txt'); reset(input);
  readln(s);
  temp:=''; p:=0;
  repeat
    inc(p);
    if not (s[p] in ['A'..'Z']) then
      if temp>'' then
        begin
          if tri(temp) then inc(ans); temp:='';
        end
      else
    else temp:=temp+s[p];
  until p>length(s);
  writeln(ans);
end. 
