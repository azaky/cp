type
  arr = array[1..5] of longint;

var
  t,kasus,n,i,j:longint;
  same:boolean;
  have:array[1..5] of boolean;
  num:array[1..5] of longint;
  score:arr;
  save:array[1..5,1..60000] of arr;

procedure play(a,b:integer; score:arr);
  begin
    if a=n then
      begin
        inc(num[n]); save[n][num[n]]:=score;
        exit;
      end
    else if b>n then
      begin
        play(a+1,a+2,score);
        exit;
      end;
    inc(score[a],3); play(a,b+1,score); dec(score[a],3);
    inc(score[b],3); play(a,b+1,score); dec(score[b],3);
    inc(score[a]); inc(score[b]); play(a,b+1,score);
  end;

begin
  readln(t);
  for kasus:=1 to t do
    begin
      read(n);
      if not have[n] then
        begin
          have[n]:=true; num[n]:=0;
          fillchar(score,sizeof(score),0);
          play(1,2,score);
        end;
      for i:=1 to n do read(score[i]);
      for i:=1 to num[n]+1 do
        begin
          if i>num[n] then
            begin
              writeln('NO'); break;
            end;
          same:=true;
          for j:=1 to n do
            if save[n][i][j]<>score[j] then
              begin
                same:=false; break;
              end;
          if same then
            begin
              writeln('YES'); break;
            end;
        end;
    end;
end.

