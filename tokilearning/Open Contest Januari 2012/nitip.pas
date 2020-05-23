const
  ss='PALLMALL';

var
  ans:longint;
  exist:array['A'..'P','A'..'P','A'..'P','A'..'P','A'..'P'] of boolean;
  used:array[0..9] of boolean;

procedure create(n:longint; s:string);
  var
    i:longint;
  
  begin
    if n=5 then
      begin
        if not exist[s[1],s[2],s[3],s[4],s[5]] then
          begin
            exist[s[1],s[2],s[3],s[4],s[5]]:=true;
            ans:=ans+1;
          end;
        exit;
      end;
    for i:=1 to 8 do
      if not used[i] then
        begin
          used[i]:=true; create(n+1,s+ss[i]); used[i]:=false;
        end;
  end;

begin
  create(0,'');
  writeln(ans);
end.
