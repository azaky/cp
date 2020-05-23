var
  n,p,i,fret,note,a,b,mid:longint;
  num:array[1..6] of longint;
  ans:array[1..6] of int64;
  tab:array[1..6,1..300000] of longint;
  
begin
  readln(n,p);
  fillchar(tab,sizeof(tab),255);
  fillchar(num,sizeof(num),0);
  fillchar(ans,sizeof(ans),0);
  
  for i:=1 to n do
    begin
      readln(fret,note);
      if note>tab[fret][num[fret]] then
        begin
          inc(num[fret]); inc(ans[fret]);
          tab[fret][num[fret]]:=note;
          continue;
        end;
      if note=tab[fret][num[fret]] then continue;
      
      a:=0; b:=num[fret];
      repeat
        mid:=(a+b) div 2;
        if note<tab[fret][mid] then b:=mid
          else a:=mid
      until b-a=1;
      
      ans[fret]:=ans[fret]+num[fret]-a;
      if tab[fret][a]<note then
        begin
          num[fret]:=a+1;
          tab[fret][num[fret]]:=note;
          ans[fret]:=ans[fret]+1;
        end
      else num[fret]:=a;
            
    end;
    
  writeln(ans[1]+ans[2]+ans[3]+ans[4]+ans[5]+ans[6]);
end.

