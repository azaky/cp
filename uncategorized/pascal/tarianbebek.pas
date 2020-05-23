var
  n,i,j,k,x,y,xmin,ymin,xmax,ymax,xt,yt:longint;
  instruksi,input,langkah:string;

begin
  readln(n);
  x:=0;
  y:=0;
  xmin:=0;
  ymin:=0;
  xmax:=0;
  ymax:=0;
  for i:=1 to n do
    begin
      readln(input);
      for j:=1 to length(input) do if input[j]=' ' then break;
      instruksi:=copy(input,1,j-1);
      langkah:=copy(input,j+1,length(input));
      val(langkah,k);
      if instruksi='maju' then
        begin
          y:=y+k;
          if y>ymax then ymax:=y;
        end
      else if instruksi='mundur' then
        begin
          y:=y-k;
          if y<ymin then ymin:=y;
        end
      else if instruksi='kanan' then
        begin
          x:=x+k;
          if x>xmax then xmax:=x;
        end
      else if instruksi='kiri' then
        begin
          x:=x-k;
          if x<xmin then xmin:=x;
        end;
    end;
  xt:=xmax-xmin;
  yt:=ymax-ymin;
  if xt>yt then writeln(xt,' ',yt) else writeln(yt,' ',xt);
end.